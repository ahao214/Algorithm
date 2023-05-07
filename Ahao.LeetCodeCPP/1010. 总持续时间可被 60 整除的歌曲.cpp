#include<vector>

using namespace std;


/*
1010. �ܳ���ʱ��ɱ� 60 �����ĸ���

�ڸ����б��У��� i �׸����ĳ���ʱ��Ϊ time[i] �롣

�������ܳ���ʱ�䣨����Ϊ��λ���ɱ� 60 �����ĸ����Ե���������ʽ�ϣ�����ϣ���±����� i �� j ����  i < j ���� (time[i] + time[j]) % 60 == 0��
*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (int t : time) {
            cnt[t % 60]++;
        }
        long long res = 0;
        for (int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        return (int)res;
    }
};
