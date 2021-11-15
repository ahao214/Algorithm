using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 659. 分割数组为连续子序列
    /// </summary>
    public class IsPossible
    {
        public bool Method(int[] nums)
        {
            int count = nums.Length;
            if (count<3)
            {
                return false;
            }
            
            //给定数组中的数及出现次数的映射
            Dictionary<int, int> dicNums = new Dictionary<int, int>();
            //可以加在某个连续子序列后的数及其次数的映射
            Dictionary<int, int> dicCosts = new Dictionary<int, int>();
            //初始化
            foreach (var num in nums)
            {
                if (dicNums.ContainsKey(num))
                {
                    dicNums[num]++;
                }
                else
                {
                    dicNums.Add(num, 1);
                }
                if (!dicCosts.ContainsKey(num))
                {
                    dicCosts.Add(num, 0);
                }
            }

            foreach (var num in nums)
            {
                //若出现次数为0，继续遍历
                if (dicNums[num] <= 0)
                    continue;
                else if (dicCosts[num] > 0)
                {
                    dicNums[num]--;
                    dicCosts[num]--;
                    //将下一个需要的连续数加一
                    if (dicCosts.ContainsKey(num + 1))
                    {
                        dicCosts[num + 1]++;
                    }
                }
                else if (dicNums.ContainsKey(num + 1) && dicNums[num + 1] > 0 && dicNums.ContainsKey(num + 2) && dicNums[num + 2] > 0)
                {
                    //如果该数不能添加到某个连续子序列末，但可以作为新的连续子序列起点
                    dicNums[num]--;
                    dicNums[num + 1]--;
                    dicNums[num + 2]--;
                    //新的连续子序列的下一个需要的数次数+1
                    if (dicCosts.ContainsKey(num + 3))
                    {
                        dicCosts[num + 3]++;
                    }
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
}
