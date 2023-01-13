using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2287
{
    public class Class2287
    {
        public int RearrangeCharacters(string s, string target)
        {
            IDictionary<char, int> sCounts = new Dictionary<char, int>();
            IDictionary<char, int> targetCounts = new Dictionary<char, int>();
            foreach (char c in target)
            {
                targetCounts.TryAdd(c, 0);
                targetCounts[c]++;
            }
            foreach (char c in s)
            {
                if (targetCounts.ContainsKey(c))
                {
                    sCounts.TryAdd(c, 0);
                    sCounts[c]++;
                }
            }
            int ans = int.MaxValue;
            foreach (KeyValuePair<char, int> pair in targetCounts)
            {
                char c = pair.Key;
                int count = pair.Value;
                int totalCount = sCounts.ContainsKey(c) ? sCounts[c] : 0;
                ans = Math.Min(ans, totalCount / count);
                if (ans == 0)
                {
                    return 0;
                }
            }
            return ans;
        }



        public int RearrangeCharacters2(string s, string target)
        {
            //最多26个字母，s长度为100
            var sList = new int[26];
            var targetList = new int[26];
            var res = int.MaxValue;

            //统计s和target中各字母的个数
            foreach (char item in s)
                sList[item - 'a']++;

            foreach (char item in target)
                targetList[item - 'a']++;

            //计算各个字母
            for (int i = 0; i < 26; i++)
            {
                //target存在此字母时，结果为s中的个数除以target中的个数，更新最小值
                if (targetList[i] != 0)
                    res = Math.Min(res, sList[i] / targetList[i]);
            }

            return res;
        }
    }
}
