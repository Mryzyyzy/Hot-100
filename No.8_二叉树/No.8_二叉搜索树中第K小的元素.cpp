/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，
请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

示例 1：
输入：root = [3,1,4,null,2], k = 1
输出：1

示例 2：
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：二叉搜索树中序遍历天然升序，迭代中序遍历时计数，第 k 次访问的节点就是答案。
关键数据结构：stack 模拟递归调用栈，用来保存一路向左经过但还没访问的节点。
注意：k 从 1 开始；每弹出一个节点才算真正访问一次。
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *curr = root;
        stack<TreeNode*> q;
        int cnt = 0;
        while(!q.empty() || curr){
            while(curr){
                q.push(curr);
                curr = curr->left;
            }
            curr = q.top();
            q.pop();
            cnt++;
            if(cnt == k){
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({3, 1, 4, std::nullopt, 2});
    int k1 = 1;
    std::cout << "case 1 input    = " << treeToString(root1) << ", k = " << k1 << "\n";
    std::cout << "case 1 output   = " << solution.kthSmallest(root1, k1) << "\n";
    std::cout << "case 1 expected = 1\n\n";

    TreeNode* root2 = buildTree({5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1});
    int k2 = 3;
    std::cout << "case 2 input    = " << treeToString(root2) << ", k = " << k2 << "\n";
    std::cout << "case 2 output   = " << solution.kthSmallest(root2, k2) << "\n";
    std::cout << "case 2 expected = 3\n\n";

    TreeNode* root3 = buildTree({2, 1});
    int k3 = 2;
    std::cout << "case 3 input    = " << treeToString(root3) << ", k = " << k3 << "\n";
    std::cout << "case 3 output   = " << solution.kthSmallest(root3, k3) << "\n";
    std::cout << "case 3 expected = 2\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
