#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/*
646. �������

����һ���� n ��������ɵ��������� pairs ������ pairs[i] = [lefti, righti] �� lefti < righti ��

���ڣ����Ƕ���һ�� ���� ��ϵ�����ҽ��� b < c ʱ������ p2 = [c, d] �ſ��Ը��� p1 = [a, b] ���档������������ʽ������ ������ ��

�ҳ��������ܹ��γɵ� ��������ĳ��� ��

�㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣
*/
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
			});

		int res = 1, ed = pairs[0][1];
		for (auto& p : pairs)
		{
			if (p[0] > ed)
			{
				res++;
				ed = p[1];
			}
		}
		return res;
	}
};