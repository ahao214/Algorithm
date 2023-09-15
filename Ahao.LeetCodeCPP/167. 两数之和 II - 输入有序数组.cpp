#include<vector>

using namespace std;



/*
167. ����֮�� II - ������������

����һ���±�� 1 ��ʼ���������� numbers ���������Ѱ� �ǵݼ�˳������  ��������������ҳ��������֮�͵���Ŀ���� target ������������������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��

�Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2��

����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ�ء�

������ƵĽ����������ֻʹ�ó������Ķ���ռ䡣
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		for (int i = 0, j = n - 1; i < n; i++)
		{
			while (j >= 0 && numbers[i] + numbers[j] > target) j--;
			if (numbers[i] + numbers[j] == target) return { i + 1,j + 1 };
		}
		return { -1, -1 };
	}
};



class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0;
		int j = numbers.size() - 1;
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum < target) {
				i++;
			}
			else if (sum > target) {
				j--;
			}
			else {
				return vector<int>{i + 1, j + 1};
			}
		}
		return vector<int>{-1, -1};
	}
};



class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		while (left < right)
		{
			if (numbers[left] + numbers[right] < target)
				left++;
			else if (numbers[left] + numbers[right] > target)
				right--;
			else
				break;
		}
		return { left + 1,right + 1 };
	}
};