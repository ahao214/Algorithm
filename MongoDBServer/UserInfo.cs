using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MongoDBServer
{
    public class UserInfo
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Address { get; set; }
        public int Age { get; set; }
        public string Sex { get; set; }
        public DepInfo DepInfo { get; set; }
    }

    public class DepInfo
    {
        public int DepId { get; set; }
        public string DepName { get; set; }
    }

}
