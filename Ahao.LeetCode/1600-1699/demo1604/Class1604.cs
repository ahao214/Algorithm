﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1604
{
    public class Class1604
    {
        public IList<string> AlertNames(string[] keyName, string[] keyTime)
        {
            IDictionary<string, IList<int>> timeDictionary = new Dictionary<string, IList<int>>();
            int n = keyName.Length;
            for (int i = 0; i < n; i++)
            {
                string name = keyName[i];
                string time = keyTime[i];
                timeDictionary.TryAdd(name, new List<int>());
                int hour = (time[0] - '0') * 10 + (time[1] - '0');
                int minute = (time[3] - '0') * 10 + (time[4] - '0');
                timeDictionary[name].Add(hour * 60 + minute);
            }
            IList<string> res = new List<string>();
            foreach (KeyValuePair<string, IList<int>> pair in timeDictionary)
            {
                string name = pair.Key;
                IList<int> list = pair.Value;
                ((List<int>)list).Sort();
                int size = list.Count;
                for (int i = 2; i < size; i++)
                {
                    int time1 = list[i - 2], time2 = list[i];
                    int difference = time2 - time1;
                    if (difference <= 60)
                    {
                        res.Add(name);
                        break;
                    }
                }
            }
            ((List<string>)res).Sort();
            return res;
        }


    }
}
