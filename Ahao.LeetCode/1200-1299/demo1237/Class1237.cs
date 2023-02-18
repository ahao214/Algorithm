using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1237
{
    public class Class1237
    {
        /// <summary>
        /// 枚举
        /// </summary>
        /// <param name="customfunction"></param>
        /// <param name="z"></param>
        /// <returns></returns>
        public IList<IList<int>> FindSolution(CustomFunction customfunction, int z)
        {
            IList<IList<int>> res = new List<IList<int>>();
            for (int x = 1; x <= 1000; x++)
            {
                for (int y = 1; y <= 1000; y++)
                {
                    if (customfunction.F(x, y) == z)
                    {
                        res.Add(new List<int> { x, y });
                    }
                }
            }
            return res;
        }


        /// <summary>
        /// 二分查找
        /// </summary>
        /// <param name="customfunction"></param>
        /// <param name="z"></param>
        /// <returns></returns>
        public IList<IList<int>> FindSolution2(CustomFunction customfunction, int z)
        {
            IList<IList<int>> res = new List<IList<int>>();
            for (int x = 1; x <= 1000; x++)
            {
                int yleft = 1, yright = 1000;
                while (yleft <= yright)
                {
                    int ymiddle = (yleft + yright) / 2;
                    if (customfunction.F(x, ymiddle) == z)
                    {
                        res.Add(new List<int> { x, ymiddle });
                        break;
                    }
                    if (customfunction.F(x, ymiddle) > z)
                    {
                        yright = ymiddle - 1;
                    }
                    else
                    {
                        yleft = ymiddle + 1;
                    }
                }
            }
            return res;
        }


        /// <summary>
        /// 双指针
        /// </summary>
        /// <param name="customfunction"></param>
        /// <param name="z"></param>
        /// <returns></returns>
        public IList<IList<int>> FindSolution3(CustomFunction customfunction, int z)
        {
            IList<IList<int>> res = new List<IList<int>>();
            for (int x = 1, y = 1000; x <= 1000 && y >= 1; x++)
            {
                while (y >= 1 && customfunction.F(x, y) > z)
                {
                    y--;
                }
                if (y >= 1 && customfunction.F(x, y) == z)
                {
                    res.Add(new List<int> { x, y });
                }
            }
            return res;
        }


    }

    public class CustomFunction
    {
        // Returns f(x, y) for any given positive integers x and y.
        // Note that f(x, y) is increasing with respect to both x and y.
        // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
        public int F(int x, int y)
        {
            return x + y;
        }
    }

}
