#include <cmath>
using namespace std;


/*
479. ���������˻�
*/

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; --left) { // ö�ٻ���������벿��
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10; // ��ת��벿�ֵ�������ĩβ����������� p
            }
            for (long x = upper; x * x >= p; --x) {
                if (p % x == 0) { // x �� p ������
                    return p % 1337;
                }
            }
        }
    }
};




class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        for (int half = pow(10, n) - 1; ; half--) { // 1��ö�ٻ�������벿��half
            // 2�����������p
            long p = half;
            for (int i = half; i > 0; i /= 10) {
                p = p * 10 + i % 10;
            }
            // 3���жϸû�λ���ܷ�����
            for (long i = pow(10, n) - 1; i * i >= p; i--) {
                if (p % i == 0) {
                    return p % 1337;
                }
            }
        }
    }
};