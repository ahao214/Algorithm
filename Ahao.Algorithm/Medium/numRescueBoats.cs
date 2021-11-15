using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 881.救生艇
    /// </summary>
    public class NumRescueBoats
    {
        public int Method(int[] people, int limit)
        {
            Array.Sort(people);
            int left = 0;
            int right = people.Length - 1;
            int result = 0;
            while (left <= right)
            {
                if (left == right)
                {
                    result++;
                    return result;
                }
                if (people[left] + people[right] <= limit)
                {
                    left++;
                    right--;
                }
                else
                {
                    right--;
                }
                result++;
            }
            return result;
        }
    }
}
