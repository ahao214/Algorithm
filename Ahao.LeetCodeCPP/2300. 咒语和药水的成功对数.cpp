#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
2300. �����ҩˮ�ĳɹ�����

������������������ spells �� potions �����ȷֱ�Ϊ n �� m ������ spells[i] ��ʾ�� i �����������ǿ�ȣ�potions[j] ��ʾ�� j ƿҩˮ������ǿ�ȡ�

ͬʱ����һ������ success ��һ�������ҩˮ������ǿ�� ��� ��� ���ڵ��� success ����ô������Ϊһ�� �ɹ� ����ϡ�

���㷵��һ������Ϊ n ���������� pairs������ pairs[i] ���ܸ��� i ������ɹ���ϵ� ҩˮ ��Ŀ��

*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& i : spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
            });
        sort(potions.begin(), potions.end(), [](int a, int b) {
            return a > b;
            });
        for (int i = 0, j = 0; i < spells.size(); ++i) {
            int p = idx[i];
            int v = spells[p];
            while (j < potions.size() && (long long)potions[j] * v >= success) {
                ++j;
            }
            res[p] = j;
        }
        return res;
    }
};
