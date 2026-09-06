/*
请你设计并实现一个满足 LRU（最近最少使用）缓存约束的数据结构。

实现 LRUCache 类：
LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存。
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value；
如果不存在，则向缓存中插入该组 key-value。
如果插入操作导致关键字数量超过 capacity，则应该逐出最久未使用的关键字。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

示例：
输入：
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/

/*
思路：get/put 都把访问过的节点移动到链表头部，容量超限时删除链表尾部最久未使用节点。
    三个重要的数据结构：
        void addhead(Node *node)
        void movehead(Node *node)
        int removetail()
关键数据结构：unordered_map 负责 O(1) 找节点，双向链表负责 O(1) 调整新旧顺序。
注意：淘汰时要从 map 中删除被移除节点的 key，不是删除刚插入的 key。
*/

#include "LinkedListTestUtils.hpp"
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(0, 0);
        this->tail = new Node(0,0);
        head->next = tail;
        tail->pro = head;
        this->i = 0;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()){
            return -1;
        }
        movehead(it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()){
            it->second->value = value;
            movehead(it->second);
            return;
        } 
        Node *temp = new Node(key, value);
        addhead(temp);
        mp[key] = temp;
        i++;
        if(i > capacity){
            i--;
            int temp = removetail();
            mp.erase(temp);
        }
    }
private:
    struct Node {
        int key, value;
        Node *next, *pro;
        Node(int key, int value): key(key), value(value){
            this->next = NULL;
            this->pro = NULL;
        }
    };

    int capacity;
    int i;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;

    void addhead(Node *node){
        node->next = head->next;
        node->pro = head;

        head->next->pro = node;
        head->next = node;
    }
    void movehead(Node *node){
        node->pro->next = node->next;
        node->next->pro = node->pro;
        
        addhead(node);
    }
    int removetail(){
        Node *temp = tail->pro;
        int ans = temp->key;
        temp->pro->next = tail;
        tail->pro = temp->pro;
        delete temp;
        return ans;
    }
};

int main() {
    LRUCache cache1(2);
    std::vector<int> output1;
    cache1.put(1, 1);
    cache1.put(2, 2);
    output1.push_back(cache1.get(1));
    cache1.put(3, 3);
    output1.push_back(cache1.get(2));
    cache1.put(4, 4);
    output1.push_back(cache1.get(1));
    output1.push_back(cache1.get(3));
    output1.push_back(cache1.get(4));
    std::cout << "case 1 output   = " << vectorToString(output1) << "\n";
    std::cout << "case 1 expected = [1, -1, -1, 3, 4]\n\n";

    LRUCache cache2(2);
    std::vector<int> output2;
    cache2.put(2, 1);
    cache2.put(2, 2);
    output2.push_back(cache2.get(2));
    std::cout << "case 2 output   = " << vectorToString(output2) << "\n";
    std::cout << "case 2 expected = [2]\n\n";

    LRUCache cache3(1);
    std::vector<int> output3;
    cache3.put(1, 1);
    cache3.put(2, 2);
    output3.push_back(cache3.get(1));
    output3.push_back(cache3.get(2));
    std::cout << "case 3 output   = " << vectorToString(output3) << "\n";
    std::cout << "case 3 expected = [-1, 2]\n";

    return 0;
}
