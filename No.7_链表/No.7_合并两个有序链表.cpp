/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/

/*
思路：双指针同时扫描两个有序链表，每次把较小节点接到结果链表尾部。
关键数据结构：dummy 虚拟头节点和 tail 尾指针，用来统一处理头节点和尾插。
注意：某一条链表先走完后，剩下的节点可以直接整体接上。
*/

/**
 * @algorithm 迭代法 + 虚拟头节点 (Dummy Node)
 *
 * @time_complexity O(N + M) - N, M 分别为两个链表的长度。
 * @space_complexity O(1) - 仅使用了常数个指针，原地修改结构。
 *
 * @note 核心战术：
 * 1. 建立 dummy 节点：在栈上分配，自动回收内存。
 * 2. 尾插法：用一个 tail 指针时刻指向新链表的末尾。
 * 3. 链表特有的收尾：如果其中一个链表先走完，不需要遍历剩下的，直接把指针连过去即可。
 */

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        tail->next = list1? list1 : list2;
        return dummy.next;
    }
};

int main() {
    Solution solution;

    ListNode* list1 = buildList({1, 2, 4});
    ListNode* list2 = buildList({1, 3, 4});
    ListNode* ans1 = solution.mergeTwoLists(list1, list2);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [1, 1, 2, 3, 4, 4]\n\n";

    ListNode* list3 = buildList({});
    ListNode* list4 = buildList({0});
    ListNode* ans2 = solution.mergeTwoLists(list3, list4);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = [0]\n\n";

    ListNode* list5 = buildList({-10, -3, 5});
    ListNode* list6 = buildList({-7, 0, 9});
    ListNode* ans3 = solution.mergeTwoLists(list5, list6);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [-10, -7, -3, 0, 5, 9]\n";

    freeReachableLists({list1, list2, ans1, list3, list4, ans2, list5, list6, ans3});
    return 0;
}
