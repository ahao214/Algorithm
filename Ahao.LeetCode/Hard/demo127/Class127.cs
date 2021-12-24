using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo127
{
    /// <summary>
    /// 127. 单词接龙
    /// </summary>
    public class Class127
    {
        public int LadderLength(string beginWord, string endWord, IList<string> wordList)
        {
            if (beginWord == null || endWord == null || beginWord.Length != endWord.Length || wordList == null || wordList.Count == 0)
            {
                return 0;
            }

            var wordSet = new HashSet<string>(wordList);
            if (!wordSet.Remove(endWord))
            {
                return 0;
            }

            var queue = new Queue<string>();
            var target = new Queue<string>();
            var depth = 1;

            queue.Enqueue(beginWord);
            target.Enqueue(endWord);
            while (queue.Count > 0 || target.Count > 0)
            {
                depth++;
                if (Trans(target, queue, wordSet))
                {
                    return depth;
                }
                depth++;
                if (Trans(queue, target, wordSet))
                {
                    return depth;
                }
            }
            return 0;
        }

        private bool Trans(Queue<string> target, Queue<string> queue, HashSet<string> wordSet)
        {
            var nextQueue = new HashSet<string>();

            foreach (var node in queue)
            {
                if (target.Any(t => CanTrans(node, t)))
                {
                    return true;
                }
                foreach (var word in wordSet.Where(t => CanTrans(t, node)))
                {
                    nextQueue.Add(word);
                }
            }
            queue.Clear();
            foreach (var word in nextQueue)
            {
                queue.Enqueue(word);
            }
            wordSet.ExceptWith(nextQueue);
            return false;
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
