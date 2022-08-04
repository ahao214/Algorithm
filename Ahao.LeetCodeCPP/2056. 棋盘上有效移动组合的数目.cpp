#include<vector>
#include<string>

using namespace std;


/*
2056. ��������Ч�ƶ���ϵ���Ŀ
��һ�� 8 x 8 �����̣������� n �����ӣ����Ӱ���������������֣�������һ������Ϊ n ���ַ������� pieces ������ pieces[i] ��ʾ�� i �����ӵ����ͣ���������󣩡��������⣬������һ������Ϊ n �Ķ�ά�������� positions ������ positions[i] = [ri, ci] ��ʾ�� i �����������������ϵ�λ��Ϊ (ri, ci) �������±�� 1 ��ʼ��

������ÿ�����Ӷ������ƶ� ����һ�� ��ÿ�����ӵ��ƶ��У�����ѡ���ƶ��� ���� ��Ȼ��ѡ�� �ƶ��Ĳ��� ��ͬʱ��Ҫȷ���ƶ����������Ӳ����Ƶ���������ĵط��������谴�����¹����ƶ���

������ ˮƽ������ֱ �� (r, c) ���ŷ��� (r+1, c)��(r-1, c)��(r, c+1) ���� (r, c-1) �ƶ���
����� ˮƽ��ֱ����б�Խ� �� (r, c) ���ŷ��� (r+1, c)��(r-1, c)��(r, c+1)��(r, c-1)��(r+1, c+1)��(r+1, c-1)��(r-1, c+1)��(r-1, c-1) �ƶ���
����� б�Խ� �� (r, c) ���ŷ��� (r+1, c+1)��(r+1, c-1)��(r-1, c+1)��(r-1, c-1) �ƶ���
�ƶ���� �����������ӵ� �ƶ� ��ÿһ�룬ÿ�����Ӷ���������ѡ��ķ�����ǰ�ƶ� һ�� ��ֱ�����ǵ���Ŀ��λ�á��������Ӵ�ʱ�� 0 ��ʼ�ƶ��������ĳ��ʱ�̣��������߸�������ռ����ͬһ�����ӣ���ô����ƶ���� ����Ч ��

���㷵�� ��Ч �ƶ���ϵ���Ŀ��

ע�⣺

��ʼʱ���������������� �� ͬһ��λ�� ��
�п�����һ���ƶ�����У������Ӳ��ƶ���
����������� ֱ������ ������������һ��Ҫ����ռ�ݶԷ���λ�ã����Խ�������ͬһ���� ����λ�� ��
*/
class Solution {
public:
	int n;
	vector<string> pc;
	vector<vector<int>> pt;
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	vector<vector<int>> path;
	int ans = 0;
	int p[5][2];

	bool check() {
		for (int i = 0; i < n; i++) {
			p[i][0] = pt[i][0];
			p[i][1] = pt[i][1];
		}

		for (int i = 1; ; i++) {
			bool flag = false;
			for (int j = 0; j < n; j++) {
				int d = path[j][0], t = path[j][1];
				if (i <= t) {
					flag = true;
					p[j][0] += dx[d];
					p[j][1] += dy[d];
				}
			}
			if (!flag) break;

			for (int j = 0; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (p[j][0] == p[k][0] && p[j][1] == p[k][1])
						return false;
		}

		return true;
	}

	void dfs(int u) {
		if (u == n) {
			if (check()) ans++;
			return;
		}

		path.push_back({ 0, 0 });
		dfs(u + 1);
		path.pop_back();

		for (int i = 0; i < 8; i++) {
			string& s = pc[u];
			if (s == "rook" && i % 2) continue;
			if (s == "bishop" && i % 2 == 0) continue;
			int x = pt[u][0], y = pt[u][1];
			for (int j = 1; ; j++) {
				x += dx[i], y += dy[i];
				if (x < 1 || x > 8 || y < 1 || y > 8) break;
				path.push_back({ i, j });
				dfs(u + 1);
				path.pop_back();
			}
		}
	}

	int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
		pc = pieces, pt = positions;
		n = pc.size();
		dfs(0);
		return ans;
	}

};