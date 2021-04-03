using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.String
{
    /// <summary>
    /// 求一个字符串的所有排列-去掉重复的排列
    /// </summary>
    public class TestPermutationThree
    {
        private static void Swap(char[] str, int i, int j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }

        //判断[begin,end]区间中是否有字符与*end相等
        private static bool IsDuplicate(char[] str, int beign, int end)
        {
            for (int i = beign; i < end; i++)
            {
                if (str[i] == str[end])
                {
                    return false;
                }
            }
            return true;
        }

        public static void Permutation(char[] str, int start)
        {
            if (str == null || start < 0)
                return;
            //完成全排列后输出当前排列的字符串
            if (start == str.Length - 1)
            {
                Console.WriteLine(new string(str) + " ");
            }
            else
            {
                for (int i = start; i < str.Length; i++)
                {
                    if (!IsDuplicate(str, start, i))
                    {
                        continue;
                    }
                    //交换start和i所在位置的字符
                    Swap(str, start, i);
                    //固定第一个字符，对剩余的字符进行全排列
                    Permutation(str, start + 1);
                    //还原start和i所在位置的字符
                    Swap(str, start, i);
                }
            }
        }

        public static void Permutation(string s)
        {
            char[] str = s.ToCharArray();
            Permutation(str, 0);
        }

    }
}
