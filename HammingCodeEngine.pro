QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        DataWorker/EncodedBitSequence/encodedBitSequence.cpp \
        DataWorker\BitSequence\bitSequence.cpp \
        DataWorker\Converter\BigInteger\BigInteger.cpp \
        DataWorker\Converter\converter.cpp \
        DataWorker\NumberGenerator\numberGenerator.cpp \
        Encoder/HammingCode/Encoder74/Encoder74.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    DataWorker/EncodedBitSequence/encodedBitSequence.h \
    DataWorker\BitSequence\bitSequence.h \
    DataWorker\Converter\BigInteger\BigInteger.h \
    DataWorker\Converter\converter.h \
    DataWorker\NumberGenerator\numberGenerator.h \
    Encoder/HammingCode/Encoder74/Encoder74.h
