using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2609
{
    public class Class2609
    {
        public int FindTheLongestBalancedSubstring(string s)
        {
            int res = 0;
            int n = s.Length;
            int[] count = new int[2];
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    count[1]++;
                    res = Math.Max(res, 2 * Math.Min(count[0], count[1]));
                }
                else if (i == 0 || s[i - 1] == '1')
                {
                    count[0] = 1;
                    count[1] = 0;
                }
                else
                {
                    count[0]++;
                }
            }
            return res;
        }



        public int FindTheLongestBalancedSubstring2(string s)
        {
            int res = 0;
            int countZero = 0;//统计当前0的个数
            int countOne = 0;   // 统计当前1的个数
            var str = s.ToCharArray();
            int i = 0;
            while (true)
            {
                while (i < s.Length && str[i] == '0')
                {
                    countZero++;
                    i++;
                }
                while (i < s.Length && str[i] == '1')
                {
                    countOne++;
                    i++;
                }
                res = Math.Max(res, Math.Min(countZero, countOne));
                countZero = 0;
                countOne = 0;
                if (i >= s.Length)
                {
                    break;
                }
            }
            return res * 2;
        }


    }
}
