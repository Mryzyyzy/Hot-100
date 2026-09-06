/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
*/

#include "BacktrackingTestUtils.hpp"
#include <string>
#include <vector>

using namespace std;

/*
思路：按数字位置递归，每一层从当前数字对应的几个字母里选一个。
关键数据结构：映射表保存数字到字母，path 保存当前组合。
注意：输入为空时返回空数组，不是包含空字符串的数组。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return {};
    }
};

int main() {
    Solution solution;

    string digits1 = "23";
    cout << "case 1 input    = " << digits1 << "\n";
    cout << "case 1 output   = " << stringVectorToString(solution.letterCombinations(digits1)) << "\n";
    cout << "case 1 expected = [\"ad\", \"ae\", \"af\", \"bd\", \"be\", \"bf\", \"cd\", \"ce\", \"cf\"]\n\n";

    string digits2 = "";
    cout << "case 2 input    = \"\"\n";
    cout << "case 2 output   = " << stringVectorToString(solution.letterCombinations(digits2)) << "\n";
    cout << "case 2 expected = []\n\n";

    string digits3 = "2";
    cout << "case 3 input    = " << digits3 << "\n";
    cout << "case 3 output   = " << stringVectorToString(solution.letterCombinations(digits3)) << "\n";
    cout << "case 3 expected = [\"a\", \"b\", \"c\"]\n";

    return 0;
}
