using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1719
{
    /*
1719. 重构一棵树的方案数
给你一个数组 pairs ，其中 pairs[i] = [xi, yi] ，并且满足：

pairs 中没有重复元素
xi < yi
令 ways 为满足下面条件的有根树的方案数：

树所包含的所有节点值都在 pairs 中。
一个数对 [xi, yi] 出现在 pairs 中 当且仅当 xi 是 yi 的祖先或者 yi 是 xi 的祖先。
注意：构造出来的树不一定是二叉树。
两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。

请你返回：

如果 ways == 0 ，返回 0 。
如果 ways == 1 ，返回 1 。
如果 ways > 1 ，返回 2 。
一棵 有根树 指的是只有一个根节点的树，所有边都是从根往外的方向。

我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 祖先 。根节点没有祖先。
*/
    public class Class1719
    {
        public int CheckWays(int[][] pairs)
        {
            Dictionary<int, ISet<int>> adj = new Dictionary<int, ISet<int>>();
            foreach (int[] p in pairs)
            {
                if (!adj.ContainsKey(p[0]))
                {
                    adj.Add(p[0], new HashSet<int>());
                }
                if (!adj.ContainsKey(p[1]))
                {
                    adj.Add(p[1], new HashSet<int>());
                }
                adj[p[0]].Add(p[1]);
                adj[p[1]].Add(p[0]);
            }
            /* 检测是否存在根节点*/
            int root = -1;
            foreach (KeyValuePair<int, ISet<int>> pair in adj)
            {
                int node = pair.Key;
                ISet<int> neighbours = pair.Value;
                if (neighbours.Count == adj.Count - 1)
                {
                    root = node;
                }
            }
            if (root == -1)
            {
                return 0;
            }

            int res = 1;
            foreach (KeyValuePair<int, ISet<int>> pair in adj)
            {
                int node = pair.Key;
                ISet<int> neighbours = pair.Value;
                /* 如果当前节点为根节点 */
                if (node == root)
                {
                    continue;
                }
                int currDegree = neighbours.Count;
                int parent = -1;
                int parentDegree = int.MaxValue;

                /* 根据 degree 的大小找到 node 的父节点 parent */
                foreach (int neighbour in neighbours)
                {
                    if (adj[neighbour].Count < parentDegree && adj[neighbour].Count >= currDegree)
                    {
                        parent = neighbour;
                        parentDegree = adj[neighbour].Count;
                    }
                }
                if (parent == -1)
                {
                    return 0;
                }

                /* 检测父节点的集合是否包含所有的孩子节点 */
                foreach (int neighbour in neighbours)
                {
                    if (neighbour == parent)
                    {
                        continue;
                    }
                    if (!adj[parent].Contains(neighbour))
                    {
                        return 0;
                    }
                }
                if (parentDegree == currDegree)
                {
                    res = 2;
                }
            }
            return res;
        }
    }
}
