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


std::vector<int> KMP_Search(const std::string &s, const std::string &t) {
    std::vector<int> occurrences;
    std::string st = s + '#' + t;
    std::vector<int> pf = PrefixFunc(st);
    for (size_t i = s.size() + 1; i < st.size(); ++i) {
        if ( pf[i] == s.size() ) {
            occurrences.push_back(i - 2 * s.size());
        }
    }
    return occurrences;
}
