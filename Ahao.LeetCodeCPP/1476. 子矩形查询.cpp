#include<vector>

using namespace std;


/*
1476. 子矩形查询
请你实现一个类 SubrectangleQueries ，它的构造函数的参数是一个 rows x cols 的矩形（这里用整数矩阵表示），并支持以下两种操作：

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

用 newValue 更新以 (row1,col1) 为左上角且以 (row2,col2) 为右下角的子矩形。
2. getValue(int row, int col)

返回矩形中坐标 (row,col) 的当前值。
*/
class Solution {
public:
    vector<vector<int>> q;
    void SubrectangleQueries(vector<vector<int>>& rectangle) {
        q = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++)
            for (int j = col1; j <= col2; j++)
                q[i][j] = newValue;
    }

    int getValue(int row, int col) {
        return q[row][col];
    }
};


