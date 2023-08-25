using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo228
{
    public class Class228
    {
        public IList<string> SummaryRanges(int[] nums)
        {
            List<String> ret = new List<String>();
            int i = 0;
            int n = nums.Length;
            while (i < n)
            {
                int low = i;
                i++;
                while (i < n && nums[i] == nums[i - 1] + 1)
                {
                    i++;
                }
                int high = i - 1;
                StringBuilder tmp = new StringBuilder(nums[low].ToString());
                if (low < high)
                {
                    tmp.Append("->");
                    tmp.Append(nums[high].ToString());
                }
                ret.Add(tmp.ToString());
            }
            return ret;
        }


    }
}
