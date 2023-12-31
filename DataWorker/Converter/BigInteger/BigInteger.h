#ifndef _bigInteger_h
#define _bigInteger_h

/*
 * Данный класс реализует длинную арифметику
 */

#include <QVector>
#include <QtGlobal>
#include <QString>
#include <QDebug>

class BigInteger {
public:
    // конструктор без параметров
    BigInteger() { }

     // конструктор с параметрами
    BigInteger(QString number) {
        for(const QChar &digit : number) {
            data.push_front(digit.digitValue());
        }
        removeZeros();
    }

     // перегрузка метода toString()
    QString toString() const;

     // метод для деления на 2
    BigInteger div2() const;

    // перегрузка оператора сложения
    BigInteger operator+(const BigInteger &number) const;

    // перегрузка оператора умножеия
    BigInteger operator*(const BigInteger &number) const;

    // метод для проверки числа на четность
    bool isEven() const;

    // метод проверяющий является ли число нулем
    bool isZero() const;

    // метод для добавления цифры в число
    void append(const int &digit);

    // перегрущка оператора индексации
    int operator[](const int& index) const;

    // метод возвращает число цифр в числе
    int length() const;

    // метод возвращает последовательность цифр числа
    BigInteger subdigit(const int &from, const int &to) const;
private:
    // метод для удаления незначащих нулей
    void removeZeros();

    QVector<int> data; // вектор для хранения числа
};

#endif
