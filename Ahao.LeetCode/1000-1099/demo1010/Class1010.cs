using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1010
{
    public class Class1010
    {
        public int NumPairsDivisibleBy60(int[] time)
        {
            int res = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in time)
            {
                int count = 0;
                dic.TryGetValue((60 - item % 60) % 60, out count);
                res += count;
                if (!dic.ContainsKey(item % 60))
                {
                    dic.Add(item % 60, 1);
                }
                else
                {
                    dic[item % 60]++;
                }
            }
            return res;
        }

    }
}
