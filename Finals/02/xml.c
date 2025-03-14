
#include "./stack.h"
#include "./xml.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

unsigned char isXML(FILE* file) {
    char line[XML_LINE_LENGTH];

    Stack tags;

    char* _line;
    unsigned char hasValidHeader = 0;

    char openTag[XML_TAG_LENGTH];
    char closeTag[XML_TAG_LENGTH];

    unsigned char isValid;

    while (fgets(line, XML_LINE_LENGTH, file)) {
        _line = line;
        while (isspace(*_line)) _line++;

        if (*_line != '\0') {
            hasValidHeader = isValidXMLHeader(_line);
            break;
        };
    };

    if (!hasValidHeader) return 0;

    newStack(&tags);

    while (fgets(line, XML_LINE_LENGTH, file)) {
        _line = line;
        _line = strchr(_line, '<');

        while (_line != NULL) {
            if (*(_line + 1) == '/') {
                if (
                    sscanf(_line, "</%[^>]", closeTag) != 1 ||
                    shiftStackElement(&tags, openTag, XML_TAG_LENGTH) ||
                    strcmp(openTag, closeTag) != 0
                ) {
                    destroyStack(&tags);
                    return 0;
                };

            } else {
                if (
                    sscanf(_line, "<%[^>]", openTag) != 1 ||
                    unshiftStack(&tags, openTag, XML_TAG_LENGTH)
                ) {
                    destroyStack(&tags);
                    return 0;
                };

            };

            _line++;
            _line = strchr(_line, '<');
        };
    };

    isValid = isStackEmpty(&tags);

    destroyStack(&tags);

    return isValid;
}

unsigned char isValidXMLHeader(char* header) {
    char* _header = header;

    char xmlHeader[] = "<? xml version=\"%d.%d\" >";
    char* _xmlHeader = xmlHeader;

    while (isspace(*_header)) _header++;

    while (*_header != '\0' && *_xmlHeader != '\0') {
        if (*_header == *_xmlHeader) {
            _header++;
            _xmlHeader++;
            continue;
        };

        if (*_xmlHeader != '%') return 0;

        _xmlHeader++;

        switch (*_xmlHeader) {
            case 'd':
                if (!isdigit(*_header)) return 0;

                while (isdigit(*_header)) _header++;
                _xmlHeader++;

                break;

            default:
                continue;
        };
    };

    while (isspace(*_header)) _header++;

    return *_header == '\0' && *_xmlHeader == '\0';
}

