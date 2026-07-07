#include<iostream>
#include<string>

using namespace std;

/*
    窗口定义：[l, r)，左边界 l，右边界 r，窗口内永远保存不含重复字符的连续子串。
    unmap[300]：ASCII 字符数组哈希，记录窗口内每个字符出现次数（ASCII 码 0~256，开 300 足够存所有字母、符号）。
    逻辑一句话：右指针不断扩张窗口，遇到重复就收缩左指针，全程记录窗口最大长度。
*/

int ZiChuan(string &s){
    int l = 0, r = 0, ans = 0;
    int unmap[300] = {0};
    int n = s.size();
    while(r < n){
        while(r < n && unmap[s[r]] < 1){
            unmap[s[r]]++;
            r++;
        }
        ans = max(ans, r - l);
        unmap[s[l]]--;
        l++;
    }
    return ans;
}

int main(){
    string s = "abcabcbb";
    int ans = ZiChuan(s);
    cout << ans << endl;
    s = "bbbbb";
    ans = ZiChuan(s);
    cout << ans << endl;
    s = "pwwkew";
    ans = ZiChuan(s);
    cout << ans << endl;
}