package fish;
import com.caucho.hessian.client.*;
import java.io.IOException; 
import java.io.PrintWriter; 
import javax.servlet.ServletException; 
import javax.servlet.http.HttpServlet; 
import javax.servlet.http.HttpServletRequest; 
import javax.servlet.http.HttpServletResponse; 
import java.util.*;
public class ClientTest {

    public static String url = "http://127.0.0.1:8080/myapps/Hello";
    public static void  main(String[] args){
        HessianProxyFactory factory = new HessianProxyFactory();
        try {
			List<String> list = new ArrayList<String>();
			list.add("1");
			list.add("2");
			Map<String,String> map = new HashMap<String,String>();
			map.put("21","fish1");
			map.put("22","fish2");
            IHello iHello = (IHello) factory.create(IHello.class, url);
            iHello.sayHelloFrom();
			iHello.sayHelloFromInt(123);
			iHello.sayHelloFromLong(123l);
			iHello.sayHelloFromDouble(123.5);
			iHello.sayHelloFromString("123");
			iHello.sayHelloFromList(list);
			iHello.sayHelloFromMap(map);
			iHello.sayHelloFromObject( new MyHello() );
			System.out.println( iHello.sayHelloGetInt() );
			System.out.println( iHello.sayHelloGetLong() );
			System.out.println( iHello.sayHelloGetDouble() );
			System.out.println( iHello.sayHelloGetString() );
			System.out.println( iHello.sayHelloGetList() );
			System.out.println( iHello.sayHelloGetMap() );
			System.out.println( iHello.sayHelloGetObject() );
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
