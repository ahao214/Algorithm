﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1032
{
    public class Class1032
    {

    }

    public class StreamChecker
    {

        TrieNode root;
        TrieNode temp;

        public StreamChecker(String[] words)
        {
            root = new TrieNode();
            foreach (String word in words)
            {
                TrieNode cur = root;
                foreach (char ch in word)
                {
                    int index = ch - 'a';
                    if (cur.getChild(index) == null)
                    {
                        cur.setChild(index, new TrieNode());
                    }
                    cur = cur.getChild(index);
                }
                cur.setIsEnd(true);
            }
            root.setFail(root);
            Queue<TrieNode> q = new Queue<TrieNode>();
            for (int i = 0; i < 26; i++)
            {
                if (root.getChild(i) != null)
                {
                    root.getChild(i).setFail(root);
                    q.Enqueue(root.getChild(i));
                }
                else
                {
                    root.setChild(i, root);
                }
            }
            while (q.Count > 0)
            {
                TrieNode node = q.Dequeue();
                node.setIsEnd(node.getIsEnd() || node.getFail().getIsEnd());
                for (int i = 0; i < 26; i++)
                {
                    if (node.getChild(i) != null)
                    {
                        node.getChild(i).setFail(node.getFail().getChild(i));
                        q.Enqueue(node.getChild(i));
                    }
                    else
                    {
                        node.setChild(i, node.getFail().getChild(i));
                    }
                }
            }

            temp = root;
        }

        public bool Query(char letter)
        {
            temp = temp.getChild(letter - 'a');
            return temp.getIsEnd();
        }
    }

    class TrieNode
    {
        TrieNode[] children;
        bool isEnd;
        TrieNode fail;

        public TrieNode()
        {
            children = new TrieNode[26];
        }

        public TrieNode getChild(int index)
        {
            return children[index];
        }

        public void setChild(int index, TrieNode node)
        {
            children[index] = node;
        }

        public bool getIsEnd()
        {
            return isEnd;
        }

        public void setIsEnd(bool b)
        {
            isEnd = b;
        }

        public TrieNode getFail()
        {
            return fail;
        }

        public void setFail(TrieNode node)
        {
            fail = node;
        }
    }
}
