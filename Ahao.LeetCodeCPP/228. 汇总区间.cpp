#include<vector>
#include <string>

using namespace std;


/*
228. ��������
����һ��  ���ظ�Ԫ�� �� ���� �������� nums ��

���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б� ��
Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ�
���Ҳ���������ĳ����Χ�������� nums ������ x ��

�б��е�ÿ�����䷶Χ [a,b] Ӧ�ð����¸�ʽ�����

"a->b" ����� a != b
"a" ����� a == b
*/
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.size() == 0)
			return {};
		int j = 0;
		string str;
		vector<string> res;
		for (int i = 0; i < nums.size(); i++)
		{
			j = i;
			while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
			{
				j++;
			}
			if (j > i)
			{
				str = to_string(nums[i]) + "->" + to_string(nums[j]);
			}
			else
			{
				str = to_string(nums[j]);
			}
			res.push_back(str);
			str.clear();
			i = j;
		}
		return res;
	}
};
