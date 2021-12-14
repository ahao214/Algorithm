using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo630
{
    /// <summary>
    /// 630. 课程表 III
    /// </summary>
    public class Class630
    {
        public int ScheduleCourse(int[][] courses)
        {
            var t = courses.OrderBy(a => a[1]);
            var list = new SortedList();
            int total = 0, i = 0;
            foreach (var cour in t)
            {
                int c0 = cour[0], c1 = cour[1];
                var sum = total + c0;
                if (sum <= c1)
                {
                    total = sum;
                    list.Add((c0 << 14) + i++, c0);
                }
                else
                {
                    var cnt = list.Count;
                    if (cnt == 0) continue;
                    var max = (int)list.GetByIndex(--cnt);
                    if (max > c0)
                    {
                        list.RemoveAt(cnt);
                        total = sum - max;
                        list.Add((c0 << 14) + i++, c0);
                    }
                }
            }
            return list.Count;
        }
    }
}
