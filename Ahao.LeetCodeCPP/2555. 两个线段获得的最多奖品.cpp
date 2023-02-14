#include<vector>

using namespace std;


/*
2555. �����߶λ�õ���ཱƷ

�� X�� ����һЩ��Ʒ������һ���������� prizePositions �������� �ǵݼ� ˳�����У����� prizePositions[i] �ǵ� i ����Ʒ��λ�á�������һ��λ�ÿ��ܻ��ж����Ʒ���ٸ���һ������ k ��

�����ѡ�������˵�Ϊ�������߶Ρ�ÿ���߶εĳ��ȶ������� k ������Ի��λ������һ�߶��ϵ����н�Ʒ�������߶ε������˵㣩��ע�⣬�����߶ο��ܻ����ཻ��

�ȷ�˵ k = 2 �������ѡ���߶� [1, 3] �� [2, 4] ������Ի������ 1 <= prizePositions[i] <= 3 ���� 2 <= prizePositions[i] <= 4 �����н�Ʒ i ��
���㷵����ѡ�����������߶ε�ǰ���£����Ի�õ� ��� ��Ʒ��Ŀ��
*/
class Solution {
public:
	int maximizeWin(vector<int>& prizePositions, int k) {
		int n = prizePositions.size();
		if (prizePositions[n - 1] - prizePositions[0] <= 2 * k)
			return prizePositions.size();

		vector<int> pre(n);
		vector<int> post(n);

		int i = 0;
		int mx = 0;

		for (int j = 0; j < n; j++) {
			while (prizePositions[j] - prizePositions[i] > k)
				i++;
			int len = j - i + 1;
			mx = max(mx, len);
			pre[j] = mx;
		}

		int j = n - 1;
		mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (prizePositions[j] - prizePositions[i] > k)
				j--;
			int len = j - i + 1;
			mx = max(mx, len);
			post[i] = mx;
		}
		int res = 0;
		for (int k = 0; k + 1 < n; k++) {
			res = max(res, pre[k] + post[k + 1]);
		}
		return res;
	}
};