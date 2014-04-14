#include <iostream>
#include <sstream>
#include "Hessian.h"
using namespace std;
using namespace FishHessianCpp;
std::string DumpData( ObjectPtr ptr ){
	std::stringstream ss;
	ptr->DumpDataTree(ss);
	return ss.str();
}
void testSerialize(){
	try{
		Hessian hessian("http://127.0.0.1:8080/myapps/Hello");
		ListPtr list;
		list->Value().push_back( StringPtr("123"));
		list->Value().push_back( StringPtr("123") );
		MapPtr map;
		map->Value().insert( make_pair(StringPtr( "11"), StringPtr( "fish1")));
		map->Value().insert( make_pair(StringPtr( "12"), StringPtr( "fish2")));
		MapPtr myHello;
		myHello->Class() = "fish.MyHello";
		myHello->Value().insert( make_pair(StringPtr( "carName"), StringPtr("name")));
		myHello->Value().insert( make_pair(StringPtr( "carModel"), StringPtr( "model")));
		vector<ObjectPtr> vecArgv;
		ObjectPtr result;
		
		vecArgv.clear();
		 result = hessian.Invoke("sayHelloFrom",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( ObjectPtr( new Integer(123)) );
		 result = hessian.Invoke("sayHelloFromInt",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( ObjectPtr( new Long(123)) );
		 result = hessian.Invoke("sayHelloFromLong",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( ObjectPtr( new Double(123)) );
		 result = hessian.Invoke("sayHelloFromDouble",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( ObjectPtr( new String("123")) );
		 result = hessian.Invoke("sayHelloFromString",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( list );
		 result = hessian.Invoke("sayHelloFromList",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( map );
		 result = hessian.Invoke("sayHelloFromMap",vecArgv);
		cout<< DumpData(result)<<endl;
		
		vecArgv.clear();
		vecArgv.push_back( myHello );
		 result = hessian.Invoke("sayHelloFromObject",vecArgv);
		cout<< DumpData(result)<<endl;
		
	}catch( exception& e ){
		std::cout<<"exception:"<<e.what()<<endl;;
	}
}
void testDeSerialize(){
	try{
		Hessian hessian("http://127.0.0.1:8080/myapps/Hello");
		vector<ObjectPtr> vecArgv;
		ObjectPtr result;
		
		result = hessian.Invoke("sayHelloGetInt",vecArgv);
		cout<< DumpData(result)<<endl;
		
		result = hessian.Invoke("sayHelloGetDouble",vecArgv);
		cout<< DumpData(result)<<endl;
		
		result = hessian.Invoke("sayHelloGetString",vecArgv);
		cout<< DumpData(result)<<endl;
		
		result = hessian.Invoke("sayHelloGetList",vecArgv);
		cout<< DumpData(result)<<endl;
		
		result = hessian.Invoke("sayHelloGetMap",vecArgv);
		cout<< DumpData(result)<<endl;
		
		result = hessian.Invoke("sayHelloGetObject",vecArgv);
		cout<< DumpData(result)<<endl;
		
	}catch( exception& e ){
		std::cout<<"exception:"<<e.what()<<endl;;
	}
}
void testAll(){
	try{
		Hessian hessian("http://127.0.0.1:8080/myapps/Hello");
		BooleanPtr booleanPtr( true);
		IntegerPtr integerPtr(123);
		LongPtr longPtr( 456 );
		DatePtr datePtr(time(NULL)  );
		DoublePtr doublePtr( 123.45 );
		StringPtr stringPtr( "Hello Fish" );
		ListPtr listPtr;
		listPtr->Value().push_back( StringPtr("fish1"));
		listPtr->Value().push_back( StringPtr( "fish2"));
		MapPtr mapPtr;
		mapPtr->Value().insert( make_pair(IntegerPtr(11), StringPtr("fish1")));
		mapPtr->Value().insert( make_pair(StringPtr("12"), StringPtr( "fish2")));
		MapPtr myHelloPtr;
		myHelloPtr->Class() = "fish.MyHello";
		myHelloPtr->Value().insert( make_pair(StringPtr( "carName"), StringPtr( "name")));
		myHelloPtr->Value().insert( make_pair(StringPtr( "carModel"), StringPtr( "model")));
		MapPtr veryComplicateObject;
		veryComplicateObject->Value().insert( make_pair(myHelloPtr, StringPtr( "name")) );
		veryComplicateObject->Value().insert( make_pair(mapPtr, StringPtr( "name")) );
		veryComplicateObject->Value().insert( make_pair(listPtr, StringPtr( "name")) );
		
		std::string functionPtr[] = {"getBooleanFromBoolean",
				"getIntFromInt",
				"getLongFromLong",
				"getDateFromDate",
				"getDoubleFromDouble",
				"getStringFromString",
				"getListFromList",
				"getMapFromMap",
				"getObjectFromObject",
				"getObjectFromObject"};
		ObjectPtr objectPtr[] = {booleanPtr,
				integerPtr,
				longPtr,
				datePtr,
				doublePtr,
				stringPtr,
				listPtr,
				mapPtr,
				myHelloPtr,
				veryComplicateObject};
		
		uint32_t dwSize = sizeof(functionPtr)/sizeof(functionPtr[0]);
		for( uint32_t i = 0 ; i != dwSize ; ++i ){
			ObjectPtr result;
			vector<ObjectPtr> vecArgv;
			vecArgv.push_back(objectPtr[i]);
			result = hessian.Invoke(functionPtr[i],vecArgv);
			cout<< "Function: "<<functionPtr[i]<<endl
				<<"InputParam: "<<DumpData(objectPtr[i])<<endl
				<<"OutputParam: "<<DumpData(result)<<endl;
			
		}	
	}catch( exception& e ){
		std::cout<<"exception:"<<e.what()<<endl;;
	}
}
int main(){
//	testSerialize();
	//testDeSerialize();
	testAll();
	return 0;
}
