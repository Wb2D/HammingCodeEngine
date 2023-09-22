#include "BitSequence/bitSequence.h"

void BitSequence::resize(const int& length) {
    int newLength = (length == 0) ? 1 : (length * 2);
    bool* newArray = new bool[newLength];
    for (int i = 0; i < bitCount - 1; ++i) {
        *(newArray + i) = *(bitArray + i);
    }
    delete[] bitArray;

    bitArray = newArray;
    arraySize = newLength;
}

bool BitSequence::operator[](const int& index) const {
    if (index < 0 || index >= bitCount) {
        qWarning() << "ERROR : BitSequence -> bitsArray -> (index out of range)";
        return false;
    }
    return *(bitArray + index);
}

void BitSequence::set(const int& index, const bool& value) {
    if (index < 0 || index >= bitCount) {
        qWarning() << "ERROR : BitSequence -> bitsArray -> (index out of range)";
        return;
    }
    *(bitArray + index) = value;
}

void BitSequence::append(const bool& value) {
    ++bitCount;
    if(bitCount >= arraySize) {
        resize(arraySize);
    }
    set(bitCount - 1, value);
}

QString BitSequence::toString() const {
    QString result;
    for (int i = bitCount - 1; i >= 0; --i) {
        result.append(bitArray[i] ? '1' : '0');
    }
    return result;
}
