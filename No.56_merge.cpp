#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool panduan(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> & nums){
    if(nums.size() <= 1){
        return nums;
    }
    sort(nums.begin(), nums.end(), panduan);
    vector<vector<int>> merge;
    for(int i = 0; i < nums.size(); i++){
        int l = nums[i][0], r = nums[i][1];
        if(merge.empty() || merge.back()[1] < l){
            merge.push_back({l, r});
        }else{
            merge.back()[1] = max(r, merge.back()[1]);
        }
    }
    return merge;
}

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(v);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

}