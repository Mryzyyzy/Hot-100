/*
给你一个二叉树的根节点 root ，检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：队列里成对保存需要镜像比较的节点，每次比较 left 和 right 是否同时为空、值是否相等。
关键数据结构：queue<pair<TreeNode*, TreeNode*>> 按层保存镜像节点对，用来同步比较左右两边。
注意：弹出队头后再判断；下一层要交叉入队：left->left 对 right->right，left->right 对 right->left。
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while(!q.empty()){
            auto [left, right] = q.front();
            q.pop();
            if(!left && !right) continue;
            if(!(left && right)) return false;
            if(left->val != right->val) return false;
            q.push({left->left, right->right});
            q.push({left->right, right->left});

        }
        return true;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({1, 2, 2, 3, 4, 4, 3});
    std::cout << std::boolalpha;
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << solution.isSymmetric(root1) << "\n";
    std::cout << "case 1 expected = true\n\n";

    TreeNode* root2 = buildTree({1, 2, 2, std::nullopt, 3, std::nullopt, 3});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << solution.isSymmetric(root2) << "\n";
    std::cout << "case 2 expected = false\n\n";

    TreeNode* root3 = buildTree({});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << solution.isSymmetric(root3) << "\n";
    std::cout << "case 3 expected = true\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
