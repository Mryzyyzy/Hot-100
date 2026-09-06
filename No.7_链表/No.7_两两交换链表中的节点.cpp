/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
*/

/*
思路：用虚拟头节点，每次取出一对相邻节点，调整四条连接完成交换。
关键数据结构：dummy 和 pre 指针，用来定位每一组交换前的前驱节点。
注意：循环条件要保证 pre 后面至少还有两个节点；交换时先保存后续节点。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *pro = &dummy;
        while(pro->next && pro->next->next){
            ListNode *node1 = pro->next;
            ListNode *node2 = pro->next->next;

            node1->next = node2->next;
            node2->next = node1;
            pro->next = node2;

            pro = node1;
        }
        return dummy.next;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildList({1, 2, 3, 4});
    ListNode* ans1 = solution.swapPairs(head1);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [2, 1, 4, 3]\n\n";

    ListNode* head2 = buildList({});
    ListNode* ans2 = solution.swapPairs(head2);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = []\n\n";

    ListNode* head3 = buildList({1, 2, 3, 4, 5});
    ListNode* ans3 = solution.swapPairs(head3);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [2, 1, 4, 3, 5]\n";

    freeReachableLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
