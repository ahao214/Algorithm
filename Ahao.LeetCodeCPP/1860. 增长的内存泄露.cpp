#include<vector>

using namespace std;


/*
1860. �������ڴ�й¶
������������ memory1 �� memory2 �ֱ��ʾ�����ڴ���ʣ������ڴ��λ����������һ������ÿ��������ٶ��������ڴ档

�ڵ� i �루������ 1 ��ʼ������ i λ�ڴ汻���䵽 ʣ���ڴ�϶� ���ڴ������������һ���࣬����䵽��һ���ڴ��������������ʣ���ڴ涼���� i λ����ô���� �����˳� ��

���㷵��һ�����飬���� [crashTime, memory1crash, memory2crash] ������ crashTime�ǳ��������˳���ʱ�䣨��λΪ�룩�� memory1crash �� memory2crash �ֱ��������ڴ������ʣ���ڴ��λ����
*/

class Solution {
public:
	vector<int> memLeak(int memory1, int memory2) {
		for (int i = 1; ; i++)
		{
			if (memory1 >= memory2)
			{
				if (memory1 < i) return { i,memory1,memory2 };
				memory1 -= i;
			}
			else
			{
				if (memory2 < i) return { i,memory1,memory2 };
				memory2 -= i;
			}
		}
		return {};
	}

};