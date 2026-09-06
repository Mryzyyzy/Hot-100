/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效二叉搜索树定义如下：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身也必须是二叉搜索树。

示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：递归给每个节点维护合法取值范围，左子树上界变成 root->val，右子树下界变成 root->val。
关键数据结构：递归调用栈向下传递 low/high 边界，用来约束整棵子树的取值范围。
注意：BST 要满足整棵子树范围，不只是和父节点比较；用 long long 防止边界值溢出。
*/

bool fm(TreeNode* root, long long low, long long height){
    if(!root) return true;

    if(root->val <= low || root->val >= height) return false;
    
    return fm(root->left, low, root->val) && fm(root->right, root->val, height);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return fm(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha;

    TreeNode* root1 = buildTree({2, 1, 3});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << solution.isValidBST(root1) << "\n";
    std::cout << "case 1 expected = true\n\n";

    TreeNode* root2 = buildTree({5, 1, 4, std::nullopt, std::nullopt, 3, 6});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << solution.isValidBST(root2) << "\n";
    std::cout << "case 2 expected = false\n\n";

    TreeNode* root3 = buildTree({5, 4, 6, std::nullopt, std::nullopt, 3, 7});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << solution.isValidBST(root3) << "\n";
    std::cout << "case 3 expected = false\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
