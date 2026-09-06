/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，
求该二叉树里节点值之和等于 targetSum 的路径的数目。

路径不需要从根节点开始，也不需要在叶子节点结束，
但是路径方向必须是向下的，只能从父节点到子节点。

示例 1：
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3

示例 2：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：枚举每个节点作为路径起点，再向下递归累加路径和，遇到 targetSum 就计数。
关键数据结构：queue 枚举所有起点，递归调用栈沿着每个起点向下累加路径和。
注意：路径只能向下走；sum 用 long long，避免节点值累加溢出。
*/

int df(TreeNode *node, long long sum, int targetSum){
    if(!node) return 0;
    sum += node->val;
    int count = 0;
    if(sum == targetSum){
        count++;
    }
    count += df(node->left, sum, targetSum);
    count += df(node->right, sum , targetSum);
    return count;
}

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            ans += df(node, 0, targetSum);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({10, 5, -3, 3, 2, std::nullopt, 11, 3, -2, std::nullopt, 1});
    int target1 = 8;
    std::cout << "case 1 input    = " << treeToString(root1) << ", target = " << target1 << "\n";
    std::cout << "case 1 output   = " << solution.pathSum(root1, target1) << "\n";
    std::cout << "case 1 expected = 3\n\n";

    TreeNode* root2 = buildTree({5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt, 5, 1});
    int target2 = 22;
    std::cout << "case 2 input    = " << treeToString(root2) << ", target = " << target2 << "\n";
    std::cout << "case 2 output   = " << solution.pathSum(root2, target2) << "\n";
    std::cout << "case 2 expected = 3\n\n";

    TreeNode* root3 = buildTree({1, -2, -3, 1, 3, -2, std::nullopt, -1});
    int target3 = -1;
    std::cout << "case 3 input    = " << treeToString(root3) << ", target = " << target3 << "\n";
    std::cout << "case 3 output   = " << solution.pathSum(root3, target3) << "\n";
    std::cout << "case 3 expected = 4\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
