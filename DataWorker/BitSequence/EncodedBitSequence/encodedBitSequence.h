#ifndef _encodedBitSequence
#define _encodedBitSequence

/*
 * Данный класс является оберткой для объекта BitSequence, который хранит информацию
 * о примененном методе кодирования, число частей, на которое была разбита исходная
 * последовательность и время, затраченное на кодирование.
 */

#include <QDateTime>
#include <QString>

#include "DataWorker\BitSequence\bitSequence.h"

class EncodedBitSequence {
public:
    // конструктор с параметрами
    EncodedBitSequence(const BitSequence &data, const QString &method, const qint64 &time,
                       const int &iteration) : data(data), method(method), time(time),
                       iteration(iteration) {   }
    // геттер для поля data
    const BitSequence &getData() const { return data; }
    // геттер для поля method
    const QString &getMethod() const { return method; }
    // геттер для поля time
    const qint64 &getTime() const { return time; }
    // геттер для поля iteration
    const int &getIteration() const { return iteration; }
    // метод для перевода в строку
    const QString toString() const;
private:
    BitSequence data; // закодированная битовая последовательность
    QString method; // алгоритм, используемый для кодирование
    qint64 time; // время, затраченное на кодирование
    int iteration; // число частей, на которые была разбита последовательность
};

#endif
