using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Difficulty.LC4
{
    /// <summary>
    /// 4. 寻找两个正序数组的中位数
    /// </summary>
    public class Class004
    {
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            //从nums1中取出K1个数，从nums2中取出K2个数
            //满足：
            //1. k1+k2=N/2
            //2. nums1[k1-1]<=nums2[k2] && nums2[k2-1]<=nums1[k1]

            //n为奇数，返回 Min(nums1[k1],nums2[k2])
            //n为偶数，返回(Max(nums1[k1-1],B[k2-1])+Min(nums1[k1],nums2[k2]))

            nums1 = nums1 ?? Array.Empty<int>();
            nums2 = nums2 ?? Array.Empty<int>();
            var m1 = 0;
            var m2 = nums1.Length;
            var k = (nums1.Length + nums2.Length) / 2;

            while (m1 < m2)
            {
                var k1 = (m1 + m2) / 2;
                var k2 = k - k1;

                if (k2 < 0)
                {
                    m2 = k1 - 1;
                    continue;
                }

                if (k2 > nums2.Length)
                {
                    m1 = k1 + 1;
                    continue;
                }

                if (Get(nums1, k1 - 1) > Get(nums2, k2))
                {
                    m2 = k1 - 1;
                    continue;
                }
                if (Get(nums2, k2 - 1) > Get(nums1, k1))
                {
                    m1 = k1 + 1;
                    continue;
                }
                m1 = k1;
                break;
            }

            {
                var k1 = m1;
                var k2 = k - k1;
                if ((nums1.Length + nums2.Length) % 2 == 1)
                {
                    return Math.Min(Get(nums1, k1), Get(nums2, k2));
                }

                return (Math.Max(Get(nums1, k1 - 1), Get(nums2, k2 - 1)) + Math.Min(Get(nums1, k1), Get(nums2, k2))) / 2.0d;
            }

            int Get(int[] nums, int index)
            {
                if (index >= 0 && index < nums.Length)
                {
                    return nums[index];
                }
                if (index == -1)
                    return int.MinValue;
                if (index == nums.Length)
                    return int.MaxValue;
                throw new IndexOutOfRangeException();
            }
        }
    }
}
