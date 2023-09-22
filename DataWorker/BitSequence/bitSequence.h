#ifndef _bitSequence_h
#define _bitSequence_h

/*
 * Данный класс служет для хранения битовой последовательности, а также позволяет устанавливать
 * и получать биты по их индексу. В нем предусмотрено увеличение размера последовательности
 * при необходимости с применением DynamicResize. Также он не упаковывает биты в байты, что
 * предоставляет комфортный доступ к каждому отдельному биту.
 */

#include <QDebug>
#include <QString>

class BitSequence {
public:
    // конструктор без параметров
    BitSequence() : bitArray(NULL), bitCount(0), arraySize(0) {}

    // деструктор для освобождения памяти
    ~BitSequence() { delete[] bitArray; }

    // метод возвращает длинну битовой последовательности
    int length() const { return bitCount; }

    // перегрузка оператора индексации
    bool operator[](const int& index) const;

    // метод для установки бита с заданным индексом
    void set(const int& index, const bool& value);

    // метод для вставки бита в конец последовательности
    void append(const bool& value);

    // метод для создания строки из битовой последовательности
    QString toString() const;

private:
    // метод для расширения последовательности
    void resize(const int& length);

    bool* bitArray; // битовая последовательность
    int bitCount; // число установленных бит
    int arraySize; // возможное число бит
};

#endif
