package fish;
import com.caucho.hessian.server.*;
import java.io.IOException; 
import java.io.PrintWriter; 
import javax.servlet.ServletException; 
import javax.servlet.http.HttpServlet; 
import javax.servlet.http.HttpServletRequest; 
import javax.servlet.http.HttpServletResponse; 
import java.util.*;
public class IHelloImpl extends HessianServlet implements IHello {
	
	private static final long serialVersionUID = 4736905401988455439L;     
	@Override
	public void sayHelloFrom(){
		System.out.println("Input Data");
	}
	@Override
	public void sayHelloFromInt( int mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromLong( long mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromDouble( double mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromString( String mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromList( List mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromMap( Map mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public void sayHelloFromObject( MyHello mm ){
		System.out.println("Input Data:" + mm );
	}
	@Override
	public int sayHelloGetInt(){
		return 123;
	}
	@Override
	public long sayHelloGetLong(){
		return 456l;
	}
	@Override
	public double sayHelloGetDouble(){
		return 123.456;
	}
	@Override
	public String sayHelloGetString(){
		return "HelloFish";
	}
	@Override
	public List sayHelloGetList(){
		List list = new ArrayList();
		list.add(new Integer(12));
		list.add("list2");
		return list;
	}
	@Override
	public Map sayHelloGetMap(){
		Map map = new HashMap();
		map.put( new Integer(12),"HelloFish");
		map.put("HelloFish",new Integer(456));
		return map;
	}
	@Override
	public Object sayHelloGetObject(){
		MyHello hello = new MyHello();
		hello.setCarName("carName");
		hello.setCarModel("carModel");
		return hello;
	}
	@Override
	public void getVoidFromVoid(){
	}
	@Override
	public int getIntFromInt( int mm ){
		return mm;
	}
	@Override
	public long getLongFromLong( long mm ){
		return mm;
	}
	@Override
	public 	Date getDateFromDate( Date mm ){
		return mm;
	}
	@Override
	public double getDoubleFromDouble( double mm ){
		return mm;
	}
	@Override
	public String getStringFromString( String mm ){
		return mm;
	}
	@Override
	public List getListFromList( List mm ){
		return mm;
	}
	@Override
	public Map getMapFromMap( Map mm ){
		return mm;
	}
	@Override
	public Object getObjectFromObject( Object mm ){
		System.out.println(mm);
		return mm;
	}
	@Override
	public boolean getBooleanFromBoolean( boolean mm ){
		return mm;
	}

}
