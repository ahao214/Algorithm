#include<vector>
#include<map>


using namespace std;


/*
352. ����������Ϊ������ཻ����
 ����һ���ɷǸ����� a1, a2, ..., an ��ɵ����������룬���㽫��ĿǰΪֹ�����������ܽ�Ϊ���ཻ�������б�

ʵ�� SummaryRanges �ࣺ

SummaryRanges() ʹ��һ������������ʼ������
void addNum(int val) ���������м������� val ��
int[][] getIntervals() �Բ��ཻ���� [starti, endi] ���б���ʽ���ض����������������ܽᡣ
*/
class Solution {
public:
	map<int, int> L, R;
	void SummaryRanges() {

	}

	void addNum(int val) {
		if (L.size())
		{
			auto it = L.lower_bound(val);
			if (it != L.end() && it->second <= val) return;
		}

		int left = L.count(val - 1), right = R.count(val + 1);
		if (left && right)
		{
			R[L[val - 1]] = R[val + 1];
			L[R[val + 1]] = L[val - 1];
			L.erase(val - 1), R.erase(val + 1);
		}
		else if (left)
		{
			R[L[val - 1]] = val;
			L[val] = L[val - 1];
			L.erase(val - 1);
		}
		else if (right)
		{
			L[R[val + 1]] = val;
			R[val] = R[val + 1];
			R.erase(val + 1);
		}
		else
		{
			R[val] = L[val] = val;
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for (auto item : R) res.push_back({ item.first,item.second });
		return res;
	}
};