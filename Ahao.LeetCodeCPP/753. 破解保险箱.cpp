#include<vector>
#include <string>
#include<unordered_set>

using namespace std;

/*
753. �ƽⱣ����

��һ����Ҫ������ܴ򿪵ı����䡣������ n λ��, �����ÿһλ�� k λ���� 0, 1, ..., k-1 �е�һ�� ��

����������������룬��������Զ���ס��� n λ���룬���ƥ�䣬���ܹ��򿪱����䡣

�ٸ����ӣ����������� "345"����������� "012345" ��������ֻ���������� 6 ���ַ�.

�뷵��һ���ܴ򿪱����������ַ�����
*/

class Solution {
private:
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        highest = pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
