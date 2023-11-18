#include<vector>

using namespace std;

/*
2342. ��λ��������Ե�����

����һ���±�� 0 ��ʼ������ nums �������е�Ԫ�ض��� �� ����������ѡ�������±� i �� j��i != j������ nums[i] ����λ�� ��  nums[j] ����λ����ȡ�

�����ҳ����������������±� i �� j ���ҳ������� nums[i] + nums[j] ���Եõ��� ���ֵ ��
*/


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int mx[82]{}; // ���� 9 �� 9 ���
        for (int num : nums) {
            int s = 0; // num ����λ��
            for (int x = num; x; x /= 10) { // ö�� num ��ÿ����λ
                s += x % 10;
            }
            if (mx[s]) { // ˵�����Ҳ����λ�͵��� s ��Ԫ��
                ans = max(ans, mx[s] + num); // ���´𰸵����ֵ
            }
            mx[s] = max(mx[s], num); // ά����λ�͵��� s �����Ԫ��
        }
        return ans;
    }
};
