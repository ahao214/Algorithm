#include<vector>

using namespace std;


/*
1491. ȥ����͹��ʺ���߹��ʺ�Ĺ���ƽ��ֵ
����һ���������� salary ��������ÿ�������� Ψһ �ģ����� salary[i] �ǵ� i ��Ա���Ĺ��ʡ�

���㷵��ȥ����͹��ʺ���߹����Ժ�ʣ��Ա�����ʵ�ƽ��ֵ��
*/
class Solution {
public:
	double average(vector<int>& salary) {
		double sum = 0;
		int maxv = INT_MIN, minv = INT_MAX;
		for (auto x : salary)
		{
			sum += x;
			maxv = max(maxv, x);
			minv = min(minv, x);
		}
		return (sum - maxv - minv) / (salary.size() - 2);
	}
};

