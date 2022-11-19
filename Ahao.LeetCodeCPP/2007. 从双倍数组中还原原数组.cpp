#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



/*
2007. ��˫�������л�ԭԭ����

һ���������� original ����ת���һ�� ˫�� ���� changed ��ת�䷽ʽΪ�� original ��ÿ��Ԫ�� ֵ���� 2 ���������У�Ȼ������Ԫ�� ������� ��

����һ������ changed ����� change �� ˫�� ���飬��ô���㷵�� original���飬�����뷵�ؿ����顣original ��Ԫ�ؿ����� ���� ˳�򷵻ء�
*/
class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		int size = changed.size();
		if (size % 2)	// Ԫ�ظ����������� ֱ�ӷ��ؿ�
		{
			return {};
		}
		sort(changed.begin(), changed.end());
		unordered_map<int, int> dict;
		for (auto num : changed)
		{
			dict[num]++;
		}

		vector<int> res;
		for (auto num : changed)
		{
			if (dict[num])
			{
				dict[num]--;
				int twice = num * 2;
				if (dict[twice] > 0)
				{
					dict[twice]--;
					res.push_back(num);
				}
				else
				{
					return {};
				}
			}
		}

		return res;
	}
};