using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中唯一的重复元素
    /// </summary>
    public class TestFindDup
    {
        /// <summary>
        /// Hash方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public static int FindDupHash(int[] nums)
        {
            if (nums == null)
            {
                return -1;
            }
            int len = nums.Length;
            Dictionary<int, int> hasttable = new Dictionary<int, int>();
            int i;
            for (i = 0; i < len - 1; i++)
            {
                hasttable.Add(i, 0);
            }
            for (i = 0; i < len; i++)
            {
                if (hasttable[nums[i] - 1] == 0)
                {
                    hasttable[nums[i] - 1] = nums[i] - 1;
                }
                else
                {
                    return nums[i];
                }
            }
            return -1;
        }

        /// <summary>
        /// 异域方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public static int FindDupYH(int[] nums)
        {
            if (nums == null)
            {
                return -1;
            }

            int len = nums.Length;
            int result = 0;
            int i;
            for (i = 0; i < len; i++)
            {
                result ^= nums[i];
            }
            for (i = 1; i < len; i++)
            {
                result ^= i;
            }
            return result;
        }

        /// <summary>
        /// 数据映射方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public static int FindDupMap(int[] nums)
        {
            if (nums == null)
            {
                return -1;
            }

            int len = nums.Length;
            int index = 0;
            int i = 0;
            while (true)
            {
                //数组中的元素的值只能小于len，否则会越界
                if (nums[i] >= len)
                {
                    return -1;
                }
                if (nums[index] < 0)
                {
                    break;
                }
                //访问后通过变相反数的方法进行标记
                nums[index] *= -1;
                //index的后续为nums[index]
                index = -1 * nums[index];
                if (index >= len)
                {
                    Console.WriteLine("数组中有非法数字");
                    return -1;
                }
            }
            return index;
        }

        /// <summary>
        /// 环形相遇方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public static int FindDupHuan(int[] nums)
        {
            if (nums == null)
            {
                return -1;
            }
            int slow = 0;
            int fast = 0;
            do
            {
                fast = nums[nums[fast]];
                slow = nums[slow];
            } while (slow != fast); //找到相遇点
            fast = 0;
            do
            {
                fast = nums[fast];
                slow = nums[slow];
            } while (slow != fast);
            return slow;

        }


        public static HashSet<int> FindRepeat(int[] array, int len, int num)
        {
            HashSet<int> s = new HashSet<int>();
            if (array == null || len < 1 || num < 1 || len < num)
            {
                return s;
            }
            int index = array[0];
            num = num - 1;
            while (true )
            {
                if(array [index ]<0)
                {
                    num--;
                    //找到了重复的数字index，为了保证能遍历数组中所有的数，把index
                    //下标对应的值修改为尽可能接近N+M的数
                    array[index] = len - num;
                    s.Add(index);
                }
                if (num ==0)
                {
                    return s;
                }
                array[index] *= -1;
                index = array[index] * (-1);
            }


        }


    }
}
