using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求数组的最大子数组差
    /// </summary>
    public class TestMaxDiffSubArrays
    {
        public static int MaxDiffSubArrays(int[] arr)
        {
            int size = arr.Length, i = 0;
            int sum = 0, maxValue = 0;
            int dec = 0, minValue = 0;
            int[] maxLeft = new int[size];
            int[] minLeft = new int[size];
            int[] maxRight = new int[size];
            int[] minRight = new int[size];
            sum = maxValue = maxLeft[0] = arr[0];
            for (i = 1; i < size; i++)
            {
                if (sum < 0)
                {
                    sum = arr[i];
                }
                else
                {
                    sum += arr[i];
                }
                if (sum > maxValue)
                {
                    maxValue = sum;
                }
                maxLeft[i] = maxValue;
            }

            sum = maxValue = maxRight[size - 1] = arr[size - 1];
            for (i = size - 1; i >= 0; i--)
            {
                if (sum < 0)
                {
                    sum = arr[i];
                }
                else
                {
                    sum += arr[i];
                }
                if (sum > maxValue)
                {
                    maxValue = sum;
                }
                maxRight[i] = maxValue;
            }

            dec = minValue = minLeft[0] = arr[0];
            for (i = 1; i < size; i++)
            {
                if (dec > 0)
                {
                    dec = arr[i];
                }
                else
                {
                    dec += arr[i];
                }
                if (dec < minValue)
                {
                    minValue = dec;
                }
                minLeft[i] = minValue;
            }

            dec = minValue = minRight[size - 1] = arr[size - 1];
            for (i = size - 2; i >= 0; i--)
            {
                if (dec > 0)
                {
                    dec = arr[i];
                }
                else
                {
                    dec += arr[i];
                }
                if (dec < minValue)
                {
                    minValue = dec;
                }
                minRight[i] = minValue;
            }

            int result1 = 0;
            int result2 = 0;
            for (i = 0; i < size - 1; i++)
            {
                result1 = (result1 > maxLeft[i] - minRight[i + 1]) ? result1 : (maxLeft[i] - minRight[i + 1]);
                result2 = (result2 > maxRight[i + 1] - minLeft[i]) ? result2 : (maxRight[i + 1] - minLeft[i]);
            }
            return (result1 > result2) ? result1 : result2;
        }
    }
}
