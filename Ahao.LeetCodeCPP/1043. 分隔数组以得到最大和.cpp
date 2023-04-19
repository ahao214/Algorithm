#include<vector>

using namespace std;

/*
1043. �ָ������Եõ�����

����һ���������� arr�����㽫������ָ�Ϊ���� ��� Ϊ k ��һЩ�������������顣�ָ���ɺ�ÿ����������е�����ֵ�����Ϊ���������е����ֵ��

���ؽ�����ָ��任���ܹ��õ���Ԫ�����͡��������õ��Ĳ���������ȷ������һ�� 32 λ������
*/

class Solution {
public:
    using ll = long long;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                d[i] = max(d[i], d[j] + maxValue * (i - j));
                if (j > 0) {
                    maxValue = max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
};
