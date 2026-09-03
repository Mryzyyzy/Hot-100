#include<iostream>
#include<vector>

using namespace std;

void MoveZero(vector<int> &nums){
    int l = 0, r;
    int n = nums.size();
    while(l < n && nums[l] != 0) l++;
    r = l + 1;
    while(r < n){
        while(r < n - 1 && nums[r] == 0) r++;
        swap(nums[l], nums[r]);
        l++;
        r++;
    }

    
}

int main(){
    vector<int> v = {0,1,0,3,12};
    MoveZero(v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}