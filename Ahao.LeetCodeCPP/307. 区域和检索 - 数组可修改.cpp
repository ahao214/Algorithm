using namespace std;
#include<vector>
#include <numeric>

class NumArray {
private:
    vector<int> sum; // sum[i] ��ʾ�� i �����Ԫ�غ�
    int size; // ��Ĵ�С
    vector<int>& nums;
public:
    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n + size - 1) / size); // n/size ����ȡ��
        for (int i = 0; i < n; i++) {
            sum[i / size] += nums[i];
        }
    }

    void update(int index, int val) {
        sum[index / size] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
        if (b1 == b2) { // ���� [left, right] ��ͬһ����
            return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
        }
        int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
        int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
        int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
        return sum1 + sum2 + sum3;
    }
};




/*
307. ����ͼ��� - ������޸�

����һ������ nums ��������������ѯ��

����һ���ѯҪ�� ���� ���� nums �±��Ӧ��ֵ
��һ���ѯҪ�󷵻����� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� �� ������ left <= right
ʵ�� NumArray �ࣺ

NumArray(int[] nums) ���������� nums ��ʼ������
void update(int index, int val) �� nums[index] ��ֵ ���� Ϊ val
int sumRange(int left, int right) �������� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� �� ������nums[left] + nums[left + 1], ..., nums[right]��
*/
class NumArray {
public:
	int n;
	vector<int> tr, num;
	int lowbit(int x)
	{
		return x & -x;
	}

	int query(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}

	NumArray(vector<int>& nums) {
		num = nums;
		n = num.size();
		tr.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			tr[i] = num[i - 1];
			for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
				tr[i] += tr[j];
		}
	}

	void update(int index, int val) {
		add(index + 1, val - num[index]);
		num[index] = val;
	}

	int sumRange(int left, int right) {
		return query(right + 1) - query(left);
	}
};
