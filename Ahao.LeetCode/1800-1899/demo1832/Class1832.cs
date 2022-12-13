using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1832
{
    public class Class1832
    {
        public bool CheckIfPangram(string sentence)
        {
            bool[] exist = new bool[26];
            foreach (char c in sentence)
            {
                exist[c - 'a'] = true;
            }
            foreach (bool x in exist)
            {
                if (!x)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
