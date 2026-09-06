/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。
请使用 原地 算法。
*/

/**
 * 1. 为什么不能直接遍历，看到 0 就把整行整列改了？
 *    - 因为你会把原本不是 0 的元素改成 0，导致后面遍历时产生“连锁反应”，全矩阵变 0。
 * 
 * 2. 空间优化的进阶：
 *    - [普通] O(M*N)：拷贝一个完整的备份矩阵。
 *    - [中等] O(M+N)：用两个数组 row[M], col[N] 记录哪一行/哪一列该变 0。
 *    - [最优] O(1)：我们直接白嫖“矩阵的第一行和第一列”来充当上面的 row 和 col 数组！
 * 
 * 3. 具体步骤：
 *    - a. 先记录第一行和第一列原本是否有 0 (用两个 bool 变量)。
 *    - b. 遍历剩下的部分 [1...M][1...N]，如果发现 matrix[i][j] == 0，
 *         就在 matrix[i][0] 和 matrix[0][j] 做标记（设为 0）。
 *    - c. 根据标记，将对应的行和列置零。
 *    - d. 最后，根据第 a 步的记录，处理第一行和第一列自己。
 */

/*
思路：先记录哪些行列需要置零，再统一修改矩阵，避免边遍历边改造成连锁影响。
一共需要5步：1. 扫描第一列，检查是否有 0 
            2. 扫描第一行，检查是否有 0
            3. 使用第一行和第一列作为“标记位”，扫描剩下的 [1...m-1][1...n-1]
            4. 根据第一行/列的标记位，执行置零
            5. 最后单独处理第一行和第一列（因为它们被用来存标记了）
关键数据结构：可以用 row/col 标记数组，进阶可用矩阵第一行第一列原地充当标记。
注意：第一行和第一列本身是否有 0 要提前单独记录。
*/

#include "MatrixTestUtils.hpp"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool fm = 0, fn = 0;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) fm = 1;
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0) fn = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(fm == 1){
            for(int i = 0; i< m; i++){
                matrix[i][0] = 0;
            }
        }
        if(fn == 1){
            for(int i = 0; i< n; i++){
                matrix[0][i] = 0;
            }
        }
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    solution.setZeroes(matrix1);
    cout << "case 1 output   = " << matrixToString(matrix1) << "\n";
    cout << "case 1 expected = [[1, 0, 1], [0, 0, 0], [1, 0, 1]]\n\n";

    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    solution.setZeroes(matrix2);
    cout << "case 2 output   = " << matrixToString(matrix2) << "\n";
    cout << "case 2 expected = [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]\n\n";

    vector<vector<int>> matrix3 = {
        {1},
        {0}
    };
    solution.setZeroes(matrix3);
    cout << "case 3 output   = " << matrixToString(matrix3) << "\n";
    cout << "case 3 expected = [[0], [0]]\n";

    return 0;
}
