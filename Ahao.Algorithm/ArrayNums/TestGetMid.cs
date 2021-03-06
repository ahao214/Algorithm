using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 在不排序的情况下求数组中的中位数
    /// </summary>
    public class TestGetMid
    {
        //中位数就是一组数组从小到大排列后中间的那个数字。如果数组长度为偶数，那么中位数的值就是中间两个数字相加除以2
        //如果数组长度为奇数，中位数的值就是中间那个数字

        private int pos = 0;
        //以arr[low]为基准把数组分成两部分
        private void partition(int[] arr, int low, int high)
        {
            int key = arr[low];
            while (low < high)
            {
                while (low < high && arr[high] > key)
                {
                    high--;
                }
                arr[low] = arr[high];
                while (low < high && arr[low] < key)
                {
                    low++;
                }
                arr[high] = arr[low];
            }
            arr[low] = key;
            pos = low;
        }


        public int GetMid(int[] arr)
        {
            int low = 0;
            int n = arr.Length;
            int high = n - 1;
            int mid = (low + high) / 2;
            while (true)
            {
                //以arr[low]为基准把数组分成两部分
                partition(arr, low, high);
                if (pos == mid)     //找到中位数
                {
                    break;
                }
                else if (pos > mid) //继续在有半部分查找
                {
                    high = pos - 1;
                }
                else    //继续在左半部分查找
                {
                    low = pos + 1;
                }               
            }
            //如果数组长度是技术，中位数为中间的元素，否则就是中间两个数的平均值
            return (n % 2) != 0 ? arr[mid] : (arr[mid] + arr[mid + 1]) / 2;
        }

    }
}
