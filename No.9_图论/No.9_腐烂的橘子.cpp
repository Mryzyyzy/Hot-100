/*
在给定的 m x n 网格中，每个单元格可以有以下三个值之一：
0 表示空单元格，1 表示新鲜橘子，2 表示腐烂橘子。
每分钟，腐烂橘子上下左右相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子所必须经过的最小分钟数。
*/

#include "GraphTestUtils.hpp"
#include <queue>
#include <vector>

using namespace std;

/*
思路：先把所有腐烂橘子入队，然后按层 BFS，一分钟扩散一层。
关键数据结构：queue 保存当前会继续腐烂别人的橘子，grid 记录新鲜/腐烂状态。
注意：最后如果还有新鲜橘子，返回 -1。
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return 0;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "case 1 input    = " << matrixToString(grid1) << "\n";
    cout << "case 1 output   = " << solution.orangesRotting(grid1) << "\n";
    cout << "case 1 expected = 4\n\n";

    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << "case 2 input    = " << matrixToString(grid2) << "\n";
    cout << "case 2 output   = " << solution.orangesRotting(grid2) << "\n";
    cout << "case 2 expected = -1\n\n";

    vector<vector<int>> grid3 = {{0, 2}};
    cout << "case 3 input    = " << matrixToString(grid3) << "\n";
    cout << "case 3 output   = " << solution.orangesRotting(grid3) << "\n";
    cout << "case 3 expected = 0\n";

    return 0;
}
