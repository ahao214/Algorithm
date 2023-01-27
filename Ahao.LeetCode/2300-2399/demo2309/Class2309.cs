using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2309
{
    public class Class2309
    {
        /// <summary>
        /// 哈希表
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public string GreatestLetter(string s)
        {
            ISet<char> ht = new HashSet<char>();
            foreach (char c in s)
            {
                ht.Add(c);
            }
            for (int i = 25; i >= 0; i--)
            {
                if (ht.Contains((char)('a' + i)) && ht.Contains((char)('A' + i)))
                {
                    return ((char)('A' + i)).ToString();
                }
            }
            return "";
        }


        /// <summary>
        /// 位运算
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public string GreatestLetter2(string s)
        {
            int lower = 0, upper = 0;
            foreach (char c in s)
            {
                if (char.IsLower(c))
                {
                    lower |= 1 << (c - 'a');
                }
                else
                {
                    upper |= 1 << (c - 'A');
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if ((lower & upper & (1 << i)) != 0)
                {
                    return ((char)('A' + i)).ToString();
                }
            }
            return "";
        }


    }
}
