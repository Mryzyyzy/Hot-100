#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
1、先按每个区间左端点从小到大排序。

2. 第二步：逐个遍历合并
    用一个新数组存结果：
    结果为空，直接把当前区间放进去；
    拿结果里最后一个区间的右端点，和当前区间左端点对比：
    结果最后区间右端 < 当前左端点：无重叠，直接新增当前区间；
    否则区间重叠，更新结果最后区间的右端为两个右端里更大的数。
*/

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