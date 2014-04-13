#ifndef __HTTPCONNECTION_H__
#define __HTTPCONNECTION_H__

#include <curl/curl.h>
#include <string>
#include <map>
namespace FishHessianCpp{

class HttpConnection{
public:
	HttpConnection();
	~HttpConnection();
	void GetHttp( 
		const std::string& strUrl ,
		const std::map<std::string,std::string>& mapHttpHeader,
		std::string& strResult );
	void PostHttp(
		const std::string& strUrl ,
		const std::map<std::string,std::string>& mapHttpHeader,
		const std::string& strPostData,
		std::string& strResult );
private:
	static size_t WriteDataFromHttp( 
		void* buffer , 
		size_t size , 
		size_t nmemb , 
		void* lpVoid );
	void GoHttp(
		const std::string& strUrl ,
		const std::map<std::string,std::string>& mapHttpHeader,
		const std::string& strPostData,
		bool	isGet,
		std::string& strResult);
private:
	CURL* m_curl;
};

}

#endif