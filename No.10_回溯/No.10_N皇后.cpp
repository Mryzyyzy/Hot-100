/*
按照国际象棋规则，皇后可以攻击与之处在同一行、同一列或同一斜线上的棋子。
给你一个整数 n，返回所有不同的 n 皇后问题的解决方案。
*/

#include "BacktrackingTestUtils.hpp"
#include <string>
#include <vector>

using namespace std;

/*
思路：按行放皇后，每一行枚举可放的列，合法就进入下一行。
关键数据结构：棋盘 board 保存当前方案，列和两条斜线标记数组快速判断冲突。
注意：主对角线和副对角线下标要错开，避免出现负数。
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return {};
    }
};

int main() {
    Solution solution;

    cout << "case 1 input    = 4\n";
    cout << "case 1 output   = " << stringMatrixToString(solution.solveNQueens(4)) << "\n";
    cout << "case 1 expected = [[\".Q..\", \"...Q\", \"Q...\", \"..Q.\"], [\"..Q.\", \"Q...\", \"...Q\", \".Q..\"]]\n\n";

    cout << "case 2 input    = 1\n";
    cout << "case 2 output   = " << stringMatrixToString(solution.solveNQueens(1)) << "\n";
    cout << "case 2 expected = [[\"Q\"]]\n\n";

    cout << "case 3 input    = 2\n";
    cout << "case 3 output   = " << stringMatrixToString(solution.solveNQueens(2)) << "\n";
    cout << "case 3 expected = []\n";

    return 0;
}
