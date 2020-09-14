using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 216.组合总和(三)
    /// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
    /// </summary>
    public class CombinationSum3
    {        
        public IList<IList<int>> Method(int k, int n)
        {
            var result = new List<IList<int>>();
            //k值最大为9，n的和最大为45
            if (k > 9 || n > 45)
            {
                return result;
            }
            IList<int> l = new List<int>();
            CombinationSum(k, n, result, l, 0);
            return result;            
        }

        public void CombinationSum(int k, int n, IList<IList<int>> result, IList<int> list, int position)
        {
            if (list.Count == k)
            {
                if (n == 0)
                {
                    int[] array = new int[k];
                    list.CopyTo(array, 0);
                    result.Add(array.ToList());
                }
                return;
            }
            for (int i = position + 1; i <= 9; i++)
            {
                list.Add(i);
                CombinationSum(k, n - i, result, list, i);
                list.Remove(i);
            }
        }



    }
}
