using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo825
{
    /// <summary>
    /// 825. 适龄的朋友
    /// </summary>
    public class Class825
    {
        //超时
        public int NumFriendRequests(int[] ages)
        {
            int result = 0;
            Array.Sort(ages);
            for (int i = 0; i < ages.Length; i++)
            {
                for (int j = i + 1; j < ages.Length; j++)
                {
                    if (!IsTrue(ages[i], ages[j]))
                    {
                        result++;
                    }
                    if (!IsTrue(ages[j], ages[i]))
                    {
                        result++;
                    }
                }
            }
            return result;
        }


        public int NumFriendRequests1(int[] ages)
        {
            if (ages == null || ages.Length == 0)
            {
                return 0;
            }

            int[] count = new int[121];
            foreach (var age in ages)
            {
                count[age]++;
            }
            int ans = 0;
            for (int ageA = 0; ageA <= 120; ageA++)
            {
                int countA = count[ageA];
                for (int ageB = 0; ageB <= 120; ageB++)
                {
                    int countB = count[ageB];
                    if (ageA * 0.5 + 7 >= ageB) continue;
                    if (ageA < ageB) continue;
                    if (ageA < 100 && 100 < ageB) continue;
                    ans += countA * countB;
                    if (ageA == ageB) ans -= countA;
                }
            }
            return ans;
        }

        //如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求
        public bool IsTrue(int x, int y)
        {
            if (y <= x / 2 + 7 || y > x || (y > 100 && x < 100))
            {
                return true;
            }
            return false;
        }
    }
}
