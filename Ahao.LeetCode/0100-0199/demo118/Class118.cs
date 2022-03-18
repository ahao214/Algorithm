using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo118
{
    /*
     118. 杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
     */
    public class Class118
    {
        public IList<IList<int>> Generate(int numRows)
        {
            var results = new List<IList<int>>(numRows);
            if (numRows > 0)
                results.Add(new[] { 1 });
            for (int i = 1; i < numRows; i++)
            {
                var preRow = results[i - 1];
                var row = new int[i + 1];
                results.Add(row);
                row[0] = row[i] = 1;
                for (int j = 1; j < row.Length - 1; j++)
                {
                    row[j] = preRow[j - 1] + preRow[j];
                }
            }
            return results;
        }
    }
}
