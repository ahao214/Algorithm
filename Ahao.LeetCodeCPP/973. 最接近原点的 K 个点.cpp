#include<vector>
#include <algorithm>

using namespace std;


/*
973. ��ӽ�ԭ��� K ����

����һ������ points ������ points[i] = [xi, yi] ��ʾ X-Y ƽ���ϵ�һ���㣬������һ������ k ��������ԭ�� (0,0) ����� k ���㡣

���ƽ��������֮��ľ����� ŷ����¾��루 ��(x1 - x2)2 + (y1 - y2)2 ����

����԰� �κ�˳�� ���ش𰸡����˵������˳��֮�⣬�� ȷ�� �� Ψһ �ġ�
*/
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
			});
		return vector<vector<int>>(points.begin(), points.begin() + k);
	}
};