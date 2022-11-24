#include<vector>
#include <random>

using namespace std;


/*
1450. �ڼȶ�ʱ������ҵ��ѧ������
���������������� startTime����ʼʱ�䣩�� endTime������ʱ�䣩����ָ��һ������ queryTime ��Ϊ��ѯʱ�䡣

��֪���� i ��ѧ���� startTime[i] ʱ��ʼд��ҵ���� endTime[i] ʱ�����ҵ��

�뷵���ڲ�ѯʱ�� queryTime ʱ��������ҵ��ѧ����������ʽ�ϣ������ܹ�ʹ queryTime �������� [startTime[i], endTime[i]]��������ѧ��������
*/

//ö��
class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int n = startTime.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				ans++;
			}
		}
		return ans;
	}
};


//�������
class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int n = startTime.size();
		int maxEndTime = *max_element(endTime.begin(), endTime.end());
		if (queryTime > maxEndTime) {
			return 0;
		}
		vector<int> cnt(maxEndTime + 2);
		for (int i = 0; i < n; i++) {
			cnt[startTime[i]]++;
			cnt[endTime[i] + 1]--;
		}
		int ans = 0;
		for (int i = 0; i <= queryTime; i++) {
			ans += cnt[i];
		}
		return ans;
	}
};


class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int res = 0;
		for (int i = 0; i < startTime.size(); i++)
		{
			if (startTime[i] <= queryTime && queryTime <= endTime[i])
				res++;
		}
		return res;
	}
};

