#include<vector>
#include <algorithm>

using namespace std;

/*
2037. ʹÿλѧ��������λ�������ƶ�����

һ���������� n ����λ�� n ��ѧ����������һ�������ʾ������һ������Ϊ n ������ seats ������ seats[i] �ǵ� i ����λ��λ�á�ͬʱ����һ������Ϊ n ������ students ������ students[j] �ǵ� j λѧ����λ�á�

�����ִ�����²�������Σ�

���ӻ��߼��ٵ� i λѧ����λ�ã�ÿ�α仯��Ϊ 1 ��Ҳ���ǽ��� i λѧ����λ�� x �ƶ��� x + 1 ���� x - 1��
���㷵��ʹ����ѧ��������λ���� �����ƶ����� ����ȷ��û����λѧ������λ��ͬ��

��ע�⣬��ʼʱ�п����ж����λ���߶�λѧ���� ͬһ λ�á�
*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int res = 0;
        for (int i = 0; i < seats.size(); i++) {
            res += abs(seats[i] - students[i]);
        }
        return res;
    }
};
