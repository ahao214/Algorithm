﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo71
{
    /// <summary>
    /// 71. 简化路径
    /// </summary>
    public class Class71
    {
        public string SimplifyPath(string path)
        {
            string[] names = path.Split("/");
            IList<string> stack = new List<string>();
            foreach (string name in names)
            {
                if ("..".Equals(name))
                {
                    if (stack.Count > 0)
                    {
                        stack.RemoveAt(stack.Count - 1);
                    }
                }
                else if (name.Length > 0 && !".".Equals(name))
                {
                    stack.Add(name);
                }
            }
            StringBuilder ans = new StringBuilder();
            if (stack.Count == 0)
            {
                ans.Append('/');
            }
            else
            {
                foreach (string name in stack)
                {
                    ans.Append('/');
                    ans.Append(name);
                }
            }
            return ans.ToString();
        }
    }
}
