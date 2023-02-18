#include<vector>

using namespace std;

/*
1237. �ҳ��������̵���������

����һ������  f(x, y) ��һ��Ŀ���� z��������ʽδ֪��������㷽�� f(x,y) == z ���п��ܵ������� ���� x �� y�����������Ľ�����Կ��԰�����˳�򷵻ء�

���ܺ����ľ���ʽ��δ֪�������ǵ�������������Ҳ����˵��

f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
�����ӿڶ������£�

interface CustomFunction {
public:
  // Returns some positive integer f(x, y) for two positive integers x and y based on a formula.
  int f(int x, int y);
};
��Ľ�������������¹���������У�

���������һ���� CustomFunction �� 9 ��ʵ����ɵ��б��Լ�һ��Ϊ�ض��� z ����������Ч���ԵĴ𰸵ķ�����
�����������������룺function_id������ʹ������ʵ�ֲ�����Ĵ��룩�Լ�Ŀ���� z ��
������򽫻������ʵ�ֵ� findSolution ������Ľ����𰸽��бȽϡ�
�����Ľ������������ô�����������������ȷ�𰸣��� Accepted ��
*/


class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> res;
		for (int x = 1; x <= 1000; x++) {
			for (int y = 1; y <= 1000; y++) {
				if (customfunction.f(x, y) == z) {
					res.push_back({ x, y });
				}
			}
		}
		return res;
	}
};


class CustomFunction {
public:
	// Returns f(x, y) for any given positive integers x and y.
	// Note that f(x, y) is increasing with respect to both x and y.
	// i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y);

};


//���ֲ���
class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> res;
		for (int x = 1; x <= 1000; x++) {
			int yleft = 1, yright = 1000;
			while (yleft <= yright) {
				int ymiddle = (yleft + yright) / 2;
				if (customfunction.f(x, ymiddle) == z) {
					res.push_back({ x, ymiddle });
					break;
				}
				if (customfunction.f(x, ymiddle) > z) {
					yright = ymiddle - 1;
				}
				else {
					yleft = ymiddle + 1;
				}
			}
		}
		return res;
	}
};


//˫ָ��
class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> res;
		for (int x = 1, y = 1000; x <= 1000 && y >= 1; x++) {
			while (y >= 1 && customfunction.f(x, y) > z) {
				y--;
			}
			if (y >= 1 && customfunction.f(x, y) == z) {
				res.push_back({ x, y });
			}
		}
		return res;
	}
};
