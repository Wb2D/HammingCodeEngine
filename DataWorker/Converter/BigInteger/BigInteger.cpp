#include "DataWorker\Converter\BigInteger\BigInteger.h"

QString BigInteger::toString() const {
    QString result;
    for(int i = data.length() - 1; i >= 0; --i) {
        result += QString::number(data.at(i));
    }
    return result;
}

void BigInteger::removeZeros() {
    while(data.size() > 1 && data.last() == 0) {
        data.pop_back();
    }
}

BigInteger BigInteger::div2() const {
    BigInteger result = *this;
    int carry = 0;
    for(int i = result.data.size() - 1; i >= 0; --i) {
        int current = result.data[i];
        int tmp = (current + carry * 10) / 2;
        carry = current % 2;
        result.data[i] = tmp;
    }
    result.removeZeros();
    return result;
}

BigInteger BigInteger::operator+(const BigInteger &number) const {
    BigInteger result;
    int carry = 0;
    int maxSize = qMax(data.size(), number.data.size());
    for (int i = 0; i < maxSize; ++i) {
        int sum = carry;
        if (i < data.size()) {
            sum += data[i];
        }
        if (i < number.data.size()) {
            sum += number.data[i];
        }
        carry = sum / 10;
        sum = sum % 10;
        result.data.append(sum);
    }
    if (carry > 0) {
        result.data.append(carry);
    }
    return result;
}

BigInteger BigInteger::operator*(const BigInteger &number) const {
    BigInteger result("0");
    for (int i = 0; i < number.data.size(); ++i) {
        int carry = 0;
        BigInteger pResult;
        for (int j = 0; j < i; ++j) {
            pResult.data.append(0);
        }
        for (int j = 0; j < data.size(); ++j) {
            int prod = data[j] * number.data[i] + carry;
            pResult.data.append(prod % 10);
            carry = prod / 10;
        }
        if (carry > 0) {
            pResult.data.append(carry);
        }
        result = result + pResult;
    }
    return result;
}

bool BigInteger::isEven() const {
    return data.first() % 2;
}

bool BigInteger::isZero() const {
    return (data.size() == 1 && data[0] == 0);
}

void BigInteger::append(const int &digit) {
    data.push_back(digit);
}

int BigInteger::operator[](const int& index) const {
    if (index < 0 || index > data.size()) {
        qWarning() << "ERROR : BitSequence -> bitsArray -> (index out of range)";
        return -1;
    }
    return data.at(index);
}

int BigInteger::length() const {
    return data.size();
}
