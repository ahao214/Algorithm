#include<vector>
#include <algorithm>

using namespace std;

/*
2517. ��е�������۶�

����һ������������ price ������ price[i] ��ʾ�� i ���ǹ��ļ۸������һ�������� k ��

�̵���� k �� ��ͬ �ǹ��������г��ۡ���е� ���۶� ����������������ǹ� �۸� ���Բ����Сֵ��

������е� ��� ���۶ȡ�
*/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int left = 0, right = price[n - 1] - price[0];
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(price, k, mid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }

    bool check(const vector<int>& price, int k, int tastiness) {
        int prev = INT_MIN >> 1;
        int cnt = 0;
        for (int p : price) {
            if (p - prev >= tastiness) {
                cnt++;
                prev = p;
            }
        }
        return cnt >= k;
    }
};

