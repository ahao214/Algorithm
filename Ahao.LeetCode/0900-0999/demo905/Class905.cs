using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo905
{
    public class Class905
    {
        /// <summary>
        /// 方法一：两次遍历
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int[] SortArrayByParity(int[] nums)
        {
            int n = nums.Length, index = 0;
            int[] res = new int[n];
            foreach (int num in nums)
            {
                if (num % 2 == 0)
                {
                    res[index++] = num;
                }
            }
            foreach (int num in nums)
            {
                if (num % 2 == 1)
                {
                    res[index++] = num;
                }
            }
            return res;
        }

        /// <summary>
        /// 方法二：双指针 + 一次遍历
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int[] SortArrayByParity2(int[] nums)
        {
            int n = nums.Length;
            int[] res = new int[n];
            int left = 0, right = n - 1;
            foreach (int num in nums)
            {
                if (num % 2 == 0)
                {
                    res[left++] = num;
                }
                else
                {
                    res[right--] = num;
                }
            }
            return res;
        }

        /// <summary>
        /// 方法三：原地交换
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int[] SortArrayByParity3(int[] nums)
        {
            int left = 0, right = nums.Length - 1;
            while (left < right)
            {
                while (left < right && nums[left] % 2 == 0)
                {
                    left++;
                }
                while (left < right && nums[right] % 2 == 1)
                {
                    right--;
                }
                if (left < right)
                {
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    left++;
                    right--;
                }
            }
            return nums;
        }

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/sort-array-by-parity/solution/an-qi-ou-pai-xu-shu-zu-by-leetcode-solut-gpmm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

    }
}
