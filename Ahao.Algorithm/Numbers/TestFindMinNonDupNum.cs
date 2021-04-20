using Ahao.Algorithm.Simple;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 找出最小的不重复数
    /// </summary>
    public class TestFindMinNonDupNum
    {
        #region 从右到左的贪心法

        /// <summary>
        /// 处理数字相加的进位
        /// </summary>
        /// <param name="num">num为字符数组，pos为进行加1操作对应的下标位置</param>
        /// <param name="pos"></param>
        private static void Carry(char[] num, int pos)
        {
            for (; pos > 0; pos--)
            {
                if (num[pos] > '9')
                {
                    num[pos] = '0';
                    num[pos - 1]++;
                }
            }
        }

        /// <summary>
        /// 获取大于n的最小不重复数
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int FindMinNonDupNum(int n)
        {
            int count = 0;
            char[] nChar = (n + 1).ToString().ToCharArray();
            char[] ch = new char[nChar.Length + 2];
            ch[0] = '0';
            ch[ch.Length - 1] = '0';
            for (int it = 0; it < nChar.Length; it++)
            {
                ch[it + 1] = nChar[it];
            }

            int len = ch.Length;
            int i = len - 2;    //从右向左遍历
            while (i > 0)
            {
                count++;
                if (ch[i - 1] == ch[i])
                {
                    ch[i]++;    //末尾数字加1
                    Carry(ch, i);

                    for (int j = i + 1; j < len; j++)
                    {
                        if ((j - i) % 2 == 1)
                        {
                            ch[j] = '0';
                        }
                        else
                        {
                            ch[j] = '1';
                        }
                    }

                    //第i位加1后，可能会与第i+1位相等，i++用来处理这种情况
                    i++;
                }
                else
                {
                    i--;
                }
            }
            Console.WriteLine("循环次数为：" + count);
            return Convert.ToInt32(new String(ch));


        }



        #endregion

    }
}
