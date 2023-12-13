using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2697
{
    public class Class2697
    {
        public string MakeSmallestPalindrome(string s)
        {
            char[] arr = s.ToCharArray();
            int left = 0, right = arr.Length - 1;
            while (left < right)
            {
                if (arr[left] != arr[right])
                {
                    arr[left] = arr[right] = (char)Math.Min(arr[left], arr[right]);
                }
                ++left;
                --right;
            }
            return new string(arr);
        }


        public String MakeSmallestPalindrome2(String s)
        {
            char[] cs = s.ToCharArray();
            for (int i = 0, j = cs.Length - 1; i < j; ++i, --j)
            {
                cs[i] = cs[j] = (char)Math.Min(cs[i], cs[j]);
            }
            return new String(cs);
        }


    }
}
