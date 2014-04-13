#include "HessianSerialize.h"
#include "Exception.h"
#include <inttypes.h>
#include <limits.h>  
#include <string.h>
#include <iostream>
using namespace std;
namespace FishHessianCpp{

HessianSerialize::HessianSerialize(){
	
}
HessianSerialize::~HessianSerialize(){
}
void HessianSerialize::Serialize( 
	const std::string& strMethodName , 
	const std::vector<ObjectPtr>& vecArgv,
	std::string& strResult ){
	SerializeBegin(strMethodName,strResult);
	for( uint32_t i = 0 ; i != vecArgv.size() ; ++i ){
		SerializeArgv( vecArgv[i].get() , strResult );
	}
	SerializeEnd(strResult);
}
void HessianSerialize::SerializeBegin( const std::string& strMethodName , std::string& strResult ){
	char buffer[3] = {0};
	buffer[0] = 'c';
	buffer[1] = 1;
	buffer[2] = 0;
	strResult.append(buffer,sizeof(buffer));
	uint16_t wMethodSize = strMethodName.size();
	char buffer2[3];
	buffer2[0] = 'm';
	buffer2[1] = (wMethodSize>>8)&0xFF;
	buffer2[2] = wMethodSize&0xFF;
	strResult.append(buffer2,sizeof(buffer2));
	strResult.append(strMethodName);
}
void HessianSerialize::SerializeArgv( const Object* object , std::string& strResult ){
	if( typeid(*object) == typeid(Null) ){
		SerializeNull( (Null*)object , strResult );
	}else if( typeid(*object) == typeid(Integer)  ){
		SerializeInteger( (const Integer*)object , strResult );
	}else if( typeid(*object) == typeid(Long)){
		SerializeLong( (const Long*)object , strResult );
	}else if( typeid(*object) == typeid(Date)){
		SerializeDate((const Date*)object , strResult );
	}else if( typeid(*object) == typeid(Double)){
		SerializeDouble( (const Double*)object , strResult );
	}else if( typeid(*object) == typeid(Boolean)){
		SerializeBoolean( (const Boolean*)object , strResult );
	}else if( typeid(*object) == typeid(Xml)){
		SerializeXml( (const Xml*)object , strResult );
	}else if( typeid(*object) == typeid(String)){
		SerializeString( (const String*)object , strResult );
	}else if( typeid(*object) == typeid(Binary)){
		SerializeBinary( (const Binary*)object , strResult );
	}else if( typeid(*object) == typeid(List)){
		SerializeList( (const List*)object , strResult );
	}else if( typeid(*object) == typeid(Map)){
		SerializeMap( (const Map*)object , strResult );
	}else if( typeid(*object) == typeid(Remote)){
		SerializeRemote( (const Remote*)object , strResult );
	}else{
		throw Exception("Unknown Object");
	}
}
void HessianSerialize::SerializeEnd( std::string& strResult ){
	strResult.append("z",1);
}
void HessianSerialize::SerializeNull( const Null* object , std::string& strResult ){
	strResult.append("N",1);
}
void HessianSerialize::SerializeBoolean( const Boolean* object , std::string& strResult ){
	if( object->Value() == true )
		strResult.append("T",1);
	else
		strResult.append("F",1);
}
void HessianSerialize::SerializeInteger( const Integer* object , std::string& strResult ){
	int32_t value;
	char buffer[5] = {0};
	value = object->Value();
	buffer[0] = 'I';
	buffer[1] = (value >>24)&0xFF;
	buffer[2] = (value >>16)&0xFF;
	buffer[3] = (value >>8)&0xFF;
	buffer[4] = (value)&0xFF;
	strResult.append(buffer,sizeof(buffer));
}
void HessianSerialize::SerializeLong( const Long* object , std::string& strResult ){
	int64_t value;
	char buffer[9] = {0};
	value = object->Value();
	buffer[0] = 'L';
	buffer[1] = (value >>56)&0xFF;
	buffer[2] = (value >>48)&0xFF;
	buffer[3] = (value >>40)&0xFF;
	buffer[4] = (value >>32)&0xFF;
	buffer[5] = (value >>24)&0xFF;
	buffer[6] = (value >>16)&0xFF;
	buffer[7] = (value >>8)&0xFF;
	buffer[8] = (value)&0xFF;
	strResult.append(buffer,sizeof(buffer));
}
void HessianSerialize::SerializeDate( const Date* object , std::string& strResult ){
	int64_t value;
	char buffer[9] = {0};
	value = object->Value();
	buffer[0] = 'd';
	buffer[1] = (value >>56)&0xFF;
	buffer[2] = (value >>48)&0xFF;
	buffer[3] = (value >>40)&0xFF;
	buffer[4] = (value >>32)&0xFF;
	buffer[5] = (value >>24)&0xFF;
	buffer[6] = (value >>16)&0xFF;
	buffer[7] = (value >>8)&0xFF;
	buffer[8] = (value)&0xFF;
	strResult.append(buffer,sizeof(buffer));
}
void HessianSerialize::SerializeDouble( const Double* object , std::string& strResult ){
	int64_t value;
	char buffer[9] = {0};
	value = *(int64_t*)(void*)&object->Value();
	buffer[0] = 'D';
	buffer[1] = (value >>56)&0xFF;
	buffer[2] = (value >>48)&0xFF;
	buffer[3] = (value >>40)&0xFF;
	buffer[4] = (value >>32)&0xFF;
	buffer[5] = (value >>24)&0xFF;
	buffer[6] = (value >>16)&0xFF;
	buffer[7] = (value >>8)&0xFF;
	buffer[8] = (value)&0xFF;
	strResult.append(buffer,sizeof(buffer));
}
void HessianSerialize::SerializeString( const String* object , std::string& strResult ){
	const std::string& value = object->Value();
	uint32_t haveWrite = 0;
	while( haveWrite != value.size() ){
		uint16_t tempWrite = value.size() > SHRT_MAX ? SHRT_MAX :value.size();
		if( haveWrite + tempWrite == value.size() )
			strResult.append("S",1);
		else
			strResult.append("s",1);
		char buffer[2];
		buffer[0] = (tempWrite >> 8) & 0xFF;
		buffer[1] = tempWrite & 0xFF;
		strResult.append(buffer,sizeof(buffer));
		strResult.append(value,haveWrite,tempWrite);
		haveWrite += tempWrite;
	}
}
void HessianSerialize::SerializeXml( const Xml* object , std::string& strResult ){
	const std::string& value = object->Value();
	uint32_t haveWrite = 0;
	while( haveWrite != value.size() ){
		uint16_t tempWrite = value.size() > SHRT_MAX ? SHRT_MAX :value.size();
		if( haveWrite + tempWrite == value.size() )
			strResult.append("X",1);
		else
			strResult.append("x",1);
		char buffer[2];
		buffer[0] = (tempWrite >> 8) & 0xFF;
		buffer[1] = tempWrite & 0xFF;
		strResult.append(buffer,sizeof(buffer));
		strResult.append(value,haveWrite,tempWrite);
		haveWrite += tempWrite;
	}
}
void HessianSerialize::SerializeBinary( const Binary* object , std::string& strResult ){
	const std::string& value = object->Value();
	uint32_t haveWrite = 0;
	while( haveWrite != value.size() ){
		uint16_t tempWrite = value.size() > SHRT_MAX ? SHRT_MAX :value.size();
		if( haveWrite + tempWrite == value.size() )
			strResult.append("B",1);
		else
			strResult.append("b",1);
		char buffer[2];
		buffer[0] = (tempWrite >> 8) & 0xFF;
		buffer[1] = tempWrite & 0xFF;
		strResult.append(buffer,sizeof(buffer));
		strResult.append(value,haveWrite,tempWrite);
		haveWrite += tempWrite;
	}
}
void HessianSerialize::SerializeList( const List* object , std::string& strResult ){
	const std::string& strClassName = object->Class();
	const std::vector<ObjectPtr>& value = object->Value();
	strResult.append("V",1);
	if( !strClassName.empty() ){
		//写入类名
		strResult.append("t",1);
		uint16_t wClassNameSize = strClassName.size();
		char buffer[2];
		buffer[0] = (wClassNameSize >> 8) & 0xFF;
		buffer[1] = wClassNameSize & 0xFF;
		strResult.append(buffer,sizeof(buffer));
		strResult.append(strClassName);
	}
	//写入列表的长度
	int32_t dwLength = value.size();
	char buffer[5];
	buffer[0] = 'l';
	buffer[1] = (dwLength >>24)&0xFF;
	buffer[2] = (dwLength >>16)&0xFF;
	buffer[3] = (dwLength >>8)&0xFF;
	buffer[4] = (dwLength)&0xFF;
	strResult.append(buffer,sizeof(buffer));
	//写入各个元素
	for( uint32_t i = 0 ; i != value.size() ; ++i )
		SerializeArgv( value[i].get() , strResult );
	strResult.append("z",1);
}
void HessianSerialize::SerializeMap( const Map* object , std::string& strResult ){
	const std::string& strClassName = object->Class();
	const std::map<ObjectPtr,ObjectPtr>& value = object->Value();
	strResult.append("M",1);
	//写入类名
	strResult.append("t",1);
	uint16_t wClassNameSize = strClassName.size();
	char buffer[2];
	buffer[0] = (wClassNameSize >> 8) & 0xFF;
	buffer[1] = wClassNameSize & 0xFF;
	strResult.append(buffer,sizeof(buffer));
	strResult.append(strClassName);
	//写入各个元素
	for( std::map<ObjectPtr,ObjectPtr>::const_iterator it = value.begin() ;
		it != value.end() ; ++it ){
		SerializeArgv( it->first.get() , strResult );
		SerializeArgv( it->second.get() , strResult );
	}
	strResult.append("z",1);
}
void HessianSerialize::SerializeRemote( const Remote* object , std::string& strResult ){
	const std::string& strClassName = object->Class();
	const std::string& value = object->Value();
	strResult.append("r",1);
	//写入类名
	strResult.append("t",1);
	uint16_t wClassNameSize = strClassName.size();
	char buffer[2];
	buffer[0] = (wClassNameSize >> 8) & 0xFF;
	buffer[1] = wClassNameSize & 0xFF;
	strResult.append(buffer,sizeof(buffer));
	strResult.append(strClassName);
	//写入url
	strResult.append("S",1);
	uint16_t wValueSize = value.size();
	char buffer2[2];
	buffer2[0] = (wValueSize >> 8) & 0xFF;
	buffer2[1] = wValueSize & 0xFF;
	strResult.append(buffer2,sizeof(buffer2));
	strResult.append(value);
}

}