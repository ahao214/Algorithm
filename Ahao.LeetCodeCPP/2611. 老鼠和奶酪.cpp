#include<vector>
#include <algorithm>

using namespace std;

/*
2611. ���������

����ֻ����� n �鲻ͬ���͵����ң�ÿ�����Ҷ�ֻ�ܱ�����һֻ����Ե���

�±�Ϊ i �������ұ��Ե��ĵ÷�Ϊ��

�����һֻ����Ե�����÷�Ϊ reward1[i] ��
����ڶ�ֻ����Ե�����÷�Ϊ reward2[i] ��
����һ������������ reward1 ��һ������������ reward2 ����һ���Ǹ����� k ��

���㷵�ص�һֻ����ǡ�óԵ� k �����ҵ�����£���� �÷�Ϊ���١�
*/

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0;
        int n = reward1.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++) {
            ans += reward2[i];
            diffs[i] = reward1[i] - reward2[i];
        }
        sort(diffs.begin(), diffs.end());
        for (int i = 1; i <= k; i++) {
            ans += diffs[n - i];
        }
        return ans;
    }
};
