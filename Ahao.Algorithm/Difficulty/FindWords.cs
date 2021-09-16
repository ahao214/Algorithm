﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Difficulty
{
    /// <summary>
    /// 212. 单词搜索 II
    /// </summary>
    public class FindWords
    {
        int[][] dirs = new int[][] {
        new int[]{1, 0},
        new int[]{-1, 0},
        new int[]{0, 1},
        new int[]{0, -1}
    };


        public IList<string> Method(char[][] board, string[] words)
        {
            Trie trie = new Trie();
            foreach (string word in words)
            {
                trie.Insert(word);
            }

            ISet<string> ans = new HashSet<string>();
            for (int i = 0; i < board.Length; ++i)
            {
                for (int j = 0; j < board[0].Length; ++j)
                {
                    DFS(board, trie, i, j, ans);
                }
            }

            return new List<string>(ans);
        }

        void DFS(char[][] board, Trie now, int i1, int j1, ISet<string> ans)
        {
            if (!now.children.ContainsKey(board[i1][j1]))
            {
                return;
            }
            char ch = board[i1][j1];
            now = now.children[ch];
            if (now.word != "")
            {
                ans.Add(now.word);
            }

            board[i1][j1] = '#';
            foreach (int[] dir in dirs)
            {
                int i2 = i1 + dir[0], j2 = j1 + dir[1];
                if (i2 >= 0 && i2 < board.Length && j2 >= 0 && j2 < board[0].Length)
                {
                    DFS(board, now, i2, j2, ans);
                }
            }
            board[i1][j1] = ch;
        }

        class Trie
        {
            public string word;
            public Dictionary<char, Trie> children;
            public bool isWord;

            public Trie()
            {
                this.word = "";
                this.children = new Dictionary<char, Trie>();
            }

            public void Insert(string word)
            {
                Trie cur = this;
                foreach (char c in word)
                {
                    if (!cur.children.ContainsKey(c))
                    {
                        cur.children.Add(c, new Trie());
                    }
                    cur = cur.children[c];
                }
                cur.word = word;
            }
        }
    }
}
