/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
*/

/*
思路：可以用小顶堆维护每条链表当前头节点，每次取出最小节点接到结果链表。
关键数据结构：priority_queue 小顶堆保存候选节点，用 dummy/tail 拼接答案。
注意：弹出节点后，如果它还有 next，要把 next 继续放入堆中。
*/

#include "LinkedListTestUtils.hpp"

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        (void)lists;
        // TODO: 在这里实现合并 K 个升序链表算法。
        return nullptr;
    }
};

int main() {
    Solution solution;

    std::vector<ListNode*> lists1 = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6})
    };
    ListNode* ans1 = solution.mergeKLists(lists1);
    std::cout << "case 1 output   = " << vectorToString(listToVector(ans1)) << "\n";
    std::cout << "case 1 expected = [1, 1, 2, 3, 4, 4, 5, 6]\n\n";

    std::vector<ListNode*> lists2 = {};
    ListNode* ans2 = solution.mergeKLists(lists2);
    std::cout << "case 2 output   = " << vectorToString(listToVector(ans2)) << "\n";
    std::cout << "case 2 expected = []\n\n";

    std::vector<ListNode*> lists3 = {
        buildList({}),
        buildList({1}),
        buildList({0, 2})
    };
    ListNode* ans3 = solution.mergeKLists(lists3);
    std::cout << "case 3 output   = " << vectorToString(listToVector(ans3)) << "\n";
    std::cout << "case 3 expected = [0, 1, 2]\n";

    lists1.push_back(ans1);
    lists2.push_back(ans2);
    lists3.push_back(ans3);
    freeReachableLists(lists1);
    freeReachableLists(lists2);
    freeReachableLists(lists3);
    return 0;
}
