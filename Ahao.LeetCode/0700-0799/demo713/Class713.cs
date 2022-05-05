using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC713
{
    public class Class713
    {
        public int NumSubarrayProductLessThanK(int[] nums, int k)
        {
            if (nums == null || nums.Length == 0 || k == 0)
            {
                return 0;
            }

            int res = 0, left = 0, right = 0, prod = 1;

            while (left < nums.Length)
            {
                if (right < nums.Length && prod * nums[right] < k)
                {
                    prod = prod * nums[right];
                    right++;
                }
                else if (left == right)
                {
                    left++;
                    right++;
                }
                else
                {
                    res += right - left;
                    prod = prod / nums[left];
                    left++;
                }
            }
            return res;
        }


        //方法一：二分查找
        public int NumSubarrayProductLessThanK2(int[] nums, int k)
        {
            if (k == 0)
            {
                return 0;
            }
            int n = nums.Length;
            double[] logPrefix = new double[n + 1];
            for (int i = 0; i < n; i++)
            {
                logPrefix[i + 1] = logPrefix[i] + Math.Log(nums[i]);
            }
            double logk = Math.Log(k);
            int ret = 0;
            for (int j = 0; j < n; j++)
            {
                int l = 0;
                int r = j + 1;
                int idx = j + 1;
                double val = logPrefix[j + 1] - logk + 1e-10;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (logPrefix[mid] > val)
                    {
                        idx = mid;
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                ret += j + 1 - idx;
            }
            return ret;
        }


        //方法二：滑动窗口   
        public int NumSubarrayProductLessThanK3(int[] nums, int k)
        {
            int n = nums.Length, ret = 0;
            int prod = 1, i = 0;
            for (int j = 0; j < n; j++)
            {
                prod *= nums[j];
                while (i <= j && prod >= k)
                {
                    prod /= nums[i];
                    i++;
                }
                ret += j - i + 1;
            }
            return ret;
        }

    }
}
