﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2569
{
    internal class Class2569
    {

        public long[] HandleQuery(int[] nums1, int[] nums2, int[][] queries)
        {
            int n = nums1.Length;
            int m = queries.Length;
            SegTree tree = new SegTree(nums1);

            long sum = 0;
            foreach (int num in nums2)
            {
                sum += num;
            }
            IList<long> list = new List<long>();
            for (int i = 0; i < m; i++)
            {
                if (queries[i][0] == 1)
                {
                    int l = queries[i][1];
                    int r = queries[i][2];
                    tree.ReverseRange(l, r);
                }
                else if (queries[i][0] == 2)
                {
                    sum += (long)tree.SumRange(0, n - 1) * queries[i][1];
                }
                else if (queries[i][0] == 3)
                {
                    list.Add(sum);
                }
            }
            long[] ans = new long[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                ans[i] = list[i];
            }
            return ans;
        }

    }


    class SegTree
    {
        private SegNode[] arr;

        public SegTree(int[] nums)
        {
            int n = nums.Length;
            arr = new SegNode[n * 4 + 1];
            Build(1, 0, n - 1, nums);
        }

        public int SumRange(int left, int right)
        {
            return Query(1, left, right);
        }

        public void ReverseRange(int left, int right)
        {
            Modify(1, left, right);
        }

        public void Build(int id, int l, int r, int[] nums)
        {
            arr[id] = new SegNode();
            arr[id].l = l;
            arr[id].r = r;
            arr[id].lazytag = false;
            if (l == r)
            {
                arr[id].sum = nums[l];
                return;
            }
            int mid = (l + r) >> 1;
            Build(2 * id, l, mid, nums);
            Build(2 * id + 1, mid + 1, r, nums);
            arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
        }

        /* pushdown函数：下传懒标记，即将当前区间的修改情况下传到其左右孩子结点 */
        public void Pushdown(int x)
        {
            if (arr[x].lazytag)
            {
                arr[2 * x].lazytag = !arr[2 * x].lazytag;
                arr[2 * x].sum = arr[2 * x].r - arr[2 * x].l + 1 - arr[2 * x].sum;
                arr[2 * x + 1].lazytag = !arr[2 * x + 1].lazytag;
                arr[2 * x + 1].sum = arr[2 * x + 1].r - arr[2 * x + 1].l + 1 - arr[2 * x + 1].sum;
                arr[x].lazytag = false;
            }
        }

        /* 区间修改 */
        public void Modify(int id, int l, int r)
        {
            if (arr[id].l >= l && arr[id].r <= r)
            {
                arr[id].sum = (arr[id].r - arr[id].l + 1) - arr[id].sum;
                arr[id].lazytag = !arr[id].lazytag;
                return;
            }
            Pushdown(id);
            int mid = (arr[id].l + arr[id].r) >> 1;
            if (arr[2 * id].r >= l)
            {
                Modify(2 * id, l, r);
            }
            if (arr[2 * id + 1].l <= r)
            {
                Modify(2 * id + 1, l, r);
            }
            arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
        }

        /* 区间查询 */
        public int Query(int id, int l, int r)
        {
            if (arr[id].l >= l && arr[id].r <= r)
            {
                return arr[id].sum;
            }
            if (arr[id].r < l || arr[id].l > r)
            {
                return 0;
            }
            Pushdown(id);
            int res = 0;
            if (arr[2 * id].r >= l)
            {
                res += Query(2 * id, l, r);
            }
            if (arr[2 * id + 1].l <= r)
            {
                res += Query(2 * id + 1, l, r);
            }
            return res;
        }
    }

    class SegNode
    {
        public int l, r, sum;
        public bool lazytag;

        public SegNode()
        {
            this.l = 0;
            this.r = 0;
            this.sum = 0;
            this.lazytag = false;
        }
    }
}
