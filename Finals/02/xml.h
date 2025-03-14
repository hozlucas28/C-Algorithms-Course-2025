#ifndef XML_H_INCLUDED
#define XML_H_INCLUDED

#include <stdio.h>

#define XML_LINE_LENGTH 256 + 1

#define XML_TAG_LENGTH 64 + 1

unsigned char isXML(FILE* file);

unsigned char isValidXMLHeader(char* header);

#endif // XML_H_INCLUDED
