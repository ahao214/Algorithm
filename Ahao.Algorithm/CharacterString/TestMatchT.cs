using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 实现字符串的匹配-KMP算法
    /// </summary>
    public class TestMatchT
    {
        /// <summary>
        /// 求字符串的next数组
        /// </summary>
        /// <param name="p"></param>
        /// <param name="next"></param>
        public static void GetNext(String p, int[] next)
        {
            int i = 0, j = -1;
            next[0] = -1;
            while (i < p.Length)
            {
                if (j == -1 || p[i] == p[j])
                {
                    i++;
                    j++;
                    next[i] = j;
                }
                else
                {
                    j = next[j];
                }
            }
        }


        public static int Match(String s, String p, int[] next)
        {
            //检查参数的合理性
            if (s == null || p == null)
            {
                Console.WriteLine("参数不合理");
                return -1;
            }
            int slen = s.Length;
            int plen = p.Length;
            //p肯定不是s的子串
            if (slen < plen)
                return -1;
            int i = 0, j = 0;
            while (i < slen && j < plen)
            {
                Console.WriteLine("i=" + i + "," + "j=" + j);
                if (j == -1 || s[i] == p[j])
                {
                    //如果相同，则继续比较后面的字符
                    i++;
                    j++;
                }
                else
                {
                    j = next[j];
                }
            }
            if (j >= slen)  //匹配成功
                return i - plen;
            return -1;

        }

    }
}
