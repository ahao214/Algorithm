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

        public void Add(Key e)
        {
            s.Add(e);
        }

        public bool Contains(Key e)
        {
            return s.Contains(e);
        }

        public void Remove(Key e)
        {
            s.Remove(e);
        }
    }
}
