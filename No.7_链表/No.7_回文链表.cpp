/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true；否则，返回 false。

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false
*/

/*
思路：快慢指针找中点，反转后半段，再从两端向中间逐个比较。
关键数据结构：slow/fast 定位中点，prev/cur 用来反转后半段链表。
注意：奇偶长度都要处理好；如果要求保持原链表，比较后应把后半段再反转回来。
*/

#include "LinkedListTestUtils.hpp"

ListNode *rv(ListNode *head){
    ListNode *pro = nullptr;
    ListNode *curr = head;
    while(curr){
        ListNode *temp = curr->next;

        curr->next = pro;

        pro = curr;
        curr = temp;
    }
    return pro;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = rv(slow->next);
        fast = head;
        while(slow){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha;

    ListNode* head1 = buildList({1, 2, 2, 1});
    std::cout << "case 1 input    = " << vectorToString(listToVector(head1)) << "\n";
    std::cout << "case 1 output   = " << solution.isPalindrome(head1) << "\n";
    std::cout << "case 1 expected = true\n\n";

    ListNode* head2 = buildList({1, 2});
    std::cout << "case 2 input    = " << vectorToString(listToVector(head2)) << "\n";
    std::cout << "case 2 output   = " << solution.isPalindrome(head2) << "\n";
    std::cout << "case 2 expected = false\n\n";

    ListNode* head3 = buildList({1, 2, 3, 2, 1});
    std::cout << "case 3 input    = " << vectorToString(listToVector(head3)) << "\n";
    std::cout << "case 3 output   = " << solution.isPalindrome(head3) << "\n";
    std::cout << "case 3 expected = true\n";

    freeReachableLists({head1, head2, head3});
    return 0;
}
