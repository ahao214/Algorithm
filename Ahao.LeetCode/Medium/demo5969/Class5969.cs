using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5969
{
    /// <summary>
    /// 5969. 摧毁小行星
    /// </summary>
    public class Class5969
    {
        public bool AsteroidsDestroyed(int mass, int[] asteroids)
        {
            Array.Sort(asteroids);
            long cur = mass;
            for (int i = 0; i < asteroids.Length; i++)
            {
                if (cur >= asteroids[i])
                {
                    cur += asteroids[i];
                    continue;
                }
                if (cur < asteroids[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
