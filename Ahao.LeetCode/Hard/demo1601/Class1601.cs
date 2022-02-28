﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1601
{
    /*
     1601. 最多可达成的换楼请求数目
我们有 n 栋楼，编号从 0 到 n - 1 。每栋楼有若干员工。由于现在是换楼的季节，部分员工想要换一栋楼居住。

给你一个数组 requests ，其中 requests[i] = [fromi, toi] ，表示一个员工请求从编号为 fromi 的楼搬到编号为 toi 的楼。

一开始 所有楼都是满的，所以从请求列表中选出的若干个请求是可行的需要满足 每栋楼员工净变化为 0 。意思是每栋楼 离开 的员工数目 等于 该楼 搬入 的员工数数目。比方说 n = 3 且两个员工要离开楼 0 ，一个员工要离开楼 1 ，一个员工要离开楼 2 ，如果该请求列表可行，应该要有两个员工搬入楼 0 ，一个员工搬入楼 1 ，一个员工搬入楼 2 。

请你从原请求列表中选出若干个请求，使得它们是一个可行的请求列表，并返回所有可行列表中最大请求数目。
     */
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
