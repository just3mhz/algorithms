#include "strings/tests.h"
#include "graphs/tests.h"


void TestAll();

int main() {
    TestAll();
    return 0;
}

void TestAll() {
    TestRunner tr;
    RUN_TEST(tr, NString::Test_KMP);
    
    RUN_TEST(tr, NGraph::Test_DFS_AnyPath);
}
