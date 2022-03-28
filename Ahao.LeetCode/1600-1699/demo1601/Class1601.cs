﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1601
{
    public class Class1601
    {
        int[] delta;
        int ans = 0, cnt = 0, zero, n;

        public int MaximumRequests(int n, int[][] requests)
        {
            delta = new int[n];
            zero = n;
            this.n = n;
            DFS(requests, 0);
            return ans;
        }

        public void DFS(int[][] requests, int pos)
        {
            if (pos == requests.Length)
            {
                if (zero == n)
                {
                    ans = Math.Max(ans, cnt);
                }
                return;
            }

            // 不选 requests[pos]
            DFS(requests, pos + 1);

            // 选 requests[pos]
            int z = zero;
            ++cnt;
            int[] r = requests[pos];
            int x = r[0], y = r[1];
            zero -= delta[x] == 0 ? 1 : 0;
            --delta[x];
            zero += delta[x] == 0 ? 1 : 0;
            zero -= delta[y] == 0 ? 1 : 0;
            ++delta[y];
            zero += delta[y] == 0 ? 1 : 0;
            DFS(requests, pos + 1);
            --delta[y];
            ++delta[x];
            --cnt;
            zero = z;
        }
    }

}
