using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中和为指定值的四元组
    /// </summary>
    public class TestFourNum
    {
        public static List<List<int>> FourNum(int[] num, int target)
        {
            List<List<int>> res = new List<List<int>>();
            Array.Sort(num);
            for (int i = 0; i < num.Length - 3; i++)
            {
                if (i != 0 && num[i] == num[i - 1])
                {
                    continue;
                }
                for (int j = i + 1; j < num.Length - 2; j++)
                {
                    if (j != i + 1 && num[j] == num[j - 1])
                    {
                        continue;
                    }
                    int left = j + 1;
                    int right = num.Length - 1;
                    while (left < right)
                    {
                        int sum = num[i] + num[j] + num[left] + num[right];
                        if (sum < target)
                        {
                            left++;
                        }
                        else if (sum > target)
                        {
                            right--;
                        }
                        else
                        {
                            List<int> tmp = new List<int>();
                            tmp.Add(num[i]);
                            tmp.Add(num[j]);
                            tmp.Add(num[left]);
                            tmp.Add(num[right]);
                            res.Add(tmp);
                            left++;
                            right--;
                            while (left < right && num[left] == num[left - 1])
                            {
                                left++;
                            }
                            while (left < right && num[right] == num[right + 1])
                            {
                                right--;
                            }
                        }
                    }
                }
            }
            return res;
        }
    }
}
