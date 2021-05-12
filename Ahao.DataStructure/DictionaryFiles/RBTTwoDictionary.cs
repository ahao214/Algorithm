using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于红黑树实现映射
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    class RBTTwoDictionary<Key, Value> : Ahao.DataStructure.IDictionary<Key, Value> where Key : IComparable<Key>
    {
        private RBTTwo<Key, Value> rbt;
        public RBTTwoDictionary()
        {
            rbt = new RBTTwo<Key, Value>();
        }

        public int Count
        {
            get
            {
                return rbt.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return rbt.IsEmpty;
            }
        }

        public void Add(Key key, Value value)
        {
            rbt.Add(key, value);
        }

        public bool ContainsKey(Key key)
        {
            return rbt.Contains(key);
        }

        public Value Get(Key key)
        {
            return rbt.Get(key);
        }

        public void Remove(Key key)
        {
            throw new NotImplementedException();
        }

        public void Set(Key key, Value newValue)
        {
            rbt.Set(key, newValue);
        }
    }
}
