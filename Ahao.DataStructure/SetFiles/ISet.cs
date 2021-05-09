using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 集合接口
    /// </summary>
    /// <typeparam name="E"></typeparam>
    interface ISet<E>
    {
        int Count { get; }
        bool IsEmpty { get; }
        void Add(E e);
        void Remove(E e);
        bool Contains(E e);
    }
}
