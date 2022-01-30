using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5993
{
    /*
     5993. 将找到的值乘以 2
    给你一个整数数组 nums ，另给你一个整数 original ，这是需要在 nums 中搜索的第一个数字。

    接下来，你需要按下述步骤操作：

    如果在 nums 中找到 original ，将 original 乘以 2 ，得到新 original（即，令 original = 2 * original）。
    否则，停止这一过程。
    只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。
    返回 original 的 最终 值。
     */
    public class Class5993
    {
        public int FindFinalValue(int[] nums, int original)
        {
            int res = original;
            bool isInclude = true;
            while (isInclude)
            {
                if (nums.Contains(original))
                {
                    original *= 2;
                    isInclude = true;
                    res = original;
                }
                else
                {
                    isInclude = false;
                }
            }
            return res;
        }
    }
}
