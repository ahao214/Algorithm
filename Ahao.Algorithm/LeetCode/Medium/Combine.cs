using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 77.组合
    /// </summary>
    public class Combine
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> Method(int n, int k)
        {            
            List<int> temp = new List<int>();
            if (n < k || n < 1) return result;
            AddItem(temp, 1, n, k);
            return result;
        }
        public void AddItem(List<int> temp, int start, int n, int k)
        {
            if (temp.Count == k)
            {
                result.Add(new List<int>(temp));               
                return;
            }
            for (; start <= n; start++)
            {
                temp.Add(start);
                AddItem(temp, start + 1, n, k);
                temp.RemoveAt(temp.Count - 1);
            }
        }
    }
}
