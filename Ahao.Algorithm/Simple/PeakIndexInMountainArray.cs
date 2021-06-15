using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 852. 山脉数组的峰顶索引
    /// </summary>
    public class PeakIndexInMountainArray
    {
        public int Method(int[] arr)
        {
            int result = -1;

            for(int i=0;i<arr.Length-1;i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    result = i;
                    break;
                }               
            }

            return result;
        }
    }
}
