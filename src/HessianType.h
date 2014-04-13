#ifndef __HESSIAN_TYPE_H__
#define __HESSIAN_TYPE_H__
#include <stdint.h>
#include <tr1/memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <time.h>
namespace FishHessianCpp{

class Object{
public:
	virtual void DumpDataTree( std::ostream& os )const{
		os << "[Object]";
	}
};
typedef std::tr1::shared_ptr<Object> ObjectPtr;
typedef std::tr1::weak_ptr<Object> WeakObjectPtr;
class Integer:public Object{
public:
	Integer(){
		m_data = 0;
	}
	Integer( int32_t data ){
		m_data = data;
	}
	int32_t& Value(){
		return m_data;
	}
	const int32_t& Value()const{
		return m_data;
	}
	 void DumpDataTree( std::ostream& os )const{
		os << "[Integer:"<<m_data<<"]";
	}
private:
	int32_t m_data;
};
typedef std::tr1::shared_ptr<Integer> IntegerPtr;
class Long:public Object{
public:
	Long(){
		m_data = 0;
	}
	Long( int64_t data ){
		m_data = data;
	}
	int64_t& Value(){
		return m_data;
	}
	const int64_t& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Long:"<<m_data<<"]";
	}
private:
	int64_t m_data;
};
typedef std::tr1::shared_ptr<Long> LongPtr;
class Double:public Object{
public:
	Double(){
		m_data = 0;
	}
	Double( double data ){
		m_data = data;
	}
	double& Value(){
		return m_data;
	}
	const double& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Double:"<<m_data<<"]";
	}
private:
	double m_data;
};
typedef std::tr1::shared_ptr<Double> DoublePtr;
class Boolean:public Object{
public:
	Boolean(){
	}
	Boolean( bool data ){
		m_data = data;
	}
	bool& Value(){
		return m_data;
	}
	const bool& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Boolean:"<<m_data<<"]";
	}
private:
	bool m_data;
};
typedef std::tr1::shared_ptr<Boolean> BooleanPtr;
class Date:public Object{
public:
	Date(){
		m_data = time(NULL);
	}
	Date( time_t data ){
		m_data = data;
	}
	time_t& Value(){
		return m_data;
	}
	const time_t& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Date:"<<ctime(&m_data)<<"]";
	}
private:
	time_t m_data;
};
typedef std::tr1::shared_ptr<Date> DatePtr;
class String:public Object{
public:
	String(){
	}
	String( const std::string& data ){
		m_data = data;
	}
	std::string& Value(){
		return m_data;
	}
	const std::string& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[String:"<<m_data<<"]";
	}
private:
	std::string m_data;
};
typedef std::tr1::shared_ptr<String> StringPtr;
class Binary:public Object{
public:
	Binary(){
	}
	Binary( const std::string& data ){
		m_data = data;
	}
	std::string& Value(){
		return m_data;
	}
	const std::string& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Binary:"<<m_data<<"]";
	}
private:
	std::string m_data;
};
typedef std::tr1::shared_ptr<Binary> BinaryPtr;
class Null:public Object{
public:
	void DumpDataTree( std::ostream& os )const{
		os<<"[Null]";
	}
};
typedef std::tr1::shared_ptr<Null> NullPtr;
class Xml:public Object{
public:
	Xml(){
	}
	Xml( const std::string& data ){
		m_data = data;
	}
	std::string& Value(){
		return m_data;
	}
	const std::string& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Xml:"<<m_data<<"]";
	}
private:
	std::string m_data;
};
typedef std::tr1::shared_ptr<Xml> XmlPtr;
class Remote:public Object{
public:
	Remote(){
	}
	Remote( const std::string& strClassName , const std::string& data ){
		m_strClassName = strClassName;
		m_data = data;
	}
	std::string& Class() {
		return m_strClassName;
	}
	const std::string& Class()const {
		return m_strClassName;
	}
	std::string& Value(){
		return m_data;
	}
	const std::string& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Remote "<<std::endl
			<<"Class:" <<m_strClassName<<std::endl
			<<"Data:" <<m_data<<std::endl
			<<"]"<<std::endl;
	}
private:
	std::string m_data;
	std::string m_strClassName;
};
typedef std::tr1::shared_ptr<Remote> RemotePtr;
class List:public Object{
public:
	List(){
	}
	List( const std::string& strClassName , const std::vector<ObjectPtr>& data ){
		m_data = data;
		m_strClassName = strClassName;
	}
	std::string& Class(){
		return m_strClassName;
	}
	const std::string& Class()const{
		return m_strClassName;
	}
	std::vector<ObjectPtr>& Value(){
		return m_data;
	}
	const std::vector<ObjectPtr>& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[List "<<std::endl
			<<"Class:" <<m_strClassName<<std::endl;
		for( uint32_t i = 0 ; i != m_data.size() ; ++i ){
			os<<"Data:";
			m_data[i]->DumpDataTree(os);
			os<<std::endl;
		}
		os<<"]"<<std::endl;
	}
private:
	std::string m_strClassName;
	std::vector<ObjectPtr>  m_data;
};
typedef std::tr1::shared_ptr<List> ListPtr;
class Map:public Object{
public:
	Map(){
	}
	Map( const std::string& strClassName , const std::map<ObjectPtr,ObjectPtr>& data ){
		m_data = data;
		m_strClassName = strClassName;
	}
	std::string& Class(){
		return m_strClassName;
	}
	const std::string& Class()const{
		return m_strClassName;
	}
	std::map<ObjectPtr,ObjectPtr>& Value(){
		return m_data;
	}
	const std::map<ObjectPtr,ObjectPtr>& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Map "<<std::endl
			<<"Class:" <<m_strClassName<<std::endl;
		for( std::map<ObjectPtr,ObjectPtr>::const_iterator  it = m_data.begin(); 
			it != m_data.end() ; ++it ){
			os<<"Key:";
			it->first->DumpDataTree(os);
			os<<std::endl;
			os<<"Value:";
			it->second->DumpDataTree(os);
			os<<std::endl;
		}
		os<<"]"<<std::endl;
	}
private:
	std::string m_strClassName;
	std::map<ObjectPtr,ObjectPtr>  m_data;
};
typedef std::tr1::shared_ptr<Map> MapPtr;
class Fault:public Object{
public:
	Fault(){
	}
	Fault( const std::map<ObjectPtr,ObjectPtr>& data ){
		m_data = data;
	}
	std::map<ObjectPtr,ObjectPtr>& Value(){
		return m_data;
	}
	const std::map<ObjectPtr,ObjectPtr>& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		os << "[Fault "<<std::endl;
		for( std::map<ObjectPtr,ObjectPtr>::const_iterator  it = m_data.begin(); 
			it != m_data.end() ; ++it ){
			os<<"Key:";
			it->first->DumpDataTree(os);
			os<<std::endl;
			os<<"Value:";
			it->second->DumpDataTree(os);
			os<<std::endl;
		}
		os<<"]"<<std::endl;
	}
private:
	std::map<ObjectPtr,ObjectPtr>  m_data;
};
typedef std::tr1::shared_ptr<Fault> FaultPtr;
class Reference:public Object{
public:
	Reference(){
	}
	Reference( const WeakObjectPtr& data ){
		m_data = data;
	}
	WeakObjectPtr& Value(){
		return m_data;
	}
	const WeakObjectPtr& Value()const{
		return m_data;
	}
	void DumpDataTree( std::ostream& os )const{
		ObjectPtr ptr = m_data.lock();
		os << "[Reference "<<ptr.get()<<"]";
	}
private:
	WeakObjectPtr m_data;
};
typedef std::tr1::shared_ptr<Reference> ReferencePtr;
class Header:public Object{
public:
	Header(){
	}
	Header( const std::string& strName ,const ObjectPtr& data ){
		m_strName = strName;
		m_data = data;
	}
	std::string& Name(){
		return m_strName;
	}
	const std::string& Name()const{
		return m_strName;
	}
	ObjectPtr& Value(){
		return m_data;
	}
	const ObjectPtr& Detail()const{
		return m_data;
	}	
	void DumpDataTree( std::ostream& os )const{
		os << "[Header "<<std::endl
			<<"Name:" <<m_strName<<std::endl
			<<"Data:" ;
			m_data->DumpDataTree(os);
		os<<std::endl;
		os<<"]"<<std::endl;
	}
private:
	std::string m_strName;
	ObjectPtr m_data;
};
typedef std::tr1::shared_ptr<Header> HeaderPtr;
}

#endif