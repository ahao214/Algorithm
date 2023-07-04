using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2679
{
    public class Class2679
    {
        public int MatrixSum(int[][] nums)
        {
            int m = nums.Length;
            int n = nums[0].Length;
            for (int i = 0; i < m; i++)
            {
                Array.Sort(nums[i]);
            }

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                int maxValue = 0;
                for (int j = 0; j < m; j++)
                {
                    maxValue = Math.Max(maxValue, nums[j][i]);
                }
                res += maxValue;
            }
            return res;

        }



        public int MatrixSum2(int[][] nums)
        {
            int res = 0;
            int m = nums.Length;
            int n = nums[0].Length;
            PriorityQueue<int, int>[] pq = new PriorityQueue<int, int>[m];
            for (int i = 0; i < m; i++)
            {
                pq[i] = new PriorityQueue<int, int>();
                for (int j = 0; j < n; j++)
                {
                    pq[i].Enqueue(nums[i][j], -nums[i][j]);
                }
            }
            for (int j = 0; j < n; j++)
            {
                int maxVal = 0;
                for (int i = 0; i < m; i++)
                {
                    maxVal = Math.Max(maxVal, pq[i].Dequeue());
                }
                res += maxVal;
            }
            return res;
        }


    }
}
