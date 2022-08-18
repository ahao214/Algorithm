using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1224
{
    public class Class1224
    {

        public int MaxEqualFreq(int[] nums)
        {
            Dictionary<int, int> freq = new Dictionary<int, int>();
            Dictionary<int, int> count = new Dictionary<int, int>();
            int res = 0, maxFreq = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (!count.ContainsKey(nums[i]))
                {
                    count.Add(nums[i], 0);
                }
                if (count[nums[i]] > 0)
                {
                    freq[count[nums[i]]]--;
                }
                count[nums[i]]++;
                maxFreq = Math.Max(maxFreq, count[nums[i]]);
                if (!freq.ContainsKey(count[nums[i]]))
                {
                    freq.Add(count[nums[i]], 0);
                }
                freq[count[nums[i]]]++;
                bool ok = maxFreq == 1 ||
                        freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                        freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
                if (ok)
                {
                    res = Math.Max(res, i + 1);
                }
            }
            return res;
        }

    }
}
