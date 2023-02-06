#include<vector>
#include <string>

using namespace std;


/*
880. �������Ľ����ַ���

����һ�������ַ��� S�������ҳ� �����ַ��� ������д��Ŵ�������ʱ���ӱ����ַ����� ÿ�ζ�ȡһ���ַ� ������ȡ���²��裺

����������ַ�����ĸ���򽫸���ĸд�ڴŴ��ϡ�
����������ַ������֣����� d������������ǰ�Ŵ��ܹ��ᱻ�ظ�д d-1 �Ρ�
���ڣ����ڸ����ı����ַ��� S ������ K�����Ҳ����ؽ����ַ����еĵ� K ����ĸ��
*/
class Solution {
public:
	string decodeAtIndex(string s, int k) {
		long long n = 0;
		for (auto c : s)
		{
			if (isdigit(c))
				n *= c - '0';
			else n++;
		}
		for (int i = s.size() - 1; i >= 0; i--)
		{
			char c = s[i];
			if (isdigit(c))
			{
				int x = c - '0';
				n /= x;
				k %= n;
				if (!k) k = n;
			}
			else
			{
				if (n == k) return string(1, c);
				n--;
			}
		}
		return "";
	}
};