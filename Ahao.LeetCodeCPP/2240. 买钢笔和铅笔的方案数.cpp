#include<vector>

using namespace std;


/*
2240. ��ֱʺ�Ǧ�ʵķ�����

����һ������ total ����ʾ��ӵ�е���Ǯ����ͬʱ������������ cost1 �� cost2 ���ֱ��ʾһ֧�ֱʺ�һ֧Ǧ�ʵļ۸�����Ի����㲿�ֻ���ȫ����Ǯ��ȥ��������Ŀ�����ֱʡ�

���㷵�ع���ֱʺ�Ǧ�ʵ� ��ͬ������Ŀ ��
*/


class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) {
            return waysToBuyPensPencils(total, cost2, cost1);
        }
        long res = 0, cnt = 0;
        while (cnt * cost1 <= total) {
            res += (total - cnt * cost1) / cost2 + 1;
            cnt++;
        }
        return res;
    }
};
