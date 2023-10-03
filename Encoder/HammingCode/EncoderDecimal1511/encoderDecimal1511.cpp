#include "Encoder/HammingCode/EncoderDecimal1511/encoderDecimal1511.h"

EncodedBigInteger EncoderDecimal1511::start(const BigInteger &data) {
    BigInteger eData;
    int eSize = data.length();
    // если длинна битовой последовательности не кратна 11
    if (eSize % 11) {
        eSize += 11 - (eSize % 11);
    }
    for (int i = 0; i < eSize; i += 11) {
        encode(data.subdigit(i, i + 10), eData);
    }
    return EncodedBigInteger(eData, "Hd1511", 0, eSize/11);
}

void EncoderDecimal1511::encode(const BigInteger &data, BigInteger &result) {
    result.append((10 - (int(data[0] +data[1] + data[3] + data[4] + data[6] + data[8] + data[10]) % 10)) % 10);
    result.append((10 - (int(data[0] + data[2] + data[3] + data[5] + data[6] + data[9] + data[10]) % 10)) % 10);
    result.append(data[0]);
    result.append((10 - (int(data[1] + data[2] + data[3] + data[7] + data[8] + data[9] + data[10])) % 10) % 10);
    result.append(data[1]);
    result.append(data[2]);
    result.append(data[3]);
    result.append((10 - (int(data[4] + data[5] + data[6] + data[7] + data[8] + data[9] + data[10]) % 10)) % 10);
    result.append(data[4]);
    result.append(data[5]);
    result.append(data[6]);
    result.append(data[7]);
    result.append(data[8]);
    result.append(data[9]);
    result.append(data[10]);
}
