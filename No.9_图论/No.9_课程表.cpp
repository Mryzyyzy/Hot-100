/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1。
prerequisites[i] = [a, b] 表示想学习课程 a，必须先完成课程 b。
判断是否可能完成所有课程。
*/

#include "GraphTestUtils.hpp"
#include <queue>
#include <vector>

using namespace std;

/*
思路：把课程依赖看成有向图，用拓扑排序判断是否存在环。
关键数据结构：邻接表保存后续课程，入度数组记录每门课还差多少前置课。
注意：最后学完的课程数等于 numCourses 才说明无环。
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "case 1 input    = numCourses = 2, prerequisites = " << matrixToString(prerequisites1) << "\n";
    cout << "case 1 output   = " << boolToString(solution.canFinish(2, prerequisites1)) << "\n";
    cout << "case 1 expected = true\n\n";

    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "case 2 input    = numCourses = 2, prerequisites = " << matrixToString(prerequisites2) << "\n";
    cout << "case 2 output   = " << boolToString(solution.canFinish(2, prerequisites2)) << "\n";
    cout << "case 2 expected = false\n\n";

    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "case 3 input    = numCourses = 4, prerequisites = " << matrixToString(prerequisites3) << "\n";
    cout << "case 3 output   = " << boolToString(solution.canFinish(4, prerequisites3)) << "\n";
    cout << "case 3 expected = true\n";

    return 0;
}
