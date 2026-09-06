/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

/**
 * 1. 定义四个边界：上(top)、下(bottom)、左(left)、右(right)。
 * 2. 按照“左到右 -> 上到下 -> 右到左 -> 下到上”的循环顺序进行遍历。
 * 3. 【关键逻辑】：每走完一个方向，对应的边界就要向内收缩一格，并立即判断是否已经越界。
 *    - 从左向右走完一行：top++。如果 top > bottom，说明全部走完，跳出循环。
 *    - 从上向下走完一列：right--。如果 left > right，跳出。
 *    - 从右向左走完一行：bottom--。如果 top > bottom，跳出。
 *    - 从下向上走完一列：left++。如果 left > right，跳出。
 */

/*
思路：维护上下左右四个边界，按右、下、左、上的顺序一圈圈向内遍历。
关键数据结构：top/bottom/left/right 四个边界变量，用来限定当前还没遍历的矩阵范围。
注意：每走完一个方向就收缩对应边界，并及时判断是否越界。
*/

#include "MatrixTestUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, buttom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        
        while(top <= buttom){
            for(int i = left; i <=right; i++){
                ans.push_back(matrix[top][i]);
            }
            if(++top > buttom) break;

            for(int i = top; i <= buttom; i++){
                ans.push_back(matrix[i][right]);
            }
            if(--right < left) break;

            for(int i = right; i >= left; i--){
                ans.push_back(matrix[buttom][i]);
            }
            if(--buttom < top) break;

            for(int i = buttom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "case 1 input    = " << matrixToString(matrix1) << "\n";
    cout << "case 1 output   = " << vectorToString(solution.spiralOrder(matrix1)) << "\n";
    cout << "case 1 expected = [1, 2, 3, 6, 9, 8, 7, 4, 5]\n\n";

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "case 2 input    = " << matrixToString(matrix2) << "\n";
    cout << "case 2 output   = " << vectorToString(solution.spiralOrder(matrix2)) << "\n";
    cout << "case 2 expected = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]\n\n";

    vector<vector<int>> matrix3 = {{1}};
    cout << "case 3 input    = " << matrixToString(matrix3) << "\n";
    cout << "case 3 output   = " << vectorToString(solution.spiralOrder(matrix3)) << "\n";
    cout << "case 3 expected = [1]\n";

    return 0;
}
