#include<vector>
#include <queue>

using namespace std;


/*
2161. ���ݸ������ֻ�������
����һ���±�� 0 ��ʼ���������� nums ��һ������ pivot �����㽫 nums �������У�ʹ������������������

����С�� pivot ��Ԫ�ض����������д��� pivot ��Ԫ�� ֮ǰ ��
���е��� pivot ��Ԫ�ض�������С�ںʹ��� pivot ��Ԫ�� �м� ��
С�� pivot ��Ԫ��֮��ʹ��� pivot ��Ԫ��֮��� ���˳�� �������ı䡣
����ʽ�ģ�����ÿһ�� pi��pj ��pi �ǳ�ʼʱλ�� i Ԫ�ص���λ�ã�pj �ǳ�ʼʱλ�� j Ԫ�ص���λ�á�����С�� pivot ��Ԫ�أ���� i < j �� nums[i] < pivot �� nums[j] < pivot ����������ô pi < pj Ҳ���������Ƶģ����ڴ��� pivot ��Ԫ�أ���� i < j �� nums[i] > pivot �� nums[j] > pivot ����������ô pi < pj ��
���㷵���������� nums �����Ľ�����顣
*/
class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> vAns;

		queue<int> qBig;
		int deng = 0;
		for (auto x : nums) {
			if (x < pivot) {
				vAns.push_back(x);
			}
			else if (x > pivot) {
				qBig.push(x);
			}
			else {
				deng++;
			}
		}
		for (int i = 0; i < deng; i++) {
			vAns.push_back(pivot);
		}
		while (!qBig.empty()) {
			vAns.push_back(qBig.front());
			qBig.pop();
		}
		return vAns;
	}
};
