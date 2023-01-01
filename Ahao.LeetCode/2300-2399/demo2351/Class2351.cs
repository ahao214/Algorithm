using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2351
{
    public class Class2351
    {
        public char RepeatedCharacter(string s)
        {
            int[] arr = new int[26];
            foreach (char c in s)
            {
                arr[c - 'a']++;
                if (arr[c - 'a'] == 2)
                {
                    return c;
                }
            }
            return ' ';
        }
    }
}
