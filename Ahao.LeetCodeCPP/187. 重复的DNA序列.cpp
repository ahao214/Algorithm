#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
187. �ظ���DNA����
DNA���� ��һϵ�к�������ɣ���дΪ 'A', 'C', 'G' �� 'T'.��

���磬"ACGAATTCCG" ��һ�� DNA���� ��
���о� DNA ʱ��ʶ�� DNA �е��ظ����зǳ����á�

����һ����ʾ DNA���� ���ַ��� s ������������ DNA �����г��ֲ�ֹһ�ε� ����Ϊ 10 ������(���ַ���)������԰� ����˳�� ���ش𰸡�
*/
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> hash;
		vector<string> res;
		for (int i = 0; i + 10 <= s.size(); i++)
		{
			string str = s.substr(i, 10);
			if (++hash[str] == 2)
				res.push_back(str);
		}
		return res;
	}
};