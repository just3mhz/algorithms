#include "strings/tests.h"


void TestAll();

int main() {
    TestAll();
    return 0;
}

void TestAll() {
    TestRunner tr;
    RUN_TEST(tr, TestKMP);
}
