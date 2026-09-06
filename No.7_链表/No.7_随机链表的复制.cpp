/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，
该指针可以指向链表中的任何节点或空节点。

构造这个链表的深拷贝。深拷贝应该正好由 n 个全新节点组成，
其中每个新节点的 val 都设为其对应原节点的 val。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点。

每个节点用一个 [val, random_index] 表示：
val 表示 Node.val，random_index 表示随机指针指向的节点索引；
如果不指向任何节点，则为 null。

示例 1：
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
*/

/*
思路：阶段 1：克隆节点并交织挂载
            原链表：A -> B -> C
            现链表：A -> A' -> B -> B' -> C -> C'
     阶段 2：处理克隆节点的 random 指针
            如果原节点的 random 不为空，
            克隆节点的 random 就是原节点 random 的 next
     阶段 3：物理拆分（极其关键：必须恢复原链表！）
            恢复原链表
            链接新链表
关键数据结构：unordered_map 保存新旧节点对应关系，用来快速找到 random 指向的新节点。
注意：复制链表不能复用原节点；random 为空时要保持 nullptr。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *p = head;
        while(p){
            Node *pp = new Node(p->val);
            pp->next = p->next;
            p->next = pp;
            p = pp->next; 
        }
        p = head;
        while(p){
            Node *pp = p->next;
            if(p->random){
                pp->random = p->random->next;
            }            
            p = pp->next;
        }
        p = head;
        Node *ans = p->next;
        Node *pp = ans;
        while(pp){
            p->next = pp->next;
            p = p->next;
            if(!p){
                return ans;
            }
            pp->next = p->next; 
            pp = p->next;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    std::vector<std::pair<int, int>> input1 = {
        {7, -1},
        {13, 0},
        {11, 4},
        {10, 2},
        {1, 0}
    };
    Node* head1 = buildRandomList(input1);
    Node* ans1 = solution.copyRandomList(head1);
    std::cout << "case 1 output   = " << randomPairsToString(randomListToPairs(ans1)) << "\n";
    std::cout << "case 1 expected = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]\n\n";

    std::vector<std::pair<int, int>> input2 = {
        {1, 1},
        {2, 1}
    };
    Node* head2 = buildRandomList(input2);
    Node* ans2 = solution.copyRandomList(head2);
    std::cout << "case 2 output   = " << randomPairsToString(randomListToPairs(ans2)) << "\n";
    std::cout << "case 2 expected = [[1, 1], [2, 1]]\n\n";

    std::vector<std::pair<int, int>> input3 = {
        {1, 0}
    };
    Node* head3 = buildRandomList(input3);
    Node* ans3 = solution.copyRandomList(head3);
    std::cout << "case 3 output   = " << randomPairsToString(randomListToPairs(ans3)) << "\n";
    std::cout << "case 3 expected = [[1, 0]]\n";

    freeReachableRandomLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
