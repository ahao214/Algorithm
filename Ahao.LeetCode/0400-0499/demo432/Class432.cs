using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo432
{
    public class AllOne
    {
        Node root;
        Dictionary<string, Node> nodes;

        public AllOne()
        {
            root = new Node();
            root.Prev = root;
            root.Next = root;  // 初始化链表哨兵，下面判断节点的 Next 若为 root，则表示 Next 为空（Prev 同理）
            nodes = new Dictionary<string, Node>();
        }

        public void Inc(string key)
        {
            if (nodes.ContainsKey(key))
            {
                Node cur = nodes[key];
                Node nxt = cur.Next;
                if (nxt == root || nxt.Count > cur.Count + 1)
                {
                    nodes[key] = cur.Insert(new Node(key, cur.Count + 1));
                }
                else
                {
                    nxt.Keys.Add(key);
                    nodes[key] = nxt;
                }
                cur.Keys.Remove(key);
                if (cur.Keys.Count == 0)
                {
                    cur.Remove();
                }
            }
            else
            {  // key 不在链表中
                if (root.Next == root || root.Next.Count > 1)
                {
                    nodes.Add(key, root.Insert(new Node(key, 1)));
                }
                else
                {
                    root.Next.Keys.Add(key);
                    nodes.Add(key, root.Next);
                }
            }
        }

        public void Dec(string key)
        {
            Node cur = nodes[key];
            if (cur.Count == 1)
            {  // key 仅出现一次，将其移出 nodes
                nodes.Remove(key);
            }
            else
            {
                Node pre = cur.Prev;
                if (pre == root || pre.Count < cur.Count - 1)
                {
                    nodes[key] = cur.Prev.Insert(new Node(key, cur.Count - 1));
                }
                else
                {
                    pre.Keys.Add(key);
                    nodes[key] = pre;
                }
            }
            cur.Keys.Remove(key);
            if (cur.Keys.Count == 0)
            {
                cur.Remove();
            }
        }

        public string GetMaxKey()
        {
            if (root.Prev == null)
            {
                return "";
            }
            string maxKey = "";
            foreach (string key in root.Prev.Keys)
            {
                maxKey = key;
                break;
            }
            return maxKey;
        }

        public string GetMinKey()
        {
            if (root.Next == null)
            {
                return "";
            }
            string minKey = "";
            foreach (string key in root.Next.Keys)
            {
                minKey = key;
                break;
            }
            return minKey;
        }
    }

    class Node
    {
        public Node Prev
        {
            get; set;
        }
        public Node Next
        {
            get; set;
        }
        public ISet<string> Keys
        {
            get; set;
        }
        public int Count
        {
            get; set;
        }

        public Node() : this("", 0)
        {

        }

        public Node(string key, int count)
        {
            this.Count = count;
            Keys = new HashSet<string>();
            Keys.Add(key);
        }

        public Node Insert(Node node)
        {  // 在 this 后插入 node
            node.Prev = this;
            node.Next = this.Next;
            node.Prev.Next = node;
            node.Next.Prev = node;
            return node;
        }

        public void Remove()
        {
            this.Prev.Next = this.Next;
            this.Next.Prev = this.Prev;
        }
    }


}
