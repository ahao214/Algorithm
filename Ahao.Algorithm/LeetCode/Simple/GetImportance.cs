using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 690. 员工的重要性
    /// </summary>
    public class GetImportance
    {
        Dictionary<int, Employee> dic = new Dictionary<int, Employee>();
        public int Method(IList<Employee> employees, int id)
        {
            foreach (Employee employee in employees)
            {
                dic.Add(employee.id, employee);
            }
            return DFS(id);
        }

        public int DFS(int id)
        {
            Employee employee = dic[id];
            int total = employee.importance;
            IList<int> subordinates = employee.subordinates;
            foreach (int subId in subordinates)
            {
                total += DFS(subId);
            }
            return total;
        }

    }


    public class Employee
    {
        public int id;
        public int importance;
        public IList<int> subordinates;
    }
}
