using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.BigData
{
    /// <summary>
    /// 找出排名前500的数
    /// </summary>
    public class TestGetTop
    {
        public static int[] getTop(int[][] data)
        {
            int rowSize = data.Length;
            int columnSize = data[0].Length;
            int[] result3 = new int[columnSize];
            //保持一个最小堆，这个堆存放来自20个数组的最小数
            PriorityQueue<DataWithSource> heap = new PriorityQueue<DataWithSource>();
            for (int i = 0; i < rowSize; i++)
            {
                //记录下来源那个数组，以及在数组中的index
                DataWithSource d = new DataWithSource(data[i][0], i, 0);
                heap.Push(d);
            }

            int num = 0;
            while (num < columnSize)
            {
                //删除顶点元素
                DataWithSource d = heap.Pop();
                result3[num++] = d.Value;

                if (num >= columnSize)
                {
                    break;
                }

                //将value置为改数原数组里的下一个数
                d.Value = data[d.ComeFrom][d.Index + 1];

                //将其在数组中的index+1
                d.Index = (d.Index + 1);
                heap.Push(d);
            }
            return result3;
        }
    }


    public class DataWithSource : IComparable<DataWithSource>
    {
        //数据
        public int Value { get; set; }
        //来源的数组
        public int ComeFrom { get; set; }
        //在数组中的index
        public int Index { get; set; }

        public DataWithSource(int value, int comeFrom, int index)
        {
            this.Value = value;
            this.ComeFrom = comeFrom;
            this.Index = index;
        }

        /// <summary>
        /// 由于PriorityQueue使用小顶堆来实现的
        /// 这里通过修改两个整数比较的逻辑来让PriorityQueue变为一个大顶堆
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        public int CompareTo(DataWithSource o)
        {
            if (this.Value > o.Value)
            {
                return -1;
            }
            else if (this.Value < o.Value)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }


    /// <summary>
    /// 有限队列
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class PriorityQueue<T>
    {
        IComparer<T> comparer;
        T[] heap;

        public int Count { get; private set; }
        public PriorityQueue() : this(null) { }
        public PriorityQueue(int capacity) : this(capacity, null) { }
        public PriorityQueue(IComparer<T> comparer) : this(16, comparer) { }

        public PriorityQueue(int capacity, IComparer<T> comparer)
        {
            this.comparer = (comparer == null) ? Comparer<T>.Default : comparer;
            this.heap = new T[capacity];
        }

        public void Push(T v)
        {
            if (Count >= heap.Length)
                Array.Resize(ref heap, Count * 2);
            heap[Count] = v;
            SiftUp(Count++);
        }

        public T Pop()
        {
            var v = Top();
            heap[0] = heap[--Count];
            if (Count > 0)
                SiftDown(0);
            return v;
        }

        public T Top()
        {
            if (Count > 0)
                return heap[0];
            throw new InvalidOperationException("优先队列为空");
        }

        void SiftUp(int n)
        {
            var v = heap[n];
            for (var n2 = n / 2; n > 0 && comparer.Compare(v, heap[n2]) > 0; n = n2, n2 /= 2)
                heap[n] = heap[n2];
            heap[n] = v;
        }

        void SiftDown(int n)
        {
            var v = heap[n];
            for (var n2 = n * 2; n2 < Count; n = n2, n2 *= 2)
            {
                if (n2 + 1 < Count && comparer.Compare(heap[n2 + 1], heap[n2]) > 0)
                    n2++;
                if (comparer.Compare(v, heap[n2]) >= 0)
                    break;
                heap[n] = heap[n2];
            }
            heap[n] = v;
        }

    }


}
