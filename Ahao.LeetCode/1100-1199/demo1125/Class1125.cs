using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1125
{
    public class Class1125
    {

        public int[] SmallestSufficientTeam(string[] req_skills, IList<IList<string>> people)
        {
            int n = req_skills.Length, m = people.Count;
            IDictionary<string, int> skill_index = new Dictionary<string, int>();
            for (int i = 0; i < n; ++i)
            {
                skill_index.Add(req_skills[i], i);
            }
            IList<int>[] dp = new IList<int>[1 << n];
            dp[0] = new List<int>();
            for (int i = 0; i < m; ++i)
            {
                int cur_skill = 0;
                foreach (string s in people[i])
                {
                    cur_skill |= 1 << skill_index[s];
                }
                for (int prev = 0; prev < dp.Length; ++prev)
                {
                    if (dp[prev] == null)
                    {
                        continue;
                    }
                    int comb = prev | cur_skill;
                    if (dp[comb] == null || dp[prev].Count + 1 < dp[comb].Count)
                    {
                        dp[comb] = new List<int>(dp[prev]);
                        dp[comb].Add(i);
                    }
                }
            }
            return dp[(1 << n) - 1].ToArray();
        }


        public int[] SmallestSufficientTeam2(string[] req_skills, IList<IList<string>> people)
        {
            int n = req_skills.Length, m = people.Count;
            IDictionary<string, int> skill_index = new Dictionary<string, int>();
            for (int i = 0; i < n; ++i)
            {
                skill_index.Add(req_skills[i], i);
            }
            int[] dp = new int[1 << n];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i] = m;
            }
            dp[0] = 0;
            int[] prev_skill = new int[1 << n];
            int[] prev_people = new int[1 << n];
            for (int i = 0; i < m; ++i)
            {
                int cur_skill = 0;
                foreach (string s in people[i])
                {
                    cur_skill |= 1 << skill_index[s];
                }
                for (int prev = 0; prev < dp.Length; prev++)
                {
                    int comb = prev | cur_skill;
                    if (dp[comb] > dp[prev] + 1)
                    {
                        dp[comb] = dp[prev] + 1;
                        prev_skill[comb] = prev;
                        prev_people[comb] = i;
                    }
                }
            }
            List<int> res = new List<int>();
            int skills = (1 << n) - 1;
            while (skills > 0)
            {
                res.Add(prev_people[skills]);
                skills = prev_skill[skills];
            }
            return res.ToArray();
        }


    }
}
