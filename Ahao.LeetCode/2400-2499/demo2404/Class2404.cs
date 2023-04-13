using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2404
{
    public class Class2404
    {
        public int MostFrequentEven(int[] nums)
        {
            IDictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var x in nums)
            {
                if (x % 2 == 0)
                {
                    dic.TryAdd(x, 0);
                    dic[x]++;
                }
            }
            int result = -1;
            int count = 0;
            foreach (KeyValuePair<int, int> pair in dic)
            {
                if ((result == -1 || pair.Value > count) || result > pair.Key && pair.Value == count)
                {
                    result = pair.Key;
                    count = pair.Value;
                }
            }
            return result;
        }
    }
}
