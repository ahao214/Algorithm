using Ahao.Algorithm.Simple;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 求一个字符串的所有排列-非递归方法
    /// </summary>
    public class TestPermutationT
    {
        //交换字符数组下标为i和j对应的字符
        private static void Swap(char[] str, int i, int j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }


        private static void Reverse(char[] str, int begin, int end)
        {
            for (int i = begin, j = end; i < j; i++, j--)
            {
                Swap(str, i, j);
            }
        }
        /// <summary>
        /// 根据当前字符串获取下一个组合
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        private static bool getNextPermutation(char[] str)
        {
            int end = str.Length - 1;
            int cur = end;
            int suc = 0;
            int tmp = 0;
            while (cur != 0)
            {
                //从后向前开始遍历字符串
                suc = cur;
                cur--;
                if (str[cur] < str[suc])
                {
                    //相邻递增的字符，cur指向较小的字符
                    //找出cur后面最小的字符tmp
                    tmp = end;
                    while (str [tmp ]<str [cur ])
                    {
                        --tmp;
                    }
                    //交换cur和tmp
                    Swap(str, cur, tmp);
                    //把cur后面的子字符串进行翻转
                    Reverse(str, suc, cur);
                    return true;
                }
            }
            return false; 

        }


        //获取字符串中字符的所有组合
        public static void Permutation(string s)
        {
            if(s ==null || s .Length <1)
            {
                Console.WriteLine("参数不合法");
            }
            char[] str = s.ToCharArray();
            Array.Sort(str);    //升序排列字符数组
            do
            {
                Console.WriteLine(str);
            }
            while (getNextPermutation(str));
        }

    }
}
