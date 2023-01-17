#include<vector>
#include <string>

using namespace std;

/*
2516. ÿ���ַ�����ȡ K ��
����һ�����ַ� 'a'��'b'��'c' ��ɵ��ַ��� s ��һ���Ǹ����� k ��ÿ���ӣ������ѡ��ȡ�� s ����� ���� ���Ҳ� ���Ǹ��ַ���

�����ȡ��ÿ���ַ� ���� k ����������Ҫ�� ���� ������������޷�ȡ�����򷵻� -1 ��
*/
class Solution {
public:
	int takeCharacters(string s, int k) {
		int aCount = 0;
		int bCount = 0;
		int cCount = 0;
		for (auto ch : s) {
			if (ch == 'a')
				aCount++;
			if (ch == 'b')
				bCount++;
			if (ch == 'c')
				cCount++;
		}

		if (aCount < k || bCount < k || cCount < k)
			return -1;

		aCount = aCount - k;
		bCount = bCount - k;
		cCount = cCount - k;

		int n = s.size();
		int j = 0;
		int a = 0, b = 0, c = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			while (a <= aCount && b <= bCount && c <= cCount) {
				res = max(res, j - i);
				if (j == n)
					break;
				if (s[j] == 'a') a++;
				if (s[j] == 'b') b++;
				if (s[j] == 'c') c++;
				j++;
			}
			if (s[i] == 'a') a--;
			if (s[i] == 'b') b--;
			if (s[i] == 'c') c--;
		}

		return n - res;
	}
};

