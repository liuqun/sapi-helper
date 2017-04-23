/**
 * @copyright 青岛中怡智能安全研究院有限公司, 2017, all rights reserved.
 */


#ifndef GENERIC_DATA_STRUCTURE_H_
#define GENERIC_DATA_STRUCTURE_H_

#include <stddef.h>
#include <sapi/tpm20.h> // @url https://github.com/01org/TPM2.0-TSS

class GenericDataStructure {
protected:
    struct DataBuffer *pData;
public:
    GenericDataStructure();

    /**
     * 返回数据缓冲区的长度记录, 不包括长度头本身的两字节
     */
    size_t getBufferSize() const;

    /**
     * 返回指向数据缓冲区的指针, 不包括两字节的长度头
     */
    const void *getBuffer() const;
    virtual ~GenericDataStructure();
};

class Data: public GenericDataStructure {
public:
    Data(size_t size);
    virtual ~Data();
};

/**
 * 函数名: Unpack()
 * 功能: 将 C++ 对象转换回 TPM2B_* 结构体指针
 *
 * @param object 待转换的 C++ 对象
 */
TPM2B_DATA *Unpack(const Data& object);

#endif /* GENERIC_DATA_STRUCTURE_H_ */
