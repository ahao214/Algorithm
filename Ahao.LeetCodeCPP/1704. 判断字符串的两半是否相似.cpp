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


class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2);
        string h = "aeiouAEIOU";
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (h.find_first_of(a[i]) != string::npos) {
                sum1++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (h.find_first_of(b[i]) != string::npos) {
                sum2++;
            }
        }
        return sum1 == sum2;
    }
};
