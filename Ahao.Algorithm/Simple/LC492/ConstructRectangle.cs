using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 492. 构造矩形
    /// </summary>
    public class ConstructRectangle
    {
        public int[] Method(int area)
        {
            int width = (int)Math.Sqrt(area);
            while (area % width != 0)
            {
                width--;
            }
            return new int[] { area / width, width };
        }
    }
}
