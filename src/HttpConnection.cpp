#include "HttpConnection.h"
#include "Exception.h"
#include <iostream>
using namespace std;

namespace FishHessianCpp{

class HttpConnectionInitilize{
public:
	HttpConnectionInitilize(){
		curl_global_init( CURL_GLOBAL_ALL );
	}
	~HttpConnectionInitilize(){
		curl_global_cleanup();
	}
};
HttpConnectionInitilize httpConnectionInitilize;

HttpConnection::HttpConnection(){
	m_curl = curl_easy_init();
	if( m_curl == NULL )
		throw Exception("curl_easy_init error!");
}
HttpConnection::~HttpConnection(){
	if( m_curl != NULL )
		curl_easy_cleanup( m_curl );
}

void HttpConnection::GetHttp( 
	const std::string& strUrl ,
	const std::map<std::string,std::string>& mapHttpHeader,
	std::string& strResult ){
	GoHttp(
		strUrl,
		mapHttpHeader,
		"",
		true,
		strResult
	);
}
void HttpConnection::PostHttp(
	const std::string& strUrl ,
	const std::map<std::string,std::string>& mapHttpHeader,
	const std::string& strPostData,
	std::string& strResult ){
	GoHttp(
		strUrl,
		mapHttpHeader,
		strPostData,
		false,
		strResult
	);
}
size_t HttpConnection::WriteDataFromHttp( 
	void* buffer , 
	size_t size , 
	size_t nmemb , 
	void* lpVoid ){
	std::string& str = *(std::string*)lpVoid;
	str.append( (char*)buffer , size * nmemb );
	return nmemb;
}
void HttpConnection::GoHttp(
	const std::string& strUrl ,
	const std::map<std::string,std::string>& mapHttpHeader,
	const std::string& strPostData,
	bool	isGet,
	std::string& strResult){
	CURLcode res;
	//设置Url
	res = curl_easy_setopt( m_curl , CURLOPT_URL , strUrl.c_str() );
	if( res != CURLE_OK )
		throw Exception("curl_easy_setopt CURLOPT_URL error");
	//设置Http的Header
	curl_slist* http_headers = NULL ;
	for( std::map<std::string,std::string>::const_iterator it = mapHttpHeader.begin();
		it != mapHttpHeader.end() ; ++it ){
		http_headers = curl_slist_append( http_headers , (it->first + ":" + it->second).c_str());
		if( http_headers == NULL )
			throw Exception("curl_slist_append error header:" + it->first );
	}
	if( http_headers != NULL ){
		res = curl_easy_setopt( m_curl , CURLOPT_HTTPHEADER , http_headers );
		if( res != CURLE_OK )
			throw Exception("curl_easy setopt CURL_HTTPHERADER error");
	}
	//设置Get或Post数据
	if( isGet ){
		res = curl_easy_setopt( m_curl , CURLOPT_HTTPGET,1);
		if( res != CURLE_OK )
			throw Exception("curl_easy_setopt CURLOPT_HTTPGET error");
	}else{
		res = curl_easy_setopt( m_curl , CURLOPT_POST , 1 );
		if( res != CURLE_OK )
			throw Exception("curl_easy_setopt CURLOPT_POST error");
		res = curl_easy_setopt( m_curl , CURLOPT_POSTFIELDS , strPostData.c_str());
		if( res != CURLE_OK )
			throw Exception("curl_easy_setopt CURLOPT_POSTFIELDS error");
		res = curl_easy_setopt(m_curl,CURLOPT_POSTFIELDSIZE,strPostData.size());
		if( res != CURLE_OK )
			throw Exception("curl_easy_setopt CURLOPT_POSTFIELDSIZE error");
	}
	//设置Http的接收数据
	res = curl_easy_setopt( m_curl , CURLOPT_FOLLOWLOCATION , 1 );
	if( res != CURLE_OK )
		throw Exception("curl_easy_setopt CURLOPT_FOLLOWLOCATION error");
	res = curl_easy_setopt( m_curl , CURLOPT_WRITEFUNCTION , &HttpConnection::WriteDataFromHttp );
	if( res != CURLE_OK )
		throw Exception("curl_easy_setopt CURLOPT_WRITEFUNCTION error");
	res = curl_easy_setopt( m_curl , CURLOPT_WRITEDATA , (void*)&strResult );
	if( res != CURLE_OK )
		throw Exception("curl_easy_setopt CURLOPT_WRITEDATA error");
	res = curl_easy_perform( m_curl );
	if( res != CURLE_OK )
		throw Exception("curl_easy_perform error");
	long retcode;
	res  = curl_easy_getinfo( m_curl , CURLINFO_RESPONSE_CODE , &retcode );
	if( res != CURLE_OK  )
		throw Exception("curl_easy_setopt CURLINFO_RESPONSE_CODE error");
	if( retcode != 200 )
		throw Exception("retcode isn't 200");
	
}

}
