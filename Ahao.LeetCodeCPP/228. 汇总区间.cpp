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
	string rangeToString(int st, int ed)
	{
		if (st == ed) return to_string(st);
		return to_string(st) + "->" + to_string(ed);
	}

	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if (nums.empty()) return res;
		int st = nums[0], ed = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int x = nums[i];
			if (x > ed + 1)
			{
				res.push_back(rangeToString(st, ed));
				st = ed = x;
			}
			else
			{
				ed++;
			}
		}
		res.push_back(rangeToString(st, ed));
		return res;
	}
};



class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		int i = 0;
		int n = nums.size();
		while (i < n) {
			int low = i;
			i++;
			while (i < n && nums[i] == nums[i - 1] + 1) {
				i++;
			}
			int high = i - 1;
			string temp = to_string(nums[low]);
			if (low < high) {
				temp.append("->");
				temp.append(to_string(nums[high]));
			}
			ret.push_back(move(temp));
		}
		return ret;
	}
};

