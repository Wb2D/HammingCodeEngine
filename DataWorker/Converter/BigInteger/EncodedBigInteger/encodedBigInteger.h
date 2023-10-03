#ifndef _encodedBigInteger
#define _encodedBigInteger

/*
 * Данный класс является оберткой для закодированного числа BigInteger
*/

#include "DataWorker/Converter/BigInteger/BigInteger.h"

class EncodedBigInteger {
public:
    // конструктор с параметрами
    EncodedBigInteger(const BigInteger &digit, const QString &method, const qint64 &time,
                      const int &iteration) : digit(digit), method(method), time(time),
                      iteration(iteration) {    }
    // геттер для поля data
    const BigInteger &getData() const { return digit; }
    // геттер для поля method
    const QString &getMethod() const { return method; }
    // геттер для поля time
    const qint64 &getTime() const { return time; }
    // геттер для поля iteration
    const int &getIteration() const { return iteration; }
    // метод для перевода в строку
    const QString toString() const;

private:
    BigInteger digit; // закодированная числовая последовательность
    QString method; // алгоритм, используемый для кодирование
    qint64 time; // время, затраченное на кодирование
    int iteration; // число частей, на которые была разбита последовательность
};

#endif
