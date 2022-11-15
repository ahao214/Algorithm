#include<vector>

using namespace std;


/*
1476. �Ӿ��β�ѯ
����ʵ��һ���� SubrectangleQueries �����Ĺ��캯���Ĳ�����һ�� rows x cols �ľ��Σ����������������ʾ������֧���������ֲ�����

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

�� newValue ������ (row1,col1) Ϊ���Ͻ����� (row2,col2) Ϊ���½ǵ��Ӿ��Ρ�
2. getValue(int row, int col)

���ؾ��������� (row,col) �ĵ�ǰֵ��
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


