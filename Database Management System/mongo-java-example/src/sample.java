//dependency: mongo-java-driver-2.12.3.jar
//adding dependency: buildpath -> add external archives -> select mongo-java-driver jar.
import com.mongodb.MongoClient;
import com.mongodb.util.JSON;
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;

public class sample {
	public static void main(String args[])throws Exception{
		MongoClient mongoclient = new MongoClient("localhost",27017);
		
		//create
		DB db = mongoclient.getDB("abc");
		System.out.println("Database created");
		db.createCollection("Student", new BasicDBObject());
		System.out.println("Collection created");
		DBCollection collection = db.getCollection("Student");
		String data1 = "{\"Name\":\"Cameron\",\"Rollno\":1,\"Subject\":\"DSA\",\"Marks\":50}";
		String data2 = "{\"Name\":\"Justine\",\"Rollno\":2,\"Subject\":\"DSA\",\"Marks\":60}";
		String data3 = "{\"Name\":\"Brynne\",\"Rollno\":3,\"Subject\":\"DSA\",\"Marks\":65}";
		DBObject dbobj1 = (DBObject)JSON.parse(data1);
		DBObject dbobj2 = (DBObject)JSON.parse(data2);
		DBObject dbobj3 = (DBObject)JSON.parse(data3);
		collection.insert(dbobj1);
		collection.insert(dbobj2);
		collection.insert(dbobj3);
		
		//read
		DBCursor cur = collection.find();
		System.out.println("\n\nDatabase: ");
		int i = 1;
		while(cur.hasNext()) {
			System.out.println("Student "+i+" "+cur.next());
			i++;
		}
		
		//update
		BasicDBObject query = new BasicDBObject();
		query.put("Rollno", 1);
		BasicDBObject newdoc = new BasicDBObject();
		newdoc.put("Marks", 100);
		BasicDBObject updateobj = new BasicDBObject();
		updateobj.put("$set",newdoc);
		collection.update(query, updateobj);
		BasicDBObject searchQuery = new BasicDBObject();
		searchQuery.put("Rollno",1);
		DBCursor cur1 = collection.find(searchQuery);
		i = 1;
		System.out.println("\n\nAfter update: ");
		while(cur1.hasNext()) {
			System.out.println("Student "+i+" "+cur1.next());
			i++;
		}
		
		//delete
		BasicDBObject deleteQuery = new BasicDBObject();
		deleteQuery.put("Rollno",2);
		collection.remove(deleteQuery);
		DBCursor cur2 = collection.find();
		i=1;
		System.out.println("\n\nAfter delete");
		while(cur2.hasNext()) {
			System.out.println("Student "+i+" "+cur2.next());
			i++;
		}
		
		collection.drop();
		System.out.println("\n\nCollection deleted");
		
		db.dropDatabase();
		System.out.println("Database deleted");
	}
}
