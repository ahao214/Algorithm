#include<string>
#include<set>

using namespace std;

/*
1796. �ַ����еڶ��������
����һ������ַ��� s �����㷵�� s �� �ڶ��� �����֣���������ڵڶ�������֣����㷵�� -1 ��

����ַ��� ��СдӢ����ĸ��������ɡ�
*/
class Solution {
public:
	int secondHighest(string s) {
		set<int> nset;
		for (auto c : s)
		{
			if (isdigit(c))
				nset.insert(c - '0');
		}
		if (nset.size() <= 1) return -1;
		auto it = nset.rbegin();
		it++;
		return *it;
	}
};
