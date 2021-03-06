using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Configuration;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求集合的所有子集
    /// </summary>
    public class TestGetAllSubset
    {
        //子集个数Sn与原集合元素个数n之间的关系满足如下等式：Sn=2^n-1

        public static void GetAllSubset(char[] array, int[] mask, int c)
        {
            int length = array.Length;
            int i;
            if (length == c)
            {
                Console.Write("{");
                for (i = 0; i < length; i++)
                {
                    if (mask[i] == 1)
                    {
                        Console.Write(array[i] + " ");
                    }
                }
                Console.WriteLine("}");
            }
            else
            {
                mask[c] = 1;
                GetAllSubset(array, mask, c + 1);
                mask[c] = 0;
                GetAllSubset(array, mask, c + 1);
            }
        }
    }
}
