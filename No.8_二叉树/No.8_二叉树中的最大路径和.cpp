/*
二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中至多出现一次。
该路径至少包含一个节点，且不一定经过根节点。

路径和是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其最大路径和。

示例 1：
输入：root = [1,2,3]
输出：6

示例 2：
输入：root = [-10,9,20,null,null,15,7]
输出：42
*/

#include "BinaryTreeTestUtils.hpp"

/*
思路：后序递归，返回当前节点能向父节点贡献的最大单边路径，同时更新全局最大路径和。
关键数据结构：递归调用栈自底向上传回单边贡献值，全局变量记录遍历过程中最大的完整路径。
注意：返回给父节点只能选左右一边；全局答案可以同时取 left + root + right，负贡献要舍弃。
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        (void)root;
        // TODO: 在这里实现二叉树中的最大路径和。
        return 0;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, 2, 3});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << solution.maxPathSum(root1) << "\n";
    std::cout << "case 1 expected = 6\n\n";

    TreeNode* root2 = buildTree({-10, 9, 20, std::nullopt, std::nullopt, 15, 7});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << solution.maxPathSum(root2) << "\n";
    std::cout << "case 2 expected = 42\n\n";

    TreeNode* root3 = buildTree({-3});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << solution.maxPathSum(root3) << "\n";
    std::cout << "case 3 expected = -3\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
