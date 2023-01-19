#include<vector>
#include <string>
#include <stack>

using namespace std;


/*
2434. ʹ�û����˴�ӡ�ֵ�����С���ַ���

����һ���ַ��� s ��һ�������ˣ������˵�ǰ��һ�����ַ��� t ��ִ�����²���֮һ��ֱ�� s �� t ����ɿ��ַ�����

ɾ���ַ��� s �� ��һ�� �ַ����������ַ��������ˡ������˰�����ַ���ӵ� t ��β����
ɾ���ַ��� t �� ���һ�� �ַ����������ַ��������ˡ������˽����ַ�д��ֽ�ϡ�
���㷵��ֽ����д�����ֵ�����С���ַ�����
*/
class Solution {
public:
	string robotWithString(string s) {
		int n = s.size();
		stack<char> st;
		vector<int> sufSmallest(n);
		char curSmallest = 'z' + 1;
		for (int i = n - 1; i >= 0; i--)
		{
			curSmallest = min(curSmallest, s[i]);
			sufSmallest[i] = curSmallest;
		}

		string res;
		int i = 0;
		while (i < n)
		{
			if (st.empty() || sufSmallest[i] < st.top())
			{
				st.push(s[i]);
				i++;
			}
			else
			{
				res.push_back(st.top());
				st.pop();
			}
		}
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}
};
