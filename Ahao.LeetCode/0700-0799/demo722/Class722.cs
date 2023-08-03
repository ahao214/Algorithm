using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo722
{
    internal class Class722
    {

        public IList<string> RemoveComments(string[] source)
        {
            IList<string> res = new List<string>();
            StringBuilder newLine = new StringBuilder();
            bool inBlock = false;
            foreach (string line in source)
            {
                for (int i = 0; i < line.Length; i++)
                {
                    if (inBlock)
                    {
                        if (i + 1 < line.Length && line[i] == '*' && line[i + 1] == '/')
                        {
                            inBlock = false;
                            i++;
                        }
                    }
                    else
                    {
                        if (i + 1 < line.Length && line[i] == '/' && line[i + 1] == '*')
                        {
                            inBlock = true;
                            i++;
                        }
                        else if (i + 1 < line.Length && line[i] == '/' && line[i + 1] == '/')
                        {
                            break;
                        }
                        else
                        {
                            newLine.Append(line[i]);
                        }
                    }
                }
                if (!inBlock && newLine.Length > 0)
                {
                    res.Add(newLine.ToString());
                    newLine.Length = 0;
                }
            }
            return res;
        }



        public List<String> RemoveComments2(String[] source)
        {
            String str = String.Join("\n", source);
            StringBuilder sb = new StringBuilder();

            while (str.Length > 0)
            {
                int s = str.IndexOf("/*"), d = str.IndexOf("//");
                if (s == -1 && d == -1)
                {
                    sb.Append(str);
                    break;
                }
                if (s != -1 && (d == -1 || s < d))
                {
                    // /*形式注释
                    sb.Append(str.Substring(0, s));
                    str = str.Substring(s + 2);
                    int e = str.IndexOf("*/");
                    str = str.Substring(e + 2);
                }
                else if (d != -1 && (s == -1 || d < s))
                {
                    // //形式注释
                    sb.Append(str.Substring(0, d));
                    str = str.Substring(d + 2);
                    int e = str.IndexOf("\n");
                    if (e == -1)
                    {
                        break;
                    }
                    str = str.Substring(e);
                }
            }
            String[] strs = sb.ToString().Split("\n");
            List<String> ans = new List<string>();
            foreach (var item in strs)
            {
                if (item.Length > 0)
                {
                    ans.Add(item);
                }
            }
            return ans;
        }

    }
}
