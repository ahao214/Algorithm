using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 20.有效的括号
    /// </summary>
    public class IsValid
    {
        public bool Method(string s)
        {
            bool result = false;
            int lenStr = s.Length;
            if (lenStr % 2 != 0)
            {
                return result;
            }
           
            for (int i = 0; i < lenStr / 2; i++)
            {
                s = s.Replace("()", "");
                s = s.Replace("[]", "");
                s = s.Replace("{}", "");
            }
            if (string.IsNullOrEmpty(s))
            {
                result = true;
            }
            return result;
        }
        
    }
}
