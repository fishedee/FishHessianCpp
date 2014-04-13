#include "Hessian.h"
#include <iostream>
using namespace std;
namespace FishHessianCpp{

Hessian::Hessian( const std::string& strUrl ){
	m_strUrl = strUrl;
}
Hessian::~Hessian(){
}
ObjectPtr Hessian::Invoke( const std::string& strMethodName , const std::vector<ObjectPtr>& vecArgv ){
	//序列化数据
	std::string strPostData;
	m_serialize.Serialize(strMethodName,vecArgv,strPostData);
	//发送并接收数据
	std::map<std::string,std::string> mapHttpHeader;
	mapHttpHeader["Content-Type"] = "application/x-hessian";
	std::string strResult;
	m_connection.PostHttp(
			m_strUrl,
			mapHttpHeader,
			strPostData,
			strResult
	);
	//反序列化数据
	return m_deserialize.DeSerialize(strResult);
}

}
