/*
给定一个 m x n 二维字符网格 board 和一个字符串 word，
如果 word 存在于网格中，返回 true。
单词必须按照字母顺序，通过相邻单元格内的字母构成。
*/

#include "BacktrackingTestUtils.hpp"
#include <string>
#include <vector>

using namespace std;

/*
思路：遍历每个格子作为起点，向上下左右 DFS 匹配 word 的下一个字符。
关键数据结构：board 原地或 visited 数组标记路径中已经使用的格子。
注意：同一个单元格在一条路径里不能重复使用，回溯时要恢复标记。
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << "case 1 input    = board = " << charMatrixToString(board1) << ", word = ABCCED\n";
    cout << "case 1 output   = " << boolToString(solution.exist(board1, "ABCCED")) << "\n";
    cout << "case 1 expected = true\n\n";

    vector<vector<char>> board2 = board1;
    cout << "case 2 input    = board = " << charMatrixToString(board2) << ", word = SEE\n";
    cout << "case 2 output   = " << boolToString(solution.exist(board2, "SEE")) << "\n";
    cout << "case 2 expected = true\n\n";

    vector<vector<char>> board3 = board1;
    cout << "case 3 input    = board = " << charMatrixToString(board3) << ", word = ABCB\n";
    cout << "case 3 output   = " << boolToString(solution.exist(board3, "ABCB")) << "\n";
    cout << "case 3 expected = false\n";

    return 0;
}
