#include<vector>
#include <map>

using namespace std;


/*
2191. ���������µ���������
����һ���±�� 0 ��ʼ���������� mapping ������ʾһ��ʮ��������ӳ�����mapping[i] = j ��ʾ��������½���λ i ӳ��Ϊ��λ j ��

һ������ ӳ����ֵ Ϊ��ԭ����ÿһ����λ i ��0 <= i <= 9��ӳ��Ϊ mapping[i] ��

�������һ���������� nums �����㽫���� nums ��ÿ������������ӳ����Ӧ���ַǵݼ�˳������󷵻ء�

ע�⣺

�����������ӳ����Ӧ�����ִ�С��ͬ�������ǰ��������е� ���˳�� ����
nums �е�Ԫ��ֻ���������ʱ����Ҫ����ӳ����ֵ���бȽϣ����ص�ֵӦ���������Ԫ�ر���
*/
class Solution {
public:
	int calculate(vector<int>& mapping, int n)
	{
		if (n == 0)
			return mapping[0];
		int res = 0, unit = 1;
		while (n != 0)
		{
			int val = mapping[n % 10];
			res += val * unit;
			unit *= 10;
			n /= 10;
		}
		return res;
	}

	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		multimap<int, int> dict;	//��һint��ת��ǰ������,�ڶ���int��ת���������
		for (auto n : nums)
		{
			int tmp = calculate(mapping, n);
			dict.insert({ tmp,n });
		}
		vector<int> res;
		for (auto pair : dict)
		{
			res.push_back(pair.second);
		}
		return res;
	}
};