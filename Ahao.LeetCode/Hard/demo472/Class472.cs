using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo472
{
    /// <summary>
    /// 472. 连接词
    /// </summary>
    public class Class472
    {
        Trie trie = new Trie();

        public IList<string> FindAllConcatenatedWordsInADict(string[] words)
        {
            IList<string> ans = new List<string>();
            Array.Sort(words, (a, b) => a.Length - b.Length);
            for (int i = 0; i < words.Length; i++)
            {
                string word = words[i];
                if (word.Length == 0)
                {
                    continue;
                }
                if (DFS(word, 0))
                {
                    ans.Add(word);
                }
                else
                {
                    Insert(word);
                }
            }
            return ans;
        }

        public bool DFS(string word, int start)
        {
            if (word.Length == start)
            {
                return true;
            }
            Trie node = trie;
            for (int i = start; i < word.Length; i++)
            {
                char ch = word[i];
                int index = ch - 'a';
                node = node.children[index];
                if (node == null)
                {
                    return false;
                }
                if (node.isEnd)
                {
                    if (DFS(word, i + 1))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public void Insert(string word)
        {
            Trie node = trie;
            for (int i = 0; i < word.Length; i++)
            {
                char ch = word[i];
                int index = ch - 'a';
                if (node.children[index] == null)
                {
                    node.children[index] = new Trie();
                }
                node = node.children[index];
            }
            node.isEnd = true;
        }
    }

    class Trie
    {
        public Trie[] children;
        public bool isEnd;

        public Trie()
        {
            children = new Trie[26];
            isEnd = false;
        }
    }
}
