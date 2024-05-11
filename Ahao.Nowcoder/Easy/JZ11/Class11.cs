using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ11
{
    /// <summary>
    /// JZ11 旋转数组的最小数字
    /// </summary>
    public class Class11
    {
        public int minNumberInRotateArray(List<int> rotateArray)
        {
            int low = 0;
            int high = rotateArray.Count - 1;
            while (low < high)
            {
                int pivot = low + (high - low) / 2;
                if (rotateArray[pivot] < rotateArray[high])
                {
                    high = pivot;
                }
                else if (rotateArray[pivot] > rotateArray[high])
                {
                    low = pivot + 1;
                }
                else
                {
                    high -= 1;
                }
            }
            return rotateArray[low];
        }
    }
}
