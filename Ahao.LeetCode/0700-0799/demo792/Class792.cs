using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo792
{
    public class Class792
    {
        /// <summary>
        /// 二分查找
        /// </summary>
        /// <param name="s"></param>
        /// <param name="words"></param>
        /// <returns></returns>
        public int NumMatchingSubseq(string s, string[] words)
        {
            IList<int>[] pos = new IList<int>[26];
            for (int i = 0; i < 26; ++i)
            {
                pos[i] = new List<int>();
            }
            for (int i = 0; i < s.Length; ++i)
            {
                pos[s[i] - 'a'].Add(i);
            }
            int res = words.Length;
            foreach (string w in words)
            {
                if (w.Length > s.Length)
                {
                    --res;
                    continue;
                }
                int p = -1;
                for (int i = 0; i < w.Length; ++i)
                {
                    char c = w[i];
                    if (pos[c - 'a'].Count == 0 || pos[c - 'a'][pos[c - 'a'].Count - 1] <= p)
                    {
                        --res;
                        break;
                    }
                    p = BinarySearch(pos[c - 'a'], p);
                }
            }
            return res;
        }

        public int BinarySearch(IList<int> list, int target)
        {
            int left = 0, right = list.Count - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (list[mid] > target)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return list[left];
        }


        /// <summary>
        /// 多指针
        /// </summary>
        /// <param name="s"></param>
        /// <param name="words"></param>
        /// <returns></returns>
        public int NumMatchingSubseq2(string s, string[] words)
        {
            Queue<int[]>[] p = new Queue<int[]>[26];
            for (int i = 0; i < 26; ++i)
            {
                p[i] = new Queue<int[]>();
            }
            for (int i = 0; i < words.Length; ++i)
            {
                p[words[i][0] - 'a'].Enqueue(new int[] { i, 0 });
            }
            int res = 0;
            for (int i = 0; i < s.Length; ++i)
            {
                char c = s[i];
                int len = p[c - 'a'].Count;
                while (len > 0)
                {
                    int[] t = p[c - 'a'].Dequeue();
                    if (t[1] == words[t[0]].Length - 1)
                    {
                        ++res;
                    }
                    else
                    {
                        ++t[1];
                        p[words[t[0]][t[1]] - 'a'].Enqueue(t);
                    }
                    --len;
                }
            }
            return res;
        }

    }
}
