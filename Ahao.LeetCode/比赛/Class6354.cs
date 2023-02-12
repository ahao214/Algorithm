using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6354. 找出数组的串联值  

给你一个下标从 0 开始的整数数组 nums 。

现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。

例如，15 和 49 的串联是 1549 。
nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空：

如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 中删除第一个和最后一个元素。
如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。
返回执行完所有操作后 nums 的串联值。
     */
    public class Class6354
    {
        public long FindTheArrayConcVal(int[] nums)
        {
            long res = 0;
            int left = 0;
            int right = nums.Length - 1;
            while (left <right)
            {
                string ans = nums[left].ToString() + nums[right].ToString();
                res += Convert.ToInt64(ans);
                left++;
                right--;
            }
            if (nums.Length % 2 == 0)
                return res;
            else
                res += nums[nums.Length / 2];

            return res;
        }
    }
}
