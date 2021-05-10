using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class SortedArrayDictionary<Key, Value> : Ahao.DataStructure.IDictionary<Key, Value> where Key : IComparable<Key>
    {
        private SortedArrayTwo<Key, Value> s;
        public SortedArrayDictionary(int capacity)
        {
            s = new SortedArrayTwo<Key, Value>(capacity);
        }

        public SortedArrayDictionary()
        {
            s = new SortedArrayTwo<Key, Value>();
        }
        public int Count
        {
            get
            {
                return s.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return s.IsEmpty;
            }
        }

        public void Add(Key key, Value value)
        {
            s.Add(key, value);
        }

        public bool ContainsKey(Key key)
        {
            return s.Contains(key);
        }

        public Value Get(Key key)
        {
            return s.Get(key);
        }

        public void Remove(Key key)
        {
            s.Remove(key);
        }

        public void Set(Key key, Value newValue)
        {
            s.Add(key, newValue);
        }
    }
}
