/*
给你一个字符串 s，请你将 s 分割成一些子串，
使每个子串都是回文串。返回 s 所有可能的分割方案。
*/

#include "BacktrackingTestUtils.hpp"
#include <string>
#include <vector>

using namespace std;

/*
思路：从当前位置枚举切割终点，只有当前子串是回文时才继续递归。
关键数据结构：path 保存当前切割方案，start 表示下一段从哪里开始。
注意：到达字符串末尾时才收集答案；判断回文可以单独写函数。
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        return {};
    }
};

int main() {
    Solution solution;

    string s1 = "aab";
    cout << "case 1 input    = " << s1 << "\n";
    cout << "case 1 output   = " << stringMatrixToString(solution.partition(s1)) << "\n";
    cout << "case 1 expected = [[\"a\", \"a\", \"b\"], [\"aa\", \"b\"]]\n\n";

    string s2 = "a";
    cout << "case 2 input    = " << s2 << "\n";
    cout << "case 2 output   = " << stringMatrixToString(solution.partition(s2)) << "\n";
    cout << "case 2 expected = [[\"a\"]]\n\n";

    string s3 = "aba";
    cout << "case 3 input    = " << s3 << "\n";
    cout << "case 3 output   = " << stringMatrixToString(solution.partition(s3)) << "\n";
    cout << "case 3 expected = [[\"a\", \"b\", \"a\"], [\"aba\"]]\n";

    return 0;
}
