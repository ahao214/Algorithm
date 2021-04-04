using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 判断两个字符串是否为换位字符串
    /// </summary>
 public    class TextCompare
    {
        public static bool Compare(String sone ,String stwo)
        {
            bool result = true;
            int[] bCount = new int[256];
            int i;
            for(i=0;i<256;i++)
            {
                bCount[i] = 0;
            }
            for (i = 0; i < sone.Length; i++)
                bCount[sone[i] - '0']++;
            for (i = 0; i < stwo.Length; i++)
                bCount[stwo[i] - '0']--;
            for(i=0;i<256;i++)
            {
                if (bCount [i]!=0)
                {
                    result = false;
                    break;
                }
            }
            return result;
        }


    }
}
