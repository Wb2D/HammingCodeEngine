#include <iostream>
#include <QDebug>

#include "DataWorker/BitSequence/bitSequence.h"
#include "DataWorker/Converter/converter.h"
#include "DataWorker/NumberGenerator/numberGenerator.h"
#include "DataWorker/EncodedBitSequence/encodedBitSequence.h"

#include "Encoder/HammingCode/Encoder74/Encoder74.h"
#include "Encoder/HammingCode/Encoder1511/encoder1511.h"
#include "Encoder/HammingCode/Encoder1611/encoder1611.h"

int main() {
    BitSequence test;
    QString number = NumberGenerator::generate(10, 3);
    qDebug() << number;
    Converter::toBinary(test, number, 10);
    qDebug() << test.toString();

    EncodedBitSequence eTest = Encoder1611::start(test);
    qDebug() << eTest.toString();

    //qDebug() << NumberGenerator::generate(36, 5);


/*
    BitSequence test;
    QString number = "5";
    Converter::toBinary(test, number, 10);
    qDebug() << test.toString();

    EncodedBitSequence eTest = Encoder74::start(test);
    qDebug() << eTest.toString();
*/
    return 0;
}
