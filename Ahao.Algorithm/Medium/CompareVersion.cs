using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 165. 比较版本号
    /// </summary>
    public class CompareVersion
    {
        public int Method(string version1, string version2)
        {
            string[] v1 = version1.Split('.');
            string[] v2 = version2.Split('.');
            // 模拟比较对应下标的修订号
            for (int i = 0; i < v1.Length || i < v2.Length; ++i)
            {
                // 用于比较，比较过程中下一个修订号没有值的看作0
                int x = 0, y = 0;
                if (i < v1.Length)
                {
                    x = int.Parse(v1[i]);
                }
                if (i < v2.Length)
                {
                    y = int.Parse(v2[i]);
                }
                // 遇到相等的情况，继续判断后面的修订号
                if (x != y)
                {
                    return x > y ? 1 : -1;
                }
            }
            return 0;
        }
    }
}
