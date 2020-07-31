#pragma once

#include <iostream>
#include <vector>

std::vector<int> PrefixFunc(const std::string &s) {
    std::vector<int> prefix_func(s.size(), 0);
    for (size_t i = 1; i < s.size(); ++i) {
        size_t k = prefix_func[i - 1];
        while ( k > 0 && s[k] != s[i] ) {
            k = prefix_func[k - 1];
        }
        if ( s[k] == s[i] ) {
            ++k;
        }
        prefix_func[i] = k;
    }
    return prefix_func;
}
