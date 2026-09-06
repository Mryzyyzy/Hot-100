/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：前序递归，当前节点先交换左右孩子，再递归翻转左右子树。
关键数据结构：递归调用栈负责遍历整棵树，swap 直接交换当前节点的左右指针。
注意：空节点直接返回；交换后 root->left 已经是原来的右子树。
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        swap(root->right, root->left);

        invertTree(root->left);
        invertTree(root->right);

        return root;  
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({4, 2, 7, 1, 3, 6, 9});
    TreeNode* ans1 = solution.invertTree(root1);
    std::cout << "case 1 output   = " << treeToString(ans1) << "\n";
    std::cout << "case 1 expected = [4, 7, 2, 9, 6, 3, 1]\n\n";

    TreeNode* root2 = buildTree({2, 1, 3});
    TreeNode* ans2 = solution.invertTree(root2);
    std::cout << "case 2 output   = " << treeToString(ans2) << "\n";
    std::cout << "case 2 expected = [2, 3, 1]\n\n";

    TreeNode* root3 = buildTree({});
    TreeNode* ans3 = solution.invertTree(root3);
    std::cout << "case 3 output   = " << treeToString(ans3) << "\n";
    std::cout << "case 3 expected = []\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
