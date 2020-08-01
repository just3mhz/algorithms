#pragma once

#include <algorithm>

#include "dfs.h"
#include "../test_runner.h"

namespace NGraph {
    void Test_DFS_AnyPath();
}


void NGraph::Test_DFS_AnyPath() {
    {
        TAdjLists graph = {
            {1, 4}, //0
            {2, 3}, //1
            {4},    //2
            {4},    //3
            {}      //4
        };
        
        std::vector<int> path;
        std::vector<char> used(5, 0);
        std::vector<int> expected = {0, 1, 2, 4};
        
        int s = 0;
        int d = 4;
        bool found = DFS_AnyPath(s, d, graph, used, path);
        std::reverse(path.begin(), path.end());
        
        ASSERT(found);
        ASSERT_EQUAL(path, expected);
    }

    {
        TAdjLists graph = {
            {1}, {2}, {3}, {0}
        };
        std::vector<int> path;
        std::vector<char> used(4, 0);
        int s = 0;
        int d = 4;
        bool found = DFS_AnyPath(s, d, graph, used, path);
        ASSERT(!found);
        ASSERT(path.empty());
    }
}
