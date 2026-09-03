#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    三步反转：
        整体反转数组；
        反转前 k  个元素；
        反转剩下后面部分。
边界：k % nums.size()：消除循环轮转多余次数，避免重复旋转。
*/

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