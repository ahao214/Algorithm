﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999._2981
{
    internal class Class2981
    {
        public int MaximumLength(string s)
        {
            int ans = -1;
            int len = s.Length;

            IList<int>[] chs = new IList<int>[26];
            for (int i = 0; i < 26; i++)
            {
                chs[i] = new List<int>();
            }
            int cnt = 0;
            for (int i = 0; i < len; i++)
            {
                cnt++;
                if (i + 1 == len || s[i] != s[i + 1])
                {
                    int ch = s[i] - 'a';
                    chs[ch].Add(cnt);
                    cnt = 0;

                    for (int j = chs[ch].Count - 1; j > 0; j--)
                    {
                        if (chs[ch][j] > chs[ch][j - 1])
                        {
                            int temp = chs[ch][j];
                            chs[ch][j] = chs[ch][j - 1];
                            chs[ch][j - 1] = temp;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (chs[ch].Count > 3)
                    {
                        chs[ch].RemoveAt(chs[ch].Count - 1);
                    }
                }
            }

            for (int i = 0; i < 26; i++)
            {
                if (chs[i].Count > 0 && chs[i][0] > 2)
                {
                    ans = Math.Max(ans, chs[i][0] - 2);
                }
                if (chs[i].Count > 1 && chs[i][0] > 1)
                {
                    ans = Math.Max(ans, Math.Min(chs[i][0] - 1, chs[i][1]));
                }
                if (chs[i].Count > 2)
                {
                    ans = Math.Max(ans, chs[i][2]);
                }
            }

            return ans;
        }



    }
}
