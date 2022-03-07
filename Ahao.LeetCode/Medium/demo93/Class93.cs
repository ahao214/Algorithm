using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo93
{
    /*
     93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
     */
    public class Class93
    {
        IList<string> res = new List<string>();
        int count = 4;
        int[] add;
        public IList<string> RestoreIpAddresses(string s)
        {
            add = new int[count];
            dfs(s, 0, 0);
            return res;
        }
        private void dfs(string s, int index, int start)
        {
            //终止条件
            if (index == count)
            {
                if (start == s.Length)
                {
                    StringBuilder sb = new StringBuilder();
                    for (int end = 0; end < count; end++)
                    {
                        sb.Append(add[end]);
                        if (end != count - 1)
                        {
                            sb.Append(".");
                        }
                    }
                    res.Add(sb.ToString());
                }
                return;
            }

            if (start == s.Length)
                return;

            //0的情况
            if (s[start] == '0')
            {
                add[index] = 0;
                dfs(s, index + 1, start + 1);
            }

            int a = 0;
            for (int end = start; end < s.Length; end++)
            {
                a = a * 10 + int.Parse(s[end].ToString());
                if (a > 0 && a <= 255)
                {
                    add[index] = a;
                    dfs(s, index + 1, end + 1);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
