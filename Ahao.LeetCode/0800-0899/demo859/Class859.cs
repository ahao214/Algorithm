using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.LC859
{
    /// <summary>
    /// 859. 亲密字符串
    /// </summary>
    public class Class859
    {
        public bool BuddyStrings(string s, string goal)
        {
            if (s.Length != goal.Length)
            {
                return false;
            }
            List<char> lstS = new List<char>();
            List<char> lstG = new List<char>();
            int diff = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != goal[i])
                {
                    lstS.Add(s[i]);
                    lstG.Add(goal[i]);
                    diff++;
                }
            }

            //s和goal不相同的时候,并且只有两个字符不相等
            if (diff == 2 && lstS[0] == lstG[1] && lstS[1] == lstG[0])
            {
                return true;
            }

            //s和goal相同的时候
            if (diff == 0)
            {
                List<char> lst = new List<char>();
                for (int i = 0; i < s.Length; i++)
                {
                    //如果有重复的字符，则返回true
                    if (lst.Contains(s[i]))
                    {
                        return true;
                    }
                    lst.Add(s[i]);
                }
            }
            return false;
        }
    }
}
