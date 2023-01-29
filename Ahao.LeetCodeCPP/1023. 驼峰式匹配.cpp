#include<vector>
#include <string>

using namespace std;


/*
1023. �շ�ʽƥ��

������ǿ��Խ�Сд��ĸ����ģʽ�� pattern �õ�����ѯ�� query����ô����ѯ�������ģʽ��ƥ�䡣�����ǿ������κ�λ�ò���ÿ���ַ���Ҳ���Բ��� 0 ���ַ�����

��������ѯ�б� queries����ģʽ�� pattern�������ɲ���ֵ��ɵĴ��б� answer��ֻ���ڴ����� queries[i] ��ģʽ�� pattern ƥ��ʱ�� answer[i] ��Ϊ true������Ϊ false��
*/
class Solution {
public:
	bool check(string& a, string& b)
	{
		int j = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (j < b.size() && a[i] == b[j]) j++;
			else if (a[i] < 'a') return false;
		}
		return j == b.size();
	}

	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> res;
		for (auto& q : queries)
			res.push_back(check(q, pattern));
		return res;
	}
};