
#include <stdlib.h>
#include <string.h>

#include "./main.h"

// Constructor
void newQueue(Queue* _queue) {
    _queue->__head = 0;
    _queue->__tail = 0;
    _queue->__remainingCapacity = QUEUE_BYTES;
}

// Destructor
void destroyQueue(Queue* _queue) {
    _queue->__head = 0;
    _queue->__tail = 0;
    _queue->__remainingCapacity = QUEUE_BYTES;
}

// Getters
unsigned char getTopQueueElement(
    const Queue* _queue,
    void* store,
    const size_t sizeOfStore
) {
    size_t offset;

    size_t bytesForData01;
    size_t bytesForData02;

    size_t sizeOfData;

    if (_queue->__remainingCapacity == QUEUE_BYTES) return 1;

    // Read size of data
    offset = _queue->__head;
    bytesForData01 = MIN(sizeof(size_t), QUEUE_BYTES - _queue->__head);

    memcpy(
        &sizeOfData,
        _queue->__data + offset,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeof(size_t) - bytesForData01;

    memcpy(
        (&sizeOfData) + bytesForData01,
        _queue->__data + offset,
        bytesForData02
    );

    if (sizeOfData != sizeOfStore) return 1;

    // Read and save data
    offset = (offset + bytesForData02) % QUEUE_BYTES;
    bytesForData01 = MIN(sizeOfData, QUEUE_BYTES - offset);

    memcpy(
        store,
        _queue->__data + offset,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeOfData - bytesForData01;

    memcpy(
        (char*)store + bytesForData01,
        _queue->__data + offset,
        bytesForData02
    );

    return 1;
}

unsigned char isQueueEmpty(const Queue* _queue) {
    return _queue->__remainingCapacity == QUEUE_BYTES;
}

unsigned char isQueueFull(
    const Queue* _queue,
    const size_t sizeOfData
) {
    const size_t requiredSpace = sizeof(size_t) + sizeOfData;
    return requiredSpace > _queue->__remainingCapacity;
}

// Methods
unsigned char shiftQueueElement(
    Queue* _queue,
    void* store,
    const size_t sizeOfStore
) {
    size_t offset;

    size_t bytesForData01;
    size_t bytesForData02;

    size_t sizeOfData;

    if (_queue->__remainingCapacity == QUEUE_BYTES) return 1;

    // Read size of data
    offset = _queue->__head;
    bytesForData01 = MIN(sizeof(size_t), QUEUE_BYTES - _queue->__head);

    memcpy(
        &sizeOfData,
        _queue->__data + offset,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeof(size_t) - bytesForData01;

    memcpy(
        (&sizeOfData) + bytesForData01,
        _queue->__data + offset,
        bytesForData02
    );

    if (sizeOfData != sizeOfStore) return 1;

    _queue->__head += ((bytesForData01 + bytesForData02) % QUEUE_BYTES);
    _queue->__remainingCapacity += sizeof(size_t);

    // Read and save data
    offset = (offset + bytesForData02) % QUEUE_BYTES;
    bytesForData01 = MIN(sizeOfData, QUEUE_BYTES - offset);

    memcpy(
        store,
        _queue->__data + offset,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeOfData - bytesForData01;

    memcpy(
        (char*)store + bytesForData01,
        _queue->__data + offset,
        bytesForData02
    );

    _queue->__head += ((bytesForData01 + bytesForData02) % QUEUE_BYTES);
    _queue->__remainingCapacity += sizeOfData;

    return 0;
}

unsigned char pushQueueElement(
    Queue* _queue,
    void* data,
    const size_t sizeOfData
) {
    size_t offset;

    size_t bytesForData01;
    size_t bytesForData02;

    const size_t requiredSpace = sizeof(size_t) + sizeOfData;

    if (requiredSpace > _queue->__remainingCapacity) return 1;

    // Save size of data
    offset = _queue->__tail;
    bytesForData01 = MIN(sizeof(size_t), QUEUE_BYTES - _queue->__tail);

    memcpy(
        _queue->__data + offset,
        &sizeOfData,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeof(size_t) - bytesForData01;

    memcpy(
        _queue->__data + offset,
        (&sizeOfData) + bytesForData01,
        bytesForData02
    );

    _queue->__tail += ((bytesForData01 + bytesForData02) % QUEUE_BYTES);
    _queue->__remainingCapacity -= sizeof(size_t);

    // Save data
    offset = (offset + bytesForData02) % QUEUE_BYTES;
    bytesForData01 = MIN(sizeOfData, QUEUE_BYTES - offset);

    memcpy(
        _queue->__data + offset,
        data,
        bytesForData01
    );

    offset = (offset + bytesForData01) % QUEUE_BYTES;
    bytesForData02 = sizeOfData - bytesForData01;

    memcpy(
        _queue->__data + offset,
        (char*)data + bytesForData01,
        bytesForData02
    );

    _queue->__tail += ((bytesForData01 + bytesForData02) % QUEUE_BYTES);
    _queue->__remainingCapacity -= sizeOfData;

    return 0;
}
