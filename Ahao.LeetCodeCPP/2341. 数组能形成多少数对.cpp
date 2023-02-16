#include<vector>
#include <unordered_map>

using namespace std;

/*
2341. �������γɶ�������

����һ���±�� 0 ��ʼ���������� nums ����һ�������У������ִ�����²��裺

�� nums ѡ�� ���� ��ȵ� ����
�� nums ���Ƴ��������������γ�һ�� ����
������ nums �϶��ִ�д˲���ֱ���޷�����ִ�С�

����һ���±�� 0 ��ʼ������Ϊ 2 ���������� answer ��Ϊ�𰸣����� answer[0] ���γɵ�������Ŀ��answer[1] �Ƕ� nums ������ִ������������ʣ�µ�������Ŀ��
*/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, bool> cnt;
        int res = 0;
        for (int num : nums) {
            if (cnt.count(num)) {
                cnt[num] = !cnt[num];
            }
            else {
                cnt[num] = true;
            }
            if (!cnt[num]) {
                res++;
            }
        }
        return { res, (int)nums.size() - 2 * res };
    }
};

