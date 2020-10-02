using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 771.宝石与石头
    /// </summary>
    public class NumJewelsInStones
    {
        public int Method(string J, string S)
        {
            int myGemCount = 0;
            for (int i = 0; i < S.Length; i++)
            {
                string Gem = S.Substring(i, 1);
                if(J.Contains(Gem))
                {
                    myGemCount++;
                }
            }
            return myGemCount;
        }
    }
}
