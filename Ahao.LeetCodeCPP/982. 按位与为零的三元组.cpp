#include<vector>

using namespace std;


/*
982. ��λ��Ϊ�����Ԫ��

����һ���������� nums ���������� ��λ����Ԫ�� ����Ŀ��

��λ����Ԫ�� �����±� (i, j, k) ��ɵ���Ԫ�飬����������ȫ��������

0 <= i < nums.length
0 <= j < nums.length
0 <= k < nums.length
nums[i] & nums[j] & nums[k] == 0 ������ & ��ʾ��λ���������
*/


//����һ��ö��
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x : nums) {
            for (int y : nums) {
                ++cnt[x & y];
            }
        }
        int ans = 0;
        for (int x : nums) {
            for (int mask = 0; mask < (1 << 16); ++mask) {
                if ((x & mask) == 0) {
                    ans += cnt[mask];
                }
            }
        }
        return ans;
    }
};
