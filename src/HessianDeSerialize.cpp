#include "HessianDeSerialize.h"
#include <iostream>
#include "Exception.h"
using namespace std;
namespace FishHessianCpp{

HessianDeSerialize::HessianDeSerialize(){
}
HessianDeSerialize::~HessianDeSerialize(){
}
ObjectPtr HessianDeSerialize::DeSerialize( const std::string& strData ){
	uint32_t dwPointer = 0;
	ObjectPtr result;
	DeSerializeBegin(strData,dwPointer);
	result = DeSerializeArgv(strData,dwPointer);
	DeSerializeEnd(strData,dwPointer);
	return result;
}
void HessianDeSerialize::DeSerializeBegin( const std::string& strData , uint32_t & dwPointer ){
	//前三个表示版本号
	ExpectedChar('r',strData,dwPointer);
	MoveNext(strData,dwPointer);
	MoveNext(strData,dwPointer);
	MoveNext(strData,dwPointer);
	while( GetChar(strData,dwPointer) == 'H')
		DeSerializeHeader(strData,dwPointer);
}
ObjectPtr HessianDeSerialize::DeSerializeArgv( const std::string& strData , uint32_t & dwPointer ){
	if( GetChar(strData,dwPointer) == 'N')
		return DeSerializeNull(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'T' || GetChar(strData,dwPointer) == 'F')
		return DeSerializeBoolean(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'I' )
		return DeSerializeInteger(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'L' )
		return DeSerializeLong(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'd' )
		return DeSerializeDate(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'D' )
		return DeSerializeDouble(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 's' || GetChar(strData,dwPointer) == 'S')
		return DeSerializeString(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'b' || GetChar(strData,dwPointer) == 'B')
		return DeSerializeBinary(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'x' || GetChar(strData,dwPointer) == 'X')
		return DeSerializeXml(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'V')
		return DeSerializeList(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'M')
		return DeSerializeMap(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'r')
		return DeSerializeRemote(strData,dwPointer);
	else if( GetChar(strData,dwPointer) == 'f')
		return DeSerializeFault(strData,dwPointer);
	else
		throw Exception("Unknown Char " + GetChar(strData,dwPointer) );
}
void HessianDeSerialize::DeSerializeEnd( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('z',strData,dwPointer);
	MoveNext(strData,dwPointer);
	if( dwPointer != strData.size())
		throw Exception("unexpected have data!");
}
ObjectPtr HessianDeSerialize::DeSerializeNull( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('N',strData,dwPointer);
	MoveNext(strData,dwPointer);
	NullPtr object;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeBoolean( const std::string& strData , uint32_t & dwPointer ){
	BooleanPtr object;
	if( GetChar(strData,dwPointer) == 'T')
		object->Value() = true;
	else if( GetChar(strData,dwPointer) == 'F' )
		object->Value() = false;
	else
		throw Exception("Unknown Boolean");
	MoveNext(strData,dwPointer);
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeInteger( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('I',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[4];
	buffer[3] = MoveNext(strData,dwPointer);
	buffer[2] = MoveNext(strData,dwPointer);
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	IntegerPtr object;
	object->Value() = *(int32_t*)buffer;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeLong( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('L',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[8];
	buffer[7] = MoveNext(strData,dwPointer);
	buffer[6] = MoveNext(strData,dwPointer);
	buffer[5] = MoveNext(strData,dwPointer);
	buffer[4] = MoveNext(strData,dwPointer);
	buffer[3] = MoveNext(strData,dwPointer);
	buffer[2] = MoveNext(strData,dwPointer);
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	LongPtr object;
	object->Value() = *(int64_t*)buffer;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeDate( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('d',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[8];
	buffer[7] = MoveNext(strData,dwPointer);
	buffer[6] = MoveNext(strData,dwPointer);
	buffer[5] = MoveNext(strData,dwPointer);
	buffer[4] = MoveNext(strData,dwPointer);
	buffer[3] = MoveNext(strData,dwPointer);
	buffer[2] = MoveNext(strData,dwPointer);
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	DatePtr object;
	object->Value() = *(int64_t*)buffer;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeDouble( const std::string& strData , uint32_t & dwPointer ){
	ExpectedChar('D',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[8];
	buffer[7] = MoveNext(strData,dwPointer);
	buffer[6] = MoveNext(strData,dwPointer);
	buffer[5] = MoveNext(strData,dwPointer);
	buffer[4] = MoveNext(strData,dwPointer);
	buffer[3] = MoveNext(strData,dwPointer);
	buffer[2] = MoveNext(strData,dwPointer);
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	DoublePtr object;
	object->Value() = *(double*)buffer;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeString( const std::string& strData , uint32_t & dwPointer ){
	StringPtr object;
	while( GetChar(strData,dwPointer) == 's' ){
		MoveNext(strData,dwPointer);
		char buffer[2];
		buffer[1] = MoveNext(strData,dwPointer);
		buffer[0] = MoveNext(strData,dwPointer);
		int16_t dwDataSize = *(int16_t*)buffer;
		if( dwPointer + dwDataSize >= strData.size() )
			throw Exception("unexpected end");
		object->Value().append(strData,dwPointer,dwDataSize);
		dwPointer += dwDataSize;
	}
	ExpectedChar('S',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[2];
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize = *(int16_t*)buffer;
	if( dwPointer + dwDataSize >= strData.size() )
		throw Exception("unexpected end");
	object->Value().append(strData,dwPointer,dwDataSize);
	dwPointer += dwDataSize;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeXml( const std::string& strData , uint32_t & dwPointer ){
	XmlPtr object;
	while( GetChar(strData,dwPointer) == 'x' ){
		MoveNext(strData,dwPointer);
		char buffer[2];
		buffer[1] = MoveNext(strData,dwPointer);
		buffer[0] = MoveNext(strData,dwPointer);
		int16_t dwDataSize = *(int16_t*)buffer;
		if( dwPointer + dwDataSize >= strData.size() )
			throw Exception("unexpected end");
		object->Value().append(strData,dwPointer,dwDataSize);
		dwPointer += dwDataSize;
	}
	ExpectedChar('X',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[2];
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize = *(int16_t*)buffer;
	if( dwPointer + dwDataSize >= strData.size() )
		throw Exception("unexpected end");
	object->Value().append(strData,dwPointer,dwDataSize);
	dwPointer += dwDataSize;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeBinary( const std::string& strData , uint32_t & dwPointer ){
	BinaryPtr object;
	while( GetChar(strData,dwPointer) == 'b' ){
		MoveNext(strData,dwPointer);
		char buffer[2];
		buffer[1] = MoveNext(strData,dwPointer);
		buffer[0] = MoveNext(strData,dwPointer);
		int16_t dwDataSize = *(int16_t*)buffer;
		if( dwPointer + dwDataSize >= strData.size() )
			throw Exception("unexpected end");
		object->Value().append(strData,dwPointer,dwDataSize);
		dwPointer += dwDataSize;
	}
	ExpectedChar('B',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[2];
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize = *(int16_t*)buffer;
	if( dwPointer + dwDataSize >= strData.size() )
		throw Exception("unexpected end");
	object->Value().append(strData,dwPointer,dwDataSize);
	dwPointer += dwDataSize;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeList( const std::string& strData , uint32_t & dwPointer ){
	ListPtr object;
	ExpectedChar('V',strData,dwPointer);
	MoveNext(strData,dwPointer);
	if( GetChar(strData,dwPointer) == 't' ){
		MoveNext(strData,dwPointer);
		char buffer[2];
		buffer[1] = MoveNext(strData,dwPointer);
		buffer[0] = MoveNext(strData,dwPointer);
		int16_t dwDataSize = *(int16_t*)buffer;
		if( dwPointer + dwDataSize >= strData.size() )
			throw Exception("unexpected end");
		object->Class().append(strData,dwPointer,dwDataSize);
		dwPointer += dwDataSize;
	}
	if( GetChar(strData,dwPointer) == 'l' ){
		MoveNext(strData,dwPointer);
		MoveNext(strData,dwPointer);
		MoveNext(strData,dwPointer);
		MoveNext(strData,dwPointer);
		MoveNext(strData,dwPointer);
	}
	while(GetChar(strData,dwPointer) != 'z' ){
		object->Value().push_back( DeSerializeArgv(strData,dwPointer) );
	}
	MoveNext(strData,dwPointer);
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeMap( const std::string& strData , uint32_t & dwPointer ){
	MapPtr object;
	ExpectedChar('M',strData,dwPointer);
	MoveNext(strData,dwPointer);
	if( GetChar(strData,dwPointer) == 't' ){
		MoveNext(strData,dwPointer);
		char buffer[2];
		buffer[1] = MoveNext(strData,dwPointer);
		buffer[0] = MoveNext(strData,dwPointer);
		int16_t dwDataSize = *(int16_t*)buffer;
		if( dwPointer + dwDataSize >= strData.size() )
			throw Exception("unexpected end");
		object->Class().append(strData,dwPointer,dwDataSize);
		dwPointer += dwDataSize;
	}
	while(GetChar(strData,dwPointer) != 'z' ){
		ObjectPtr oKey,oValue;
		oKey = DeSerializeArgv(strData,dwPointer) ;
		oValue = DeSerializeArgv(strData,dwPointer) ;
		object->Value()[oKey] = oValue;
	}
	MoveNext(strData,dwPointer);
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeRemote( const std::string& strData , uint32_t & dwPointer ){
	RemotePtr object;
	ExpectedChar('r',strData,dwPointer);
	MoveNext(strData,dwPointer);
	//读取类型信息
	ExpectedChar('t',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer[2];
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize = *(int16_t*)buffer;
	if( dwPointer + dwDataSize >= strData.size() )
		throw Exception("unexpected end");
	object->Class().append(strData,dwPointer,dwDataSize);
	dwPointer += dwDataSize;
	//读取字符串信息
	ExpectedChar('S',strData,dwPointer);
	MoveNext(strData,dwPointer);
	char buffer2[2];
	buffer2[1] = MoveNext(strData,dwPointer);
	buffer2[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize2 = *(int16_t*)buffer2;
	if( dwPointer + dwDataSize2 >= strData.size() )
		throw Exception("unexpected end");
	object->Value().append(strData,dwPointer,dwDataSize2);
	dwPointer += dwDataSize2;
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeHeader( const std::string& strData , uint32_t & dwPointer ){
	HeaderPtr object;
	ExpectedChar('H',strData,dwPointer);
	MoveNext(strData,dwPointer);
	//读取Name信息
	char buffer[2];
	buffer[1] = MoveNext(strData,dwPointer);
	buffer[0] = MoveNext(strData,dwPointer);
	int16_t dwDataSize = *(int16_t*)buffer;
	if( dwPointer + dwDataSize >= strData.size() )
		throw Exception("unexpected end");
	object->Name().append(strData,dwPointer,dwDataSize);
	dwPointer += dwDataSize;
	//读取Value信息
	object->Value() = DeSerializeArgv(strData,dwPointer);
	return object;
}
ObjectPtr HessianDeSerialize::DeSerializeFault( const std::string& strData , uint32_t & dwPointer ){
	FaultPtr object;
	ExpectedChar('f',strData,dwPointer);
	MoveNext(strData,dwPointer);
	while(GetChar(strData,dwPointer) != 'z' ){
		ObjectPtr oKey,oValue;
		oKey = DeSerializeArgv(strData,dwPointer) ;
		oValue = DeSerializeArgv(strData,dwPointer) ;
		object->Value()[oKey] = oValue;
	}
	MoveNext(strData,dwPointer);
	return object;
}
char HessianDeSerialize::GetChar( const std::string& strData , uint32_t & dwPointer ){
	if( dwPointer >= strData.size() )
		throw Exception("unexpected end!");
	return strData[dwPointer];
}
char HessianDeSerialize::MoveNext( const std::string& strData , uint32_t & dwPointer ){	
	if( dwPointer >= strData.size() )
		throw Exception("unexpected end!");
	return strData[dwPointer++];
}
void HessianDeSerialize::ExpectedChar( char expectChar , const std::string& strData , uint32_t & dwPointer ){
	if( GetChar(strData,dwPointer) != expectChar )
		throw Exception(string() + "unexpected char! Expected Char Is " + expectChar + ", But it is " + GetChar(strData,dwPointer) );
}

}