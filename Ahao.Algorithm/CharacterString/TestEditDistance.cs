using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 求字符串的编辑距离
    /// </summary>
    public class TestEditDistance
    {
        private int Min(int a, int b, int c)
        {
            int tmp = a < b ? a : b;
            return tmp < c ? tmp : c;
        }

        public int edit(String s1, String s2, int replaceWight)
        {
            //两个空串的编辑距离为0
            if (s1 == null && s2 == null)
                return 0;
            //如果s1为空串，则编辑距离为s2的长度
            if (s1 == null)
                return s2.Length;
            if (s2 == null)
                return s1.Length;
            int len1 = s1.Length;
            int len2 = s2.Length;
            //申请二维数组来存储中间的计算结果
            int[,] D = new int[len1 + 1, len2 + 1];

            int i, j;
            for (i = 0; i < len1 + 1; i++)
            {
                D[i, 0] = i;
            }
            for (i = 0; i < len2 + 1; i++)
            {
                D[0, i] = i;
            }
            for (i = 1; i < len1 + 1; i++)
            {
                for (j = 1; j < len2 + 1; j++)
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        D[i, j] = Min(D[i - 1, j] + 1, D[i, j - 1] + 1, D[i - 1, j - 1]);
                    }
                    else
                    {
                        D[i, j] = Min(D[i - 1, j] + 1, D[i, j - 1] + 1, D[i - 1, j - 1] + replaceWight);
                    }
                }
            }

            Console.WriteLine("--------------------");

            for (i = 0; i < len1 + 1; i++)
            {
                for (j = 0; j < len2 + 1; j++)
                {
                    Console.Write(D[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("--------------------");
            int dis = D[len1, len2];
            return dis;
        }


    }
}
