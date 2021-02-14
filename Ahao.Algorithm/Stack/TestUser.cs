using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    public class TestUser
    {
        public int Id { get; set; }
        public String Name { get; set; }
        public int Seq { get; set; }


        public TestUser(int id, String name)
        {
            this.Id = id;
            this.Name = name;
        }

        public bool equals(TestUser u)
        {
            return this.Id == u.Id;
        }

        public String toString()
        {
            return "id:" + this.Id + "  name:" + this.Name + "  seq:" + this.Seq;
        }

    }
}
