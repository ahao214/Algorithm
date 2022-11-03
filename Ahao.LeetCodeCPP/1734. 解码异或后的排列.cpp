#include<vector>

using namespace std;



/*
1734. �������������
����һ���������� perm ������ǰ n �������������У��� n �Ǹ� ���� ��

�������ܳ���һ������Ϊ n - 1 ���������� encoded ������ encoded[i] = perm[i] XOR perm[i + 1] ���ȷ�˵����� perm = [1,3,2] ����ô encoded = [2,1] ��

���� encoded ���飬���㷵��ԭʼ���� perm ����Ŀ��֤�𰸴�����Ψһ��
*/
class Solution {
public:
	vector<int> decode(vector<int>& encoded) {
		int sum = 0;
		int n = encoded.size() + 1;
		for (int i = 1; i <= n; i++)
			sum ^= i;
		for (int i = encoded.size() - 1; i >= 0; i -= 2)
			sum ^= encoded[i];
		vector<int> a(1, sum);
		for (int i = 0; i < encoded.size(); i++)
			a.push_back(a.back() ^ encoded[i]);
		return a;
	}
};
