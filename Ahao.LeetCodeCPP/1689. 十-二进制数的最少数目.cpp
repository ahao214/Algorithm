#include<vector>
#include<string>

using namespace std;


/*
1689. ʮ-����������������Ŀ
���һ��ʮ�������ֲ����κ�ǰ���㣬��ÿһλ�ϵ����ֲ��� 0 ���� 1 ����ô�����־���һ�� ʮ-�������� �����磬101 �� 1100 ���� ʮ-������������ 112 �� 3001 ���ǡ�

����һ����ʾʮ�����������ַ��� n �����غ�Ϊ n �� ʮ-�������� ��������Ŀ��
*/
class Solution {
public:
	int minPartitions(string n) {
		int res = 0;
		for (auto c : n) res = max(res, c - '0');
		return res;
	}
};
