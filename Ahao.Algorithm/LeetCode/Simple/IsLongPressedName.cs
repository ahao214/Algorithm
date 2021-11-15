using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 925.长按键入
    /// </summary>
    public class IsLongPressedName
    {
        public bool Method(string name, string typed)
        {
            if (name == typed)
            {
                return true;
            }
            if (name.Length > typed.Length)
            {
                return false;
            }

            char[] names = name.ToCharArray();
            char[] typeds = typed.ToCharArray();
            int i = 0;
            int n = names.Length;
            int t = typeds.Length;
            for (int j = 0; j < t; j++)
            {
                if (i < n && names[i] == typeds[j])
                {
                    i++;
                }
                else if (j == 0 || typeds[j] != typeds[j - 1])
                {
                    return false;
                }
            }

            return i == n;
        }
    }
}
