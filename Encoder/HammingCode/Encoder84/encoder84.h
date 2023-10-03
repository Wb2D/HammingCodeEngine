#ifndef _encoder84_h
#define _encoder84_h

/*
 * Данный класс реализует алгоритм перевода последовательнсоти бит в код Хэмминга 8-4. Также
 * был учтен случай, когда размерность последовательности превышет 4. В данной ситуации
 * последовательность будет разбита на несколько подпоследовательностей.
 * Код Хэмминга 8-4 составляется по следующему принципу:
 * e1 e2 d1 e3 d2 d3 d4, где d1, d2, d3, d4 - элементы битовой последовательности
 * e0 = (e1 + e2 + d1 + e3 + d2 + d3 + d4 + d5 + d6 + d7) mod2
 * e1 = (d3 + d5 + d7) mod2
 * e2 = (d3 + d6 + d7) mod2
 * e3 = (d5 + d6 + d7) mod2
 *
 * Примечание: при необходимости добавить недостающие биты, незначащий нуль добавляется в
 * правую часть, т.к последовательность ИНВЕРТИРОВАНА.
 */

#include "DataWorker/BitSequence/bitSequence.h"
#include "DataWorker/BitSequence/EncodedBitSequence/encodedBitSequence.h"

class Encoder84 {
public:
    // метод, в котором битовая последовательность разбивается и каждая часть кодируется
    static EncodedBitSequence start(const BitSequence &data);

private:
    // метод, который кодирует последовательность из 4 бит
    static void encode(const BitSequence &data, BitSequence &result);
};

#endif
