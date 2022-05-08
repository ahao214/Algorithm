using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo442
{
    public class Class442
    {
        /// <summary>
        /// 方法一：将元素交换到对应的位置
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public IList<int> FindDuplicates(int[] nums)
        {
            int n = nums.Length;
            for (int i = 0; i < n; ++i)
            {
                while (nums[i] != nums[nums[i] - 1])
                {
                    Swap(nums, i, nums[i] - 1);
                }
            }
            IList<int> ans = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] - 1 != i)
                {
                    ans.Add(nums[i]);
                }
            }
            return ans;
        }

        public void Swap(int[] nums, int index1, int index2)
        {
            int temp = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = temp;
        }


        /// <summary>
        /// 方法二：使用正负号作为标记
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>

        public IList<int> FindDuplicates2(int[] nums)
        {
            int n = nums.Length;
            IList<int> ans = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                int x = Math.Abs(nums[i]);
                if (nums[x - 1] > 0)
                {
                    nums[x - 1] = -nums[x - 1];
                }
                else
                {
                    ans.Add(x);
                }
            }
            return ans;
        }


    }
}
