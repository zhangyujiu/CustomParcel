#include "Parcel.h"

Parcel::Parcel() {
    this->mData = static_cast<char *>(malloc(1024));
}

Parcel::~Parcel() {
    LOGE("Parcel析构函数")
    if (this->mData) {
        free(this->mData);
        this->mData = nullptr;
    }
}

void Parcel::writeInt(int value) {
    writeInt32(value);
}

int Parcel::readInt() {
    int result = *reinterpret_cast<int *>(this->mData + this->mDataPos);
    updatePosition(sizeof(int));
    return result;
}

void Parcel::writeChar(char value) {
    *(this->mData + this->mDataPos) = value;
    updatePosition(sizeof(char));
}

char Parcel::readChar() {
    char result = *(this->mData + this->mDataPos);
    updatePosition(sizeof(char));
    return result;
}

void Parcel::writeString(const char16_t *value, int len) {
    writeInt(len);
    char *dst = mData + mDataPos;
    memcpy(dst, value, len);
    updatePosition(len);
}

std::string Parcel::readString() {
    int strLen = readInt();
    char *data = mData + mDataPos;
    std::string result;
    int index = 0;
    while (index < strLen) {
        result = result + *(data + index * sizeof(char));
        index++;
    }
    updatePosition(strLen * sizeof(char));
    return result;
}

void Parcel::setDataPosition(int position) {
    this->mDataPos = position;
}

void Parcel::writeInt32(int32_t len) {
    writeAligned(len);
}

template<class T>
void Parcel::writeAligned(T len) {
    *reinterpret_cast<T *>(mData + mDataPos) = len;
    updatePosition(sizeof(len));
}

void Parcel::updatePosition(size_t len) {
    mDataPos += (int) len;
    LOGE("updatePosition -> sizeof(len) = %d, mDataPos = %d", len, mDataPos)
}