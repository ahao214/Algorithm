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

    }
}
