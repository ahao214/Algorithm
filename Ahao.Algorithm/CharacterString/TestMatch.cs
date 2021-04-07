using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 实现字符串的匹配-直接计算法
    /// </summary>
    public class TestMatch
    {
        public static int match(String s, String p)
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
                if (s[i] == p[j])
                {
                    //如果相同，则继续比较后面的字符
                    i++;
                    j++;
                }
                else
                {
                    //退回去重新比较
                    i = i - j + 1;
                    j = 0;
                    if (i > slen - plen)
                        return -1;
                }
            }
            if (j >= plen)   //匹配成功
            {
                return i - plen;
            }
            return -1;

        }



    }
}
