#include<vector>
#include <algorithm>

using namespace std;

/*
1040. �ƶ�ʯ��ֱ������ II

��һ������ ���� �������ϣ��� i ��ʯ�ӵ�λ��Ϊ stones[i]�����һ��ʯ�ӵ�λ����С/�����ô��ʯ�ӱ����� �˵�ʯ�� ��

ÿ���غϣ�����Խ�һ�Ŷ˵�ʯ�������ƶ���һ��δռ�õ�λ�ã�ʹ�ø�ʯ�Ӳ�����һ�Ŷ˵�ʯ�ӡ�

ֵ��ע����ǣ����ʯ���� stones = [1,2,5] �������㽫 �޷� �ƶ�λ��λ�� 5 �Ķ˵�ʯ�ӣ���Ϊ���۽����ƶ����κ�λ�ã����� 0 �� 3������ʯ�Ӷ���Ȼ���Ƕ˵�ʯ�ӡ�

�����޷������κ��ƶ�ʱ��������Щʯ�ӵ�λ������ʱ����Ϸ������

Ҫʹ��Ϸ�����������ִ�е���С������ƶ������ֱ��Ƕ��٣� �Գ���Ϊ 2 ��������ʽ���ش𰸣�answer = [minimum_moves, maximum_moves] ��
*/

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        if (stones.back() - stones[0] + 1 == n) {
            return { 0, 0 };
        }
        int ma = max(stones[n - 2] - stones[0] + 1, stones[n - 1] - stones[1] + 1) - (n - 1);
        int mi = n;
        for (int i = 0, j = 0; i < n && j + 1 < n; ++i) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
                ++j;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                mi = min(mi, 2);
            }
            else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return { mi, ma };
    }
};
