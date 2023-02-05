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
            int n = queries.Length; ;
            int[] result = new int[n];
            List<int> lst = new List<int>();
            List<int> res = new List<int>();
            for (int i = 0; i < words.Length; i++)
            {
                if ((words[i].Substring(0,1).ToString() == "a" || words[i].Substring(0, 1).ToString() == "e" || words[i].Substring(0, 1).ToString() == "i" || words[i].Substring(0, 1).ToString() == "o" || words[i].Substring(0, 1).ToString() == "u") && (words[i].Substring(words[i].Length - 1, 1).ToString() == "a" || words[i].Substring(words[i].Length - 1, 1).ToString() == "e" || words[i].Substring(words[i].Length - 1, 1).ToString() == "i" || words[i].Substring(words[i].Length - 1, 1).ToString() == "o" || words[i].Substring(words[i].Length - 1, 1).ToString() == "u"))
                {
                    lst.Add(i);
                }
            }
            for (int i = 0; i < queries.Length; i++)
            {
                int count = 0;
                for(int j = queries [i][0];j <=queries[i][1]; j++)
                {
                    if (lst.Contains(j))
                        count++;
                }
                res.Add(count);
            }

            return res.ToArray();
        }
    }
}
