/*
给你一个整数数组 nums ，其中元素已经按升序排列。
请你将其转换为一棵高度平衡二叉搜索树。

高度平衡二叉树是一棵满足每个节点的左右两个子树的高度差的绝对值不超过 1 的二叉树。

示例 1：
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]

示例 2：
输入：nums = [1,3]
输出：[3,1] 或 [1,null,3]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：每次取有序数组中点作为根，左半边递归建左子树，右半边递归建右子树。
关键数据结构：vector 存有序数组，左右下标限定当前递归负责的区间。
注意：区间 left > right 时返回空；中点建树可以保证左右高度尽量接近。
*/

TreeNode* fm(vector<int>& nums, int left, int right){
    if(left > right) return nullptr;
    int mid = (left + right) >> 1;
    
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = fm(nums, left, mid - 1);
    node->right = fm(nums, mid + 1, right);

    return node;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        TreeNode *root = fm(nums, 0, nums.size() - 1);
        // TODO: 在这里实现将有序数组转换为二叉搜索树。
        return root;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = solution.sortedArrayToBST(nums1);
    std::cout << "case 1 input    = " << vectorToString(nums1) << "\n";
    std::cout << "case 1 output   = " << treeToString(root1) << "\n";
    std::cout << "case 1 expected = one valid height-balanced BST, such as [0, -3, 9, -10, null, 5]\n\n";

    std::vector<int> nums2 = {1, 3};
    TreeNode* root2 = solution.sortedArrayToBST(nums2);
    std::cout << "case 2 input    = " << vectorToString(nums2) << "\n";
    std::cout << "case 2 output   = " << treeToString(root2) << "\n";
    std::cout << "case 2 expected = one valid height-balanced BST\n\n";

    std::vector<int> nums3 = {};
    TreeNode* root3 = solution.sortedArrayToBST(nums3);
    std::cout << "case 3 input    = " << vectorToString(nums3) << "\n";
    std::cout << "case 3 output   = " << treeToString(root3) << "\n";
    std::cout << "case 3 expected = []\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
