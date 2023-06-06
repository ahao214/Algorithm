#include<vector>
#include <map>

using namespace std;


/*
2352. ������ж�

����һ���±�� 0 ��ʼ����СΪ n x n ���������� grid ���������� Ri �к� Cj ����ȵ����ж� (Ri, Cj) ����Ŀ��

����к�������ͬ��˳�������ͬ��Ԫ�أ�����ȵ����飩������Ϊ��������ȵġ�
*/


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (equal(row, col, grid)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool equal(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (grid[row][i] != grid[i][col]) {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for (auto row : grid) {
            cnt[row]++;
        }

        int res = 0;
        for (int j = 0; j < n; j++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                arr.emplace_back(grid[i][j]);
            }
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }
        return res;
    }
};
