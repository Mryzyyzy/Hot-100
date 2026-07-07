#include<iostream>
#include<vector>
#include<deque>

using namespace std;

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