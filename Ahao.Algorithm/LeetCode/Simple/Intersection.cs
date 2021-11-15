using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 349.两个数组的交集
    /// </summary>
    public class Intersection
    {
        /// <summary>
        /// 349.两个数组的交集
        /// </summary>
        /// <param name="nums1"></param>
        /// <param name="nums2"></param>
        /// <returns></returns>
        public int[] Method1(int[] nums1, int[] nums2)
        {
            return nums1.Intersect(nums2).ToArray();
        }


        /// <summary>
        /// 350.两个数组的交集(2)
        /// </summary>
        /// <param name="nums1"></param>
        /// <param name="nums2"></param>
        /// <returns></returns>
        public int[] Method2(int[] nums1, int[] nums2)
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
