#include<vector>
#include<string>
#include <numeric>
#include <algorithm>

using namespace std;


/*
2418. ���������

����һ���ַ������� names ����һ���� ������ͬ ����������ɵ����� heights ����������ĳ��Ⱦ�Ϊ n ��

����ÿ���±� i��names[i] �� heights[i] ��ʾ�� i ���˵����ֺ���ߡ�

�밴��� ���� ˳�򷵻ض�Ӧ���������� names ��
*/


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int x, int y) {
            return heights[x] > heights[y];
            });
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = names[indices[i]];
        }
        return res;
    }
};
