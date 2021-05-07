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

        /// <summary>
        /// 数组的容量
        /// </summary>
        public int Capacity
        {
            get { return data.Length; }
        }

        /// <summary>
        /// 数组中元素的个数
        /// </summary>
        public int Count
        {
            get { return N; }
        }

        /// <summary>
        /// 判断数组是否为空
        /// </summary>
        public bool IsEmpty
        {
            get { return N == 0; }
        }

        /// <summary>
        /// 向数组中添加元素
        /// </summary>
        /// <param name="index">添加的位置</param>
        /// <param name="ele">添加的元素</param>
        public void Add(int index, int ele)
        {
            if (index < 0 || index > N)
                throw new ArgumentException("数组索引越界");
            if (N == data.Length)
                throw new ArgumentException("数组已满");
            for (int i = N - 1; i >= index; i--)
            {
                //把前面一个元素赋值给后面
                data[i + 1] = data[i];
            }
            //把元素ele赋值到index位置
            data[index] = ele;
            //数组个数加1
            N++;
        }

    }
}
