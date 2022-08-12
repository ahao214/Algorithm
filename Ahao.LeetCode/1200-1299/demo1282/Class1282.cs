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



        public IList<IList<int>> GroupThePeople2(int[] groupSizes)
        {
            IList<IList<int>> list = new List<IList<int>>();
            Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
            int n = groupSizes.Length;
            for (int i = 0; i < n; i++)
            {
                int size = groupSizes[i];
                if (dic.ContainsKey(size))
                    dic[size].Add(i);
                else
                    dic.Add(size, new List<int>() { i });

                //分组容量已满，加入集合
                if (size == dic[size].Count)
                {
                    list.Add(dic[size]);
                    dic.Remove(size);
                }
            }
            return list;
        }

        public IList<IList<int>> GroupThePeople3(int[] groupSizes)
        {
            IList<IList<int>> ilist = new List<IList<int>>();
            List<int> list = new List<int>();
            int[] arr = groupSizes.Distinct().ToArray();
            for (int i = 0; i < arr.Length; i++)
            {
                int j = i;
                while (j < groupSizes.Length)
                {
                    if (arr[i] == groupSizes[j])
                        list.Add(j);
                    if (list.Count == arr[i] || j == groupSizes.Length - 1 && list.Count > 0)
                    {
                        ilist.Add(new List<int>(list));
                        list.Clear();
                    }
                    j++;
                }
            }
            return ilist;
        }



    }
}
