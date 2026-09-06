/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯地改变节点内部的值，而是需要实际进行节点交换。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
*/

/*
思路：每次先确认后面够 k 个节点，再把这一段局部反转并接回原链表。
关键数据结构：dummy/pre/end 指针定位每组边界，start/next 保存反转段和后续链表。
注意：不足 k 个节点时保持原顺序；反转前要先断开这一组的尾部。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        (void)head;
        (void)k;
        // TODO: 在这里实现 K 个一组翻转链表算法。
        return nullptr;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    ListNode* ans1 = solution.reverseKGroup(head1, 2);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [2, 1, 4, 3, 5]\n\n";

    ListNode* head2 = buildList({1, 2, 3, 4, 5});
    ListNode* ans2 = solution.reverseKGroup(head2, 3);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = [3, 2, 1, 4, 5]\n\n";

    ListNode* head3 = buildList({1, 2});
    ListNode* ans3 = solution.reverseKGroup(head3, 3);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [1, 2]\n";

    freeReachableLists({head1, ans1, head2, ans2, head3, ans3});
    return 0;
}
