using namespace std;
#include<string>;
#include<vector>;

#pragma region 15. ��ά�����еĲ���

/*
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������

�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

���ݷ�Χ
��ά������Ԫ�ظ�����Χ [0,1000]
����
�������飺

[
  [1,2,8,9]��
  [2,4,9,12]��
  [4,7,10,13]��
  [6,8,11,15]
]

������������ֵΪ7���򷵻�true��

������������ֵΪ5���򷵻�false��
*/

/*
˼·��
���ǿ��Դ�������������Ͻǿ�ʼö�٣����赱ǰö�ٵ����� xx��

��� xx ����target����˵�������ҵ���Ŀ��ֵ������true��
��� xx С��target���� xx ��ߵ���һ����С��target�����ǿ���ֱ���ų���ǰһ���е�����
��� xx ����target���� xx �±ߵ���һ��������target�����ǿ���ֱ������ǰһ���е�����
�ų�һ���о�����ö�ٵĵ�ĺ������һ���ų�һ���о������������һ��
�������ų��������������û���ҵ�Ŀ��ֵʱ����˵��Ŀ��ֵ�����ڣ�����false��

ʱ�临�Ӷȷ���
ÿһ�����ų�һ�л���һ�У�����һ���� nn �У�mm �У������������ n+mn+m ����
����ʱ�临�Ӷ��� O(n+m)O(n+m)��
*/

#pragma endregion

class Solution {
public:
	bool searchArray(vector<vector<int>> array, int target) {
		if (array.empty() || array[0].empty()) return false;
		int i = 0, j = array[0].size() - 1;
		while (i < array.size() && j >= 0) {
			if (array[i][j] == target) return true;
			if (array[i][j] > target) j--;
			else i++;
		}
		return false;
	}
};
