#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
2136. ȫ������������һ��

���� n ö�������ӡ�ÿö���ӱ��������£����ܿ�ʼ������������������Ҫʱ�䣬���ӵ�����Ҳ����ˡ����������±�� 0 ��ʼ���������� plantTime �� growTime ��ÿ������ĳ��ȶ��� n ��

plantTime[i] �� ���� �� i ö��������� �������� ��ÿ�죬��ֻ��Ϊ����ĳһö���Ӷ����������� �������춼����ͬһö���ӣ��������Ӳ��ֱ������㹤���������ﵽ plantTime[i] ֮�������ɡ�
growTime[i] �ǵ� i ö������ȫ���º���������� �������� ���������������һ�� ֮�� �����Ὺ��������Զ ���� ��
�ӵ� 0 ��ʼ������԰� ���� ˳�������ӡ�

�����������Ӷ������� ���� һ���ǵڼ��졣
*/



class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return growTime[i] > growTime[j];
            });
        int prev = 0, ans = 0;
        for (int i : id) {
            ans = max(ans, prev + plantTime[i] + growTime[i]);
            prev += plantTime[i];
        }
        return ans;
    }
};
