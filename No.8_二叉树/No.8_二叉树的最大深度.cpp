/*
给定一个二叉树 root ，返回其最大深度。

二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3

示例 2：
输入：root = [1,null,2]
输出：2
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：后序递归，先分别求左右子树深度，当前节点深度就是 max(left, right) + 1。
关键数据结构：递归调用栈保存每层节点状态，用返回值把子树深度传回父节点。
注意：空节点深度为 0，这是递归出口；返回的是节点数，不是边数。
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << solution.maxDepth(root1) << "\n";
    std::cout << "case 1 expected = 3\n\n";

    TreeNode* root2 = buildTree({1, std::nullopt, 2});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << solution.maxDepth(root2) << "\n";
    std::cout << "case 2 expected = 2\n\n";

    TreeNode* root3 = buildTree({});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << solution.maxDepth(root3) << "\n";
    std::cout << "case 3 expected = 0\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
