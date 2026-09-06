/*
给你一个整数数组 nums，数组中的元素互不相同。
返回该数组所有可能的子集。
*/

#include "BacktrackingTestUtils.hpp"
#include <vector>

using namespace std;

/*
思路：从当前位置开始枚举选哪个数，每到一个节点都把当前 path 加入答案。
关键数据结构：path 保存当前子集，start 控制下一次从哪里继续选。
注意：子集不要求长度固定，所以每层进入时都可以收集一次答案。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    cout << "case 1 input    = " << vectorToString(nums1) << "\n";
    cout << "case 1 output   = " << matrixToString(solution.subsets(nums1)) << "\n";
    cout << "case 1 expected = [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]\n\n";

    vector<int> nums2 = {0};
    cout << "case 2 input    = " << vectorToString(nums2) << "\n";
    cout << "case 2 output   = " << matrixToString(solution.subsets(nums2)) << "\n";
    cout << "case 2 expected = [[], [0]]\n";

    return 0;
}
