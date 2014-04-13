package fish;
import java.util.*;
public interface IHello {
	//测试序列化
	void sayHelloFrom();
	void sayHelloFromInt( int mm );
	void sayHelloFromLong( long mm );
	void sayHelloFromDouble( double mm );
	void sayHelloFromString( String mm );
	void sayHelloFromList( List mm );
	void sayHelloFromMap( Map mm );
	void sayHelloFromObject( MyHello mm );
	//测试反序列化
	int sayHelloGetInt();
	long sayHelloGetLong();
	double sayHelloGetDouble();
	String sayHelloGetString();
	List sayHelloGetList();
	Map sayHelloGetMap();
	Object sayHelloGetObject();
	//同时测试序列化与反序列化
	void getVoidFromVoid();
	int getIntFromInt( int mm );
	boolean getBooleanFromBoolean( boolean mm );
	long getLongFromLong( long mm );
	Date getDateFromDate( Date mm );
	double getDoubleFromDouble( double mm );
	String getStringFromString( String mm );
	List getListFromList( List mm );
	Map getMapFromMap( Map mm );
	Object getObjectFromObject( Object mm );
	
}
