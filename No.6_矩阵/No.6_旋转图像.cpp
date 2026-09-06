/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

/**
 * 顺时针旋转 90 度，在数学上等价于两个简单的几何变换组合：
 * 1. 【转置 (Transpose)】：沿着主对角线（左上到右下）翻转。
 *    (row, col) 变成 (col, row)
 * 2. 【左右翻转 (Reflect)】：每一行内部进行逆序。
 *    (row, col) 变成 (row, n-1-col)
 * 
 * 这种方法比直接去算四个点的坐标交换（四连环交换）要直观得多，不容易写出 Bug。
 */

/*
思路：先沿主对角线转置矩阵，再反转每一行，等价于顺时针旋转 90 度。
关键数据结构：二维 vector 原地交换元素，不需要额外矩阵。
注意：转置只遍历对角线一侧；反转每一行时不要漏掉所有行。
*/

#include "MatrixTestUtils.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < m; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    solution.rotate(matrix1);
    cout << "case 1 output   = " << matrixToString(matrix1) << "\n";
    cout << "case 1 expected = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]\n\n";

    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    solution.rotate(matrix2);
    cout << "case 2 output   = " << matrixToString(matrix2) << "\n";
    cout << "case 2 expected = [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]\n\n";

    vector<vector<int>> matrix3 = {{1}};
    solution.rotate(matrix3);
    cout << "case 3 output   = " << matrixToString(matrix3) << "\n";
    cout << "case 3 expected = [[1]]\n";

    return 0;
}
