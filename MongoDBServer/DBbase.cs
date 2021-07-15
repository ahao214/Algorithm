using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MongoDBServer
{
    public class DBbase<T> :where T : class new()
    {
        MongoClient client;
        IMongoDatabase database;
        public IMongoCollection<T> collection;
        public DBbase()
        {
            client = new MongoClient("mongodb://localhost:27017");
            database = client.GetDatabase("test");
            Type type = typeof ;
            collection = database.GetCollection<T>(type.Name.ToLower());
        }
    }
}
