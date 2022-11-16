#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
1655. �����ظ�����
����һ������Ϊ n ���������� nums ����������������� 50 ����ͬ��ֵ��ͬʱ���� m ���˿͵Ķ��� quantity �����У����� quantity[i] �ǵ� i λ�˿Ͷ�������Ŀ�������ж��Ƿ��ܽ� nums �е������������Щ�˿ͣ������㣺

�� i λ�˿� ǡ�� �� quantity[i] ��������
�� i λ�˿��õ����������� ��ͬ�� ��
ÿλ�˿Ͷ�������������Ҫ��
�������Է��� nums �е��������������Ҫ����ô�뷵�� true �����򷵻� false ��
*/
class Solution {
public:
	bool canDistribute(vector<int>& nums, vector<int>& quantity) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		vector<int> w(1);
		for (auto [x, y] : hash) w.push_back(y);
		int n = hash.size(), m = quantity.size();
		vector<int> s(1 << m);
		for (int i = 0; i < 1 << m; i++)
			for (int j = 0; j < m; j++)
				if (i >> j & 1)
					s[i] += quantity[j];

		vector<vector<int>> f(n + 1, vector<int>(1 << m));
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 1 << m; j++)
				if (f[i][j]) {
					f[i + 1][j] = 1;
					for (int t = j ^ ((1 << m) - 1), k = t; k; k = (k - 1) & t)
						if (s[k] <= w[i + 1])
							f[i + 1][j | k] = 1;
				}

		return f[n][(1 << m) - 1];
	}
};


