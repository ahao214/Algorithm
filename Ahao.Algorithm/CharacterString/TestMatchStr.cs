using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 进行通配符匹配
    /// </summary>
    public class TestMatchStr
    {
        public bool Match(char[] str, char[] strpattern)
        {
            int nStr = str.Length;
            int nPatt = strpattern.Length;
            int[][] pTable = new int[nStr + 1][];
            for (int k = 0; k <= nStr; k++)
            {
                pTable[k] = new int[nPatt + 1];
            }

            if (strpattern[0] == '*')
            {
                for (int i = 0; i <= nPatt; i++)
                {
                    pTable[0][i] = 1;
                }
            }
            pTable[0][0] = 1;
            for (int j = 1; j <= nPatt; ++j)
            {
                for (int i = 1; i <= nStr; ++i)
                {
                    if ((strpattern[j - 1] == '?' && str[i - 1] != '\0') || strpattern[j - 1] == str[i - 1])
                    {
                        pTable[i][j] = pTable[i - 1][j - 1];
                    }
                    else if (strpattern[j - 1] == '*')
                    {
                        if (pTable[i][j - 1] == 1 || pTable[i - 1][j] == 1 || pTable[i - 1][j - 1] == 1)
                            pTable[i][j] = 1;
                    }
                }
            }
            bool res = (pTable[nStr][nPatt] == 1 ? true : false);
            return res;
        }

    }
}
