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
    }
}
