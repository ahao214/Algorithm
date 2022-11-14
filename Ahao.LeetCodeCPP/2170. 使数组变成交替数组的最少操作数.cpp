#include<vector>

using namespace std;


/*
2170. ʹ�����ɽ�����������ٲ�����
����һ���±�� 0 ��ʼ������ nums ���������� n ����������ɡ�

����������������������� nums ��һ�� �������� ��

nums[i - 2] == nums[i] ������ 2 <= i <= n - 1 ��
nums[i - 1] != nums[i] ������ 1 <= i <= n - 1 ��
��һ�� ���� �У������ѡ���±� i ���� nums[i] ���� Ϊ ��һ ��������

����ʹ�����ɽ�������� ���ٲ����� ��
*/
class Solution {

    int a[100001], b[100002], c[100002], d[100002];
public:
    int minimumOperations(vector<int>& nums) {
        memset(a, 0, sizeof(a));
        int n = nums.size(), m = 0;
        for (int i = 0; i < n; i += 2)
            ++a[nums[i]], ++m;
        int m1 = 0;
        memset(b, 0, sizeof(a));
        for (int i = 1; i < n; i += 2)
            ++b[nums[i]], ++m1;
        for (int i = 1; i <= 100000; i++)
            c[i] = max(c[i - 1], b[i]);
        for (int i = 100000; i; --i)
            d[i] = max(d[i + 1], b[i]);
        int ans = 1 << 30;
        for (int i = 1; i <= 100000; i++)
            ans = min(ans, m - a[i] + m1 - max(c[i - 1], d[i + 1]));
        return ans;
    }
};
