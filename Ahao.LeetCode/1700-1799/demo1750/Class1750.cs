using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1750
{
    public class Class1750
    {

        public int MinimumLength(string s)
        {
            int n = s.Length;
            int left = 0, right = n - 1;
            while (left < right && s[left] == s[right])
            {
                char c = s[left];
                while (left <= right && s[left] == c)
                {
                    left++;
                }
                while (left <= right && s[right] == c)
                {
                    right--;
                }
            }
            return right - left + 1;
        }
    }
}
