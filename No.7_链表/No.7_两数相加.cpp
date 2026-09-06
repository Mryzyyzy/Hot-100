/*
给你两个非空的链表，表示两个非负的整数。
它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807

示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
*/

/*
思路：两个链表从头开始逐位相加，用 carry 保存进位，新建结果链表。
关键数据结构：dummy/tail 拼接结果节点，carry 记录当前位产生的进位。
注意：循环要覆盖 l1、l2 和最后 carry 三种情况，避免漏掉最终进位。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;
        int sum = 0;
        while(l1 || l2){
            int a = l1? l1->val : 0;
            int b = l2? l2->val : 0;
            sum = a + b + carry;
            tail->next = new ListNode(sum % 10);
            carry = sum / 10;
            tail = tail->next;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        if(carry) tail->next = new ListNode(carry);
        return dummy.next;
    }
};

int main() {
    Solution solution;

    ListNode* l1 = buildList({2, 4, 3});
    ListNode* l2 = buildList({5, 6, 4});
    ListNode* ans1 = solution.addTwoNumbers(l1, l2);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [7, 0, 8]\n\n";

    ListNode* l3 = buildList({0});
    ListNode* l4 = buildList({0});
    ListNode* ans2 = solution.addTwoNumbers(l3, l4);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = [0]\n\n";

    ListNode* l5 = buildList({9, 9, 9, 9, 9, 9, 9});
    ListNode* l6 = buildList({9, 9, 9, 9});
    ListNode* ans3 = solution.addTwoNumbers(l5, l6);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [8, 9, 9, 9, 0, 0, 0, 1]\n";

    freeReachableLists({l1, l2, ans1, l3, l4, ans2, l5, l6, ans3});
    return 0;
}
