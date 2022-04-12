using namespace std;
#include<string>;
#include<vector>;
#include <unordered_map>

class Solution {
public:
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="target"></param>
	/// <returns></returns>
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == target) {
					return { i,j };
				}
			}
		}
		return {};
	}
};



class Solution {
	/*
	1. ����֮��
	����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
	����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
	����԰�����˳�򷵻ش𰸡�
	*/
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//�����ϣ��
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); ++i) {
			int num = target - nums[i];
			if (record.find(num) != record.end()) {
				return { record[num],i };
			}
			record[nums[i]] = i;
		}
		return { -1, -1 };
	}
};