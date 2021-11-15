using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 845. 数组中的最长山脉
    /// </summary>
    public class LongestMountain
    {
        public int Method(int[] A)
        {            
            //判断数值是否变大
            bool up = true;            
            int length = 1;            
            int max = 1;
            //开始向上走
            for (int i = 1; i < A.Length; i++)
            {                                
                //向上走
                if (A[i] > A[i - 1] && up)
                {
                    length++;
                }
                else if (A[i] < A[i - 1] && length > 1)
                {
                    //向下走                  
                    up = false;
                    length++;                    
                    max = length > max ? length : max;
                }
                else if (A[i] == A[i - 1])//结束
                {
                    up = true;
                    length = 1;
                }
                else if (!up)
                {
                    i--;
                    up = true;
                    length = 1;
                }
            }
            return max > 2 ? max : 0;
        }
    }
}
