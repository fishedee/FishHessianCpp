#include "Exception.h"

namespace FishHessianCpp{

Exception::Exception( const std::string& strMsg ){
	m_strMsg = strMsg;
}
Exception::~Exception()throw(){
}
const char* Exception::what()const throw(){
	return m_strMsg.c_str();
}

}