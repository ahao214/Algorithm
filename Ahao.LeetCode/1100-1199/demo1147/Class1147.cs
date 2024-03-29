﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1147
{
    public class Class1147
    {

        public int LongestDecomposition(string text)
        {
            int n = text.Length;
            int res = 0;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int len = 1;
                while (l + len - 1 < r - len + 1)
                {
                    if (Judge(text, l, r - len + 1, len))
                    {
                        res += 2;
                        break;
                    }
                    ++len;
                }
                if (l + len - 1 >= r - len + 1)
                {
                    ++res;
                }
                l += len;
                r -= len;
            }
            return res;
        }

        public bool Judge(string text, int l1, int l2, int len)
        {
            while (len > 0)
            {
                if (text[l1] != text[l2])
                {
                    return false;
                }
                ++l1;
                ++l2;
                --len;
            }
            return true;
        }



        long[] pre1;
        long[] pre2;
        long[] pow1;
        long[] pow2;
        const int MOD1 = 1000000007;
        const int MOD2 = 1000000009;
        int base1, base2;
        Random random = new Random();

        public int LongestDecomposition2(string text)
        {
            Init(text);
            int n = text.Length;
            int res = 0;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int len = 1;
                while (l + len - 1 < r - len + 1)
                {
                    if (Enumerable.SequenceEqual(GetHash(l, l + len - 1), GetHash(r - len + 1, r)))
                    {
                        res += 2;
                        break;
                    }
                    ++len;
                }
                if (l + len - 1 >= r - len + 1)
                {
                    ++res;
                }
                l += len;
                r -= len;
            }
            return res;
        }

        public void Init(String s)
        {
            base1 = 1000000 + random.Next(9000000);
            base2 = 1000000 + random.Next(9000000);
            while (base2 == base1)
            {
                base2 = 1000000 + random.Next(9000000);
            }
            int n = s.Length;
            pow1 = new long[n];
            pow2 = new long[n];
            pre1 = new long[n + 1];
            pre2 = new long[n + 1];
            pow1[0] = pow2[0] = 1;
            pre1[1] = pre2[1] = s[0];
            for (int i = 1; i < n; i++)
            {
                pow1[i] = (pow1[i - 1] * base1) % MOD1;
                pow2[i] = (pow2[i - 1] * base2) % MOD2;
                pre1[i + 1] = (pre1[i] * base1 + s[i]) % MOD1;
                pre2[i + 1] = (pre2[i] * base2 + s[i]) % MOD2;
            }
        }

        public long[] GetHash(int l, int r)
        {
            return new long[] { (pre1[r + 1] - ((pre1[l] * pow1[r + 1 - l]) % MOD1) + MOD1) % MOD1, (pre2[r + 1] - ((pre2[l] * pow2[r + 1 - l]) % MOD2) + MOD2) % MOD2 };
        }




        public int LongestDecomposition3(string text)
        {
            if (string.IsNullOrEmpty(text)) return 0;
            for (int i = 1; i * 2 <= text.Length; i++)
            {
                if (text.Substring(0, i).Equals(text.Substring(text.Length - i, i)))
                {
                    return 2 + LongestDecomposition3(text.Substring(i, text.Length - 2 * i));
                }
            }

            return 1;
        }


    }
}
