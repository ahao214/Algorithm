#include<vector>
#include<algorithm>

using namespace std;


/*
2463. ��С�ƶ��ܾ���
X ������һЩ�����˺͹���������һ���������� robot ������ robot[i] �ǵ� i �������˵�λ�á��ٸ���һ����ά�������� factory ������ factory[j] = [positionj, limitj] ����ʾ�� j ��������λ���� positionj ���ҵ� j ���������������� limitj �������ˡ�

ÿ�����������ڵ�λ�� ������ͬ ��ÿ���������ڵ�λ��Ҳ ������ͬ ��ע��һ�������˿���һ��ʼ��һ�������� ��ͬ��λ�� ��

���л�����һ��ʼ���ǻ��ģ����ǻ������趨�ķ���һֱ�ƶ����趨�ķ���Ҫô�� X ���������Ҫô�� X ��ĸ����򡣵�һ�������˾���һ��û�ﵽ���޵Ĺ���ʱ�����������ά����������ˣ��һ�����ֹͣ�ƶ���

�κ�ʱ�̣��㶼�������� ���� �����˵��ƶ��������Ŀ������С�����л������ܵ��ƶ����롣

���㷵�����л������ƶ�����С�ܾ��롣�������ݱ�֤���л����˶����Ա�ά�ޡ�

ע�⣺

���л������ƶ��ٶ���ͬ��
��������������ƶ�������ͬ��������Զ������ײ��
�������������ӭ������������Ҳ������ײ�����Ǳ˴�֮�����������
���һ�������˾�����һ���Ѿ��ﵽ���޵Ĺ����������˻ᵱ�����������ڣ������ƶ���
�����˴�λ�� x ��λ�� y ���ƶ�����Ϊ |y - x| ��
*/
using LL = long long;
class Solution {
	LL dist[101][101][101];
	LL dp[101][101];
public:
	long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
		int m = robot.size();
		int n = factory.size();

		sort(robot.begin(), robot.end());
		sort(factory.begin(), factory.end());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				LL sum = 0;
				for (int k = j; k < m; k++) {
					sum += abs(factory[i][0] - robot[k]);
					dist[i][j][k] = sum;
				}
			}
		}

		dp[0][0] = 0;
		for (int j = 1; j <= m; j++) {
			if (j <= factory[0][1]) {
				dp[0][j] = dist[0][0][j - 1];
			}
			else {
				dp[0][j] = LLONG_MAX / 2;
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				for (int k = 1; k <= min(factory[i][1], j); k++) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + dist[i][j - k][j - 1]);
				}
			}
		}
		return dp[n - 1][m];
	}
};
