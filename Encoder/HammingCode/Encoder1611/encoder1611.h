#ifndef _encoder1611_h
#define _encoder1611_h

/*
 * Данный класс реализует алгоритм перевода последовательнсоти бит в код Хэмминга 16-11. Также
 * был учтен случай, когда размерность последовательности превышет 11. В данной ситуации
 * последовательность будет разбита на несколько подпоследовательностей.
 * Код Хэмминга 16-11 составляется по следующему принципу:
 * e0 e1 e2 d1 e3 d2 d3 d4 e4 d5 d6 d7 d8 d9 d10 d11  - элементы битовой последовательности
 * e0 = (e1 + e2 + d1 + e3 + d2 + d3 + d4 + e4 + d5 + d6 + d7 + d8 + d9 + d10 + d11) mod2
 * e1 = (d1 + d2 + d4 + d5 + d7 + d9 + d11) mod2
 * e2 = (d1 + d3 + d4 + d6 + d7 + d10 + d11) mod2
 * e3 = (d2 + d3 + d4 + d8 + d9 + d10 + d11) mod2
 * e4 = (d5 + d6 + d7 + d8 + d9 + d10 + d11) mod2
 *
 * Примечание: при необходимости добавить недостающие биты, незначащий нуль добавляется в
 * правую часть, т.к последовательность ИНВЕРТИРОВАНА.
*/

#include "DataWorker/BitSequence/bitSequence.h"
#include "DataWorker/BitSequence/EncodedBitSequence/encodedBitSequence.h"

class Encoder1611 {
public:
    // метод, в котором битовая последовательность разбивается и каждая часть кодируется
    static EncodedBitSequence start(const BitSequence &data);

private:
    // метод, который кодирует последовательность из 4 бит
    static void encode(const BitSequence &data, BitSequence &result);
};

#endif
