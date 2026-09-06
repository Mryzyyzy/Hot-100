/*
给你链表的头结点 head ，请将其按升序排列并返回排序后的链表。

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：
输入：head = []
输出：[]
*/

/*
思路：链表排序常用归并排序，先用快慢指针切成两半，递归排序后再合并。
关键数据结构：slow/fast 找中点，dummy/tail 合并两个有序子链表。
注意：切分时要断开前半段尾节点；递归出口是空链表或单节点。
*/

#include "LinkedListTestUtils.hpp"

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while(l1 && l2){
        if(l1->val < l2->val){
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }
    }
    tail->next = l1? l1 : l2;
    return dummy.next;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *l = sortList(head);
        ListNode *r = sortList(mid);
        ListNode *ans = merge(l, r);
        return ans;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildList({4, 2, 1, 3});
    ListNode* ans1 = solution.sortList(head1);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [1, 2, 3, 4]\n\n";

    ListNode* head2 = buildList({-1, 5, 3, 4, 0});
    ListNode* ans2 = solution.sortList(head2);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = [-1, 0, 3, 4, 5]\n\n";

    ListNode* head3 = buildList({3, 1, 2, 3, 2});
    ListNode* ans3 = solution.sortList(head3);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [1, 2, 2, 3, 3]\n";

    freeReachableLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
