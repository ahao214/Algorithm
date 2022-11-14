#include<vector>
#include <algorithm>

using namespace std;



/*
1508. ������������������
����һ������ nums �������� n ��������������Ҫ�������зǿ�����������ĺͣ��������ǰ��������򣬵õ�һ���µİ��� n * (n + 1) / 2 �����ֵ����顣

���㷵�������������±�Ϊ left �� right ���±�� 1 ��ʼ�����������ֺͣ��������Ҷ˵㣩�����ڴ𰸿��ܴܺ����㽫���� 10^9 + 7 ȡģ�󷵻ء�
*/
typedef long long LL;
typedef pair<int, LL> PIL;
const int MOD = 1e9 + 7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MODULO = 1000000007;
        int sumsLength = n * (n + 1) / 2;
        auto sums = vector <int>(sumsLength);
        int index = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums[index++] = sum;
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % MODULO;
        }
        return ans;
    }
};