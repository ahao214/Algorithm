#include<vector>
#include <algorithm>

using namespace std;

/*
891. �����п��֮��

����

һ�����е� ��� ����Ϊ�����������Ԫ�غ���СԪ�صĲ�ֵ��

����һ���������� nums ������ nums �����зǿ� ������ �� ���֮�� �����ڴ𰸿��ܷǳ����뷵�ض� 109 + 7 ȡ�� ��Ľ����

������ ����Ϊ��һ��������ɾ��һЩ�����߲�ɾ����Ԫ�أ������ı�ʣ��Ԫ�ص�˳��õ������顣���磬[3,6,2,7] �������� [0,3,1,6,2,2,7] ��һ�������С�
*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, mod = 1e9 + 7;
        long long x = nums[0], y = 2;
        for (int j = 1; j < nums.size(); j++) {
            res = (res + nums[j] * (y - 1) - x) % mod;
            x = (x * 2 + nums[j]) % mod;
            y = y * 2 % mod;
        }
        return (res + mod) % mod;
    }
};




class Solution {
public:
    int mod = 1000000007;
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, p = 1, sum = 0;
        for (auto x : nums)
        {
            res = (res + x * (p - 1) - sum) % mod;
            sum = (sum * 2 + x) % mod;
            p = p * 2 % mod;
        }
        return (res + mod) % mod;
    }
};