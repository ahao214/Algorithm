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



        public int NumPairsDivisibleBy602(int[] time)
        {
            int[] cnt = new int[60];
            foreach (int t in time)
            {
                cnt[t % 60]++;
            }
            long res = 0;
            for (int i = 1; i < 30; i++)
            {
                res += cnt[i] * cnt[60 - i];
            }
            res += (long)cnt[0] * (cnt[0] - 1) / 2 + (long)cnt[30] * (cnt[30] - 1) / 2;
            return (int)res;
        }


    }
}
