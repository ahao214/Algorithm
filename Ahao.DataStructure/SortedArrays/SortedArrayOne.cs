using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 有序数组
    /// </summary>
    class SortedArrayOne<Key> where Key : IComparable<Key>
    {
        private Key[] keys;
        private int N;
        public SortedArrayOne(int capacity)
        {
            keys = new Key[capacity];
        }

        public SortedArrayOne() : this(10) { }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }

        public int Rank(Key key)
        {
            int left = 0;
            int right = N - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (key.CompareTo(keys[mid]) < 0)
                    right = mid - 1;
                else if (key.CompareTo(keys[mid]) > 0)
                    left = mid + 1;
                else
                    return mid;
            }
            return left;
        }


    }
}
