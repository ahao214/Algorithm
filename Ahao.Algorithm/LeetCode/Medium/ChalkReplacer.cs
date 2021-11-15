using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1894. 找到需要补充粉笔的学生编号
    /// </summary>
    public class ChalkReplacer
    {
        public int Method(int[] chalk, int k)
        {
            long sumChalk = 0;
            foreach (int item in chalk)
            {
                sumChalk += item;
            }
            if (k >= sumChalk)
            {
                k %= (int)sumChalk;
            }
            int result = -1;
            for (int i = 0; i < chalk.Length; ++i)
            {
                if (k < chalk[i])
                {
                    result = i;
                    break;
                }
                k -= chalk[i];
            }
            return result;
        }
    }
}
