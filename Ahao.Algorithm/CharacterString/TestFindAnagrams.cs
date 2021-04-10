using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 解决字符串包含问题
    /// </summary>
    public class TestFindAnagrams
    {
        public List<int> FindAnagrams(string s, string p)
        {
            List<int> sv = new List<int>();
            List<int> pv = new List<int>();
            List<int> result = new List<int>();

            for (int i = 0; i < p.Length; i++)
            {
                sv[s[i] - 'a']++;
                pv[p[i] - 'a']++;
            }

            //字母一共26个，看两个数组是否相等
            if (CheckValueSame(sv, pv))
            {
                result.Add(0);
            }

            for (int i = p.Length; i < s.Length; i++)
            {
                //从左向右，遍历，每次遍历一个保持窗口大小为p.size()
                sv[s[i] - 'a']++;
                //去除窗口最左边的元素
                sv[s[i - p.Length] - 'a']--;
                if (CheckValueSame(sv, pv))
                {
                    result.Add(i - p.Length + 1);
                }
            }
            return result;

        }

        private bool CheckValueSame(List<int> s, List<int> p)
        {
            //字母一共26个，看两个数组是否相等
            for (int i = 0; i < 26; i++)
            {
                if (s[i] != p[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
