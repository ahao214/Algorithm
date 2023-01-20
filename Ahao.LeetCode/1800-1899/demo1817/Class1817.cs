using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1817
{
    public class Class1817
    {
        public int[] FindingUsersActiveMinutes(int[][] logs, int k)
        {
            IDictionary<int, ISet<int>> activeMinutes = new Dictionary<int, ISet<int>>();
            foreach (int[] log in logs)
            {
                int id = log[0], time = log[1];
                activeMinutes.TryAdd(id, new HashSet<int>());
                activeMinutes[id].Add(time);
            }
            int[] answer = new int[k];
            foreach (ISet<int> minutes in activeMinutes.Values)
            {
                int activeCount = minutes.Count;
                answer[activeCount - 1]++;
            }
            return answer;
        }



        public int[] FindingUsersActiveMinutes1(int[][] logs, int k)
        {
            int[] ans = new int[k];
            Array.Fill(ans, 0);
            Dictionary<int, int> dic = new Dictionary<int, int>();

            var result = logs.GroupBy(i => String.Join(",", i))
                           .Select(i => i.First().ToList()).ToList();

            for (int i = 0; i < result.Count; i++)
            {
                if (!dic.ContainsKey(result[i][0]))
                    dic.Add(result[i][0], 1);
                else dic[result[i][0]]++;
            }

            foreach (var log in result)
            {
                if (dic.ContainsKey(log[0]))
                {
                    ans[dic[log[0]] - 1]++;
                    dic.Remove(log[0]);
                }
            }
            return ans;
        }

    }
}
