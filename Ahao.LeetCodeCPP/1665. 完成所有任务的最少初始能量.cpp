#include<vector>
#include <algorithm>

using namespace std;


/*
1665. ���������������ٳ�ʼ����
����һ���������� tasks ������ tasks[i] = [actuali, minimumi] ��

actuali ����ɵ� i ������ ��Ҫ�ķ� ��ʵ��������
minimumi �ǿ�ʼ�� i ������ǰ��Ҫ�ﵽ�����������
�ȷ�˵���������Ϊ [10, 12] ���㵱ǰ������Ϊ 11 ����ô�㲻�ܿ�ʼ�����������㵱ǰ������Ϊ 13 ��������������������������ʣ������Ϊ 3 ��

����԰��� ����˳�� �������

���㷵�������������� ���� ��ʼ������
*/
class Solution {
public:
	/*
	����minimumi - actuali��С��������
	����W�����ĳ�������ʣ�������
	���ǰ��W + actuali >= minimumi
	W >= minimumi - actuali
	W��ֵ��������������ÿ�������minimumi - actuali��С�����ֵ�ĺ�
	*/
	int minimumEffort(vector<vector<int>>& tasks) {
		sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] - a[0] < b[1] - b[0];
			});

		int w = 0, s = 0;
		for (auto& t : tasks)
		{
			int x = t[0], y = t[1];
			s += x;
			w = max(w, y - s);
		}
		for (auto& t : tasks) w += t[0];
		return w;
	}
};