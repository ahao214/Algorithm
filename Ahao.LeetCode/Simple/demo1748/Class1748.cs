using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1748
{
    /*
    1748. 唯一元素的和
    给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
    请你返回 nums 中唯一元素的 和 。
     */
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
