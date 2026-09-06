#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
题目限制：数组含正负、0，无法使用定长 / 伸缩滑动窗口；暴力双循环超时，采用前缀和 + 哈希表 O (n) 解法。

前缀和公式推导：
设 pre[i] 为前 i 项和，人为规定 pre[0]=0；
子数组 [l, r] 和 K = pre[r+1] - pre[l]；
要求和为 k ：
    pre[l] = pre[r+1] - k。

哈希表功能：哈希表记录遍历途中每个前缀和出现的次数；遍历得到当前前缀和 pro，查表 pro-k 存在多少次，就新增多少个符合条件的子数组。

边界：初始化unmap[0] = 1;因为pro刚好等于k的时候，也算一次。
*/

int subarraySum(vector<int>& nums, int &k){
    unordered_map<int, int> unmap;
    int ans = 0, pro = 0;
    unmap[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        pro += nums[i];
        auto it = unmap.find(pro - k);
        if(it != unmap.end()){
            ans += it->second;
        }
        unmap[pro]++;
    }
    return ans;
}

int main(){
    vector<int> v = {1,1,1};
    int k = 2;
    int ans = subarraySum(v, k);
    cout << ans << endl;
    v = {1,2,3};
    k = 3;
    ans = subarraySum(v, k);
    cout << ans << endl;
}