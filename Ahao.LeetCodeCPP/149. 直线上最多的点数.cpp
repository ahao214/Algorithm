#include<vector>
#include <unordered_map>
#include <string>

using namespace std;


/*
149. ֱ�������ĵ���

����һ������ points ������ points[i] = [xi, yi] ��ʾ X-Y ƽ���ϵ�һ���㡣������ж��ٸ�����ͬһ��ֱ���ϡ�
*/
class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int len = points.size();
		// �����������
		if (len < 3) {
			return len;
		}
		int maxNum = 2;
		// ����ÿ������
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				// ͳ��б����ȸ���
				int count = 2;
				long long dx = points[i][0] - points[j][0];
				long long dy = points[i][1] - points[j][1];
				// ��������Ƚ�
				for (int k = j + 1; k < len; k++) {
					// ���б�����
					if (dx * (points[i][1] - points[k][1]) == dy * (points[i][0] - points[k][0])) {
						count++;
					}
				}
				maxNum = max(maxNum, count);
				if (maxNum > len / 2) return maxNum;
			}
		}
		return maxNum;
	}
};



class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			unordered_map<string, int> h;
			int cnt = 0;
			for (int j = i + 1; j < n; j++)
			{
				int x1 = points[i][0], y1 = points[i][1];
				int x2 = points[j][0], y2 = points[j][1];

				string key = calc(x1, y1, x2, y2);
				h[key]++;
				cnt = max(cnt, h[key]);
			}
			res = max(res, cnt + 1);
		}
		return res;
	}

	string calc(int x1, int y1, int x2, int y2)
	{
		int dx = abs(x1 - x2), dy = abs(y1 - y2);
		int k = gcd(dx, dy);
		string key = to_string(dy / k) + "_" + to_string(dx / k);
		if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2))
			return "-" + key;
		return key;
	}

	//�����Լ��
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
};