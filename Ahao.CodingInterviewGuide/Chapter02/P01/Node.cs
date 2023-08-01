using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter02.P01
{
    public class Node
    {
        public int Value;
        public Node Next;
        public Node(int data)
        {
            this.Value = data;
        }

        public void PrintCommonPart(Node head1, Node head2)
        {
            Console.WriteLine("Common Part:");
            while (head1 != null && head2 != null)
            {
                if (head1.Value < head2.Value)
                {
                    head1 = head1.Next;
                }
                else if (head2.Value < head1.Value)
                {
                    head2 = head2.Next;
                }
                else
                {
                    Console.WriteLine(head1.Value + " ");
                    head1 = head1.Next;
                    head2 = head2.Next;
                }
            }
            Console.WriteLine();

        }
    }


}
