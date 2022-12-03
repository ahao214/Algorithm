#include<vector>

using namespace std;


/*
223. �������
���� ��ά ƽ�������� ��ֱ�߹����ұ���������ƽ��/��ֱ �ľ��Σ�������㲢�����������θ��ǵ��������

ÿ���������� ���� ����� ���� ���������ʾ��

��һ�������������¶��� (ax1, ay1) �����϶��� (ax2, ay2) ���塣
�ڶ��������������¶��� (bx1, by1) �����϶��� (bx2, by2) ���塣
*/
class Solution {
public:
	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		long long x = min(ax2, bx2) + 0ll - max(ax1, bx1);
		long long y = min(ay2, by2) + 0ll - max(ay1, by1);
		return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - max(0ll, x) * (0ll, y);
	}
};