using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo14
{
    public class Class14
    {
        public string LongestCommonPrefix(string[] strs)
        {
            if (strs == null || strs.Length == 0)
                return string.Empty;
            var s = strs[0];
            for (int i = 0; i < s.Length; i++)
            {
                var c = s[i];
                for (int j = 1; j < strs.Length; j++)
                {
                    var sj = strs[j];
                    if (i >= sj.Length || sj[i] != c)
                    {
                        return s.Substring(0, i);
                    }
                }
            }
            return s;
        }
    }
}
