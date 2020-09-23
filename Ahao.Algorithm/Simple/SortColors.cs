using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 75.颜色分类
    /// </summary>
    public class SortColors
    {
        public void Method(int[] nums)
        {
            int red = 0;
            int white = 0;
            int blue = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 0)
                {
                    red += 1;
                }
                if (nums[i] == 1)
                {
                    white += 1;
                }
                if (nums[i] == 2)
                {
                    blue += 1;
                }
            }
            for (int i = 0; i < nums.Length; i++)
            {
                if (red > 0)
                {
                    nums[i] = 0;
                    red--;
                    continue;
                }
                if (white > 0)
                {
                    nums[i] = 1;
                    white--;
                    continue;
                }
                nums[i] = 2;
            }
        }
    }
}
