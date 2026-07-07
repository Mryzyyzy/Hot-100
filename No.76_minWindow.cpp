#include<iostream>
#include<string>

using namespace std;

string minWindow(string &s, string &t){
    int cnt[128] = {0};
    int less = 0;
    for(int i = 0; i < t.size(); i++){
        if(cnt[t[i]] == 0){
            less++;
        }
        cnt[t[i]]++;
    }
    int l = 0, r = 0, ll = 0, rr = 999999;
    while(r < s.size()){
        cnt[s[r]]--;
        if(cnt[s[r]] == 0){
            less--;
        }
        while(less == 0){
            if(rr - ll > r - l){
                rr = r;
                ll = l;
            }
            if(cnt[s[l]] == 0){
                less++;
            }
            cnt[s[l]]++;
            l++;
        }
        r++;
    }
    if(rr == 999999){
        return "";
    }
    return s.substr(ll, rr - ll + 1); 
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