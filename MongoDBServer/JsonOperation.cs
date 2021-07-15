using MongoDB.Bson;
using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MongoDBServer
{
    public class JsonOperation
    {
        public static void Show()
        {
            var client = new MongoClient("mongodb://localhost:27017");
            var database = client.GetDatabase("test");
            var document = BsonDocument.Parse("{a:1,b:[{c:1}],c:'ff'}");
            database.GetCollection<BsonDocument>("UserInfo").InsertOne(document);
        }
    }
}
