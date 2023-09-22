#ifndef _bigInteger_h
#define _bigInteger_h

/*
 *
 *
 */

#include <QVector>
#include <QtGlobal>

class BigInteger {
public:
    BigInteger() { }
    BigInteger(QString number) {
        for(const QChar &digit : number) {
            data.push_front(digit.digitValue());
        }
        removeZeros();
    }
    QString toString() const;
    BigInteger div2() const;
    BigInteger operator+(const BigInteger &number) const;
    BigInteger operator*(const BigInteger &number) const;
    bool isEven() const;
    bool isZero() const;

private:
    void removeZeros();

    QVector<int> data;
};

#endif
