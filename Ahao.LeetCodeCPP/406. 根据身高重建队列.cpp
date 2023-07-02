#include<vector>
#include <algorithm>

using namespace std;


/*
406. ��������ؽ�����

�����д���˳���һȺ��վ��һ�����У����� people ��ʾ������һЩ�˵����ԣ���һ����˳�򣩡�ÿ�� people[i] = [hi, ki] ��ʾ�� i ���˵����Ϊ hi ��ǰ�� ���� �� ki ����ߴ��ڻ���� hi ���ˡ�

�������¹��첢������������ people ����ʾ�Ķ��С����صĶ���Ӧ�ø�ʽ��Ϊ���� queue ������ queue[j] = [hj, kj] �Ƕ����е� j ���˵����ԣ�queue[0] �����ڶ���ǰ����ˣ���
ʾ�� 1��

���룺people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
�����[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
���ͣ�
���Ϊ 0 �������Ϊ 5 ��û����߸��߻�����ͬ����������ǰ�档
���Ϊ 1 �������Ϊ 7 ��û����߸��߻�����ͬ����������ǰ�档
���Ϊ 2 �������Ϊ 5 ���� 2 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 0 �� 1 ���ˡ�
���Ϊ 3 �������Ϊ 6 ���� 1 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 1 ���ˡ�
���Ϊ 4 �������Ϊ 4 ���� 4 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 0��1��2��3 ���ˡ�
���Ϊ 5 �������Ϊ 7 ���� 1 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 1 ���ˡ�
��� [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] �����¹����Ķ��С�
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
            });
        vector<vector<int>> ans;
        for (const vector<int>& person : people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};




/*
406. ��������ؽ�����
*/
class Solution {
public:
	int n;
	vector<int> tr;
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}
	int query(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		n = people.size();
		tr.resize(n + 1);
		sort(people.begin(), people.end(), [](vector<int>a, vector<int> b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] > b[1];
			});

		vector<vector<int>> res(n);
		for (auto p : people)
		{
			int h = p[0], k = p[1];
			int left = 1, right = n;
			while (left < right)
			{
				int mid = (left + right) >> 1;
				if (mid - query(mid) >= k + 1)
					right = mid;
				else
					left = mid + 1;
			}
			res[right - 1] = p;
			add(right, 1);
		}
		return res;
	}
};
