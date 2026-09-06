/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/

/**
 * 矩阵的特点：每一行从左到右递增，每一列从上到下递增。
 * 
 * 2. 【上帝视角】：我们要找一个“矛盾点”，即一个方向变大、另一个方向变小的位置。
 *    那就是【右上角】 (0, n-1) 或 【左下角】 (m-1, 0)。
 * 
 * 3. 以【右上角】为起点：
 *    - 如果 current == target：找到了！
 *    - 如果 current > target：由于这一列下面的数都比当前值大，target 绝不可能在这一列。
 *      决策：列号减一 (col--)，往左移。
 *    - 如果 current < target：由于这一行左边的数都比当前值小，target 绝不可能在这一行。
 *      决策：行号加一 (row++)，往下移。
 */

/*
思路：从右上角开始搜索，当前值大于 target 就左移，小于 target 就下移。
关键数据结构：row 和 col 两个下标指针，用来在矩阵中逐步排除一整行或一整列。
注意：空矩阵要先处理；移动时保证 row、col 不越界。
*/

#include "MatrixTestUtils.hpp"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int row = 0, col = matrix[0].size() - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                col--;
            }else row++;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << boolalpha;

    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << "case 1 input    = " << matrixToString(matrix1) << ", target = 5\n";
    cout << "case 1 output   = " << solution.searchMatrix(matrix1, 5) << "\n";
    cout << "case 1 expected = true\n\n";

    vector<vector<int>> matrix2 = matrix1;
    cout << "case 2 input    = " << matrixToString(matrix2) << ", target = 20\n";
    cout << "case 2 output   = " << solution.searchMatrix(matrix2, 20) << "\n";
    cout << "case 2 expected = false\n\n";

    vector<vector<int>> matrix3 = {{-5}};
    cout << "case 3 input    = " << matrixToString(matrix3) << ", target = -5\n";
    cout << "case 3 output   = " << solution.searchMatrix(matrix3, -5) << "\n";
    cout << "case 3 expected = true\n";

    return 0;
}
