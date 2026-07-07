#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int findlong(vector<int> &nums){
    if(nums.size() == 0){
        return 0;
    }
    unordered_set<int> unset;
    for(int i = 0; i < nums.size(); i++){
        unset.insert(nums[i]);
    }
    int result = 0, temp = 1, i;
    for(auto it = unset.begin(); it != unset.end(); it++){
        if(unset.find(*it - 1) != unset.end()) continue;
        i = 1;
        while(unset.find(*it + i) != unset.end()){
            i++;
            temp++;
        }
        result = max(result, temp);

    }
    return result;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    vector<int> nums(n);
    int ii;
    for(int i = 0; i < n; i++){
        scanf("%d", &ii);
        nums[i] = ii;
    }
    
    printf("the answer is : %d", findlong(nums));

    return 0;
}