#include<vector>

using namespace std;

/*
2596. �����ʿѲ�ӷ���

��ʿ��һ�� n x n ��������Ѳ�ӡ�����Ч��Ѳ�ӷ����У���ʿ������̵� ���Ͻ� ���������ҷ��������ϵ�ÿ������ ǡ��һ�� ��

����һ�� n x n ���������� grid ���ɷ�Χ [0, n * n - 1] �ڵĲ�ͬ������ɣ����� grid[row][col] ��ʾ��Ԫ�� (row, col) ����ʿ���ʵĵ� grid[row][col] ����Ԫ����ʿ���ж��Ǵ��±� 0 ��ʼ�ġ�

��� grid ��ʾ����ʿ����ЧѲ�ӷ��������� true�����򷵻� false��

ע�⣬��ʿ�ж�ʱ���Դ�ֱ�ƶ�����������ˮƽ�ƶ�һ�����ӣ���ˮƽ�ƶ����������Ҵ�ֱ�ƶ�һ�����ӡ���ͼչʾ����ʿ��ĳ�����ӳ������ܵİ����ж�·�ߡ�
*/

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        vector<array<int, 2>> indices(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                indices[grid[i][j]] = { i, j };
            }
        }
        for (int i = 1; i < indices.size(); i++) {
            int dx = abs(indices[i][0] - indices[i - 1][0]);
            int dy = abs(indices[i][1] - indices[i - 1][1]);
            if (dx * dy != 2) {
                return false;
            }
        }
        return true;
    }
};
