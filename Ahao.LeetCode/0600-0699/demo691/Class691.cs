﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo691
{
    public class Class691
    {
        public int MinStickers(string[] stickers, string target)
        {
            int m = target.Length;
            int[] memo = new int[1 << m];
            Array.Fill(memo, -1);
            memo[0] = 0;
            int res = DP(stickers, target, memo, (1 << m) - 1);
            return res <= m ? res : -1;
        }

        public int DP(string[] stickers, string target, int[] memo, int mask)
        {
            int m = target.Length;
            if (memo[mask] < 0)
            {
                int res = m + 1;
                foreach (string sticker in stickers)
                {
                    int left = mask;
                    int[] cnt = new int[26];
                    for (int i = 0; i < sticker.Length; i++)
                    {
                        cnt[sticker[i] - 'a']++;
                    }
                    for (int i = 0; i < target.Length; i++)
                    {
                        char c = target[i];
                        if (((mask >> i) & 1) == 1 && cnt[c - 'a'] > 0)
                        {
                            cnt[c - 'a']--;
                            left ^= 1 << i;
                        }
                    }
                    if (left < mask)
                    {
                        res = Math.Min(res, DP(stickers, target, memo, left) + 1);
                    }
                }
                memo[mask] = res;
            }
            return memo[mask];
        }

    }
}
