#include "DataWorker/Converter/BigInteger/EncodedBigInteger/encodedBigInteger.h"

const QString EncodedBigInteger::toString() const {
    return QString("Encoded sequency: " + digit.toString() + ", Method: " +
                   method + ", Time: " + QString::number(time) + ", Splitting:"
                   + QString::number(iteration));
}
