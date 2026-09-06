/*
数字 n 代表生成括号的对数，请你设计一个函数，
用于生成所有可能并且有效的括号组合。
*/

#include "BacktrackingTestUtils.hpp"
#include <string>
#include <vector>

using namespace std;

/*
思路：递归决定下一个位置放左括号还是右括号，保证过程始终合法。
关键数据结构：path 保存当前括号串，left/right 记录已经使用的左右括号数量。
注意：右括号数量不能超过左括号，左括号数量不能超过 n。
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return {};
    }
};

int main() {
    Solution solution;

    cout << "case 1 input    = 3\n";
    cout << "case 1 output   = " << stringVectorToString(solution.generateParenthesis(3)) << "\n";
    cout << "case 1 expected = [\"((()))\", \"(()())\", \"(())()\", \"()(())\", \"()()()\"]\n\n";

    cout << "case 2 input    = 1\n";
    cout << "case 2 output   = " << stringVectorToString(solution.generateParenthesis(1)) << "\n";
    cout << "case 2 expected = [\"()\"]\n\n";

    cout << "case 3 input    = 2\n";
    cout << "case 3 output   = " << stringVectorToString(solution.generateParenthesis(2)) << "\n";
    cout << "case 3 expected = [\"(())\", \"()()\"]\n";

    return 0;
}
