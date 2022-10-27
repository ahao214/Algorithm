#include<vector>

using namespace std;


/*
1725. �����γ���������εľ�����Ŀ
����һ������ rectangles ������ rectangles[i] = [li, wi] ��ʾ�� i �����εĳ���Ϊ li �����Ϊ wi ��

������� k ͬʱ���� k <= li �� k <= wi ���Ϳ��Խ��� i �������гɱ߳�Ϊ k �������Ρ����磬���� [4,6] �����гɱ߳����Ϊ 4 �������Ρ�

�� maxLen Ϊ���ԴӾ������� rectangles �зֵõ��� ��������� �ı߳���

����ͳ���ж��ٸ������ܹ��г��߳�Ϊ maxLen �������Σ������ؾ��� ��Ŀ ��
*/
class Solution {
public:
	/*
	�����rectangles������ɾ��ε�����ֵ
	Ȼ����rectangles�ҳ����Ϳ����ڵ������ֵ�ĸ���
	*/
	int countGoodRectangles(vector<vector<int>>& rectangles) {
		int maxLen = 0;
		for (auto& t : rectangles)
			maxLen = max(maxLen, min(t[0], t[1]));
		int res = 0;
		for (auto& t : rectangles)
			if (t[0] >= maxLen && t[1] >= maxLen)
				res++;
		return res;
	}
};