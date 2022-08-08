#include<vector>
#include<string>
#include<unordered_set>

using namespace std;



/*
1898. ���Ƴ��ַ��������Ŀ
���������ַ��� s �� p ������ p �� s ��һ�� ������ ��ͬʱ������һ��Ԫ�� ������ͬ ���±� �� 0 ��ʼ �������������� removable ���������� s ���±��һ���Ӽ���s ���±�Ҳ �� 0 ��ʼ ��������

�����ҳ�һ������ k��0 <= k <= removable.length����ѡ�� removable �е� ǰ k ���±꣬Ȼ��� s ���Ƴ���Щ�±��Ӧ�� k ���ַ������� k �����㣺��ִ������������� p ��Ȼ�� s ��һ�� ������ ������ʽ�Ľ����ǣ�����ÿ�� 0 <= i < k ���ȱ�ǳ�λ�� s[removable[i]] ���ַ��������Ƴ����б�ǹ����ַ���Ȼ���� p �Ƿ���Ȼ�� s ��һ�������С�

����������ҳ��� ��� k ���������Ƴ��ַ��� p ��Ȼ�� s ��һ�������С�

�ַ�����һ�� ������ ��һ����ԭ�ַ������ɵ����ַ��������ɹ����п��ܻ��Ƴ�ԭ�ַ����е�һЩ�ַ���Ҳ���ܲ��Ƴ��������ı�ʣ���ַ�֮������˳��
*/
class Solution {
public:
	int maximumRemovals(string s, string p, vector<int>& removable) {
		int left = 0, right = removable.size();
		while (left < right)
		{
			int mid = (left + right + 1) >> 1;
			unordered_set<int> hs;
			for (int i = 0; i < mid; i++) hs.insert(removable[i]);
			int i = 0, j = 0;
			while (i < s.size() && j < p.size())
			{
				if (hs.count(i))
				{
					i++;
					continue;
				}
				if (s[i] == p[j])j++;
				i++;
			}
			if (j == p.size()) left = mid;
			else right = mid - 1;
		}
		return right;
	}
};

