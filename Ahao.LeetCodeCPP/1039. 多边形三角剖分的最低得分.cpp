#include<vector>
#include <unordered_map>
#include <functional>

using namespace std;

/*
1039. ����������ʷֵ���͵÷�

����һ��͹�� n ���Σ���ÿ�����㶼��һ������ֵ������һ���������� values ������ values[i] �ǵ� i �������ֵ���� ˳ʱ��˳�� ����

���轫����� �ʷ� Ϊ n - 2 �������Ρ�����ÿ�������Σ��������ε�ֵ�Ƕ����ǵĳ˻��������ʷֵķ����ǽ��������ʷֺ����� n - 2 �������ε�ֵ֮�͡�

���� ����ν��������ʷֺ���Եõ�����ͷ� ��
*/


class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};
