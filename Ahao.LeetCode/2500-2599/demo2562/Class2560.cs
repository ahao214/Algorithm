using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2562
{
    internal class Class2562
    {

        public long FindTheArrayConcVal(int[] nums)
        {
            long res = 0;
            int l = 0;
            int r = nums.Length - 1;
            string s = string.Empty;
            while (l < r)
            {
                s += nums[l].ToString();
                s += nums[r].ToString();
                res += Convert.ToInt64(s);
                s = string.Empty;
                l++;
                r--;
            }
            if (nums.Length % 2 != 0)
            {
                res += nums[nums.Length / 2];
            }
            return res;
        }




        public long FindTheArrayConcVal2(int[] nums)
        {
            long ans = 0;
            for (int i = 0, j = nums.Length - 1; i <= j; i++, j--)
            {
                if (i != j)
                {
                    ans += int.Parse(nums[i].ToString() + nums[j].ToString());
                }
                else
                {
                    ans += nums[i];
                }
            }
            return ans;
        }


    }
}
