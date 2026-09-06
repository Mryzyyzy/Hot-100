/*
给你一个由 '1'（陆地）和 '0'（水）组成的二维网格 grid ，
请你计算网格中岛屿的数量。
*/

#include "GraphTestUtils.hpp"
#include <vector>

using namespace std;

/*
思路：遍历每个格子，遇到未处理的陆地就从这里扩散，把整座岛标记掉。
关键数据结构：二维 grid 记录地图，DFS/BFS 调用栈或队列用来扩散相邻陆地。
注意：只能上下左右连通，不能斜着连。
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return 0;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "case 1 input    = " << charMatrixToString(grid1) << "\n";
    cout << "case 1 output   = " << solution.numIslands(grid1) << "\n";
    cout << "case 1 expected = 1\n\n";

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "case 2 input    = " << charMatrixToString(grid2) << "\n";
    cout << "case 2 output   = " << solution.numIslands(grid2) << "\n";
    cout << "case 2 expected = 3\n\n";

    vector<vector<char>> grid3 = {{'0'}};
    cout << "case 3 input    = " << charMatrixToString(grid3) << "\n";
    cout << "case 3 output   = " << solution.numIslands(grid3) << "\n";
    cout << "case 3 expected = 0\n";

    return 0;
}
