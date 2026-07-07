#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> & nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]);
        int l = i + 1, r = nums.size() - 1;
        while(l <  r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0){
                ans.push_back({nums[i], nums[l], nums[r]});
                while(l < r && nums[l] == nums[l + 1]) l++; 
                while(l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            }else if(sum > 0) r--;
            else l++;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = ThreeSum(v);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}