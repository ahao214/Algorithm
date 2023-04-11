using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1041
{
    public class Class1041
    {
        public bool IsRobotBounded(string instructions)
        {
            int[][] direc = { new int[] { 0, 1 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { -1, 0 } };
            int direcIndex = 0;
            int x = 0, y = 0;
            int n = instructions.Length;
            for (int idx = 0; idx < n; idx++)
            {
                char instruction = instructions[idx];
                if (instruction == 'G')
                {
                    x += direc[direcIndex][0];
                    y += direc[direcIndex][1];
                }
                else if (instruction == 'L')
                {
                    direcIndex += 3;
                    direcIndex %= 4;
                }
                else
                {
                    direcIndex++;
                    direcIndex %= 4;
                }
            }
            return direcIndex != 0 || (x == 0 && y == 0);
        }

    }
}
