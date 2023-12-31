#include "DataWorker\Converter\converter.h"

const QMap<QChar, int> Converter::charToDigit = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11},
    {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17},
    {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23},
    {'O', 24}, {'P', 25}, {'Q', 26}, {'R', 27}, {'S', 28}, {'T', 29},
    {'U', 30}, {'V', 31}, {'W', 32}, {'X', 33}, {'Y', 34}, {'Z', 35},
};

 BigInteger Converter::toDecimal(const QString &number, const int &base) {
    BigInteger result("0");
    BigInteger value("1");
    for (int i = number.length() - 1; i >= 0; --i) {
        int tmp = charToDecimal(number.at(i));
        if (tmp == -1 || tmp >= base) {
            qDebug() << "ERROR : Converter -> toDecimal";
            return BigInteger("0");
        }
        result = result + (BigInteger(QString::number(tmp)) * value);
        value = value * BigInteger(QString::number(base));
    }
    return result;
}

int Converter::charToDecimal(QChar ch) {
    int result = -1;
    if(ch.isDigit()) {
        return ch.digitValue();
    } else if(ch.isLetter()) {
        result = charToDigit.value(ch.toUpper().toLatin1());
    }
    return result;
}

void Converter::toBinary(BitSequence &bitSequency, const QString &number, const int &base) {
    if (base < 2 || base > 36) {
        qDebug() << "ERROR : Converter -> wrong base";
    }
    BigInteger decimalNumber = toDecimal(number, base);
    while(!decimalNumber.isZero()) {
        bitSequency.append((decimalNumber.isEven()));
        decimalNumber = decimalNumber.div2();
    }
}

