using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo796
{
    public class Class796
    {
        public bool RotateString(string s, string goal)
        {
            if (s.Length != goal.Length)
                return false;
            for (int i = 0; i < s.Length; i++)
            {
                string newS = swap(s, 0, s.Length - 1);
                if (newS == goal)
                {
                    return true;
                }
                s = newS;
            }
            return false;
        }

        public string swap(string s, int left, int right)
        {
            string newS = string.Empty;
            string first = s[left].ToString();
            newS = s.Substring(1) + first;
            return newS;
        }



        public bool RotateString2(string s, string goal)
        {
            int m = s.Length, n = goal.Length;
            if (m != n)
            {
                return false;
            }
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                for (int j = 0; j < n; j++)
                {
                    if (s[(i + j) % n] != goal[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    return true;
                }
            }
            return false;
        }


        public bool RotateString3(string s, string goal)
        {
            return s.Length == goal.Length && (s + s).Contains(goal);
        }

    }
}
