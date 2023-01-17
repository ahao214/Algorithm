#include<vector>
#include <string>

using namespace std;


/*
438. �ҵ��ַ�����������ĸ��λ��

���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�������
*/
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int m = s.size(), n = p.size();
		if (m < n) {
			return {};
		}
		vector<int> pCount(26, 0), sCount(26, 0);
		for (auto c : p) {
			pCount[c - 'a']++;
		}
		vector<int> res;
		for (int i = 0; i < m; ++i) {
			sCount[s[i] - 'a']++;
			if (i >= n) {
				sCount[s[i - n] - 'a']--;
			}
			if (sCount == pCount) {
				res.push_back(i - n + 1);
			}
		}
		return res;
	}
};
