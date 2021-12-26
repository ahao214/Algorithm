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
            for (int ageX = 0; ageX <= 120; ageX++)
            {
                int countX = count[ageX];
                for (int ageY = 0; ageY <= 120; ageY++)
                {
                    int countY = count[ageY];
                    if (ageX * 0.5 + 7 >= ageY) continue;
                    if (ageX < ageY) continue;
                    if (ageX < 100 && 100 < ageY) continue;
                    ans += countX * countY;
                    if (ageX == ageY) ans -= countX;
                }
            }
            return ans;
        }

        public int NumFriendRequests2(int[] ages)
        {
            int n = ages.Length;
            Array.Sort(ages);
            int left = 0, right = 0, ans = 0;
            foreach (int age in ages)
            {
                if (age < 15)
                {
                    continue;
                }
                while (ages[left] <= 0.5 * age + 7)
                {
                    ++left;
                }
                while (right + 1 < n && ages[right + 1] <= age)
                {
                    ++right;
                }
                ans += right - left;
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
