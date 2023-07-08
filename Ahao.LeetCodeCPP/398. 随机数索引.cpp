#include<vector>
#include<unordered_map>

using namespace std;




/*
398. ���������

����һ�����ܺ��� �ظ�Ԫ�� ���������� nums ������������������Ŀ������ target ������������Լ������������һ�������������С�

ʵ�� Solution �ࣺ

Solution(int[] nums) ������ nums ��ʼ������
int pick(int target) �� nums ��ѡ��һ������ nums[i] == target ��������� i ��������ڶ����Ч����������ÿ�������ķ��ظ���Ӧ����ȡ�
*/
class Solution {
public:
    unordered_map<int, vector<int>> hash;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]].push_back(i);
    }

    int pick(int target) {
        return hash[target][rand() % hash[target].size()];
    }
};

class Solution {
    unordered_map<int, vector<int>> pos;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& indices = pos[target];
        return indices[rand() % indices.size()];
    }
};
