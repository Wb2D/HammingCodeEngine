#include <iostream>
#include <QDebug>

#include "DataWorker/BitSequence/bitSequence.h"
#include "DataWorker/Converter/converter.h"
#include "DataWorker/NumberGenerator/numberGenerator.h"

int main() {
    BitSequence test;
    QString number = NumberGenerator::generate(4, 10);
    qDebug() << number;
    Converter::toBinary(test, number, 4);
    qDebug() << test.toString();

    //qDebug() << NumberGenerator::generate(36, 5);

    return 0;
}
