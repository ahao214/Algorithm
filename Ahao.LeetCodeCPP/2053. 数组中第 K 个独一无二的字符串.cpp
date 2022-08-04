#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
2053. �����е� K ����һ�޶����ַ���
��һ�޶����ַ��� ָ������һ��������ֻ���ֹ� һ�� ���ַ�����

����һ���ַ������� arr ��һ������ k �����㷵�� arr �е� k �� ��һ�޶����ַ��� ����� ���� k ����һ�޶����ַ�������ô���� ���ַ��� "" ��

ע�⣬�����ַ�����ԭ�����е� ˳�� �ҵ��� k ����һ�޶��ַ�����
*/
class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		unordered_map<string, int> cnt;
		for (auto& s : arr)cnt[s]++;
		for (auto& s : arr)
		{
			if (cnt[s] == 1)
			{
				if (--k == 0)
					return s;
			}
		}
		return "";
	}

};



