/*
给定一个二叉树的根节点 root ，想象自己站在它的右侧，
按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1：
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]

示例 2：
输入：root = [1,null,3]
输出：[1,3]

示例 3：
输入：root = []
输出：[]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：层序遍历，每层从左到右扫描，最后访问到的节点就是这一层的右视图。
关键数据结构：queue 保存当前层和下一层节点，用 q_size 固定每一层的边界。
注意：每层开始先固定 q_size；空树直接返回空数组，避免使用未初始化的 maxright。
*/

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        int maxright;
        TreeNode *curr;
        if(root) q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                curr = q.front();
                q.pop();
                maxright = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);        
            }
            ans.push_back(maxright);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, 2, 3, std::nullopt, 5, std::nullopt, 4});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << vectorToString(solution.rightSideView(root1)) << "\n";
    std::cout << "case 1 expected = [1, 3, 4]\n\n";

    TreeNode* root2 = buildTree({1, std::nullopt, 3});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << vectorToString(solution.rightSideView(root2)) << "\n";
    std::cout << "case 2 expected = [1, 3]\n\n";

    TreeNode* root3 = buildTree({});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << vectorToString(solution.rightSideView(root3)) << "\n";
    std::cout << "case 3 expected = []\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
