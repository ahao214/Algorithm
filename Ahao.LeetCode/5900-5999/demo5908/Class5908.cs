using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5908
{
    /// <summary>
    /// 5980. 将字符串拆分为若干长度为 k 的组
    /// </summary>
    public class Class5908
    {
        public string[] DivideString(string s, int k, char fill)
        {
            List<string> lst = new List<string>();
            int n = s.Length / k;
            int reminder = s.Length % k;
            if (reminder != 0)
            {
                for (int i = 0; i < k - reminder; i++)
                {
                    s += fill;
                }
            }
            for (int i = 0; i < s.Length; i += k)
            {
                lst.Add(s.Substring(i, k));
            }
            return lst.ToArray();
        }
    }
}
