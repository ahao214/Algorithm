using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5967
{
    /// <summary>
    /// 5967. 检查是否所有 A 都在 B 之前
    /// </summary>
    public class Class5967
    {
        public bool CheckString(string s)
        {
            if (s.Length == 1)
            {
                return true;
            }
            int count = 0;
            if (s[0] == 'a')
            {
                for (int i = 1; i < s.Length; i++)
                {
                    if (s[i] == s[i - 1])
                    {
                        continue;
                    }
                    if (s[i] != s[i - 1])
                    {
                        count++;
                    }
                }
            }
            if (s[0] == 'b')
            {
                for (int i = 1; i < s.Length; i++)
                {
                    if (s[i] != s[0])
                    {
                        return false;
                    }
                }
            }
            return count == 1 || count == 0;
        }
    }
}
