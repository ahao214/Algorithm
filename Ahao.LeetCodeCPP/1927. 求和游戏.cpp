#include<vector>
#include<string>

using namespace std;


/*
1927. �����Ϸ
Alice �� Bob ��һ����Ϸ�����������ж���Alice ���� ��

����һ�� ż������ ���ַ��� num ��ÿһ���ַ�Ϊ�����ַ����� '?' ��ÿһ�β����У���� num ��������һ�� '?' ����ô��ҿ���ִ�����²�����

ѡ��һ���±� i ���� num[i] == '?' ��
�� num[i] �� '0' �� '9' ֮���һ�������ַ������
�� num ��û�� '?' ʱ����Ϸ������

Bob ��ʤ�������� num ��ǰһ�����ֵĺ� ���� ��һ�����ֵĺ͡�Alice ��ʤ��������ǰһ��ĺ����һ��ĺ� ����� ��

�ȷ�˵����Ϸ����ʱ num = "243801" ����ô Bob ��ʤ����Ϊ 2+4+3 = 8+0+1 �������Ϸ����ʱ num = "243803" ����ô Alice ��ʤ����Ϊ 2+4+3 != 8+0+3 ��
�� Alice �� Bob ����ȡ ���� ���Ե�ǰ���£���� Alice ��ʤ���뷵�� true ����� Bob ��ʤ���뷵�� false ��
*/
class Solution {
public:
	bool sumGame(string num) {
		int sum = 0, cnt = 0, n = num.size();
		for (int i = 0; i < n / 2; i++)
		{
			if (num[i] == '?') cnt++;
			else sum += num[i] - '0';
		}
		for (int i = n / 2; i < n; i++)
		{
			if (num[i] == '?')cnt--;
			else sum -= num[i] - '0';
		}
		if (!sum) return cnt;
		if (sum < 0) sum *= -1, cnt *= -1;
		if (cnt >= 0) return true;
		cnt *= -1;
		if (cnt % 2) return true;
		if (cnt / 2 * 9 == sum) return false;
		return true;
	}
};

