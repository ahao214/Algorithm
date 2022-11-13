#include<vector>

using namespace std;


/*
2172. �����������
����һ������Ϊ n ���������� nums ��һ������ numSlots ������2 * numSlots >= n ���ܹ��� numSlots �����ӣ����Ϊ 1 �� numSlots ��

����Ҫ������ n �������ֵ���Щ�����У���ÿ������ ���� �� 2 ��������һ�ַ��䷽���� ��� ����Ϊÿ���������������ӱ�ŵ� ��λ������ ���֮�͡�

�ȷ�˵�������� [1, 3] �������� 1 �У�[4, 6] �������� 2 �У�������������Ϊ (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4 ��
���㷵�ؽ� nums ������������ numSlots �������е������͡�
*/
class Solution {

    int f[20001], b[10];

public:
    int maximumANDSum(vector<int>& a, int m) {
        int n = a.size();
        memset(f, 0, sizeof(f));
        int l = 1;
        for (int i = 1; i <= m; i++)
            l *= 3;

        for (int i = 0; i < n; i++) {
            for (int j = l - 1; j >= 0; --j) {
                for (int k = 1, l = j; k <= m; k++, l /= 3)
                    b[k] = l % 3;
                int x = 1;
                for (int k = 1; k <= m; k++, x *= 3)
                    if (b[k] != 2) {
                        f[j + x] = max(f[j + x], f[j] + (a[i] & k));
                    }
            }
        }
        return f[l - 1];
    }
};
