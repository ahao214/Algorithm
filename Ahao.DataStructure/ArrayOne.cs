using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 动态数组
    /// </summary>
    class ArrayOne
    {
        private int[] data;
        private int N;

        public ArrayOne(int capacity)
        {
            data = new int[capacity];
            N = 0;
        }

        public ArrayOne() : this(10) { }

        public int Capacity
        {
            get { return data.Length; }
        }

        public int Count
        {
            get { return N; }
        }

        public bool IsEmpty
        {
            get { return N == 0; }
        }

    }
}
