#ifndef __HESSIAN_SERIALIZE_H__
#define __HESSIAN_SERIALIZE_H__

#include <string>
#include <stdint.h>
#include <map>
#include "HessianType.h"
namespace FishHessianCpp{

class HessianSerialize{
public:
	HessianSerialize();
	~HessianSerialize();
	void Serialize( 
		const std::string& strMethodName , 
		const std::vector<ObjectPtr>& vecArgv,
		std::string& strResult );
private:
	void SerializeBegin( const std::string& strMethodName , std::string& strResult );
	void SerializeArgv( const Object* object , std::string& strResult ); 
	void SerializeEnd( std::string& strResult ); 
private:
	void SerializeNull( const Null* object , std::string& strResult );
	void SerializeBoolean( const Boolean* object , std::string& strResult );
	void SerializeInteger( const Integer* object , std::string& strResult );
	void SerializeLong( const Long* object , std::string& strResult );
	void SerializeDate( const Date* object , std::string& strResult );
	void SerializeDouble( const Double* object , std::string& strResult );
	void SerializeString( const String* object , std::string& strResult );
	void SerializeXml( const Xml* object , std::string& strResult );
	void SerializeBinary( const Binary* object , std::string& strResult );
	void SerializeList( const List* object , std::string& strResult );
	void SerializeMap( const Map* object , std::string& strResult );
	void SerializeRemote( const Remote* object , std::string& strResult );
};

}

#endif