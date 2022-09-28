#include<vector>
#include<string>

using namespace std;



/*
1769. �ƶ�������ÿ�������������С������
�� n �����ӡ�����һ������Ϊ n �Ķ������ַ��� boxes ������ boxes[i] ��ֵΪ '0' ��ʾ�� i �������� �� �ģ��� boxes[i] ��ֵΪ '1' ��ʾ�������� һ�� С��

��һ�������У�����Խ� һ�� С���ĳ�������ƶ���һ����֮���ڵĺ����С��� i �����Ӻ͵� j ���������������� abs(i - j) == 1 ��ע�⣬����ִ�к�ĳЩ�����п��ܻ���ڲ�ֹһ��С��

����һ������Ϊ n ������ answer ������ answer[i] �ǽ�����С���ƶ����� i ����������� ��С ��������

ÿ�� answer[i] ����Ҫ���ݺ��ӵ� ��ʼ״̬ ���м��㡣
*/
class Solution {
public:
	vector<int> minOperations(string boxes) {
		int n = boxes.size();
		vector<int> ans(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (boxes[j] == '1')
					ans[i] += abs(i - j);
		return ans;
	}
};