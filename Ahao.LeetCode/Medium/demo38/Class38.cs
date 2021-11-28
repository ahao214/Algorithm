using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo38
{
    /// <summary>
    /// 38. 外观数列
    /// </summary>
    public class Class38
    {
        public string CountAndSay(int n)
        {
            if (n <= 0)
            {
                return string.Empty;
            }

            var answer = new StringBuilder("1");
            var tmp = new StringBuilder();
            for (int i = 1; i < n; i++)
            {
                var t = answer;
                answer = tmp;
                tmp = t;
                answer.Clear();
                var j = 1;
                var count = 1;
                var ch = tmp[0];
                while (j < tmp.Length)
                {
                    if (tmp[j] == ch)
                    {
                        j++;
                        count++;
                    }
                    else
                    {
                        answer.Append(count).Append(ch);
                        ch = tmp[j];
                        count = 1;
                        j++;
                    }
                }
                answer.Append(count).Append(ch);
            }
            return answer.ToString();
        }
    }
}
