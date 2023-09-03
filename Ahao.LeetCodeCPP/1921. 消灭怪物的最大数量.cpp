#include<vector>
#include <algorithm>

using namespace std;


/*
1921. ���������������

��������һ�������Ϸ������Ϸ������Ҫ�����������ܹ�����Ϯ������һ�� �±�� 0 ��ʼ �ҳ���Ϊ n ���������� dist ������ dist[i] �ǵ� i ����������е� ��ʼ���루��λ���ף���

������ �㶨 ���ٶ�������С�����һ������Ϊ n ���������� speed ��ʾÿ��������ٶȣ����� speed[i] �ǵ� i ��������ٶȣ���λ����/�֣���

����� �� 0 ���� ʱ��ʼ�ƶ�������һ�������������� ѡ�� ��ÿһ���ӵĿ�ʼʱʹ�ã������� 0 ���ӡ��������޷���һ���ӵ��м�ʹ�����������������������ˣ�һ�ο���������һ�����ŵĹ��

һ����һ���ﵽ����У����������ⳡ��Ϸ�����ĳ������ ǡ ��ĳһ���ӿ�ʼʱ������У���ᱻ��Ϊ ��� ��Ϸ���������ʹ������֮ǰ����Ϸ�ͻ������

�������������Ϸǰ��������Ĺ���� ��� �������������������й��ﵽ�����ǰ������ȫ�����𣬷���  n ��
*/



class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrivalTimes(n);
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1;
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= i) {
                return i;
            }
        }
        return n;
    }
};
