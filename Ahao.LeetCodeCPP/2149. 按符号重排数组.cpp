#include<vector>

using namespace std;


/*
2149. ��������������
����һ���±�� 0 ��ʼ���������� nums �����鳤��Ϊ ż�� ������Ŀ��ȵ��������͸�������ɡ�

����Ҫ ���� nums �е�Ԫ�أ�ʹ�޸ĺ��������������������

���� ���� ���������� �����෴
���ڷ�����ͬ���������������� ������ nums �е� ˳�� ��
���ź���������������ͷ��
����Ԫ���������������󣬷����޸ĺ�����顣
*/
class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int>a, b;
		for (auto x : nums)
		{
			if (x > 0) a.push_back(x);
			else b.push_back(x);
		}
		vector<int> res;
		for (int i = 0; i < a.size(); i++)
		{
			res.push_back(a[i]);
			res.push_back(b[i]);
		}
		return res;
	}
};