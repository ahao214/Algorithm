﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo811
{
    public class Class811
    {
        public IList<string> SubdomainVisits(string[] cpdomains)
        {
            IList<string> ans = new List<string>();
            Dictionary<string, int> counts = new Dictionary<string, int>();
            foreach (string cpdomain in cpdomains)
            {
                int space = cpdomain.IndexOf(' ');
                int count = int.Parse(cpdomain.Substring(0, space));
                string domain = cpdomain.Substring(space + 1);
                if (!counts.ContainsKey(domain))
                {
                    counts.Add(domain, 0);
                }
                counts[domain] += count;
                for (int i = 0; i < domain.Length; i++)
                {
                    if (domain[i] == '.')
                    {
                        string subdomain = domain.Substring(i + 1);
                        if (!counts.ContainsKey(subdomain))
                        {
                            counts.Add(subdomain, 0);
                        }
                        counts[subdomain] += count;
                    }
                }
            }
            foreach (KeyValuePair<string, int> pair in counts)
            {
                string subdomain = pair.Key;
                int count = pair.Value;
                ans.Add(count + " " + subdomain);
            }
            return ans;
        }
    }
}
