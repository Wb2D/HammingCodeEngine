#ifndef _numberGenerator_h
#define _numberGenerator_h

/*
 *
 *
 *
 */

#include <QString>
#include <QDebug>
#include <QRandomGenerator>

class NumberGenerator {
public:
    static QString generate(const int &base, const int &digits);

private:
    static const QString arr;
};

#endif
