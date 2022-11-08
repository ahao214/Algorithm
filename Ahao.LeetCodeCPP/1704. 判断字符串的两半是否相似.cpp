#include<vector>
#include <string>
#include <set>

using namespace std;


/*
1704. �ж��ַ����������Ƿ�����
����һ��ż�����ȵ��ַ��� s �������ֳɳ�����ͬ�����룬ǰһ��Ϊ a ����һ��Ϊ b ��

�����ַ��� ���� ��ǰ�������Ƕ�������ͬ��Ŀ��Ԫ����'a'��'e'��'i'��'o'��'u'��'A'��'E'��'I'��'O'��'U'����ע�⣬s ����ͬʱ���д�д��Сд��ĸ��

��� a �� b ���ƣ����� true �����򣬷��� false ��
*/
class Solution {
public:
	int count(string s)
	{
		int res = 0;
		set<char> S({ 'a','e','i','o','u' });
		for (auto c : s)
		{
			auto x = tolower(c);
			if (S.count(x))
				res++;
		}
		return res;
	}

	bool halvesAreAlike(string s) {
		int n = s.size() / 2;
		return count(s.substr(0, n)) == count(s.substr(n));
	}
};
