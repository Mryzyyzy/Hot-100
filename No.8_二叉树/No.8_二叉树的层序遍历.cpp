/*
给你二叉树的根节点 root ，返回其节点值的层序遍历。
也就是逐层地，从左到右访问所有节点。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：BFS 按层遍历，每轮先记录当前队列长度，只处理这一层的节点。
关键数据结构：queue 保存待访问节点，vector<int> temp 收集当前层结果。
注意：空树不要入队；一层处理完再把 temp 放进答案。
*/

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int q_size = q.size();
            vector<int> temp;
            for(int i = 0; i < q_size; i++){
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
    std::cout << "case 1 input    = " << treeToString(root1) << "\n";
    std::cout << "case 1 output   = " << matrixToString(solution.levelOrder(root1)) << "\n";
    std::cout << "case 1 expected = [[3], [9, 20], [15, 7]]\n\n";

    TreeNode* root2 = buildTree({1});
    std::cout << "case 2 input    = " << treeToString(root2) << "\n";
    std::cout << "case 2 output   = " << matrixToString(solution.levelOrder(root2)) << "\n";
    std::cout << "case 2 expected = [[1]]\n\n";

    TreeNode* root3 = buildTree({});
    std::cout << "case 3 input    = " << treeToString(root3) << "\n";
    std::cout << "case 3 output   = " << matrixToString(solution.levelOrder(root3)) << "\n";
    std::cout << "case 3 expected = []\n";

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}
