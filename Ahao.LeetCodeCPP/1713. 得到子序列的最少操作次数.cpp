#include<vector>
#include <unordered_map>

using namespace std;


/*
1713. �õ������е����ٲ�������
����һ������ target ���������� ������ͬ ���������Լ���һ���������� arr ��arr ���� �����ظ�Ԫ�ء�

ÿһ�β����У�������� arr ������λ�ò�����һ�������ȷ�˵����� arr = [1,4,1,2] ����ô��������м���� 3 �õ� [1,4,3,1,2] ��������������ʼ����������������

���㷵�� ���� ����������ʹ�� target ��Ϊ arr ��һ�������С�

һ������� ������ ָ����ɾ��ԭ�����ĳЩԪ�أ�����һ��Ԫ�ض���ɾ������ͬʱ���ı�����Ԫ�ص����˳��õ������顣�ȷ�˵��[2,7,4] �� [4,2,3,7,2,1,4] �������У��Ӵ�Ԫ�أ����� [2,4,2] ���������С�
*/
class Solution {
public:
	int minOperations(vector<int>& target, vector<int>& arr) {
		unordered_map<int, int> pos;
		for (int i = 0; i < target.size(); i++)
		{
			pos[target[i]] = i;
		}
		vector<int> a;
		for (auto x : arr)
			if (pos.count(x))
				a.push_back(pos[x]);

		int len = 0;
		vector<int> q(a.size() + 1);
		for (int i = 0; i < a.size(); i++)
		{
			int left = 0, right = len;
			while (left < right) {
				int mid = left + right + 1 >> 1;
				if (q[mid] < a[i]) left = mid;
				else right = mid - 1;
			}
			len = max(len, right + 1);
			q[right + 1] = a[i];
		}
		return target.size() - len;
	}
};