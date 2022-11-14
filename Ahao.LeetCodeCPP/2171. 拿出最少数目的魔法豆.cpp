#include<vector>
#include <algorithm>

using namespace std;


/*
2171. �ó�������Ŀ��ħ����
����һ�� �� �������� beans ������ÿ��������ʾһ��������װ��ħ��������Ŀ��
�����ÿ�������� �ó� һЩ���ӣ�Ҳ���Բ��ó�����ʹ��ʣ�µ� �ǿ� �����У��� ���� ���� һ�� ħ�����Ĵ��ӣ�ħ��������Ŀ ��� ��һ��ħ�����Ӵ�����ȡ�����㲻�ܽ����ŵ��κ������Ĵ����С�

���㷵������Ҫ�ó�ħ������ ������Ŀ��
*/
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += beans[i];
        long long ans = sum - 1LL * n * beans[0], pre = 0;
        for (int i = 0; i < n; i++) {
            pre += beans[i];
            sum -= beans[i];
            if (i != n - 1)
                ans = min(ans, pre + sum - 1LL * (n - i - 1) * beans[i + 1]);
        }
        return ans;
    }
};