using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo85
{

    public class MinHeap<T> where T : IComparable
    {
        ///<summary>
        /// 储存元素的List
        ///<summary>
        private List<T> _elements;
        ///<summary>
        /// 堆元素数量
        ///<summary>
        public int Count
        {
            get { return _elements.Count; }
        }
        ///<summary>
        /// 构造函数
        ///<summary>
        public MinHeap()
        {
            _elements = new List<T>();

        }
        ///<summary>
        ///构造函数
        ///<summary>
        /// <param name="initSize">初始堆大小</param>
        public MinHeap(int initSize)
        {
            _elements = new List<T>(initSize);

        }

        ///<summary>
        /// 弹出堆首元素
        ///<summary>
        public T Pop()
        {

            if (Count == 0)
            {
                throw new IndexOutOfRangeException("No element can be poped.");
            }
            else
            {
                //将堆中最后一个节点元素放置在根节点中，并移除最后一个节点元素
                //更换位置后，将根节点元素进行下沉操作
                T result = _elements[0];
                _elements[0] = _elements[Count - 1];
                _elements.RemoveAt(Count - 1);
                Sink();

                return result;
            }
        }
        ///<summary>
        /// 将根元素下沉
        ///<summary>
        private void Sink()
        {

            int currentIndex = 0;
            int leftChildIndex = 1;
            int rightChildIndex = 2;

            while (true)
            {

                //如果没有左子节点，说明目前节点已经是最后一个节点了
                if (leftChildIndex >= Count)
                {
                    break;

                }


                T currentElement = _elements[currentIndex];
                T leftChildElement = _elements[leftChildIndex];

                //如果没有右子节点， 则只处理左节点
                if (rightChildIndex >= Count)
                {
                    if (currentElement.CompareTo(leftChildElement) > 0)
                    {

                        _elements[currentIndex] = leftChildElement;
                        _elements[leftChildIndex] = currentElement;

                        currentIndex = leftChildIndex;

                    }
                }
                else
                {
                    //下面的情况为左右子节点均存在
                    T rightChildElement = _elements[rightChildIndex];

                    int compareResult = leftChildElement.CompareTo(rightChildElement);

                    // 左子节点为最小值
                    // 或
                    // 左右子节点值相同，取左子节点
                    if (compareResult < 0 || compareResult == 0)
                    {

                        if (currentElement.CompareTo(leftChildElement) > 0)
                        {

                            _elements[currentIndex] = leftChildElement;
                            _elements[leftChildIndex] = currentElement;

                            currentIndex = leftChildIndex;

                        }

                    }
                    //右子节点为最小值
                    else if (compareResult > 0)
                    {
                        if (currentElement.CompareTo(rightChildElement) > 0)
                        {

                            _elements[currentIndex] = rightChildElement;
                            _elements[rightChildIndex] = currentElement;

                            currentIndex = rightChildIndex;

                        }

                    }

                }

                leftChildIndex = currentIndex * 2 + 1;
                rightChildIndex = currentIndex * 2 + 2;

            }

        }

        ///<summary>
        /// 插入元素
        ///<summary>
        /// <param name="element">插入的元素</param>
        public void Insert(T element)
        {

            //将元素添加到最后一个节点
            _elements.Add(element);

            //将最后一个元素进行上浮操作
            Heapify();

        }
        ///<summary>
        ///重构堆
        ///<summary>
        private void Heapify()
        {

            int currentIndex = Count - 1;
            int parentIndex = 0;

            while (parentIndex >= 0)
            {

                parentIndex = (currentIndex - 1) / 2;

                T currentElement = _elements[currentIndex];
                T parentElement = _elements[parentIndex];

                if (currentElement.CompareTo(parentElement) < 0)
                {
                    _elements[parentIndex] = currentElement;
                    _elements[currentIndex] = parentElement;

                    currentIndex = parentIndex;
                }
                else
                {
                    break;
                }
            }
        }

    }


}
