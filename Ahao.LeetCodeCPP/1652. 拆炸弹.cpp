#include<vector>

using namespace std;



/*
1652. ��ը��
����һ��ը����Ҫ�����ʱ����ȣ�����鱨Ա�����һ������Ϊ n �� ѭ�� ���� code �Լ�һ����Կ k ��

Ϊ�˻����ȷ�����룬����Ҫ�滻��ÿһ�����֡��������ֻ� ͬʱ ���滻��

��� k > 0 ������ i �������� ������ k ������֮���滻��
��� k < 0 ������ i �������� ֮ǰ k ������֮���滻��
��� k == 0 ������ i �������� 0 �滻��
���� code ��ѭ���ģ� code[n-1] ��һ��Ԫ���� code[0] ���� code[0] ǰһ��Ԫ���� code[n-1] ��

���� ѭ�� ���� code ��������Կ k �����㷵�ؽ��ܺ�Ľ�������ը����
*/

class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> res(n);
		if (k == 0) {
			return res;
		}
		code.resize(n * 2);
		copy(code.begin(), code.begin() + n, code.begin() + n);
		int l = k > 0 ? 1 : n + k;
		int r = k > 0 ? k : n - 1;
		int w = 0;
		for (int i = l; i <= r; i++) {
			w += code[i];
		}
		for (int i = 0; i < n; i++) {
			res[i] = w;
			w -= code[l];
			w += code[r + 1];
			l++;
			r++;
		}
		return res;
	}
};




class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> res(n);
		for (int i = 0; i < n; i++)
		{
			if (k == 0) res[i] = 0;
			else if (k > 0)
			{
				for (int j = 1; j <= k; j++)
					res[i] += code[(i + j) % n];
			}
			else {
				for (int j = -1; j >= k; j--)
					res[i] += code[(i + j + n) % n];
			}
		}
		return res;
	}
};