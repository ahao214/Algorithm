using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2085
{
    public class Class2085
    {
        public int CountWords(string[] words1, string[] words2)
        {
            // 统计字符串出现频率
            IDictionary<string, int> freq1 = new Dictionary<string, int>();
            IDictionary<string, int> freq2 = new Dictionary<string, int>();
            foreach (var item in words1)
            {
                if (!freq1.ContainsKey(item))
                    freq1.Add(item, 1);
                else
                    freq1[item]++;
            }
            foreach (var item in words2)
            {
                if (!freq2.ContainsKey(item))
                    freq2.Add(item, 1);
                else
                    freq2[item]++;
            }

            // 遍历 words1 出现的字符串并检查个数
            int res = 0;
            foreach (var w in freq1)
            {
                if (w.Value == 1 && freq2.ContainsKey(w.Key) && freq2[w.Key] == 1)
                    res++;                
            }
            return res;
        }



    }
}
