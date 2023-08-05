using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P04
{
    public class Pet
    {
        private string type;
        public Pet(string type)
        {
            this.type = type;
        }

        public string GetPetType()
        {
            return this.type;
        }
    }
}
