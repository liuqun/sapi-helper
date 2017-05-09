/**
 * @copyright 青岛中怡智能安全研究院有限公司, 2017, all rights reserved.
 */

#include <stddef.h>
#include <stdint.h>
#include <sapi/tpm20.h>
#include "GenericDataStructure.h"

struct DataBuffer {
    uint16_t max;
    char buffer[1];
};

GenericDataStructure::GenericDataStructure()
{
    static struct DataBuffer DefaultDataBuffer = { 0, { '\0' } };
    pData = &DefaultDataBuffer;
}

size_t GenericDataStructure::getBufferSize() const
{
    return (size_t) pData->max;
}

const void* GenericDataStructure::getBuffer() const
{
    return (const void *) (pData->buffer);
}

GenericDataStructure::~GenericDataStructure()
{
}

/**
 * 构造函数
 *
 * @param size 在构造的同时可以指定最大缓冲区长度
 */

Data::Data(size_t max)
{
    if (max > (uint16_t) 0xFFFF) {
        max = 0xFFFF; // 限制缓冲区预留空间最大值为 65535 字节
    } else if (0 == max) {
        // 这里允许创建空数据块
    }

    int *p = new int[(sizeof(uint16_t) + max + sizeof(int) - 1) / sizeof(int)]; // 32 位主机内存块对齐 4 字节地址, 64 主机对齐 8 字节地址
    pData = (struct DataBuffer *) p;
    pData->max = max;
}

Data::~Data()
{
    uint8_t *p = (uint8_t *) ((void *) pData);
    delete[] p;
}

TPM2B_DATA *Unpack(const Data& obj)
{
    return (TPM2B_DATA *) obj.getBuffer();
}
