using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    public class Class2100
    {
        public IList<int> GoodDaysToRobBank(int[] security, int time)
        {
            //超出时间限制
            IList<int> res = new List<int>();

            for (int i = time; i < security.Length - time; i++)
            {
                bool mulFlag = true;
                bool addFlag = true;
                for (int m = i - time; m < i; m++)
                {
                    if (security[m] >= security[m + 1])
                        mulFlag = true;
                    else
                    {
                        mulFlag = false;
                        break;
                    }
                }
                for (int n = i + 1; n <= i + time; n++)
                {
                    if (security[n - 1] <= security[n])
                        addFlag = true;
                    else
                    {
                        addFlag = false;
                        break;
                    }
                }
                if (mulFlag && addFlag)
                    res.Add(i);
            }

            return res;
        }

        public IList<int> GoodDaysToRobBank1(int[] security, int time)
        {
            int n = security.Length;
            //左边递减
            int[] left = new int[n];
            //右边递增
            int[] right = new int[n];
            for (int i = 1; i < n; i++)
            {
                left[i] = (security[i] <= security[i - 1] ? left[i - 1] + 1 : 0);
            }
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = (security[i] <= security[i + 1] ? right[i + 1] + 1 : 0);
            }
            List<int> res = new List<int>();
            for (int i = time; i < n - time; i++)
            {
                if (left[i] >= time && right[i] >= time)
                    res.Add(i);
            }
            return res;
        }

        public IList<int> GoodDaysToRobBank2(int[] security, int time)
        {
            int n = security.Length;
            int[] left = new int[n];
            int[] right = new int[n];
            for (int i = 1; i < n; i++)
            {
                if (security[i] <= security[i - 1])
                {
                    left[i] = left[i - 1] + 1;
                }
                if (security[n - i - 1] <= security[n - i])
                {
                    right[n - i - 1] = right[n - i] + 1;
                }
            }

            IList<int> ans = new List<int>();
            for (int i = time; i < n - time; i++)
            {
                if (left[i] >= time && right[i] >= time)
                {
                    ans.Add(i);
                }
            }
            return ans;
        }

    }
}
