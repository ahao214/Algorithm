using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo553
{
    public class Class553
    {
        public string OptimalDivision(int[] nums)
        {
            int size = nums.Length;
            if (size == 1)
                return nums[0].ToString();
            if (size == 2)
                return nums[0].ToString() + "/" + nums[1].ToString();
            string res = string.Empty;
            res += nums[0] + "/(" + nums[1];
            for (int i = 2; i < size; i++)
            {
                res += "/";
                res += nums[i];
            }
            res += ")";

            return res;
        }


        public string OptimalDivision1(int[] nums)
        {
            int n = nums.Length;
            if (n == 1)
            {
                return nums[0].ToString();
            }
            if (n == 2)
            {
                return nums[0].ToString() + "/" + nums[1].ToString();
            }
            StringBuilder res = new StringBuilder();
            res.Append(nums[0]);
            res.Append("/(");
            res.Append(nums[1]);
            for (int i = 2; i < n; i++)
            {
                res.Append("/");
                res.Append(nums[i]);
            }
            res.Append(")");
            return res.ToString();
        }
    }
}
