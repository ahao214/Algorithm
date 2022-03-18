using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo119
{
    /*
     119. 杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
     */
    public class Class119
    {
        public IList<int> GetRow(int rowIndex)
        {
            IList<IList<int>> ret = new List<IList<int>>();
            for (int i = 0; i <= rowIndex; i++)//注意这里本来没有=
            {
                IList<int> row = new List<int>();
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i)
                    {
                        row.Add(1);
                    }
                    else
                    {
                        row.Add(ret[i - 1][j - 1] + ret[i - 1][j]);//i-1代表上一行 ，j-1 代表上一行的左边，j代表上一行的左边的右边
                    }
                }
                ret.Add(row);
            }
            return ret[rowIndex];
        }
    }
}
