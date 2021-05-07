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
            int[] arr = new int[10];
            for (int i = 0; i < 10; i++)
            {
                arr[i] = i;
                Write(arr[i] + " ");
                
            }
            WriteLine();

            ArrayList array = new ArrayList(10);
            for (int i = 0; i < 15; i++)
            {
                array.Add(i);
                Write(array[i] + " ");                
            }
            WriteLine();

            List<int> lst = new List<int>(10);
            for (int i = 0; i < 15; i++)
            {
                lst.Add(i);
                Write(lst[i] + " ");
            }


            ReadLine();
        }
    }
}
