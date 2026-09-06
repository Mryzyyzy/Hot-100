/*
给你一个无重复元素的整数数组 candidates 和一个目标整数 target，
找出 candidates 中可以使数字和为 target 的所有不同组合。
同一个数字可以被无限制重复选取。
*/

#include "BacktrackingTestUtils.hpp"
#include <vector>

using namespace std;

/*
思路：从 start 开始枚举候选数，当前和超过 target 就停止，等于 target 就收集。
关键数据结构：path 保存当前组合，start 控制组合顺序并允许当前数重复使用。
注意：同一个数可重复选，所以递归下一层还是从当前下标开始。
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> candidates1 = {2, 3, 6, 7};
    cout << "case 1 input    = candidates = " << vectorToString(candidates1) << ", target = 7\n";
    cout << "case 1 output   = " << matrixToString(solution.combinationSum(candidates1, 7)) << "\n";
    cout << "case 1 expected = [[2, 2, 3], [7]]\n\n";

    vector<int> candidates2 = {2, 3, 5};
    cout << "case 2 input    = candidates = " << vectorToString(candidates2) << ", target = 8\n";
    cout << "case 2 output   = " << matrixToString(solution.combinationSum(candidates2, 8)) << "\n";
    cout << "case 2 expected = [[2, 2, 2, 2], [2, 3, 3], [3, 5]]\n\n";

    vector<int> candidates3 = {2};
    cout << "case 3 input    = candidates = " << vectorToString(candidates3) << ", target = 1\n";
    cout << "case 3 output   = " << matrixToString(solution.combinationSum(candidates3, 1)) << "\n";
    cout << "case 3 expected = []\n";

    return 0;
}
