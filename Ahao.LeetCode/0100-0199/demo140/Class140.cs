using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo140
{
    /// <summary>
    /// 140. 单词拆分 II
    /// </summary>
    public class Class140
    {
        public IList<string> WordBreak(string s, IList<string> wordDict)
        {
            if (string.IsNullOrEmpty(s))
            {
                return Array.Empty<string>();
            }

            var set = wordDict.ToHashSet();
            var dp = new IEnumerable<IEnumerable<string>>[s.Length + 1];
            dp[0] = new[] { Array.Empty<string>() };
            for (int k = 1; k <= s.Length; k++)
            {
                for (int i = 0; i < k; i++)
                {
                    var word = s.Substring(i, k - i);
                    if (dp[i] != null && set.Contains(word))
                    {
                        dp[k] = Concat(dp[k], Append(dp[i], word));
                    }
                }
            }
            return dp[s.Length] == null ? (IList<string>)Array.Empty<string>() : dp[s.Length].Select(t => string.Join(" ", t)).ToList();
        }

        private IEnumerable<IEnumerable<string>> Append(IEnumerable<IEnumerable<string>> list, string word)
        {
            return list == null ? new[] { new[] { word } } : list.Select(t => t.Append(word));
        }

        private IEnumerable<IEnumerable<string>> Concat(IEnumerable<IEnumerable<string>> list1, IEnumerable<IEnumerable<string>> list2)
        {
            return list1 == null || list2 == null ? list1 ?? list2 : list1.Concat(list2);
        }
    }
}
