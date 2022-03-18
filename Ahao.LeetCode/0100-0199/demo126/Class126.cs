using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo126
{
    /// <summary>
    /// 126. 单词接龙 II
    /// </summary>
    public class Class126
    {
        public IList<IList<string>> FindLadders(string beginWord, string endWord, IList<string> wordList)
        {
            if (beginWord == null || endWord == null || wordList == null || beginWord.Length != endWord.Length || wordList.Count == 0)
            {
                return new List<IList<string>>(0);
            }

            var wordSet = new HashSet<string>(wordList);
            if (!wordSet.Contains(endWord))
            {
                return new List<IList<string>>(0);
            }

            var results = new List<IList<string>>();
            var queue = new Queue<(string word, List<IList<string>> paths)>();
            queue.Enqueue((beginWord, new List<IList<string>>() { new[] { beginWord } }));
            while (queue.Count > 0)
            {
                for (int i = queue.Count; i > 0; i--)
                {
                    var node = queue.Dequeue();
                    foreach (var word in wordSet)
                    {
                        if (CanTrans(node.word, word))
                        {
                            //node.paths.ForEach(t => t.Add(word));
                            if (word == endWord)
                            {
                                results.AddRange(node.paths.Select(t => new List<string>(t) { word }));
                            }
                            else if (results.Count == 0)
                            {
                                queue.Enqueue((word, node.paths.Select(t => new List<string>(t) { word } as IList<string>).ToList()));
                            }
                        }
                    }
                }
                if (results.Count > 0)
                    break;
                foreach (var node in queue)
                {
                    wordSet.Remove(node.word);
                }
            }
            return results;
        }


        private bool CanTrans(string word1, string word2)
        {
            if (word1.Length != word2.Length)
            {
                return false;
            }
            var count = 1;
            for (int i = 0; i < word1.Length; i++)
            {
                if (word1[i] != word2[i])
                {
                    count--;
                    if (count < 0)
                    {
                        return false;
                    }
                }
            }
            return count == 0;
        }
    }
}
