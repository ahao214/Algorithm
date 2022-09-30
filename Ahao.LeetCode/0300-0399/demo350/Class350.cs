using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo350
{
    public class Class350
    {
        public int[] Intersect(int[] nums1, int[] nums2)
        {
            var dict = new Dictionary<int, int>();
            List<int> list = new List<int>();
            if (nums1.Length == 0 || nums2.Length == 0)
            {
                return list.ToArray();
            }
            foreach (int n in nums1)
            {
                if (dict.ContainsKey(n))
                {
                    dict[n]++;
                }
                else
                {
                    dict.Add(n, 1);
                }
            }
            foreach (int n in nums2)
            {
                if (dict.ContainsKey(n) && dict[n] > 0)
                {
                    dict[n]--;
                    list.Add(n);
                }
            }
            return list.ToArray();
        }
    }
}
