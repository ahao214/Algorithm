using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1234
{
    public class Class1234
    {

        public int BalancedString(string s)
        {
            int[] cnt = new int[26];
            foreach (char c in s)
            {
                cnt[Idx(c)]++;
            }

            int partial = s.Length / 4;
            int res = s.Length;

            if (Check(cnt, partial))
            {
                return 0;
            }
            for (int l = 0, r = 0; l < s.Length; l++)
            {
                while (r < s.Length && !Check(cnt, partial))
                {
                    cnt[Idx(s[r])]--;
                    r++;
                }
                if (!Check(cnt, partial))
                {
                    break;
                }
                res = Math.Min(res, r - l);
                cnt[Idx(s[l])]++;
            }
            return res;
        }

        public int Idx(char c)
        {
            return c - 'A';
        }

        public bool Check(int[] cnt, int partial)
        {
            if (cnt[Idx('Q')] > partial || cnt[Idx('W')] > partial || cnt[Idx('E')] > partial || cnt[Idx('R')] > partial)
            {
                return false;
            }
            return true;
        }

        public int BalancedString2(string s)
        {
            int left = 0;
            int right = 0;
            int[] mark = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                mark[s[i] - 'A']++;
            }
            int min = int.MaxValue;

            int m = s.Length / 4;
            if (mark['Q' - 'A'] == m && mark['W' - 'A'] == m && mark['E' - 'A'] == m && mark['R' - 'A'] == m)
            {
                return 0;
            }

            while (right < s.Length)
            {
                mark[s[right] - 'A']--;
                right++;
                while (mark['Q' - 'A'] <= m && mark['W' - 'A'] <= m && mark['E' - 'A'] <= m && mark['R' - 'A'] <= m)
                {
                    min = Math.Min(min, right - left);
                    mark[s[left] - 'A']++;
                    left++;
                }
            }

            return min;
        }

    }
}
