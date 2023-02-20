using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2347
{
    public class Class2347
    {
        public string BestHand(int[] ranks, char[] suits)
        {
            ISet<char> st = new HashSet<char>();
            foreach (var item in suits)
            {
                st.Add(item);
            }

            if (st.Count == 1)
                return "Flush";

            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in ranks)
            {
                dic.TryAdd(item, 0);
                dic[item]++;
            }
            if (dic.Count == 5)
                return "High Card";

            foreach (KeyValuePair<int, int> pair in dic)
            {
                if (pair.Value > 2)
                    return "Three of a Kind";
            }

            return "Pair";
        }


    }
}
