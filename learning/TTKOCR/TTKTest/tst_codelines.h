#ifndef CODELINESTEST_H
#define CODELINESTEST_H

#include "ocrautotest.h"

class CodeLinesTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase();
    void codeLines();
    void cleanupTestCase();

};

DECLARE_TEST(CodeLinesTest)

#endif // CODELINESTEST_H
