﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1773
{
    public class Class1773
    {
        public int CountMatches(IList<IList<string>> items, string ruleKey, string ruleValue)
        {
            int index = new Dictionary<string, int>() {
            {"type", 0}, {"color", 1}, {"name", 2}
        }[ruleKey];
            int res = 0;
            foreach (IList<string> item in items)
            {
                if (item[index].Equals(ruleValue))
                {
                    res++;
                }
            }
            return res;
        }

    }
}
