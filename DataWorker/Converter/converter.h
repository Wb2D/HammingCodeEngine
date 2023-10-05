#ifndef _converter_h
#define _converter_h

/*
 * Данный класс используется для перевода заданного числа в формате QString в двоичную СС и
 * сопуствующую его запись в объект класса BitSequence. Методы класса способны обрабатывать
 * числа до 36-ричной СС. Также для ускорения перевода и уменьшения вычислений был использон
 * словарь QMap<char, int>
 */

#include <QString>
#include <QMap>
#include <QtMath>
#include <QDebug>

#include "DataWorker\BitSequence\bitSequence.h"
#include "DataWorker\Converter\BigInteger\BigInteger.h"

class Converter {
public:
    // метод для перевода числа в двоичную сс и его запись в bitSequency
    static void toBinary(BitSequence &bitSequency, const QString &number, const int &base) ;
    // метод для перевода последовательности символов в битовую
    static void toBinary(BitSequence &bitSequency, const QString &chars);

private:
    // метод для перевода числа в десятичную СС
    static BigInteger toDecimal(const QString &number, const int &base);
    // метод для поиска десятичного числа в словаре
    static int charToDecimal(QChar ch);

    static const QMap<QChar, int> charToDigit; // словарь соответсвий
};

#endif
