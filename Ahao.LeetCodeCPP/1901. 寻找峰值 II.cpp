#include<vector>

using namespace std;

/*
1901. Ѱ�ҷ�ֵ II

һ�� 2D �����е� ��ֵ ��ָ��Щ �ϸ���� �����ڸ���(�ϡ��¡�����)��Ԫ�ء�

����һ�� �� 0 ��ʼ��� �� m x n ���� mat �����������������ڸ��ӵ�ֵ�� ����ͬ ���ҳ� ����һ�� ��ֵ mat[i][j] �� ������λ�� [i,j] ��

����Լ������������ܱ߻�����һȦֵΪ -1 �ĸ��ӡ�

Ҫ�����д��ʱ�临�Ӷ�Ϊ O(m log(n)) �� O(n log(m)) ���㷨
*/



class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
            if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j]) {
                high = i - 1;
                continue;
            }
            if (i + 1 < m && mat[i][j] < mat[i + 1][j]) {
                low = i + 1;
                continue;
            }
            return { i, j };
        }
        return {}; // impossible
    }
};
