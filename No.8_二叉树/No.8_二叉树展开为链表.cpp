/*
给你二叉树的根节点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个节点，
而 left 子指针始终为 null。
展开后的单链表应该与二叉树先序遍历顺序相同。

示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [0]
输出：[0]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：后序递归，先把左右子树各自展开，再把左链表接到 root->right，原右链表接到末尾。
关键数据结构：递归调用栈保存子树处理顺序，临时指针 temp 保存原右子树。
注意：拼接前要先保存原来的右子树；展开后所有 left 都要置空。
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode *curr = root;
        while(curr->right) curr = curr->right;
        curr->right = temp;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, 2, 5, 3, 4, std::nullopt, 6});
    solution.flatten(root1);
    std::cout << "case 1 right chain = " << vectorToString(rightChainValues(root1)) << "\n";
    std::cout << "case 1 expected    = [1, 2, 3, 4, 5, 6]\n\n";

    TreeNode* root2 = buildTree({});
    solution.flatten(root2);
    std::cout << "case 2 right chain = " << vectorToString(rightChainValues(root2)) << "\n";
    std::cout << "case 2 expected    = []\n\n";

    TreeNode* root3 = buildTree({0});
    solution.flatten(root3);
    std::cout << "case 3 right chain = " << vectorToString(rightChainValues(root3)) << "\n";
    std::cout << "case 3 expected    = [0]\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
