/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null。

题目数据保证整个链式结构中不存在环。
注意，函数返回结果后，链表必须保持其原始结构。

自定义评测：
intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0。
listA - 第一个链表。
listB - 第二个链表。
skipA - 在 listA 中从头节点开始跳到交叉节点的节点数。
skipB - 在 listB 中从头节点开始跳到交叉节点的节点数。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'

示例 2：
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：No intersection
*/

/*
思路：双指针分别从 A、B 出发，走到末尾后切换到另一条链表，最终会在相交点或 nullptr 相遇。
关键数据结构：pA、pB 两个指针，用 A+B 和 B+A 的等长路径抵消长度差。
注意：判断相交看节点地址是否相同，不是看节点值是否相等。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *A = headA, *B = headB;
        // 如果没有相交的话，ab会同时为空
        while(A != B){
            A = !A? headB : A->next;
            B = !B? headA : B->next;
        }
        return A;
    }
};

void attachSharedTail(ListNode*& head, ListNode* shared) {
    if (head == nullptr) {
        head = shared;
        return;
    }
    tailOf(head)->next = shared;
}

int main() {
    Solution solution;

    ListNode* shared1 = buildList({8, 4, 5});
    ListNode* headA1 = buildList({4, 1});
    ListNode* headB1 = buildList({5, 6, 1});
    attachSharedTail(headA1, shared1);
    attachSharedTail(headB1, shared1);
    ListNode* ans1 = solution.getIntersectionNode(headA1, headB1);
    std::cout << "case 1 output   = " << (ans1 == nullptr ? -1 : ans1->val) << "\n";
    std::cout << "case 1 expected = 8\n\n";

    ListNode* shared2 = buildList({2, 4});
    ListNode* headA2 = buildList({1, 9, 1});
    ListNode* headB2 = buildList({3});
    attachSharedTail(headA2, shared2);
    attachSharedTail(headB2, shared2);
    ListNode* ans2 = solution.getIntersectionNode(headA2, headB2);
    std::cout << "case 2 output   = " << (ans2 == nullptr ? -1 : ans2->val) << "\n";
    std::cout << "case 2 expected = 2\n\n";

    ListNode* headA3 = buildList({2, 6, 4});
    ListNode* headB3 = buildList({1, 5});
    ListNode* ans3 = solution.getIntersectionNode(headA3, headB3);
    std::cout << "case 3 output   = " << (ans3 == nullptr ? -1 : ans3->val) << "\n";
    std::cout << "case 3 expected = -1\n";

    freeReachableLists({headA1, headB1, headA2, headB2, headA3, headB3});
    return 0;
}
