using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 
    /// </summary>
    public class ArrangeCoins
    {
		public int Method(int n)
		{
			int k;
			int sum = 0;
			if (n == 1)
			{
				return 1;
			}

			for (k= 1; k < n; k++)
			{
				sum += k;
				if (sum > n)
					break;
			}
			return k - 1;
		}
	}
}
