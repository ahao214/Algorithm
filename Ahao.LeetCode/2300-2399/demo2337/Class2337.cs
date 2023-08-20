using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2337
{
    public class Class2337
    {
        public bool CanChange(string start, string target)
        {
            int n = start.Length;
            int i = 0, j = 0;
            while (i < n && j < n)
            {
                while (i < n && start[i] == '_')
                {
                    i++;
                }
                while (j < n && target[j] == '_')
                {
                    j++;
                }
                if (i < n && j < n)
                {
                    if (start[i] != target[j])
                    {
                        return false;
                    }
                    char c = start[i];
                    if ((c == 'L' && i < j) || (c == 'R' && i > j))
                    {
                        return false;
                    }
                    i++;
                    j++;
                }
            }
            while (i < n)
            {
                if (start[i] != '_')
                {
                    return false;
                }
                i++;
            }
            while (j < n)
            {
                if (target[j] != '_')
                {
                    return false;
                }
                j++;
            }
            return true;
        }

    }
}
