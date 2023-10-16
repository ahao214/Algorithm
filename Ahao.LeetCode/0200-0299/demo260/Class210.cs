using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo260
{
    internal class Class260
    {

        public int[] SingleNumber(int[] nums)
        {
            Dictionary<int, int> freq = new Dictionary<int, int>();
            foreach (int num in nums)
            {
                if (freq.ContainsKey(num))
                {
                    ++freq[num];
                }
                else
                {
                    freq.Add(num, 1);
                }
            }
            int[] ans = new int[2];
            int index = 0;
            foreach (KeyValuePair<int, int> pair in freq)
            {
                if (pair.Value == 1)
                {
                    ans[index++] = pair.Key;
                }
            }
            return ans;
        }


        public int[] SingleNumber2(int[] nums)
        {
            int xorsum = 0;
            foreach (int num in nums)
            {
                xorsum ^= num;
            }
            // 防止溢出
            int lsb = (xorsum == int.MinValue ? xorsum : xorsum & (-xorsum));
            int type1 = 0, type2 = 0;
            foreach (int num in nums)
            {
                if ((num & lsb) != 0)
                {
                    type1 ^= num;
                }
                else
                {
                    type2 ^= num;
                }
            }
            return new int[] { type1, type2 };
        }

    }
}
