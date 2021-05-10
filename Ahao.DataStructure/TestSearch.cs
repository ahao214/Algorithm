using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class TestSearch
    {
        public static int BinarySearch(int[] arr, int target)
        {
            int left = 0;
            int right = arr.Length - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (target < arr[mid])
                    right = mid - 1;
                else if (target > arr[mid])
                    left = mid + 1;
                else
                    return arr[mid];
            }
            return -1;
        }

    }
}
