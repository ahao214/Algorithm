using Ahao.DataStructure.BSTree;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于二叉树实现映射
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    class BSTTwoDictionary<Key, Value> : Ahao.DataStructure.IDictionary<Key, Value> where Key : IComparable<Key>
    {

        private BSTTwo<Key, Value> bst;
        public BSTTwoDictionary()
        {
            bst = new BSTTwo<Key, Value>();
        }
        public int Count
        {
            get
            {
                return bst.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return bst.IsEmpty;
            }
        }

        public void Add(Key key, Value value)
        {
            bst.add(key, value);
        }

        public bool ContainsKey(Key key)
        {
            return bst.Contains(key);
        }

        public Value Get(Key key)
        {
            return bst.Get(key);
        }

        public void Remove(Key key)
        {
            bst.Remove(key);
        }

        public void Set(Key key, Value newValue)
        {
            bst.Set(key, newValue);
        }
    }
}
