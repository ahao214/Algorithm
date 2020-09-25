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
            //var result = new List<IList<int>>();
            //for (int i = 0; i < rowIndex + 1; i++)
            //{
            //    var list = new List<int>(i + 1);
            //    for (int j = 0; j < i + 1; j++)
            //    {
            //        int number;
            //        if (i == 0 || j == 0 || j == i)
            //        {
            //            number = 1;
            //        }
            //        else
            //        {
            //            number = result[i - 1][j - 1] + result[i - 1][j];
            //        }
            //        list.Add(number);
            //    }
            //    if (rowIndex == i)
            //    {
            //        return list;
            //    }
            //    result.Add(list);
            //}

            //return result.Last();

            int[] arr = new int[rowIndex + 1];
            for (int i = 0; i <= rowIndex; i++)
            {
                arr[i] = 1;
                for (int j = i; j > 1; j--)
                {
                    arr[j - 1] = arr[j - 2] + arr[j - 1];
                }
            }
            return arr;
        }
    }
}
