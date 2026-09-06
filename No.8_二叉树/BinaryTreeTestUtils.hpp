#pragma once

#include <iostream>
#include <optional>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

inline TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) {
        return nullptr;
    }

    std::vector<TreeNode*> nodes(values.size(), nullptr);
    for (size_t i = 0; i < values.size(); ++i) {
        if (values[i].has_value()) {
            nodes[i] = new TreeNode(values[i].value());
        }
    }

    size_t child = 1;
    for (size_t i = 0; i < nodes.size() && child < nodes.size(); ++i) {
        if (nodes[i] == nullptr) {
            continue;
        }
        if (child < nodes.size()) {
            nodes[i]->left = nodes[child++];
        }
        if (child < nodes.size()) {
            nodes[i]->right = nodes[child++];
        }
    }

    return nodes[0];
}

inline std::vector<std::optional<int>> treeToLevelOrder(TreeNode* root) {
    std::vector<std::optional<int>> values;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            values.push_back(std::nullopt);
            continue;
        }

        values.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
    }

    while (!values.empty() && !values.back().has_value()) {
        values.pop_back();
    }
    return values;
}

inline std::string levelOrderToString(const std::vector<std::optional<int>>& values) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        if (values[i].has_value()) {
            oss << values[i].value();
        } else {
            oss << "null";
        }
    }
    oss << "]";
    return oss.str();
}

inline std::string treeToString(TreeNode* root) {
    return levelOrderToString(treeToLevelOrder(root));
}

inline std::string vectorToString(const std::vector<int>& values) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << values[i];
    }
    oss << "]";
    return oss.str();
}

inline std::string matrixToString(const std::vector<std::vector<int>>& values) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << vectorToString(values[i]);
    }
    oss << "]";
    return oss.str();
}

inline TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    TreeNode* left = findNode(root->left, val);
    return left == nullptr ? findNode(root->right, val) : left;
}

inline std::vector<int> rightChainValues(TreeNode* root) {
    std::vector<int> values;
    while (root != nullptr) {
        values.push_back(root->val);
        root = root->right;
    }
    return values;
}

inline void freeTree(TreeNode* root) {
    std::unordered_set<TreeNode*> visited;
    std::stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node == nullptr || visited.count(node) != 0) {
            continue;
        }
        visited.insert(node);
        st.push(node->left);
        st.push(node->right);
        delete node;
    }
}

