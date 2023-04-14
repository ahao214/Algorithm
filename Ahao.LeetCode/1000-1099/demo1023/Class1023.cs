using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;


namespace Ahao.LeetCode._1000_1099.demo1023
{
    public class Class1023
    {

        public IList<bool> CamelMatch(string[] queries, string pattern)
        {
            int n = queries.Length;
            IList<bool> res = new List<bool>();
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                int p = 0;
                foreach (char c in queries[i])
                {
                    if (p < pattern.Length && pattern[p] == c)
                    {
                        p++;
                    }
                    else if (char.IsUpper(c))
                    {
                        flag = false;
                        break;
                    }
                }
                if (p < pattern.Length)
                {
                    flag = false;
                }
                res.Add(flag);
            }
            return res;
        }

        public IList<bool> CamelMatch2(string[] queries, string pattern)
        {

            List<bool> res = new List<bool>();
            StringBuilder sb = new StringBuilder();
            sb.Append("^");
            foreach (var it in pattern)
            {
                sb.Append("[a-z]*");
                sb.Append("[");
                sb.Append(it);
                sb.Append("]{1}");

            }
            sb.Append("[a-z]*");
            sb.Append("$");
            String pat = sb.ToString();
            Regex re = new Regex(pat);
            foreach (var it in queries)
            {
                Match m = re.Match(it);
                if (m.Success)
                {
                    res.Add(true);
                }
                else
                {
                    res.Add(false);
                }
            }

            return res;

        }


        public IList<bool> CamelMatch3(string[] queries, string pattern)
        {
            List<bool> ret = new List<bool>();
            foreach (var item in queries)
            {
                ret.Add(Func(item, pattern));
            }
            return ret;
        }
        public bool Func(string q, string p)
        {
            int index = 0;
            for (int i = 0; i < q.Length; i++)
            {
                if (index >= p.Length)
                {
                    if (q[i] >= 'A' && q[i] <= 'Z')
                        return false;
                    else
                        continue;
                }
                if (q[i] == p[index])
                {
                    index++;
                    continue;
                }

                if (q[i] >= 'A' && q[i] <= 'Z')
                {
                    return false;
                }
            }
            if (index < p.Length) return false;
            return true;
        }



    }
}
