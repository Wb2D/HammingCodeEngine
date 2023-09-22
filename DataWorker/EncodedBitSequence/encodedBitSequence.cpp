#include "DataWorker/EncodedBitSequence/encodedBitSequence.h"

const QString EncodedBitSequence::toString() const {
    return QString("Encoded sequency: " + data.toString() + ", Method: " +
                   method + ", Time: " + QString::number(time) + ", Splitting:"
                   + QString::number(iteration));
}
