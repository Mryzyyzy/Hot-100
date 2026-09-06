/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 表示链表尾连接到链表中的位置（索引从 0 开始）。
pos 不作为参数进行传递，仅用于标识链表的实际情况。

如果链表中存在环，则返回 true；否则返回 false。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true

示例 2：
输入：head = [1,2], pos = 0
输出：true

示例 3：
输入：head = [1], pos = -1
输出：false
*/

/*
思路：快慢指针同时走，slow 每次一步，fast 每次两步；有环时两者一定会相遇。
关键数据结构：slow 和 fast 两个 ListNode 指针，用来判断链表是否存在追及。
注意：循环条件要保证 fast 和 fast->next 非空，避免访问空指针。
    环形链表的两个题目用：while(fast && fast->next)
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha;

    ListNode* head1 = buildCycledList({3, 2, 0, -4}, 1);
    std::cout << "case 1 input    = [3, 2, 0, -4], pos = 1\n";
    std::cout << "case 1 output   = " << solution.hasCycle(head1) << "\n";
    std::cout << "case 1 expected = true\n\n";

    ListNode* head2 = buildCycledList({1, 2}, 0);
    std::cout << "case 2 input    = [1, 2], pos = 0\n";
    std::cout << "case 2 output   = " << solution.hasCycle(head2) << "\n";
    std::cout << "case 2 expected = true\n\n";

    ListNode* head3 = buildCycledList({1}, -1);
    std::cout << "case 3 input    = [1], pos = -1\n";
    std::cout << "case 3 output   = " << solution.hasCycle(head3) << "\n";
    std::cout << "case 3 expected = false\n";

    freeList(head1);
    freeList(head2);
    freeList(head3);
    return 0;
}
