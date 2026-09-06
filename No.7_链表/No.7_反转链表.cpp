/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

/*
思路：用三个指针逐个改变 next 指向，把链表从前往后原地反转。
关键数据结构：ListNode 指针 prev、cur、next，用来保存前驱、当前节点和后继节点。
注意：改 cur->next 前必须先保存 next，否则后面的链表会断掉找不回来。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pro =  nullptr;
        ListNode *curr = head;
        while(curr){
            ListNode *temp = curr->next;

            curr->next = pro;

            pro = curr;
            curr = temp;
        }
        return pro;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    ListNode* ans1 = solution.reverseList(head1);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [5, 4, 3, 2, 1]\n\n";

    ListNode* head2 = buildList({1, 2});
    ListNode* ans2 = solution.reverseList(head2);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = [2, 1]\n\n";

    ListNode* head3 = buildList({});
    ListNode* ans3 = solution.reverseList(head3);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = []\n";

    freeReachableLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
