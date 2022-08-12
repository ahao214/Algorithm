using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1282
{
    public class Class1282
    {
        public IList<IList<int>> GroupThePeople(int[] groupSizes)
        {
            Dictionary<int, IList<int>> groups = new Dictionary<int, IList<int>>();
            int n = groupSizes.Length;
            for (int i = 0; i < n; i++)
            {
                int size = groupSizes[i];
                groups.TryAdd(size, new List<int>());
                groups[size].Add(i);
            }
            IList<IList<int>> groupList = new List<IList<int>>();
            foreach (KeyValuePair<int, IList<int>> pair in groups)
            {
                int size = pair.Key;
                IList<int> people = pair.Value;
                int groupCount = people.Count / size;
                for (int i = 0; i < groupCount; i++)
                {
                    IList<int> group = new List<int>();
                    int start = i * size;
                    for (int j = 0; j < size; j++)
                    {
                        group.Add(people[start + j]);
                    }
                    groupList.Add(group);
                }
            }
            return groupList;
        }

    }
}
