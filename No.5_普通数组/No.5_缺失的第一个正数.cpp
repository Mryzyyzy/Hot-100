#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    根据抽屉原理：最小缺失正整数只会是 1∼n+1，小于等于 0 或大于 n 的值无需考虑。
    原地哈希：将区间[1,n]内的数字x交换到下标x−1处；遇到重复数字结束交换，避免死循环。
    遍历数组，第一个满足 nums[i]=i+1，返回 i+1；全部匹配则返回 n+1。
边界：注意：用 while 而不是 if，因为换过来一个新数后还需要继续检查
*/

int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] >= 1 && nums[i] <= n){
            int to = nums[i] - 1;
            if(nums[to] == nums[i]) break;
            swap(nums[to], nums[i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] != i + 1) return i + 1;
    }
    return n + 1;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums[i] = num;
    }
    int ans = firstMissingPositive(nums);
    cout << "ans = " << ans;
}
