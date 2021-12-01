using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1446
{
    /// <summary>
    /// 1446. 连续字符
    /// </summary>
    public class Class1446
    {
        public int MaxPower(string s)
        {
            int result = 1;
            int count = 1;
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == s[i - 1])
                {
                    count++;
                    result = Math.Max(result, count);
                }
                else
                {
                    count = 1;
                }
            }
            return result;
        }
    }
}
