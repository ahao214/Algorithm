using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2003
{
    public class Class2003
    {
        public int[] SmallestMissingValueSubtree(int[] parents, int[] nums)
        {
            int n = parents.Length;
            IList<int>[] children = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                children[i] = new List<int>();
            }
            for (int i = 1; i < n; i++)
            {
                children[parents[i]].Add(i);
            }

            int[] res = new int[n];
            Array.Fill(res, 1);
            ISet<int>[] geneSet = new ISet<int>[n];
            for (int i = 0; i < n; i++)
            {
                geneSet[i] = new HashSet<int>();
            }
            DFS(0, res, nums, children, geneSet);
            return res;
        }

        public int DFS(int node, int[] res, int[] nums, IList<int>[] children, ISet<int>[] geneSet)
        {
            geneSet[node].Add(nums[node]);
            foreach (int child in children[node])
            {
                res[node] = Math.Max(res[node], DFS(child, res, nums, children, geneSet));
                if (geneSet[node].Count < geneSet[child].Count)
                {
                    ISet<int> temp = geneSet[node];
                    geneSet[node] = geneSet[child];
                    geneSet[child] = temp;
                }
                foreach (int val in geneSet[child])
                {
                    geneSet[node].Add(val);
                }
            }
            while (geneSet[node].Contains(res[node]))
            {
                res[node]++;
            }
            return res[node];
        }



        public int[] SmallestMissingValueSubtree1(int[] parents, int[] nums)
        {
            int n = parents.Length;
            IList<int>[] children = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                children[i] = new List<int>();
            }
            for (int i = 1; i < n; i++)
            {
                children[parents[i]].Add(i);
            }

            ISet<int> geneSet = new HashSet<int>();
            bool[] visited = new bool[n];

            int[] res = new int[n];
            Array.Fill(res, 1);
            int iNode = 1, node = -1;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 1)
                {
                    node = i;
                    break;
                }
            }
            while (node != -1)
            {
                DFS1(node, nums, children, geneSet, visited);
                while (geneSet.Contains(iNode))
                {
                    iNode++;
                }
                res[node] = iNode;
                node = parents[node];
            }
            return res;
        }

        public void DFS1(int node, int[] nums, IList<int>[] children, ISet<int> geneSet, bool[] visited)
        {
            if (visited[node])
            {
                return;
            }
            visited[node] = true;
            geneSet.Add(nums[node]);
            foreach (int child in children[node])
            {
                DFS1(child, nums, children, geneSet, visited);
            }
        }


    }
}
