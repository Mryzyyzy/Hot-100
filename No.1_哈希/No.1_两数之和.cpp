#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twosum(vector<int> &nums, int target){
    unordered_map<int , int> unmap;
    for(int i = 0; i < nums.size(); i ++){
        auto it = unmap.find(target - nums[i]);
        if(it != unmap.end()){
            return {i, it->second};
        }
        unmap[nums[i]] = i;
    }
    return {-1, -1};
}

int main(){
    int n;
    int target;
    scanf("%d", &n);
    scanf("%d", &target);
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    vector<int> result = twosum(nums, target);

    printf("%d %d\n", result[0], result[1]);

    return 0;

}




// #include<iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// // 两数之和就是利用unordered_map的查找为O(1).
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map <int, int> unmap; // 键来存数组的值，值来存数组的下标
//         for(int i = 0; i < nums.size(); i++){
//             auto it = unmap.find(target - nums[i]); // find 函数查找的是键
//             if(it != unmap.end()){
//                 return {i, it->second};
//             }
//             unmap[nums[i]] = i;
//         }
//         return {-1,-1};
//     }
// };

// int main(){
//     int n, target, num;
//     scanf("%d", &n);
//     scanf("%d", &target);
//     vector<int> v(n);
//     for(int i = 0; i < n; i++){
//         scanf("%d", &v[i]);
//         //v.push_back(num);
//     }
//     Solution s;
//     vector<int> vv =s.twoSum(v, target);
//     for(int i = 0; i < vv.size(); i++){
//       printf("%d ", vv[i]);
//     }

// }


/*
// 定义 int:string 哈希表
    unordered_map<int, string> fruit;

    // 插入
    fruit[1] = "苹果";
    fruit.insert({2, "香蕉"});
    fruit.emplace(3, "葡萄");

    // 修改
    fruit[1] = "红富士苹果";

    // 查找
    int key = 2;
    auto it = fruit.find(key);
    if (it != fruit.end()) {
        cout << "key=" << it->first << ", value=" << it->second << endl;
    }

    // 遍历
    cout << "\n全部键值对：" << endl;
    for (const auto& item : fruit) {
        cout << item.first << " -> " << item.second << endl;
    }

    // 删除
    fruit.erase(3);
    cout << "\n删除key3后size：" << fruit.size() << endl;

    // 判断存在
    if (fruit.count(1)) cout << "key1存在\n";

*/
