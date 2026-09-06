/*
给定一个不含重复数字的数组 nums ，返回其所有可能的全排列。
*/

#include "BacktrackingTestUtils.hpp"
#include <vector>

using namespace std;

/*
思路：每一层选择一个还没用过的数字加入 path，长度等于 nums.size() 时收集答案。
关键数据结构：path 保存当前排列，used 数组标记数字是否已经被选过。
注意：递归返回前要撤销选择，恢复现场。
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    cout << "case 1 input    = " << vectorToString(nums1) << "\n";
    cout << "case 1 output   = " << matrixToString(solution.permute(nums1)) << "\n";
    cout << "case 1 expected = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]\n\n";

    vector<int> nums2 = {0, 1};
    cout << "case 2 input    = " << vectorToString(nums2) << "\n";
    cout << "case 2 output   = " << matrixToString(solution.permute(nums2)) << "\n";
    cout << "case 2 expected = [[0, 1], [1, 0]]\n\n";

    vector<int> nums3 = {1};
    cout << "case 3 input    = " << vectorToString(nums3) << "\n";
    cout << "case 3 output   = " << matrixToString(solution.permute(nums3)) << "\n";
    cout << "case 3 expected = [[1]]\n";

    return 0;
}
