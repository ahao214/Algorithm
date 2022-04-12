using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo380
{
    public class Class380
    {

        IList<int> nums;
        Dictionary<int, int> indices;
        Random random;

        public Class380()
        {
            nums = new List<int>();
            indices = new Dictionary<int, int>();
            random = new Random();
        }

        public bool Insert(int val)
        {
            if (indices.ContainsKey(val))
            {
                return false;
            }
            int index = nums.Count;
            nums.Add(val);
            indices.Add(val, index);
            return true;
        }

        public bool Remove(int val)
        {
            if (!indices.ContainsKey(val))
            {
                return false;
            }
            int index = indices[val];
            int last = nums[nums.Count - 1];
            nums[index] = last;
            indices[last] = index;
            nums.RemoveAt(nums.Count - 1);
            indices.Remove(val);
            return true;
        }

        public int GetRandom()
        {
            int randomIndex = random.Next(nums.Count);
            return nums[randomIndex];
        }

    }
}
