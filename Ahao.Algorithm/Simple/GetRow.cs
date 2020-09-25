using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 119.杨辉三角(2)
    /// </summary>
   public class GetRow
    {        
        public IList<int> Method(int rowIndex)
        {           
            var result = new List<IList<int>>();
            var res = new List<int>();
            for (int i = 0; i < rowIndex+1; i++)
            {
                var list = new List<int>(i + 1);
                for (int j = 0; j < i + 1; j++)
                {
                    int number;
                    if (i == 0 || j == 0 || j == i)
                    {
                        number = 1;
                    }
                    else
                    {
                        number = result[i - 1][j - 1] + result[i - 1][j];
                    }
                    list.Add(number);
                }
                res = list;
                result.Add(list);
            }
            
            return res;
        }
    }
}
