using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo429
{
    public class Class429
    {
        public IList<IList<int>> LevelOrder(Node root)
        {
            if (root == null)
            {
                return new List<IList<int>>();
            }

            IList<IList<int>> ans = new List<IList<int>>();
            Queue<Node> queue = new Queue<Node>();
            queue.Enqueue(root);

            while (queue.Count > 0)
            {
                int cnt = queue.Count;
                IList<int> level = new List<int>();
                for (int i = 0; i < cnt; ++i)
                {
                    Node cur = queue.Dequeue();
                    level.Add(cur.val);
                    foreach (Node child in cur.children)
                    {
                        queue.Enqueue(child);
                    }
                }
                ans.Add(level);
            }

            return ans;
        }

    }

    public class Node
    {
        public int val;
        public IList<Node> children;

        public Node()
        {
        }

        public Node(int _val)
        {
            val = _val;
        }

        public Node(int _val, IList<Node> _children)
        {
            val = _val;
            children = _children;
        }
    }
}
