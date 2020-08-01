#pragma once

#include <iostream>
#include <vector>


using TAdjLists = std::vector<std::vector<int>>;

enum class TStatus {
    UNUSED,
    USED
};

bool DFS_AnyPath(int curr, int end, const TAdjLists &graph, std::vector<TStatus> &used, std::vector<int> &path) {
    used[curr] = TStatus::USED;
    // Vertex "end" is found, start recording path
    if ( curr == end ) {
        path.push_back(curr);
        return true;
    }
    for (int v: graph[curr]) {
        // Current vertex lies on path
        if ( used[v] == TStatus::UNUSED && DFS_AnyPath(v, end, graph, used, path)) {
            path.push_back(curr);
            return true;
        }
    }
    return false;
}
