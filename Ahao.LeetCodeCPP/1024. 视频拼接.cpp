#include<vector>
#include <algorithm>

using namespace std;


/*
1024. ��Ƶƴ��

�㽫����һϵ����ƵƬ�Σ���ЩƬ��������һ�����ʱ��Ϊ time ����������¡���ЩƬ�ο��������ص���Ҳ���ܳ��Ȳ�һ��

ʹ������ clips �������е���ƵƬ�Σ����� clips[i] = [starti, endi] ��ʾ��ĳ����ƵƬ�ο�ʼ�� starti ���� endi ������

�������Զ���ЩƬ�����ɵ��ټ�����

���磬Ƭ�� [0, 7] ���Լ��г� [0, 1] + [1, 3] + [3, 7] �����֡�
������Ҫ����ЩƬ�ν����ټ��������������������ƴ�ӳɸ��������˶����̵�Ƭ�Σ�[0, time]������������Ƭ�ε���С��Ŀ������޷���ɸ������򷵻� -1 ��
*/
class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int time) {
		sort(clips.begin(), clips.end(), [&](vector<int>& a, vector<int>& b) {
			return a[0] < b[0];
			});

		int res = 0, last = 0;
		for (int i = 0; i < clips.size();)
		{
			if (clips[i][0] > last) return -1;
			int r = 0;
			while (i < clips.size() && clips[i][0] <= last)
			{
				r = max(r, clips[i][1]);
				i++;
			}
			last = r;
			res++;
			if (last >= time) break;
		}
		if (last >= time) return res;
		return -1;
	}
};
