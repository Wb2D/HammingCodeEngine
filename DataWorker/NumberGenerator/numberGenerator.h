#ifndef _numberGenerator_h
#define _numberGenerator_h

/*
 * Данный класс предназначен для генерации случайных чисел. Он способен генерировать числа
 * с указанным числом разрядов и в заданной системе счисления.
 */

#include <QString>
#include <QDebug>
#include <QRandomGenerator>

class NumberGenerator {
public:
    // метод для генерации случайного числа
    static QString generate(const int &base, const int &digits);
private:
    // строка возможных символов
    static const QString arr;
};

#endif
