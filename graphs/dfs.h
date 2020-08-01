#pragma once

#include <iostream>
#include <vector>


using TAdjLists = std::vector<std::vector<int>>;

const char USED = 1;
const char UNUSED = 0;

bool DFS_AnyPath(int curr, int end, const TAdjLists &graph, std::vector<char> &used, std::vector<int> &path) {
    used[curr] = USED;
    // Vertex "end" is found, start recording path
    if ( curr == end ) {
        path.push_back(curr);
        return true;
    }
    for (int v: graph[curr]) {
        // Current vertex lies on path
        if ( used[v] == UNUSED && DFS_AnyPath(v, end, graph, used, path)) {
            path.push_back(curr);
            return true;
        }
    }
    return false;
}
