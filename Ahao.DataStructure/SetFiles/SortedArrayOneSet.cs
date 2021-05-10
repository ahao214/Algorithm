using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class SortedArrayOneSet<Key> : ISet<Key> where Key : IComparable<Key>
    {
        private SortedArrayOne<Key> s;
        public SortedArrayOneSet(int capacity)
        {
            s = new SortedArrayOne<Key>(capacity);
        }

        public SortedArrayOneSet()
        {
            s = new SortedArrayOne<Key>();
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

        public void Add(Key key)
        {
            s.Add(key);
        }

        public bool Contains(Key key)
        {
            return s.Contains(key);
        }

        public void Remove(Key key)
        {
            s.Remove(key);
        }
    }
}
