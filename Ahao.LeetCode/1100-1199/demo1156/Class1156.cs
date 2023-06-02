using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1156
{
    public class Class1156
    {

        public int MaxRepOpt1(string text)
        {
            IDictionary<char, int> count = new Dictionary<char, int>();
            foreach (char c in text)
            {
                count.TryAdd(c, 0);
                count[c]++;
            }

            int res = 0;
            for (int i = 0; i < text.Length;)
            {
                // step1: 找出当前连续的一段 [i, j)
                int j = i;
                while (j < text.Length && text[j] == text[i])
                {
                    j++;
                }
                int curCnt = j - i;

                // step2: 如果这一段长度小于该字符出现的总数，并且前面或后面有空位，则使用 curCnt + 1 更新答案
                if (curCnt < (count.ContainsKey(text[i]) ? count[text[i]] : 0) && (j < text.Length || i > 0))
                {
                    res = Math.Max(res, curCnt + 1);
                }

                // step3: 找到这一段后面与之相隔一个不同字符的另一段 [j + 1, k)，如果不存在则 k = j + 1 
                int k = j + 1;
                while (k < text.Length && text[k] == text[i])
                {
                    k++;
                }
                res = Math.Max(res, Math.Min(k - i, count.ContainsKey(text[i]) ? count[text[i]] : 0));
                i = j;
            }
            return res;
        }



        public int MaxRepOpt1_2(String text)
        {
            char[] chars = text.ToCharArray();
            int[] count = new int[26];
            int n = chars.Length, cnt = 1, res = 1;
            // 记录每种字符出现次数
            foreach (var c in chars)
            {
                count[c - 'a']++;
            }
            // 选定字符开始比对
            char last = chars[0];
            // 从第二个开始匹配
            for (int i = 1; i < n; i++)
            {
                // 匹配成功 当前最长++
                if (chars[i] == last)
                {
                    cnt++;
                }
                else
                {
                    // 从i+1往后找
                    int index = i + 1;
                    // aaabaaa这种只是相隔一个字符的情况，继续往下遍历
                    while (index < n && chars[index] == last)
                    {
                        ++cnt;
                        ++index;
                    }
                    // 如果不是相隔一个字符的情况则更新结果
                    if (count[last - 'a'] > cnt) ++cnt;
                    res = Math.Max(res, cnt);
                    // 当前最长重新设置为1，待比对字符更新为当前字符
                    cnt = 1;
                    last = chars[i];
                }
            }
            // 遍历完成后确定最终答案，选中的字符当前最大长度若小于出现评率则可+1
            // 如 abbaaaa 最终last = chars[3] cnt = 4
            if (count[last - 'a'] > cnt) ++cnt;
            res = Math.Max(res, cnt);
            return res;
        }


    }
}
