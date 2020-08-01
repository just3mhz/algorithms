#pragma once

#include "kmp_search.h"
#include "../test_runner.h"

namespace NString {
    void Test_KMP();
}

void NString::Test_KMP() {
    {
        std::string s = "abcabcd";
        std::vector<int> expected = {0,0,0,1,2,3,0};
        ASSERT_EQUAL(PrefixFunc(s), expected);
    }

    {
        std::string s = "aaaaaa";
        std::vector<int> expected = {0, 1, 2, 3, 4, 5};
        ASSERT_EQUAL(PrefixFunc(s), expected);
    }

    {
        std::string s = "abcdef";
        std::vector<int> expected = {0, 0, 0, 0, 0, 0};
        ASSERT_EQUAL(PrefixFunc(s), expected);
    }
}
