#include "../leetcode.h"

///////////////////////////////////////////////////
// 73. 矩阵置零
// ------------------------------------------------
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
// ------------------------------------------------
// 示例：
// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]
// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/set-matrix-zeroes/
///////////////////////////////////////////////////

void setZeros(vector<vector<int>>& mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    // 创建标记数组，若该行/列含零元素，则为true，否则为false
    vector<int> row(rows), col(cols);

    // 遍历矩阵，记录含零的行号和列号
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!mat[i][j])
                row[i] = col[j] = true;
        }
    }

    // 在此遍历矩阵，对在“含零行”或“含零列”上的元素置零
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] || col[j])
                mat[i][j] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> mat = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeros(mat);
    display(mat);
    return 0;
}