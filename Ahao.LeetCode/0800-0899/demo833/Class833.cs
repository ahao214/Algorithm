using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo833
{
    public class Class833
    {

        public string FindReplaceString(string s, int[] indices, string[] sources, string[] targets)
        {
            int n = s.Length, m = indices.Length;

            IList<int> ops = new List<int>();
            for (int i = 0; i < m; i++)
            {
                ops.Add(i);
            }
            ((List<int>)ops).Sort((i, j) => indices[i] - indices[j]);

            StringBuilder ans = new StringBuilder();
            int pt = 0;
            for (int i = 0; i < n;)
            {
                while (pt < m && indices[ops[pt]] < i)
                {
                    pt++;
                }
                bool succeed = false;
                while (pt < m && indices[ops[pt]] == i)
                {
                    if (s.Substring(i, Math.Min(sources[ops[pt]].Length, n - i)).Equals(sources[ops[pt]]))
                    {
                        succeed = true;
                        break;
                    }
                    pt++;
                }
                if (succeed)
                {
                    ans.Append(targets[ops[pt]]);
                    i += sources[ops[pt]].Length;
                }
                else
                {
                    ans.Append(s[i]);
                    i++;
                }
            }
            return ans.ToString();
        }



        public string FindReplaceString2(string s, int[] indices, string[] sources, string[] targets)
        {
            int n = s.Length, m = indices.Length;

            IDictionary<int, IList<int>> ops = new Dictionary<int, IList<int>>();
            for (int i = 0; i < m; ++i)
            {
                ops.TryAdd(indices[i], new List<int>());
                ops[indices[i]].Add(i);
            }

            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < n;)
            {
                bool succeed = false;
                if (ops.ContainsKey(i))
                {
                    foreach (int pt in ops[i])
                    {
                        if (s.Substring(i, Math.Min(i + sources[pt].Length, n) - i).Equals(sources[pt]))
                        {
                            succeed = true;
                            ans.Append(targets[pt]);
                            i += sources[pt].Length;
                            break;
                        }
                    }
                }
                if (!succeed)
                {
                    ans.Append(s[i]);
                    ++i;
                }
            }
            return ans.ToString();
        }




    }
}
