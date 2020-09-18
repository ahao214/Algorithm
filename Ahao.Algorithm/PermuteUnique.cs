using System;
using System.Collections.Generic;
using System.Linq;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 47.全排列(2)
    /// </summary>
    public class PermuteUnique
    {
        public IList<IList<int>> Method(int[] nums)
        {
            if (nums.Length == 0)
            {
                return new List<IList<int>>();
            }
            else if (nums.Length == 1)
            {
                return new List<IList<int>> { new List<int> { nums[0] } };
            }

            Array.Sort(nums);
            var result = new List<IList<int>>();
            //存储已经使用过元素
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(nums[i]))
                {
                    continue;
                }
                dic.Add(nums[i], 1);
                int curreny = nums[i];
                List<int> temp = nums.ToList();
                temp.RemoveAt(i);
                IList<IList<int>> pre = Method(temp.ToArray());
                foreach (var item in pre)
                {
                    item.Insert(0, curreny);
                    result.Add(item);
                }
            }
            return result;
        }
    }
}
