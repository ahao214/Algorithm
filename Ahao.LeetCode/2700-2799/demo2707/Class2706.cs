﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2707
{
    public class Class2707
    {

        public int MinExtraChar(string s, string[] dictionary)
        {
            int n = s.Length;
            int[] d = new int[n + 1];
            Array.Fill(d, int.MaxValue);
            IDictionary<string, int> dic = new Dictionary<string, int>();
            foreach (string str in dictionary)
            {
                dic.TryAdd(str, 0);
                dic[str]++;
            }
            d[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                d[i] = d[i - 1] + 1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (dic.ContainsKey(s.Substring(j, i - j)))
                    {
                        d[i] = Math.Min(d[i], d[j]);
                    }
                }
            }
            return d[n];
        }



        public int MinExtraChar2(string s, string[] dictionary)
        {
            int n = s.Length;
            int[] d = new int[n + 1];
            Array.Fill(d, int.MaxValue);
            Trie trie = new Trie();
            foreach (string str in dictionary)
            {
                StringBuilder sb = new StringBuilder();
                for (int i = str.Length - 1; i >= 0; i--)
                {
                    sb.Append(str[i]);
                }
                trie.Insert(sb.ToString());
            }
            d[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                d[i] = d[i - 1] + 1;
                Trie node = trie;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (node != null)
                    {
                        node = node.Track(s[j]);
                        if (node != null && node.IsEnd)
                        {
                            d[i] = Math.Min(d[i], d[j]);
                        }
                    }
                }
            }
            return d[n];
        }


        public class Trie
        {
            public Trie[] children;
            public bool IsEnd
            {
                get; set;
            }

            public Trie()
            {
                children = new Trie[26];
                IsEnd = false;
            }

            public void Insert(String word)
            {
                Trie node = this;
                foreach (char ch in word)
                {
                    if (node.children[ch - 'a'] == null)
                    {
                        node.children[ch - 'a'] = new Trie();
                    }
                    node = node.children[ch - 'a'];
                }
                node.IsEnd = true;
            }

            public Trie Track(char ch)
            {
                Trie node = this;
                if (node == null || node.children[ch - 'a'] == null)
                {
                    return null;
                }
                node = node.children[ch - 'a'];
                return node;
            }
        }



    }
}
