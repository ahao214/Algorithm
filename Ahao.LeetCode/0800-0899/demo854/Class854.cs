using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo854
{
    public class Class854
    {
        #region 广度优先


        public int KSimilarity1(string s1, string s2)
        {
            int n = s1.Length;
            Queue<Tuple<string, int>> queue = new Queue<Tuple<string, int>>();
            ISet<string> visit = new HashSet<string>();
            queue.Enqueue(new Tuple<string, int>(s1, 0));
            visit.Add(s1);
            int step = 0;
            while (queue.Count > 0)
            {
                int sz = queue.Count;
                for (int i = 0; i < sz; i++)
                {
                    Tuple<string, int> tuple = queue.Dequeue();
                    string cur = tuple.Item1;
                    int pos = tuple.Item2;
                    if (cur.Equals(s2))
                    {
                        return step;
                    }
                    while (pos < n && cur[pos] == s2[pos])
                    {
                        pos++;
                    }
                    for (int j = pos + 1; j < n; j++)
                    {
                        if (s2[j] == cur[j])
                        {
                            continue;
                        }
                        if (s2[pos] == cur[j])
                        {
                            string next = Swap1(cur, pos, j);
                            if (!visit.Contains(next))
                            {
                                visit.Add(next);
                                queue.Enqueue(new Tuple<string, int>(next, pos + 1));
                            }
                        }
                    }
                }
                step++;
            }
            return step;
        }

        public string Swap1(string cur, int i, int j)
        {
            char[] arr = cur.ToCharArray();
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            return new string(arr);
        }


        #endregion

        #region 深度优先

        int ans;

        public int KSimilarity(string s1, string s2)
        {
            StringBuilder str1 = new StringBuilder();
            StringBuilder str2 = new StringBuilder();
            for (int i = 0; i < s1.Length; i++)
            {
                if (s1[i] != s2[i])
                {
                    str1.Append(s1[i]);
                    str2.Append(s2[i]);
                }
            }
            if (str1.Length == 0)
            {
                return 0;
            }
            ans = str1.Length - 1;
            DFS(0, 0, str1.Length, str1.ToString(), str2.ToString());
            return ans;
        }

        public void DFS(int pos, int cost, int len, string str1, string str2)
        {
            if (cost > ans)
            {
                return;
            }
            while (pos < str1.Length && str1[pos] == str2[pos])
            {
                pos++;
            }
            if (pos == str1.Length)
            {
                ans = Math.Min(ans, cost);
                return;
            }
            /* 当前状态的交换次数下限大于等于当前的最小交换次数 */
            if (cost + MinSwap(str1, str2, pos) >= ans)
            {
                return;
            }
            for (int i = pos + 1; i < str1.Length; i++)
            {
                if (str1[i] == str2[pos])
                {
                    string str1Next = Swap(str1, i, pos);
                    DFS(pos + 1, cost + 1, len, str1Next, str2);
                }
            }
        }

        public int MinSwap(string s1, string s2, int pos)
        {
            int tot = 0;
            for (int i = pos; i < s1.Length; i++)
            {
                tot += s1[i] != s2[i] ? 1 : 0;
            }
            return (tot + 1) / 2;
        }

        public string Swap(string cur, int i, int j)
        {
            char[] arr = cur.ToCharArray();
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            return new string(arr);
        }
        #endregion
    }
}
