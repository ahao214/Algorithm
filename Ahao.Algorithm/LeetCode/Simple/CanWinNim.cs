using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 292. Nim 游戏
    /// </summary>
    public class CanWinNim
    {
        public bool Method(int n)
        {
            return n % 4 != 0;
        }
    }
}
