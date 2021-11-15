using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI.WebControls;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 面试题 17.10. 主要元素
    /// </summary>
    public class MajorityElement
    {
        public int Method(int[] nums)
        {
            int count = 0;
            int date = -1;
            foreach (var item in nums)
            {
                if (count == 0)
                {
                    date = item;
                }
                if (item == date)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            count = 0;
            int len = nums.Length;
            foreach (var item in nums)
            {
                if (item == date)
                {
                    count++;
                }
            }
            return count * 2 > len ? date : -1;
        }


        public int Method2(int[] nums)
        {
            int result = -1;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in nums)
            {
                if (!dic.ContainsKey(item))
                {
                    dic.Add(item, 1);
                }
                else
                {
                    dic[item] += 1;
                }
            }

            foreach (var item in dic)
            {
                if (item.Value * 2 > nums.Length)
                {
                    result = item.Key;
                }
            }
            return result;
        }
    }
}
