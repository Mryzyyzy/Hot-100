#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotate(vector<int> & nums, int &k){
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k % nums.size());
    reverse(nums.begin() + k % nums.size(), nums.end());
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(v, k);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

}