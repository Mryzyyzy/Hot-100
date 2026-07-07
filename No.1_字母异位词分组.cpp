#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<string>> groupanagrams(vector<string> &nums){
    unordered_map <string, vector<string>> unmap;
    for(int i = 0; i < nums.size(); i++){
        string s = nums[i];
        sort(s.begin(), s.end());
        unmap[s].push_back(nums[i]);
    }
    vector<vector<string>> result;
    for(auto it = unmap.begin(); it != unmap.end(); it++){
        result.push_back(it->second);
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<string> s(n);
    string ss;
    for(int i = 0; i < n; i++){
        cin >> ss;
        s[i] = ss;
    }
    vector<vector<string>> result = groupanagrams(s);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
            
        printf("\n");
    }

    return 0;
}