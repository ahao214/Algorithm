using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._5200_5299.demo5268
{
    public class Class5268
    {
        /*
         5268. 找出两数组的不同
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，请你返回一个长度为 2 的列表 answer ，其中：

answer[0] 是 nums1 中所有 不 存在于 nums2 中的 不同 整数组成的列表。
answer[1] 是 nums2 中所有 不 存在于 nums1 中的 不同 整数组成的列表。
注意：列表中的整数可以按 任意 顺序返回。
         */
        public IList<IList<int>> FindDifference(int[] nums1, int[] nums2)
        {
            HashSet<int> h1 = new HashSet<int>();
            HashSet<int> h2 = new HashSet<int>();

            HashSet<int> set1 = new HashSet<int>();
            foreach (var item in nums1)
            {                
                set1.Add(item);
            }
            foreach (var item in nums2)
            {
                if (!set1.Contains(item))
                {
                    h2.Add(item);
                }
            }
            HashSet<int> set2 = new HashSet<int>();
            foreach (var item in nums2)
            {
                set2.Add(item);
            }
            foreach (var item in nums1)
            {
                if (!set2.Contains(item))
                    h1.Add(item);
            }

            List<List<int>> res = new List<List<int>>();
            res.Add(h1.ToList());
            res.Add(h2.ToList());

            return res.ToArray();
        }
    }
}
