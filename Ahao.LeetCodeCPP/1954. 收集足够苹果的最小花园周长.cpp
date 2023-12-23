#include<vector>

using namespace std;

/*
1954. �ռ��㹻ƻ������С��԰�ܳ�

����һ�������޶�ά�����ʾ�Ļ�԰��ÿһ�� �������괦����һ��ƻ�������������� (i, j) ����ƻ������ |i| + |j| ��ƻ����

�㽫������������������ (0, 0) ��һ�� ���������� ����ÿ���߶�������������֮һƽ�С�

����һ������ neededApples �����㷵�����ص� ��С�ܳ� ��ʹ�� ���� �� neededApples ��ƻ�������� ������߱�Ե�ϡ�

|x| ��ֵ����Ϊ��

��� x >= 0 ����ôֵΪ x
��� x < 0 ����ôֵΪ -x
*/

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n = 1;
        for (; 2 * n * (n + 1) * (2 * n + 1) < neededApples; ++n);
        return n * 8;
    }
};



class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 100000, ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (2 * mid * (mid + 1) * (mid * 2 + 1) >= neededApples) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans * 8;
    }
};
