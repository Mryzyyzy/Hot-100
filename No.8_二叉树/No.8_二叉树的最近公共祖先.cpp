/*
给定一个二叉树，找到该树中两个指定节点的最近公共祖先。

最近公共祖先定义为：对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大。
一个节点也可以是它自己的祖先。

示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
*/

#include "BinaryTreeTestUtils.hpp"

using namespace std;

/*
思路：DFS 回溯分别记录 root 到 p、q 的路径，再比较两条路径，最后一个相同节点就是最近公共祖先。
关键数据结构：vector 保存根到目标节点的路径，用来按下标逐个比较公共前缀。
注意：path/path_p/path_q 要引用传递；答案指针最好初始化为 nullptr。
     处理完一个左右节点之后，说明这个子节点已经结束了，要记得回溯一下。
*/

void df(TreeNode *root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path, vector<TreeNode*> &path_p, vector<TreeNode*> &path_q){
    if(!root) return;
    path.push_back(root);
    if(root == p){
        path_p = path;
    }
    if(root == q){
        path_q = path;
    }
    df(root->left, p, q, path, path_p, path_q);
    df(root->right, p, q, path, path_p, path_q);
    path.pop_back();
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path, path_p, path_q;
        TreeNode*ans;
        
        df(root, p, q, path, path_p, path_q);
        
        for(int i = 0; i < min(path_p.size(), path_q.size()); i++){
            if(path_p[i] == path_q[i]){
                ans = path_p[i];
            }else{
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = buildTree({3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4});
    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);
    TreeNode* ans1 = solution.lowestCommonAncestor(root1, p1, q1);
    std::cout << "case 1 input    = " << treeToString(root1) << ", p = 5, q = 1\n";
    std::cout << "case 1 output   = " << (ans1 == nullptr ? -1 : ans1->val) << "\n";
    std::cout << "case 1 expected = 3\n\n";

    TreeNode* root2 = buildTree({3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4});
    TreeNode* p2 = findNode(root2, 5);
    TreeNode* q2 = findNode(root2, 4);
    TreeNode* ans2 = solution.lowestCommonAncestor(root2, p2, q2);
    std::cout << "case 2 input    = " << treeToString(root2) << ", p = 5, q = 4\n";
    std::cout << "case 2 output   = " << (ans2 == nullptr ? -1 : ans2->val) << "\n";
    std::cout << "case 2 expected = 5\n";

    freeTree(root1);
    freeTree(root2);
    return 0;
}
