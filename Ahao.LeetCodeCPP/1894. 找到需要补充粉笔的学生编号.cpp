#include<vector>
#include<numeric>

using namespace std;


/*
1894. �ҵ���Ҫ����۱ʵ�ѧ�����
һ���༶���� n ��ѧ�������Ϊ 0 �� n - 1 ��ÿ��ѧ�������λش����⣬���Ϊ 0 ��ѧ���Ȼش�Ȼ���Ǳ��Ϊ 1 ��ѧ�����Դ����ƣ�ֱ�����Ϊ n - 1 ��ѧ����Ȼ����ʦ���ظ�������̣����´ӱ��Ϊ 0 ��ѧ����ʼ�ش����⡣

����һ������Ϊ n ���±�� 0 ��ʼ���������� chalk ��һ������ k ��һ��ʼ�۱ʺ����ܹ��� k ֧�۱ʡ������Ϊ i ��ѧ���ش�����ʱ���������� chalk[i] ֧�۱ʡ����ʣ��۱����� �ϸ�С�� chalk[i] ����ôѧ�� i ��Ҫ ���� �۱ʡ�

���㷵����Ҫ ���� �۱ʵ�ѧ�� ��� ��
*/
class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		long long sum = accumulate(chalk.begin(), chalk.end(), 0ll);
		k %= sum;
		for (int i = 0; i < chalk.size(); i++)
		{
			if (k < chalk[i]) return i;
			k -= chalk[i];
		}
		return -1;
	}

};

