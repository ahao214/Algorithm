#include<vector>
#include<string>

using namespace std;



/*
1871. ��Ծ��Ϸ VII
����һ���±�� 0 ��ʼ�Ķ������ַ��� s ���������� minJump �� maxJump ��һ��ʼ�������±� 0 �����Ҹ�λ�õ�ֵһ��Ϊ '0' ����ͬʱ������������ʱ������Դ��±� i �ƶ����±� j ����

i + minJump <= j <= min(i + maxJump, s.length - 1) ��
s[j] == '0'.
�������Ե��� s ���±� s.length - 1 �������㷵�� true �����򷵻� false ��
*/
class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int n = s.size();
		vector<int> f(n + 1), str(n + 1);
		f[1] = 1;
		str[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (s[i - 1] == '0' && i - minJump >= 1)
			{
				int left = max(1, i - maxJump), right = i - minJump;
				if (str[right] > str[left - 1])
					f[i] = 1;
			}
			str[i] = str[i - 1] + f[i];
		}
		return f[n];
	}
};

