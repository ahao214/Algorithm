using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo791
{
    public class Class791
    {
        /// <summary>
        /// 自定义排序
        /// </summary>
        /// <param name="order"></param>
        /// <param name="s"></param>
        /// <returns></returns>
        public string CustomSortString(string order, string s)
        {
            int[] val = new int[26];
            for (int i = 0; i < order.Length; ++i)
            {
                val[order[i] - 'a'] = i + 1;
            }
            char[] arr = s.ToCharArray();
            Array.Sort(arr, (c0, c1) => val[c0 - 'a'] - val[c1 - 'a']);
            return new string(arr);
        }


        /// <summary>
        /// 计数排序
        /// </summary>
        /// <param name="order"></param>
        /// <param name="s"></param>
        /// <returns></returns>
        public string CustomSortString2(string order, string s)
        {
            int[] freq = new int[26];
            foreach (char ch in s)
            {
                ++freq[ch - 'a'];
            }
            StringBuilder ans = new StringBuilder();
            foreach (char ch in order)
            {
                while (freq[ch - 'a'] > 0)
                {
                    ans.Append(ch);
                    freq[ch - 'a']--;
                }
            }
            for (int i = 0; i < 26; ++i)
            {
                while (freq[i] > 0)
                {
                    ans.Append((char)(i + 'a'));
                    freq[i]--;
                }
            }
            return ans.ToString();
        }


    }
}
