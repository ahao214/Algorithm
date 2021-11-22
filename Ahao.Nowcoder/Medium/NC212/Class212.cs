using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC212
{
    /// <summary>
    /// NC212 颜色分类
    /// </summary>
    public class Class212
    {
        public List<int> sortColor(List<int> colors)
        {
            int red = 0;
            int white = 0;
            int blue = 0;
            for (int i = 0; i < colors.Count; i++)
            {
                if (colors[i] == 0)
                {
                    red += 1;
                }
                if (colors[i] == 1)
                {
                    white += 1;
                }
                if (colors[i] == 2)
                {
                    blue += 1;
                }
            }
            for (int i = 0; i < colors.Count; i++)
            {
                if (red > 0)
                {
                    colors[i] = 0;
                    red--;
                    continue;
                }
                if (white > 0)
                {
                    colors[i] = 1;
                    white--;
                    continue;
                }
                colors[i] = 2;
            }
            return colors;
        }
    }
}
