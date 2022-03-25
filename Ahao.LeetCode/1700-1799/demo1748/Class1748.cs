using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1748
{
    public class Class1748
    {
        public int SumOfUnique(int[] nums)
        {
            int res = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in nums)
            {
                if (!dic.ContainsKey(item))
                {
                    dic.Add(item, 1);
                }
                else
                {
                    ++dic[item];
                }
            }
            foreach (var item in dic)
            {
                if (item.Value == 1)
                {
                    res += item.Key;
                }
            }
            return res;
        }
    }
}
