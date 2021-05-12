using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于哈希表实现映射
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    class HashSTTwoDictionary<Key, Value> : Ahao.DataStructure.IDictionary<Key, Value>
    {
        private HashSTTwo<Key, Value> sTTwo;
        public HashSTTwoDictionary(int M)
        {
            sTTwo = new HashSTTwo<Key, Value>(M);
        }

        public HashSTTwoDictionary()
        {
            sTTwo = new HashSTTwo<Key, Value>();
        }

        public int Count
        {
            get
            {
                return sTTwo.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return sTTwo.IsEmpty;
            }
        }

        public void Add(Key key, Value value)
        {
            sTTwo.Add(key, value);
        }

        public bool ContainsKey(Key key)
        {
            return sTTwo.Contains(key);
        }

        public Value Get(Key key)
        {
            return sTTwo.Get(key);
        }

        public void Remove(Key key)
        {
            sTTwo.Remove(key);
        }

        public void Set(Key key, Value newValue)
        {
            sTTwo.Set(key, newValue);
        }
    }
}
