/*
给定一个链表的头节点 head ，返回链表开始入环的第一个节点。
如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 表示链表尾连接到链表中的位置（索引从 0 开始）。
pos 不作为参数进行传递，仅用于标识链表的实际情况。

不允许修改链表。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点

示例 2：
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点

示例 3：
输入：head = [1], pos = -1
输出：null
*/

/*
思路：先用快慢指针判断是否有环；相遇后让一个指针回到头节点，两者同步走，重逢处就是入环点。
关键数据结构：slow、fast 两个指针用于找相遇点，再用 head 和 slow 同步定位入口。
注意：无环时直接返回 nullptr；第二阶段两个指针都一次走一步。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(fast == NULL || fast->next == NULL) return NULL;

        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = buildCycledList({3, 2, 0, -4}, 1);
    ListNode* ans1 = solution.detectCycle(head1);
    std::cout << "case 1 input          = [3, 2, 0, -4], pos = 1\n";
    std::cout << "case 1 output index   = " << indexOfNode(head1, ans1, 4) << "\n";
    std::cout << "case 1 expected index = 1\n\n";

    ListNode* head2 = buildCycledList({1, 2}, 0);
    ListNode* ans2 = solution.detectCycle(head2);
    std::cout << "case 2 input          = [1, 2], pos = 0\n";
    std::cout << "case 2 output index   = " << indexOfNode(head2, ans2, 2) << "\n";
    std::cout << "case 2 expected index = 0\n\n";

    ListNode* head3 = buildCycledList({1}, -1);
    ListNode* ans3 = solution.detectCycle(head3);
    std::cout << "case 3 input          = [1], pos = -1\n";
    std::cout << "case 3 output index   = " << indexOfNode(head3, ans3, 1) << "\n";
    std::cout << "case 3 expected index = -1\n";

    freeList(head1);
    freeList(head2);
    freeList(head3);
    return 0;
}
