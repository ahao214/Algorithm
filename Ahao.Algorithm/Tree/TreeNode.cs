using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    public class TreeNode
    {
        public int Val;
        public TreeNode Left { get; set; }
        public TreeNode Right { get; set; }
        public TreeNode(int val)
        {
            this.Val = val;
        }
    }


    public class IntRef
    {
        public int Val { get; set; }
    }
}
