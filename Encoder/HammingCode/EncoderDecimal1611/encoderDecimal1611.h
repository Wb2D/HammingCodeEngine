#ifndef _encoderDecimal1611_h
#define _encoderDecimal1611_h

/*
 * Данный класс реализует алгоритм перевода десятичного числа в код Хэмминга 16-11. Также
 * был учтен случай, когда размерность последовательности превышет 11. В данной ситуации
 * последовательность будет разбита на несколько подпоследовательностей.
 * Код Хэмминга 16-11 для десятичных чисел составляется по следующему принципу:
 *
 * Примечание: при необходимости добавить недостающие цифры, незначащие нули добавляются в
 * правую часть, т.к последовательность ИНВЕРТИРОВАНА.
*/

#include "DataWorker/Converter/BigInteger/BigInteger.h"
#include "DataWorker/Converter/BigInteger/EncodedBigInteger/encodedBigInteger.h"

class EncoderDecimal1611 {
public:
    // метод, в котором битовая последовательность разбивается и каждая часть кодируется
    static EncodedBigInteger start(const BigInteger &data);

private:
    // метод, который кодирует последовательность из 4 бит
    static void encode(const BigInteger &data, BigInteger &result);
};

#endif
