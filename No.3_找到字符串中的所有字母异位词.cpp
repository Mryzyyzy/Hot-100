#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
    用固定长度滑动窗口，窗口大小 = len (p)，在 s 上从左往右滑动，每次判断窗口内字符计数是否和 p 一致。

    只有小写英文字母，开两个长度 26 数组：
    pcount[26]：统计 p 中每个字母出现次数（固定不变）
    scount[26]：统计当前窗口内 s 的字母次数（窗口滑动时动态更新）
    如果 scount == pcount，说明当前窗口是 p 的异位词，记录起始下标。
    使用vector直接进行过判断26个字母的个数是否相等。
    边界：r为n - 1时，循环里面没有比较scount[s[n - 1]]这个字符。
*/

vector<int> findAnagrams(string &s, string &p){
    vector<int> ans;
    vector<int> scount(26, 0);
    vector<int> pcount(26, 0);
    int l = 0, r = p.size(), n = s.size();
    if(r > n){
        return ans;
    } 
    for(int i = 0; i < r; i++){
        scount[s[i] - 'a']++;
        pcount[p[i] - 'a'] ++;
    }
    while(r < n){
        if(pcount == scount){
            ans.push_back(l);
        }
        scount[s[l] - 'a']--;
        scount[s[r] - 'a']++;
        r++;
        l++;
    }
    if(pcount == scount){
            ans.push_back(l);
    }
    return ans;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    s = "abab";
    p = "ab";
    ans = findAnagrams(s, p);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}