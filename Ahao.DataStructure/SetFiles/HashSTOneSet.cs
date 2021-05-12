using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于哈希表实现集合
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    class HashSTOneSet<Key> : ISet<Key>
    {
        private HashSTOne<Key> sTOne;

        public HashSTOneSet(int M)
        {
            sTOne = new HashSTOne<Key>(M);
        }

        public HashSTOneSet()
        {
            sTOne = new HashSTOne<Key>();
        }

        public int Count
        {
            get
            {
                return sTOne.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return sTOne.IsEmpty;
            }
        }

        public void Add(Key key)
        {
            sTOne.Add(key);
        }

        public void Remove(Key key)
        {
            sTOne.Remove(key);
        }

        public bool Contains(Key key)
        {
            return sTOne.Contains(key);
        }
    }
}
