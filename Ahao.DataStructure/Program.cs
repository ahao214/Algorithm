using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;



namespace Ahao.DataStructure
{
    class Program
    {
        static void Main(string[] args)
        {
            #region 数组
            //int[] arr = new int[10];
            //for (int i = 0; i < 10; i++)
            //{
            //    arr[i] = i;
            //    Write(arr[i] + " ");

            //}
            //WriteLine();

            //ArrayList array = new ArrayList(10);
            //for (int i = 0; i < 15; i++)
            //{
            //    array.Add(i);
            //    Write(array[i] + " ");
            //}
            //WriteLine();

            //List<int> lst = new List<int>(10);
            //for (int i = 0; i < 15; i++)
            //{
            //    lst.Add(i);
            //    Write(lst[i] + " ");
            //}

            //WriteLine();

            //ArrayOne aOne = new ArrayOne(20);
            //for (int i = 0; i < 10; i++)
            //    aOne.AddLast(i);
            //WriteLine(aOne);

            //aOne.AddFirst(44);
            //WriteLine(aOne);

            //WriteLine("数组的查询、修改---Begin");
            //WriteLine(aOne.GetFirst());
            //WriteLine(aOne.GetLast());
            //WriteLine(aOne.Get(1));
            //aOne.Set(1, 999);
            //WriteLine(aOne);
            //WriteLine("数组的查询、修改---End");

            //WriteLine("数组的删除-Begin");
            //aOne.RemoveAt(3);
            //aOne.RemoveFirst();
            //aOne.RemoveLast();
            //aOne.Remove(4);
            //WriteLine(aOne);

            //WriteLine("数组的删除-End");


            //WriteLine("-------------------------");

            //WriteLine("使用泛型技术-Begin");

            //int[] nE = { 1, 2, 3, 4, 5, 6, 7, 8 };
            //ArrayE<int> arrayE = new ArrayE<int>();
            //for (int i = 0; i < nE.Length; i++)
            //    arrayE.AddLast(nE[i]);
            //WriteLine(arrayE);

            //string[] s = { "a", "b", "c", "d", "e" };
            //ArrayE<string> se = new ArrayE<string>();
            //for (int i = 0; i < s.Length; i++)
            //    se.AddLast(s[i]);
            //WriteLine(se);

            //WriteLine("使用泛型技术-End");

            #endregion

            #region 链表

            //WriteLine("-------------------------");
            //WriteLine("链表-Begin");

            //LinkedListOne <int> l = new LinkedListOne<int>();
            //for (int i = 0; i < 6; i++)
            //{
            //    l.AddFirst(i);
            //    WriteLine(l);
            //}

            //l.Add(2, 444);
            //WriteLine(l);

            //l.Set(4, 555);
            //WriteLine(l);

            //WriteLine(l.Contains(5));

            //l.RemoveFirst();
            //l.RemoveLast();
            //WriteLine(l);


            //WriteLine("链表-End");

            #endregion

            WriteLine("-------------------------");

            #region 栈

            WriteLine("栈-Begin");

            WriteLine("数组栈");
            ArrayOneStack<int> stack = new ArrayOneStack<int>();
            for (int i = 0; i < 5; i++)
            {
                stack.Push(i);
                WriteLine(stack);
            }

            //出栈
            stack.Pop();
            WriteLine("出栈之后");
            WriteLine(stack);

            WriteLine("链表栈");
            LinkedListOneStack<int> lstStack = new LinkedListOneStack<int>();
            for (int i = 0; i < 5; i++)
            {
                lstStack.Push(i);
                WriteLine(lstStack);
            }
            //出栈
            lstStack.Pop();
            WriteLine("出栈之后");
            WriteLine(lstStack);


            WriteLine("栈-End");

            #endregion

            WriteLine("-------------------------");


            WriteLine("-------------------------");


            WriteLine("-------------------------");


            WriteLine("-------------------------");

            WriteLine("-------------------------");


            WriteLine("-------------------------");


            ReadLine();
        }
    }
}
