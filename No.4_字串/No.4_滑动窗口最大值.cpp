#include<iostream>
#include<vector>
#include<deque>

using namespace std;

/*
优方案：单调递减双端队列 deque，整体 O (n)。

队列里只存数组下标，维护规则：队列对应的数值从队头到队尾严格递减。
队头永远是当前窗口最大值的下标；
新元素入队前，把队尾所有 ≤ 当前值的下标全部弹出（它们不可能成为后续窗口最大值，直接舍弃）；
窗口右移后，检查队头下标是否滑出窗口左边界，超出则弹出队头。
*/

vector<int> maxSlidingWindow(vector<int> &nums, int &k){
    deque<int> que;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        while(!que.empty() && nums[i] >= nums[que.back()]){
            que.pop_back();
        }
        que.push_back(i);
    }
    ans.push_back(nums[que.front()]);
    for(int i = k; i < nums.size(); i++){
        while(!que.empty() && nums[i] >= nums[que.back()]){
            que.pop_back();
        }
        que.push_back(i);
        if(que.front() <= i - k){
            que.pop_front();
        }
        ans.push_back(nums[que.front()]);
    }
    return ans;
}

int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(v, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    v = {1};
    k = 1;
    ans = maxSlidingWindow(v, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}