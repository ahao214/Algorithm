using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC384
{
    public class Class384
    {
        int[] nums;
        int[] original;

        public Class384(int[] nums)
        {
            this.nums = nums;
            this.original = new int[nums.Length];
            Array.Copy(nums, original, nums.Length);
        }

        public int[] Reset()
        {
            Array.Copy(original, nums, nums.Length);
            return nums;
        }

        public int[] Shuffle()
        {
            int[] shuffled = new int[nums.Length];
            IList<int> lst = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                lst.Add(nums[i]);
            }
            Random random = new Random();
            for (int i = 0; i < nums.Length; i++)
            {
                int j = random.Next(lst.Count);
                shuffled[i] = lst[j];
                lst.Remove(lst[j]);
            }
            Array.Copy(shuffled, nums, nums.Length);
            return nums;
        }


    }


    //Fisher-Yates洗牌算法
    public class Solution
    {
        int[] nums;
        int[] original;

        public Solution(int[] nums)
        {
            this.nums = nums;
            this.original = new int[nums.Length];
            Array.Copy(nums, original, nums.Length);
        }

        public int[] Reset()
        {
            Array.Copy(original, nums, nums.Length);
            return nums;
        }

        public int[] Shuffle()
        {
            Random random = new Random();
            for (int i = 0; i < nums.Length; i++)
            {
                int j = random.Next(i, nums.Length);
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            return nums;
        }
    }

}
