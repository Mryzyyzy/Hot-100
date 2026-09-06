#pragma once

#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

inline ListNode* buildList(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

inline ListNode* buildList(std::initializer_list<int> values) {
    return buildList(std::vector<int>(values));
}

inline ListNode* nodeAt(ListNode* head, int index) {
    for (int i = 0; head != nullptr && i < index; ++i) {
        head = head->next;
    }
    return head;
}

inline ListNode* tailOf(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}

inline int indexOfNode(ListNode* head, ListNode* target, int limit = 1000) {
    for (int index = 0; head != nullptr && index < limit; ++index) {
        if (head == target) {
            return index;
        }
        head = head->next;
    }
    return -1;
}

inline void printList(ListNode* head, const std::string& label = "list", int limit = 50) {
    std::cout << label << " = [";
    std::unordered_set<ListNode*> visited;
    int count = 0;
    while (head != nullptr && count < limit) {
        if (visited.count(head) != 0) {
            std::cout << "(cycle to " << head->val << ")";
            break;
        }
        visited.insert(head);
        if (count > 0) {
            std::cout << ", ";
        }
        std::cout << head->val;
        head = head->next;
        ++count;
    }
    if (head != nullptr && count >= limit) {
        std::cout << ", ...";
    }
    std::cout << "]\n";
}

inline std::vector<int> listToVector(ListNode* head, int limit = 1000) {
    std::vector<int> values;
    std::unordered_set<ListNode*> visited;
    while (head != nullptr && visited.count(head) == 0 && static_cast<int>(values.size()) < limit) {
        visited.insert(head);
        values.push_back(head->val);
        head = head->next;
    }
    return values;
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

inline void freeList(ListNode* head) {
    std::unordered_set<ListNode*> visited;
    while (head != nullptr && visited.count(head) == 0) {
        visited.insert(head);
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

inline void freeReachableLists(const std::vector<ListNode*>& heads) {
    std::unordered_set<ListNode*> visited;
    for (ListNode* head : heads) {
        while (head != nullptr && visited.count(head) == 0) {
            visited.insert(head);
            ListNode* next = head->next;
            delete head;
            head = next;
        }
    }
}

inline ListNode* buildCycledList(const std::vector<int>& values, int pos) {
    ListNode* head = buildList(values);
    if (pos >= 0) {
        ListNode* entry = nodeAt(head, pos);
        ListNode* tail = tailOf(head);
        if (tail != nullptr) {
            tail->next = entry;
        }
    }
    return head;
}

inline Node* buildRandomList(const std::vector<std::pair<int, int>>& valuesAndRandomIndexes) {
    std::vector<Node*> nodes;
    nodes.reserve(valuesAndRandomIndexes.size());
    for (const auto& item : valuesAndRandomIndexes) {
        nodes.push_back(new Node(item.first));
    }
    for (size_t i = 0; i + 1 < nodes.size(); ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        int randomIndex = valuesAndRandomIndexes[i].second;
        if (randomIndex >= 0 && randomIndex < static_cast<int>(nodes.size())) {
            nodes[i]->random = nodes[randomIndex];
        }
    }
    return nodes.empty() ? nullptr : nodes.front();
}

inline void printRandomList(Node* head, const std::string& label = "random list") {
    std::vector<Node*> nodes;
    std::unordered_map<Node*, int> indexByNode;
    for (Node* current = head; current != nullptr; current = current->next) {
        indexByNode[current] = static_cast<int>(nodes.size());
        nodes.push_back(current);
    }

    std::cout << label << " = [";
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << "[" << nodes[i]->val << ", ";
        if (nodes[i]->random == nullptr) {
            std::cout << "null";
        } else {
            auto it = indexByNode.find(nodes[i]->random);
            if (it == indexByNode.end()) {
                std::cout << "external";
            } else {
                std::cout << it->second;
            }
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}

inline std::vector<std::pair<int, int>> randomListToPairs(Node* head) {
    std::vector<Node*> nodes;
    std::unordered_map<Node*, int> indexByNode;
    for (Node* current = head; current != nullptr; current = current->next) {
        indexByNode[current] = static_cast<int>(nodes.size());
        nodes.push_back(current);
    }

    std::vector<std::pair<int, int>> result;
    result.reserve(nodes.size());
    for (Node* node : nodes) {
        int randomIndex = -1;
        if (node->random != nullptr) {
            auto it = indexByNode.find(node->random);
            randomIndex = (it == indexByNode.end()) ? -2 : it->second;
        }
        result.push_back({node->val, randomIndex});
    }
    return result;
}

inline std::string randomPairsToString(const std::vector<std::pair<int, int>>& pairs) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << "[" << pairs[i].first << ", ";
        if (pairs[i].second == -1) {
            oss << "null";
        } else if (pairs[i].second == -2) {
            oss << "external";
        } else {
            oss << pairs[i].second;
        }
        oss << "]";
    }
    oss << "]";
    return oss.str();
}

inline void freeRandomList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

inline bool hasNoSharedRandomNodes(Node* first, Node* second) {
    std::unordered_set<Node*> firstNodes;
    for (Node* current = first; current != nullptr; current = current->next) {
        firstNodes.insert(current);
    }
    for (Node* current = second; current != nullptr; current = current->next) {
        if (firstNodes.count(current) != 0) {
            return false;
        }
    }
    return true;
}

inline void freeReachableRandomLists(const std::vector<Node*>& heads) {
    std::unordered_set<Node*> visited;
    for (Node* head : heads) {
        while (head != nullptr && visited.count(head) == 0) {
            visited.insert(head);
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
}
