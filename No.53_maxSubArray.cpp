#include<iostream>
#include<vector>

using namespace std;

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