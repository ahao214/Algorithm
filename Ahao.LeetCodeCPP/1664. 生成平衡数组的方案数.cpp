#include<vector>

using namespace std;


/*
1664. ����ƽ������ķ�����

����һ���������� nums ������Ҫѡ�� ǡ�� һ���±꣨�±�� 0 ��ʼ����ɾ����Ӧ��Ԫ�ء���ע��ʣ��Ԫ�ص��±���ܻ���Ϊɾ�������������ı䡣

�ȷ�˵����� nums = [6,1,7,4,1] ����ô��

ѡ��ɾ���±� 1 ��ʣ�µ�����Ϊ nums = [6,7,4,1] ��
ѡ��ɾ���±� 2 ��ʣ�µ�����Ϊ nums = [6,1,4,1] ��
ѡ��ɾ���±� 4 ��ʣ�µ�����Ϊ nums = [6,1,7,4] ��
���һ���������������±�Ԫ�صĺ���ż���±�Ԫ�صĺ���ȣ����������һ�� ƽ������ ��

���㷵��ɾ��������ʣ�µ����� nums �� ƽ������ �� ������ ��
*/
class Solution {
public:
	/*
	�����������ܺ�sum
	����λ֮�ͣ�ɾ��ĳ��iֵ֮������λ������֮�͵���iΪ֮ǰ����λ֮�ͺ�iλ֮��ż��λ֮��
	ż��λ֮�ͣ�sum - arr[i] - ����λ֮��
	*/
	int waysToMakeFair(vector<int>& nums) {
		int n = nums.size();
		vector<int> s1(n + 1), s2(n + 1);
		for (int i = 1; i <= n; i++)
		{
			s1[i] = s1[i - 1], s2[i] = s2[i - 1];
			if (i % 2) s1[i] += nums[i - 1];
			else s2[i] += nums[i - 1];
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			//����λ֮��
			int odd = s1[i - 1] + s2[n] - s2[i];
			//ż��λ֮��
			int even = s2[i - 1] + s1[n] - s1[i];
			if (odd == even) res++;
		}
		return res;
	}
};



//��̬�滮
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd1 = 0, even1 = 0;
        int odd2 = 0, even2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 += nums[i];
            }
            else {
                even2 += nums[i];
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 -= nums[i];
            }
            else {
                even2 -= nums[i];
            }
            if (odd1 + even2 == odd2 + even1) {
                ++res;
            }
            if (i & 1) {
                odd1 += nums[i];
            }
            else {
                even1 += nums[i];
            }
        }
        return res;
    }
};
