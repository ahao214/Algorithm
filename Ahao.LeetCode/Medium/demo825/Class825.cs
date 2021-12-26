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
