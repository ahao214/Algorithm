using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2399
{
    public class Class2399
    {

        public bool CheckDistances(string s, int[] distance)
        {
            int n = s.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] == s[j] && distance[s[i] - 'a'] != j - i - 1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }


        public bool CheckDistances2(string s, int[] distance)
        {
            int[] firstIndex = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                int idx = s[i] - 'a';
                if (firstIndex[idx] != 0 && i - firstIndex[idx] != distance[idx])
                {
                    return false;
                }
                firstIndex[idx] = i + 1;
            }
            return true;
        }

    }
}
