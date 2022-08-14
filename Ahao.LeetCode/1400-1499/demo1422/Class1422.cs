using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1422
{
    public class Class1422
    {
        public int MaxScore(string s)
        {
            int res = 0;
            int n = s.Length;
            for (int i = 1; i < n; i++)
            {
                int score = 0;
                for (int j = 0; j < i; j++)
                {
                    if (s[j] == '0')
                        score++;
                }
                for (int j = i; j < n; j++)
                {
                    if (s[j] == '1')
                        score++;
                }
                res = Math.Max(res, score);
            }
            return res;
        }



        public int MaxScore2(string s)
        {
            int score = 0;
            int n = s.Length;
            if (s[0] == '0')
            {
                score++;
            }
            for (int i = 1; i < n; i++)
            {
                if (s[i] == '1')
                {
                    score++;
                }
            }
            int ans = score;
            for (int i = 1; i < n - 1; i++)
            {
                if (s[i] == '0')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                ans = Math.Max(ans, score);
            }
            return ans;
        }

    }
}
