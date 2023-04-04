#include<vector>

using namespace std;


/*
2427. �����ӵ���Ŀ

�������������� a �� b ������ a �� b �� �� ���ӵ���Ŀ��

��� x ����ͬʱ���� a �� b ������Ϊ x �� a �� b ��һ�� ������ ��
*/


class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int x = 1; x <= min(a, b); ++x) {
            if (a % x == 0 && b % x == 0) {
                ++ans;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int commonFactors(int a, int b) {
        int c = gcd(a, b), ans = 0;
        for (int x = 1; x * x <= c; ++x) {
            if (c % x == 0) {
                ++ans;
                if (x * x != c) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

