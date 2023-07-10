using namespace std;
#include<vector>
#include <numeric>

class NumArray {
private:
    vector<int> sum; // sum[i] 表示第 i 个块的元素和
    int size; // 块的大小
    vector<int>& nums;
public:
    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n + size - 1) / size); // n/size 向上取整
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
        if (b1 == b2) { // 区间 [left, right] 在同一块中
            return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
        }
        int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
        int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
        int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
        return sum1 + sum2 + sum3;
    }
};




/*
307. 区域和检索 - 数组可修改

给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
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
