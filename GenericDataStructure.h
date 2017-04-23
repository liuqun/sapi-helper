/**
 * @copyright 青岛中怡智能安全研究院有限公司, 2017, all rights reserved.
 */


#ifndef GENERIC_DATA_STRUCTURE_H_
#define GENERIC_DATA_STRUCTURE_H_

#include <stddef.h>
#include <stdint.h>
typedef uint8_t UINT8;
typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;

class GenericDataStructure {
protected:
    struct DataBuffer *pData;
public:
    GenericDataStructure();

    /**
     * 返回数据缓冲区的长度记录, 不包括长度头本身的两字节
     */
    size_t getBufferSize();

    /**
     * 返回指向数据缓冲区的指针, 不包括两字节的长度头
     */
    const void *getBuffer();
    virtual ~GenericDataStructure();
};

class Data: public GenericDataStructure {
public:
    Data(size_t size);
    virtual ~Data();
};

#endif /* GENERIC_DATA_STRUCTURE_H_ */
