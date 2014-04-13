#ifndef __HESSIAN_H__
#define __HESSIAN_H__

#include "HessianDeSerialize.h"
#include "HessianSerialize.h"
#include "HttpConnection.h"
#include <string>

namespace FishHessianCpp{

class Hessian{
public:
	Hessian( const std::string& strUrl );
	~Hessian();
	ObjectPtr Invoke( const std::string& strMethodName , const std::vector<ObjectPtr>& vecArgv );
private:
	std::string m_strUrl;
	HttpConnection m_connection;
	HessianSerialize m_serialize;
	HessianDeSerialize m_deserialize;
};

}

#endif