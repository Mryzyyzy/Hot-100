/*
给定一个二叉树的根节点 root ，返回它的中序遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
*/

#include "BinaryTreeTestUtils.hpp"
#include<stack>
#include<vector>

using namespace std;

/*
思路：迭代模拟递归中序遍历，先一路向左把当前节点入栈，再弹出访问，最后转向右子树。
关键数据结构：stack 保存祖先节点，用来回到上一个还没访问的根节点。
注意：入栈的是 curr 本身，不是 curr->left；循环条件要同时看 curr 和栈是否为空。
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> p;
        TreeNode *curr = root;
        vector<int> ans;
        while(!p.empty() || curr){
            while(curr){
                p.push(curr);
                curr = curr->left;
            }
            curr = p.top();
            ans.push_back(curr->val);
            p.pop();

            curr = curr->right;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, std::nullopt, 2, 3});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << vectorToString(solution.inorderTraversal(root1)) << "\n";
    std::cout << "case 1 expected = [1, 3, 2]\n\n";

    TreeNode* root2 = buildTree({});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << vectorToString(solution.inorderTraversal(root2)) << "\n";
    std::cout << "case 2 expected = []\n\n";

    TreeNode* root3 = buildTree({1});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << vectorToString(solution.inorderTraversal(root3)) << "\n";
    std::cout << "case 3 expected = [1]\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
