#include<iostream>
#include<vector>

using namespace std;

int JieShui(vector<int> & height){
    int l = 0, r = height.size() - 1;
    int lm = 0, rm = 0, ans = 0;
    while(l < r){
        lm = max(lm, height[l]);
        rm = max(rm, height[r]);
        if(lm < rm){
            if(height[l] < lm) ans += lm - height[l];
            l++;
        }else{
            if(height[r] < rm) ans += rm - height[r];
            r--;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v2 = {4,2,0,3,2,5};
    int ans = JieShui(v);
    int ans2 = JieShui(v2);
    cout << ans << " " << ans2;
}