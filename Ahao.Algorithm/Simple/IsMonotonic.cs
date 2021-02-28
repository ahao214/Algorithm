using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 896. 单调数列
    /// </summary>
    public class IsMonotonic
    {
        public bool Method(int[] arr)
        {
            bool isUp = true;
            bool isDown = true;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if (arr[i] <= arr[i + 1])
                {
                    isUp = true;
                }
                else
                {
                    isUp = false;
                    break;
                }

            }
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if (arr[i] >= arr[i + 1])
                {
                    isDown = true;
                }
                else
                {
                    isDown = false;
                    break;
                }
            }

            return isUp || isDown;
        }
    }
}
