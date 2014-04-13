#ifndef __HESSIAN_DESERIALIZE_H__
#define __HESSIAN_DESERIALIZE_H__

#include <string>
#include <stdint.h>
#include <map>
#include "HessianType.h"
namespace FishHessianCpp{

class HessianDeSerialize{
public:
	HessianDeSerialize();
	~HessianDeSerialize();
	ObjectPtr DeSerialize( 
		const std::string& strData );
private:
	void DeSerializeBegin( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeArgv( const std::string& strData , uint32_t & dwPointer );
	void DeSerializeEnd( const std::string& strData , uint32_t & dwPointer );
private:
	ObjectPtr DeSerializeNull( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeBoolean( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeInteger( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeLong( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeDate( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeDouble( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeString( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeXml( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeBinary( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeList( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeMap( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeRemote( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeHeader( const std::string& strData , uint32_t & dwPointer );
	ObjectPtr DeSerializeFault( const std::string& strData , uint32_t & dwPointer );
private:
	char GetChar( const std::string& strData , uint32_t & dwPointer );
	char MoveNext( const std::string& strData , uint32_t & dwPointer );
	void ExpectedChar( char expectChar , const std::string& strData , uint32_t & dwPointer );
};

}

#endif