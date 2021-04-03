using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.String
{
    /// <summary>
    /// 求一个字符串的所有排列
    /// </summary>
    public class TestPermutation
    {
        //交换字符数组下标为i和j对应的字符
        static void Swap(char[] str, int i, int j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }

        /// <summary>
        /// 对字符串中的字符进行全排列
        /// </summary>
        /// <param name="str">待排序的字符串</param>
        /// <param name="start">待排序的子字符串的首字符下标</param>
        static void Permutation(char[] str, int start)
        {
            if (str == null || start < 0)
            {
                return;
            }

            //完成全排列后输出当前排列的字符串
            if (start == str.Length - 1)
            {
                Console.WriteLine(str);
            }
            else
            {
                for (int i = start; i < str.Length - 1; i++)
                {
                    //交换start和i所在位置的字符
                    Swap(str, start, i);
                    //固定第一个字符，对剩余的字符进行全排列
                    Permutation(str, start + 1);
                    //还原start和i所在位置的字符
                    Swap(str, start, i);
                }
            }
        }

        public static void Permutation(String s)
        {
            char[] str = s.ToCharArray();
            Permutation(str, 0);
        }
    }
}
