using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 60.第K个排列
    /// </summary>
    public class GetPermutation
    {
        public string Method(int n, int k)
        {
            List<string> nums = new List<string>();
            int temp = GetCount(n);//获取n!
            if (k <= temp)
            {
                k--;
                string result = "";
                for (int i = 1; i <= n; i++)
                {
                    nums.Add(i.ToString());
                }
                while (true)
                {
                    temp = temp / n--;
                    int current = k / temp;//得到第i个数的索引
                    k = k % temp;
                    result += nums[current];
                    nums.RemoveAt(current);//在加入后，将对应数字从List中删除
                    if (k == 0)
                    {
                        for (int i = 0; i < nums.Count; i++)
                        {
                            result += nums[i];
                        }
                        return result;
                    }
                }
            }


            return "0";

        }

        public int GetCount(int n)
        {
            int count = n;
            for (int i = n - 1; i > 0; i--)
            {
                count *= i;
            }
            return count;
        }
    }
}
