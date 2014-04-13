#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <exception>
#include <string>
namespace FishHessianCpp{

class Exception:public std::exception{
public:
	Exception( const std::string& strMsg );
	~Exception()throw();
	const char* what()const  throw();
private:
	std::string m_strMsg;
};

}
#endif