/*
给你一棵二叉树的根节点，返回该树的直径。

二叉树的直径是指树中任意两个节点之间最长路径的长度。
这条路径可能经过也可能不经过根节点。
两节点之间路径的长度由它们之间边数表示。

示例 1：
输入：root = [1,2,3,4,5]
输出：3

示例 2：
输入：root = [1,2]
输出：1
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：后序递归求每个节点的左右深度，left + right 就是经过当前节点的最长路径边数。
关键数据结构：递归调用栈返回子树深度，maxheight 用来保存所有节点里最大的直径。
注意：递归返回深度给父节点，全局 maxheight 记录答案；直径按边数算，所以不用再 +1。
     记得对maxheight进行 “解指” 操作之后再进行运算。
*/

int df(TreeNode* root, int *maxheight){
    if(!root) return 0;

    int left = df(root->left, maxheight);
    int right = df(root->right, maxheight);

    *maxheight = max(left + right, *maxheight);

    return max(left, right) + 1;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxheight = 0;
        df(root, &maxheight);
        return maxheight;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, 2, 3, 4, 5});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << solution.diameterOfBinaryTree(root1) << "\n";
    std::cout << "case 1 expected = 3\n\n";

    TreeNode* root2 = buildTree({1, 2});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << solution.diameterOfBinaryTree(root2) << "\n";
    std::cout << "case 2 expected = 1\n\n";

    TreeNode* root3 = buildTree({1});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << solution.diameterOfBinaryTree(root3) << "\n";
    std::cout << "case 3 expected = 0\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
