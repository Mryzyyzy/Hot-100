#include<iostream>
#include<string>

using namespace std;

/*
    预处理：need 存 t 字符需求量，统计 t 不同字符种类 kind；win 记录窗口字符数，match 记录匹配齐全的字符种类。
    r 右扩窗口，更新 win，字符刚好满足需求则 match+1。
    match==kind 时窗口合法，收缩左边界 l，同步更新最短子串，移出关键字符则 match-1。
    最后返回最短子串或空串。
*/

string minWindow(string &s, string &t){
    int win[128] = {0}, need[128] = {0};
    int kind = 0;  // t中不同字符种类
    for(int i = 0; i < t.size(); i++){
        if(need[t[i]] == 0){
            kind++;
        }
        need[t[i]]++;
    }
    int match = 0, start = 0, len = 99999;
    int l = 0, r = 0, n = s.size();
    while(r < n){
        win[s[r]]++;
        
        // 当前字符数量刚好匹配，匹配种类+1
        if(win[s[r]] == need[s[r]]){
            match++;
        }
        // 窗口合法，收缩左边界
        while(match == kind){
            // 更新最小窗口
            int temp = r - l + 1;
            if(len > temp){
                len = temp;
                start = l;
            }
            // 如果这个字符是刚好匹配的，移除后匹配数减少         
            if(win[s[l]] == need[s[l]]) match--;
            win[s[l]]--;
            l++;
        }
        r++;
    }
    return len == 99999? "" : s.substr(start, len);
}

int main(){
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    string s3 = minWindow(s1, s2);
    cout << s3 << endl;
    s1 = "a";
    s2 = "a";
    s3 = minWindow(s1, s2);
    cout << s3 << endl;    
    s1 = "a";
    s2 = "aa";
    s3 = minWindow(s1, s2);
    cout << s3 << endl;   
}