using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6347. 统计范围内的元音字符串数 
给你一个下标从 0 开始的字符串数组 words 以及一个二维整数数组 queries 。

每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（包含 这两个值）并且以元音开头和结尾的字符串的数目。

返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。

注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。
     */
    public class Class6347
    {
        public int[] VowelStrings(string[] words, int[][] queries)
        {
            ISet<char> st = new HashSet<char>();
            st.Add('a');
            st.Add('e');
            st.Add('i');
            st.Add('o');
            st.Add('u');
            int n = words.Length; ;

            int[] val = new int[n];
            for (int i = 0; i < n; i++)
            {
                if (st.Contains(words[i][0]) && st.Contains(words[i][words.Length - 1]))
                    val[i] = 1;
            }
            int[] sum = new int[n + 1];
            for (int i = 1; i <= n; ++i)
            {
                sum[i] = sum[i - 1] + val[i - 1];
            }

            int[] result = new int[queries.Length];
            for (int i = 0; i < queries.Length; i++)
            {
                result[i] = sum[queries[i][1] + 1] - sum[queries[i][0]];
            }
            return result;

            List<int> lst = new List<int>();
            Dictionary<int, int> dic = new Dictionary<int, int>();
            List<int> res = new List<int>();
            for (int i = 0; i < words.Length; i++)
            {
                if ((words[i].Substring(0, 1).ToString() == "a" || words[i].Substring(0, 1).ToString() == "e" || words[i].Substring(0, 1).ToString() == "i" || words[i].Substring(0, 1).ToString() == "o" || words[i].Substring(0, 1).ToString() == "u") && (words[i].Substring(words[i].Length - 1, 1).ToString() == "a" || words[i].Substring(words[i].Length - 1, 1).ToString() == "e" || words[i].Substring(words[i].Length - 1, 1).ToString() == "i" || words[i].Substring(words[i].Length - 1, 1).ToString() == "o" || words[i].Substring(words[i].Length - 1, 1).ToString() == "u"))
                {
                    lst.Add(i);
                    dic.Add(i, 1);
                }
            }
            for (int i = 0; i < queries.Length; i++)
            {
                int first = queries[i][0];
                int last = queries[i][1];
                int count = 0;
                while (lst.IndexOf(first) == -1)
                {
                    first++;
                }
                while (lst.IndexOf(last) == -1)
                {
                    last--;
                }

                if (lst.IndexOf(first) != -1 && lst.IndexOf(last) != -1 && first <= last)
                {
                    count = lst.IndexOf(last) - lst.IndexOf(first) + 1;
                }


                res.Add(count);
            }

            return res.ToArray();
        }
    }
}
