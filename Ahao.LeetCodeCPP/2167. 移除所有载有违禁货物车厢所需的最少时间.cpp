#include<vector>
#include <string>

using namespace std;


/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */



 /*
2167. �Ƴ���������Υ�����ﳵ�����������ʱ��
����һ���±�� 0 ��ʼ�Ķ������ַ��� s ����ʾһ���г��������С�s[i] = '0' ��ʾ�� i �ڳ��� �� ��Υ������� s[i] = '1' ��ʾ�� i �ڳ��ẬΥ�����

��Ϊ�г���������Ҫ�������������Υ������ĳ��ᡣ����Բ��޴���ִ���������ֲ����е�����һ����

���г� �� ���Ƴ�һ�ڳ��ᣨ���Ƴ� s[0]������ȥ 1 ��λʱ�䡣
���г� �� ���Ƴ�һ�ڳ��ᣨ���Ƴ� s[s.length - 1]������ȥ 1 ��λʱ�䡣
���г��������е� ����λ�� �Ƴ�һ�ڳ��ᣬ��ȥ 2 ��λʱ�䡣
�����Ƴ���������Υ�����ﳵ������Ҫ�� ���� ��λʱ������

ע�⣬�յ��г�����������Ϊû�г��ẬΥ�����
*/
class Solution {
public:
	int minimumTime(string s)
	{
		int n = s.size();
		vector<int>a(n + 5);
		for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
		int now = 1e9;
		int ans = now;
		for (int i = n; i >= 0; i--)
		{
			now = min(now + 2 * a[i + 1], n - i);
			ans = min(ans, now + i);
		}
		return ans;
	}
};



class Solution {
public:
	int minimumTime(string s)
	{
		int n = s.size();
		vector<int> left(n + 1);
		vector<int> right(n + 1);

		for (int i = 0; i < n; i++) {
			left[i + 1] = left[i];
			if (s[i] == '1') {
				left[i + 1] += 2;
			}
			left[i + 1] = min(left[i + 1], i + 1);
		}

		int ans = n;
		for (int i = n - 1; i >= 0; i--) {
			right[i] = right[i + 1];
			if (s[i] == '1') {
				right[i] += 2;
			}
			right[i] = min(right[i], n - i);
			ans = min(ans, right[i] + left[i]);
		}
		return ans;
	}
};


const int MAXN = 2e5 + 50;
int dp[MAXN];
class Solution {
public:
	int minimumTime(string s) {
		int n = s.size();
		int ans = n;
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = min(dp[i + 1], n - i - 1) + (s[i] == '1' ? 2 : 0);
		}
		for (int i = 0; i < n; i++) {
			ans = min(ans, i + min(dp[i], n - i));
		}
		return ans;
	}
};