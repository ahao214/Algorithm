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


class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > first) {
                    second = first;
                    first = num;
                }
                else if (num < first && num > second) {
                    second = num;
                }
            }
        }
        return second;
    }
};
