#include<vector>
#include <string>

using namespace std;


/*
1446. �����ַ�
����һ���ַ��� s ���ַ����ġ�����������Ϊ��ֻ����һ���ַ�����ǿ����ַ����ĳ��ȡ�

���㷵���ַ�����������
*/
class Solution {
public:
	//˫ָ��
	int maxPower(string s) {
		int res = 0;
		for (int i = 0; i < s.size();)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i]) j++;
			res = max(res, j - i);
			i = j;
		}
		return res;
	}
};