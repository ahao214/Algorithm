using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 13.罗马数字转整数
    /// </summary>
    public class RomanToInt
    {
        public int Method(string s)
        {
            var dic = new Dictionary<string, int>();
            dic.Add("I", 1);
            dic.Add("IV", 4);
            dic.Add("V", 5);
            dic.Add("IX", 9);
            dic.Add("X", 10);
            dic.Add("XL", 40);
            dic.Add("L", 50);
            dic.Add("XC", 90);
            dic.Add("C", 100);
            dic.Add("CD", 400);
            dic.Add("D", 500);
            dic.Add("CM", 900);
            dic.Add("M", 1000);
            var sum = 0;
            s = s.ToUpper();
            for (var i = 0; i < s.Length;)
            {
                //是否包含特殊的字符
                if (i + 2 <= s.Length && dic.ContainsKey(s.Substring(i, 2)))
                {
                    sum += dic[s.Substring(i, 2)];
                    i += 2;
                }
                else
                {
                    sum += dic[s.Substring(i, 1)];
                    i++;
                }
            }
            return sum;
        }
    }
}
