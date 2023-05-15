#include<vector>
#include <unordered_map>

using namespace std;

/*
1072. ���з�ת�õ����ֵ������

���� m x n ���� matrix ��

����Դ���ѡ�������������в���ת���ϵ� ÿ�� ��Ԫ�񡣣�����ת�󣬵�Ԫ���ֵ�� 0 ��� 1�����ߴ� 1 ��Ϊ 0 ����

���� ����һЩ��ת��������֮������ֵ����ȵ�������� ��
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            string s = string(n, '0');
            for (int j = 0; j < n; j++) {
                // ��� matrix[i][0] Ϊ 1����Ը���Ԫ�ؽ��з�ת
                s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
            }
            mp[s]++;
        }
        int res = 0;
        for (auto& [k, v] : mp) {
            res = max(res, v);
        }
        return res;
    }
};
