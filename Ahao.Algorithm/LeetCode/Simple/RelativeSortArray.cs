using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1122.数组的相对排序
    /// </summary>
    public class RelativeSortArray
    {
        public int[] Method(int[] arr1, int[] arr2)
        {
            int check = 0;

            //arr1根据arr2排序
            foreach (int i in arr2)
            {
                for (int j = 0; j < arr1.Length; j++)
                {
                    if (arr1[j] == i)
                    {
                        int temp = arr1[check];
                        arr1[check] = arr1[j];
                        arr1[j] = temp;
                        check++;
                    }
                }
            }
            
            //使用Take获取排序过的数据
            var arrTake = arr1.Take(check).ToArray();
            //使用Skip获取跳转check后的数据,并进行排序
            var arrSkip = arr1.Skip(check).OrderBy(d => d).ToArray();
            //使用Concat合并两个数组并输出
            return arrTake.Concat(arrSkip).ToArray();            

        }
    }
}
