using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple.LC1436
{
    /// <summary>
    /// 1436. 旅行终点站
    /// </summary>
    public class DestCity
    {
        public string Method(IList<IList<string>> paths)
        {
            ISet<string> cities = new HashSet<string>();
            foreach (IList<string> startPath in paths)
            {
                cities.Add(startPath[0]);
            }
            foreach (IList<string> endPath in paths)
            {
                if (!cities.Contains(endPath[1]))
                {
                    return endPath[1];
                }
            }
            return "";
        }
    }
}
