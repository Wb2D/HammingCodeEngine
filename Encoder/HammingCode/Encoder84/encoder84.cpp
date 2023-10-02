#include "Encoder/HammingCode/Encoder84/encoder84.h"

EncodedBitSequence Encoder84::start(const BitSequence &data) {
    BitSequence eData;
    int eSize = data.length();
    // если длинна битовой последовательности не кратна 4
    if (eSize % 4) {
        eSize += 4 - (eSize % 4);
    }
    for (int i = 0; i < eSize; i +=4) {
        encode(data.subsequence(i, i + 3), eData);
    }
    return EncodedBitSequence(eData, "H84", 0, eSize / 4);
}

void Encoder84::encode(const BitSequence &data, BitSequence &result) {
    bool e1 = int(data[0] + data[1] + data[3]) % 2;
    bool e2 = int(data[0] + data[2] + data[3]) % 2;
    bool e3 = int(data[1] + data[2] + data[3]) % 2;

    result.append(int(e1 + e2 +e3 + data[0] + data[1] + data[2] + data[3]));
    result.append(e1);
    result.append(e2);
    result.append(data[0]);
    result.append(e3);
    result.append(data[1]);
    result.append(data[2]);
    result.append(data[3]);
}
