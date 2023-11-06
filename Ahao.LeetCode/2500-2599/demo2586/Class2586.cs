using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2586
{
    internal class Class2586
    {
        public int VowelStrings(string[] words, int left, int right)
        {
            int result = 0;
            for (int i = left; i <= right; i++)
            {
                string word = words[i];
                if (IsYuan(word.Substring(0, 1)) && IsYuan(word.Substring(word.Length - 1, 1)))
                {
                    result++;
                }
            }
            return result;
        }


        private bool IsYuan(string s)
        {
            if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u")
            {
                return true;
            }
            return false;
        }

    }
}
