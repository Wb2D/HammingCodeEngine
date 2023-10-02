#include "Encoder/HammingCode/Encoder74/Encoder74.h"

EncodedBitSequence Encoder74::start(const BitSequence &data) {
    BitSequence eData;
    int eSize = data.length();
    // если длинна битовой последовательности не кратна 4
    if (eSize % 4) {
        eSize += 4 - (eSize % 4);
    }
    for (int i = 0; i < eSize; i +=4) {
        encode(data.subsequence(i, i + 3), eData);
    }
    return EncodedBitSequence(eData, "H74", 0, eSize / 4);
}

void Encoder74::encode(const BitSequence &data, BitSequence &result) {
    result.append(int(data[0] + data[1] + data[3]) % 2);
    result.append(int(data[0] + data[2] + data[3]) % 2);
    result.append(data[0]);
    result.append(int(data[1] + data[2] + data[3]) % 2);
    result.append(data[1]);
    result.append(data[2]);
    result.append(data[3]);
}
