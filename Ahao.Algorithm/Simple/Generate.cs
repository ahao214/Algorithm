using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 118.杨辉三角
    /// </summary>
    public class Generate
    {
        public IList<IList<int>> Method(int numRows)
        {
            //var list = new List<IList<int>>();
            //for (int i = 0; i < numRows; i++)
            //{
            //    var level = Enumerable.Repeat(1, i + 1).ToList();
            //    if (i > 0)
            //    {
            //        var sub = list[i - 1];
            //        for (int j = 1; j < sub.Count; j++)
            //        {
            //            level[j] = sub[j - 1] + sub[j];
            //        }
            //    }
            //    list.Add(level);
            //}
            //return list;

            var result = new List<IList<int>>();

            for (int i = 0; i < numRows; i++)
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
                result.Add(list);
            }

            return result;
        }
    }
}
