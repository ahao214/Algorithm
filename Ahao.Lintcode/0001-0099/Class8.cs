using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._0001_0099
{
    #region 8 · 旋转字符串

    /*
     给定一个字符串str和一个偏移量，根据偏移量原地旋转字符串(从左向右旋转)。    
     */

    #endregion
    public class Class8
    {
        public void RotateString(char[] s, int offset)
        {
            if (offset == 0)
                s = s;
            int first = s.Length - offset;
            string arr = string.Empty;
            for (int i = 0; i < s.Length; i++)
            {
                arr += s[i];
            }
            string front = arr.Substring(0, first);
            string end = arr.Substring(first);            
            string ns = "\"" + (end + front) + "\"";
            s = ns.ToCharArray();
        }
    }
}
