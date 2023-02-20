#include<vector>

using namespace std;

/*
2347. ��õ��˿�����

����һ���������� ranks ��һ���ַ����� suit ������ 5 ���˿��ƣ��� i ���ƴ�СΪ ranks[i] ����ɫΪ suits[i] ��

�����ǴӺõ�������ܳ��е� �������� ��

"Flush"��ͬ����������ͬ��ɫ���˿��ơ�
"Three of a Kind"���������� 3 �Ŵ�С��ͬ���˿��ơ�
"Pair"�����ӣ����Ŵ�Сһ�����˿��ơ�
"High Card"�����ƣ����Ŵ�С������ͬ���˿��ơ�
���㷵��һ���ַ�������ʾ������ 5 �����У�������ɵ� ����������� ��

ע�⣺���ص��ַ��� ��Сд ������Ŀ������ͬ��
*/


class Solution {
public:
	string bestHand(vector<int>& ranks, vector<char>& suits) {
		unordered_set<char> suitsSet;
		for (char suit : suits) {
			suitsSet.emplace(suit);
		}
		if (suitsSet.size() == 1) {
			return "Flush";
		}
		unordered_map<int, int> h;
		for (int rank : ranks) {
			h[rank]++;
		}
		if (h.size() == 5) {
			return "High Card";
		}
		for (auto [_, val] : h) {
			if (val > 2) {
				return "Three of a Kind";
			}
		}
		return "Pair";
	}
};