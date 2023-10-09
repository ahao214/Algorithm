#include<vector>
#include <string>
#include <algorithm>

using namespace std;


/*
2731. �ƶ�������

��һЩ�����˷ֲ���һ�����޳��������ϣ����ǳ�ʼ������һ���±�� 0 ��ʼ���������� nums ��ʾ��������������´�����ʱ��������ÿ����һ��λ���ٶȿ�ʼ�ƶ���

����һ���ַ��� s ��ÿ���ַ���˳��ֱ��ʾÿ���������ƶ��ķ���'L' ��ʾ�����������������ĸ������ƶ���'R' ��ʾ���������һ���������������ƶ���

��������������ײʱ�����ǿ�ʼ����ԭ���෴�ķ����ƶ���

���㷵��ָ���ظ�ִ�� d ������л�����֮����������֮�͡����ڴ𰸿��ܴܺ����㽫�𰸶� 109 + 7 ȡ��󷵻ء�
*/

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                pos[i] = (long long)nums[i] - d;
            }
            else {
                pos[i] = (long long)nums[i] + d;
            }
        }
        sort(pos.begin(), pos.end());
        long long res = 0;
        for (int i = 1; i < n; i++) {
            res += 1ll * (pos[i] - pos[i - 1]) * i % mod * (n - i) % mod;
            res %= mod;
        }
        return res;
    }
};
