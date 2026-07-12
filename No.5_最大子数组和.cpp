#include<iostream>
#include<vector>

using namespace std;

/*
两个变量：
    “pro：以当前数字结尾的最大连续和”
    ans：全程记录最大结果
遍历每个数：
    如果前面的和加当前数，不如只取当前数，就丢掉前面，重新从当前数算起：
    pro = max(pro + nums[i], nums[i])
    每次更新全局最大值 ans
*/

int maxSubArray(vector<int> &nums){
    int pro = -999999, ans = -999999;
    for(int i = 0; i < nums.size(); i++){
        pro = max(pro + nums[i], nums[i]);
        ans = max(ans, pro);
    }
    return ans;
}

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(v) << endl;
    v = {5,4,-1,7,8};
    cout << maxSubArray(v) << endl;
}