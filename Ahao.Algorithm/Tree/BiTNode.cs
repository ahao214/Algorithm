using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 二叉树的结构
    /// </summary>
    public class BiTNode
    {
        public int Data { get; set; }
        public BiTNode Lchild { get; set; }
        public BiTNode Rchild { get; set; }
    }
}
