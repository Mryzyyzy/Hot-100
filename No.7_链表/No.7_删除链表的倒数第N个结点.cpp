/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
*/

/*
思路：快慢指针保持 n 个节点间距，fast 到尾时 slow 正好在待删节点前面。
关键数据结构：dummy 虚拟头节点统一删除头节点情况，fast/slow 定位删除位置。
注意：先让 fast 走 n 步；删除后返回 dummy.next，不要直接返回原 head。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *de = slow->next;
        slow-> next = de->next;
        delete de;
        return dummy.next;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    ListNode* ans1 = solution.removeNthFromEnd(head1, 2);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [1, 2, 3, 5]\n\n";

    ListNode* head2 = buildList({1});
    ListNode* ans2 = solution.removeNthFromEnd(head2, 1);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = []\n\n";

    ListNode* head3 = buildList({1, 2});
    ListNode* ans3 = solution.removeNthFromEnd(head3, 2);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [2]\n";

    freeReachableLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
