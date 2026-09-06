/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1：
输入：preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出：[3,9,20,null,null,15,7]

示例 2：
输入：preorder = [-1], inorder = [-1]
输出：[-1]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：前序第一个值是根；在中序中找到根的位置，用左子树节点个数切分左右数组并递归建树。
关键数据结构：vector 切分出左右子树的前序和中序序列，用来递归构造子树。
注意：vector 区间是左闭右开；index 表示左子树节点数量。
*/

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        int index = 0;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[0] == inorder[i]){
                index = i;
                break;
            }
        }

        vector<int> leftpre(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> leftino(inorder.begin(), inorder.begin() + index);
        root->left = buildTree(leftpre, leftino);
        vector<int> rightpre(preorder.begin() + index + 1, preorder.end());
        vector<int> rightino(inorder.begin() + index + 1, inorder.end());
        root->right = buildTree(rightpre, rightino);

        return root;
    }
};

int main() {
    Solution solution;

    std::vector<int> preorder1 = {3, 9, 20, 15, 7};
    std::vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    std::cout << "case 1 preorder = " << vectorToString(preorder1) << "\n";
    std::cout << "case 1 inorder  = " << vectorToString(inorder1) << "\n";
    std::cout << "case 1 output   = " << treeToString(root1) << "\n";
    std::cout << "case 1 expected = [3, 9, 20, null, null, 15, 7]\n\n";

    std::vector<int> preorder2 = {-1};
    std::vector<int> inorder2 = {-1};
    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    std::cout << "case 2 preorder = " << vectorToString(preorder2) << "\n";
    std::cout << "case 2 inorder  = " << vectorToString(inorder2) << "\n";
    std::cout << "case 2 output   = " << treeToString(root2) << "\n";
    std::cout << "case 2 expected = [-1]\n";

    freeTree(root1);
    freeTree(root2);
    return 0;
}
