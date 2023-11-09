using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2300
{
    public class Class2300
    {

        public int[] SuccessfulPairs(int[] spells, int[] potions, long success)
        {
            Array.Sort(potions);
            int n = spells.Length, m = potions.Length;
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
            {
                long t = (success + spells[i] - 1) / spells[i] - 1;
                res[i] = m - BinarySearch(potions, 0, m - 1, t);
            }
            return res;
        }

        public int BinarySearch(int[] arr, int lo, int hi, long target)
        {
            int res = hi + 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] > target)
                {
                    res = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            return res;
        }


        public int[] SuccessfulPairs2(int[] spells, int[] potions, long success)
        {
            int n = spells.Length, m = potions.Length;
            int[] res = new int[n];
            int[][] idx = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                idx[i] = new int[2];
                idx[i][0] = spells[i];
                idx[i][1] = i;
            }
            Array.Sort(potions);
            for (int i = 0, j = m - 1; i < j; ++i, --j)
            {
                int temp = potions[i];
                potions[i] = potions[j];
                potions[j] = temp;
            }
            Array.Sort(idx, (a, b) => a[0] - b[0]);
            for (int i = 0, j = 0; i < n; ++i)
            {
                int p = idx[i][1];
                int v = idx[i][0];
                while (j < m && (long)potions[j] * v >= success)
                {
                    ++j;
                }
                res[p] = j;
            }
            return res;
        }



        public int[] SuccessfulPairs3(int[] spells, int[] potions, long success)
        {
            Array.Sort(potions);
            int[] res = new int[spells.Length];
            for (int i = 0; i < spells.Length; ++i)
            {
                int spell = spells[i];
                // 计算最小的药水大小
                long minBase = (success + spell - 1) / spell;
                res[i] = twoSeach(potions, minBase);
            }
            return res;
        }

        // 查找第一个大于等于 "最小药水" 的下标，并计算满足条件的药水数量
        private int twoSeach(int[] potions, long target)
        {
            int l = 0;
            int r = potions.Length - 1;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (potions[mid] >= target)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return potions[l] >= target ? potions.Length - l : 0;
        }



        public int[] SuccessfulPairs4(int[] spells, int[] potions, long success)
        {
            int[] result = new int[spells.Length];
            Array.Sort(potions);
            for (int i = 0; i < spells.Length; i++)
            {
                int left = 0, right = potions.Length - 1;
                int power = spells[i];
                long mul = 0;
                int ret = potions.Length;
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    mul = potions[mid] * (long)power;
                    if (mul >= success)
                    {
                        ret = mid;
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                result[i] = potions.Length - ret;
            }
            return result;
        }




        public int[] SuccessfulPairs5(int[] spells, int[] potions, long success)
        {
            //排序，为二分作准备
            Array.Sort(potions);
            int n = spells.Length;
            var result = new int[n];
            for (var i = 0; i < n; i++)
            {
                //与spells[i]相乘可大于等于success的值
                var t = (double)success / spells[i];

                var left = 0;
                var right = potions.Length - 1;
                var mid = 0;
                //二分查找大于等于t的最小下标
                while (left <= right)
                {
                    mid = (left + right) / 2;
                    if (potions[mid] < t)
                        left = mid + 1;
                    else if (mid - 1 < 0 || potions[mid] >= t && potions[mid - 1] < t)
                        break;
                    else if (potions[mid] >= t)
                        right = mid;

                    //left超出长度说明没有大于等于t的值，直接赋值给mid跳出循环
                    if (left > potions.Length - 1)
                    {
                        mid = left;
                        break;
                    }
                }

                //mid以及mid右边的数均符合条件
                result[i] += potions.Length - mid;
            }
            return result;
        }


    }
}
