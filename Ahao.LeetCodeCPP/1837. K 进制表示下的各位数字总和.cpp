#include<vector>

using namespace std;


/*
1837. K ���Ʊ�ʾ�µĸ�λ�����ܺ�
����һ������ n��10 ���ƣ���һ������ k �����㽫 n �� 10 ���Ʊ�ʾת��Ϊ k ���Ʊ�ʾ�����㲢����ת�����λ���ֵ� �ܺ� ��

ת���󣬸�λ����Ӧ�������� 10 �������֣������ǵ��ܺ�ҲӦ���� 10 ���Ʊ�ʾ���ء�
*/
class Solution {
public:
	int sumBase(int n, int k) {
		int res = 0;
		while (n) res += n % k, n /= k;
		return res;
	}
};