using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo136
{

    public class Class136
    {
        public int SingleNumber(int[] nums)
        {
            int eor = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                eor ^= nums[i];
            }
            return eor;
        }

        //数组中两个数出现奇数次
        public void Print(int[] arr)
        {
            int eor = 0, onlyOne = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                eor ^= arr[i];
            }
            //eor = a ^ b
            //eor != 0
            //ero必然有一个位置上是1
            int rightOne = eor & (~eor + 1);    //提取出最右边的1
            for (int i = 0; i < arr.Length; i++)
            {
                if ((arr[i] & rightOne) == 0)
                {
                    onlyOne ^= arr[i];
                }
            }
            Console.WriteLine(onlyOne);
            Console.WriteLine(eor ^ onlyOne);

        }



        public int SingleNumber2(int[] nums)
        {
            int ret = 0;
            foreach (int e in nums) ret ^= e;
            return ret;
        }

    }
}
