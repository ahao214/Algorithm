using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo307
{
    public class Class307
    {
        private int[] sum; // sum[i] 表示第 i 个块的元素和
        private int size; // 块的大小
        private int[] nums;

        public Class307(int[] nums)
        {
            this.nums = nums;
            int n = nums.Length;
            size = (int)Math.Sqrt(n);
            sum = new int[(n + size - 1) / size]; // n/size 向上取整
            for (int i = 0; i < n; i++)
            {
                sum[i / size] += nums[i];
            }
        }

        public void Update(int index, int val)
        {
            sum[index / size] += val - nums[index];
            nums[index] = val;
        }

        public int SumRange(int left, int right)
        {
            int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
            if (b1 == b2)
            { // 区间 [left, right] 在同一块中
                int sum = 0;
                for (int j = i1; j <= i2; j++)
                {
                    sum += nums[b1 * size + j];
                }
                return sum;
            }
            int sum1 = 0;
            for (int j = i1; j < size; j++)
            {
                sum1 += nums[b1 * size + j];
            }
            int sum2 = 0;
            for (int j = 0; j <= i2; j++)
            {
                sum2 += nums[b2 * size + j];
            }
            int sum3 = 0;
            for (int j = b1 + 1; j < b2; j++)
            {
                sum3 += sum[j];
            }
            return sum1 + sum2 + sum3;
        }

    }
}
