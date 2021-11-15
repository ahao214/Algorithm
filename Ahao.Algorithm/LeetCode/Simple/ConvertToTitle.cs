using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 168.Excel表列名称
    /// </summary>
    public class ConvertToTitle
    {
        public string Method(int n)
        {
            string item = string.Empty;
            while (n > 0)
            {
                n--;
                int word = n % 26;
                item = (char)('A' + word) + item;
                n = n / 26;
            }
            return item;
        }
    }
}
