using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Hosting;
using System.Web.Management;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出n个整数中最小的K个数
    /// </summary>
    public class TestGetLeastNumbers
    {
        public static void GetLeastNumbers(int[] input, int k)
        {
            if (input.Length == 0 || k > input.Length || k <= 0)
            {
                Console.WriteLine("无法找到符合条件的数据!");
            }

            int low = 0;
            int high = input.Length - 1;
            int index = Partition(input, k, low, high);
            while (index != k - 1)
            {
                if (index > k - 1)
                {
                    high = index - 1;
                    index = Partition(input, k, low, high);
                }
                else
                {
                    low = index + 1;
                    index = Partition(input, k, low, high);
                }
            }
            for (int i = 0; i < k; i++)
            {
                Console.Write(input[i].ToString() + " ");
            }
        }


        static int Partition(int[] input, int k, int low, int high)
        {
            int pivotKey = input[k - 1];
            Swap(input, k - 1, low);
            while (low < high)
            {
                while (low < high && input[high] >= pivotKey)
                {
                    high--;
                }
                Swap(input, low, high);
                while (low < high && input[low] <= pivotKey)
                {
                    low++;
                }
                Swap(input, low, high);
            }
            return low;
        }


        static void Swap(int[] input, int low, int high)
        {
            int temp = input[high];
            input[high] = input[low];
            input[low] = temp;
        }
    }
}
