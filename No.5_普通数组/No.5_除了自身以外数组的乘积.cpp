#include<iostream>
#include <vector>

using namespace std;

/*
    不能用除法，拆分乘积：除 nums [i] 之外的乘积 = i 左边所有数的乘积 × i 右边所有数乘积。
    cpro[i]：前缀乘积，存从开头到 i 位置元素的乘积；
    clro[i]：后缀乘积，存末尾向前的乘积；
    ans[i]=左侧全部乘积×右侧全部乘积
。
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> cpro(n, 0), clro(n, 0), ans(n, 0);
    cpro[0] = nums[0];
    for(int i = 1; i < n - 1; i++){
        cpro[i] = cpro[i - 1] * nums[i];
    }
    clro[0] = nums[n - 1];
    for(int i = 1; i < n - 1; i++){
        clro[i] = clro[i - 1] * nums[n - i - 1];
    }
    ans[0] = clro[n - 2];
    for(int i = 1; i < n - 1; i++){
        ans[i] = cpro[i - 1] * clro[n - i - 2];
    }
    ans[n - 1] = cpro[n - 2];
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4};
    vector<int> ans = productExceptSelf(v);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    v = {-1,1,0,-3,3};
    ans = productExceptSelf(v);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}