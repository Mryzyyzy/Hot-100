#include<iostream>
#include<vector>

using namespace std;

int Maxarea(vector<int> &height){
    int l = 0, r = height.size() - 1;
    int lm = 0, rm = 0, ans = 0, temp = 0;
    ans = min(height[l], height[r]) * (r - l);
    while(l < r){
        lm = max(lm, height[l]);
        rm = max(rm, height[r]);
        if(lm < rm){
            while(l < r && height[l] <= lm) l++;
        }else{
            while(l < r && height[r] <= rm) r--;
        }
        temp = min(height[l], height[r]) * (r - l);
        ans = max(ans, temp);
    }
    return ans;
}

int main(){
    vector<int> v ={1,8,6,2,5,4,8,3,7};
    int s = Maxarea(v);
    cout << s ; 
}