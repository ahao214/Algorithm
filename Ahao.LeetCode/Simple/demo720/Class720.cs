using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo720
{
    /*
     720. 词典中最长的单词
给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

示例 1：

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
     */
    public class Class720
    {
        /// <summary>
        /// 哈希集合
        /// </summary>
        /// <param name="words"></param>
        /// <returns></returns>
        public string LongestWord(string[] words)
        {
            Array.Sort(words, (a, b) => {
                if (a.Length != b.Length)
                {
                    return a.Length - b.Length;
                }
                else
                {
                    return b.CompareTo(a);
                }
            });
            string longest = "";
            ISet<string> set = new HashSet<string>();
            set.Add("");
            int n = words.Length;
            for (int i = 0; i < n; i++)
            {
                string word = words[i];
                if (set.Contains(word.Substring(0, word.Length - 1)))
                {
                    set.Add(word);
                    longest = word;
                }
            }
            return longest;
        }

    }
}
