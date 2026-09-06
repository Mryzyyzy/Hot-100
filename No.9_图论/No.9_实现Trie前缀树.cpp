/*
实现 Trie 类：
insert(word) 向前缀树中插入字符串 word。
search(word) 如果字符串 word 在前缀树中，返回 true。
startsWith(prefix) 如果之前插入的字符串有前缀 prefix，返回 true。
*/

#include "GraphTestUtils.hpp"
#include <string>

using namespace std;

/*
思路：每个节点表示一个字符位置，从根节点按字符一路向下插入或查询。
关键数据结构：TrieNode 子节点数组/哈希表保存下一层字符，isEnd 标记单词结尾。
注意：search 必须走到单词结尾并且 isEnd 为 true，startsWith 只要前缀路径存在即可。
*/

class Trie {
public:
    Trie() {
    }

    void insert(string word) {
    }

    bool search(string word) {
        return false;
    }

    bool startsWith(string prefix) {
        return false;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << "case 1 search(\"apple\") output   = " << boolToString(trie.search("apple")) << "\n";
    cout << "case 1 search(\"apple\") expected = true\n\n";

    cout << "case 2 search(\"app\") output     = " << boolToString(trie.search("app")) << "\n";
    cout << "case 2 search(\"app\") expected   = false\n\n";

    cout << "case 3 startsWith(\"app\") output   = " << boolToString(trie.startsWith("app")) << "\n";
    cout << "case 3 startsWith(\"app\") expected = true\n\n";

    trie.insert("app");
    cout << "case 4 search(\"app\") output     = " << boolToString(trie.search("app")) << "\n";
    cout << "case 4 search(\"app\") expected   = true\n";

    return 0;
}
