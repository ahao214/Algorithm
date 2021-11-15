using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1720. 解码异或后的数组
    /// </summary>
    public class Decode
    {
        public int[] Method(int[] encoded, int first)
        {
            int len = encoded.Length + 1;
            int[] arr = new int[len];
            arr[0] = first;
            for (int i = 1; i < len; i++)
            {
                arr[i] = arr[i - 1] ^ encoded[i - 1];
            }
            return arr;
        }
    }
}
