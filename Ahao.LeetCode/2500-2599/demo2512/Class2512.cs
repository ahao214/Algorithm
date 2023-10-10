using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2512
{
    public class Class2512
    {
        public IList<int> TopStudents(string[] positive_feedback, string[] negative_feedback, string[] report, int[] student_id, int k)
        {
            IDictionary<string, int> words = new Dictionary<string, int>();
            foreach (string word in positive_feedback)
            {
                words.TryAdd(word, 3);
            }
            foreach (string word in negative_feedback)
            {
                words.TryAdd(word, -1);
            }
            int n = report.Length;
            int[] scores = new int[n];
            int[][] A = new int[n][];
            for (int i = 0; i < n; i++)
            {
                int score = 0;
                foreach (string word in report[i].Split(" "))
                {
                    score += words.ContainsKey(word) ? words[word] : 0;
                }
                A[i] = new int[] { -score, student_id[i] };
            }
            Array.Sort(A, (a, b) => a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
            IList<int> topK = new List<int>();
            for (int i = 0; i < k; i++)
            {
                topK.Add(A[i][1]);
            }
            return topK;
        }




        public IList<int> TopStudents2(string[] positive_feedback, string[] negative_feedback, string[] report, int[] student_id, int k)
        {
            var rp = new PriorityQueue<int, int[]>(
                Comparer<int[]>.Create((a, b) => a[1] == b[1] ? a[0] - b[0] : b[1] - a[1])
            );
            var map = new Dictionary<string, int>();
            foreach (var s in positive_feedback) { if (!map.ContainsKey(s)) map.Add(s, 3); }
            foreach (var s in negative_feedback) { if (!map.ContainsKey(s)) map.Add(s, -1); }
            int n = student_id.Length, score = 0;
            for (int i = 0; i < n; ++i)
            {
                score = 0;
                var tmp = report[i].Split(' ');
                foreach (var s in tmp)
                {
                    if (map.ContainsKey(s)) score += map[s];
                }
                rp.Enqueue(student_id[i], new int[] { student_id[i], score });
            }
            var list = new List<int>();
            for (int i = 0; i < k; i++)
            {
                list.Add(rp.Dequeue());
            }
            return list;
        }


    }
}
