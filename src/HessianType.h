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
class Null:public Object{
public:
	void DumpDataTree( std::ostream& os )const{
		os<<"[Null]";
	}
};
class NullPtr:public std::tr1::shared_ptr<Null>{
public:
	NullPtr():std::tr1::shared_ptr<Null>( new Null() ){
	}
	template<typename T1>
	NullPtr( const T1& a ):std::tr1::shared_ptr<Null>( new Null() ){
	}
};
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
class BooleanPtr:public std::tr1::shared_ptr<Boolean>{
public:
	BooleanPtr():std::tr1::shared_ptr<Boolean>( new Boolean() ){
	}
	template<typename T1>
	BooleanPtr( const T1& a ):std::tr1::shared_ptr<Boolean>( new Boolean(a)){
	}
};
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
class IntegerPtr:public std::tr1::shared_ptr<Integer>{
public:
	IntegerPtr():std::tr1::shared_ptr<Integer>( new Integer() ){
	}
	template<typename T1>
	IntegerPtr( const T1& a ):std::tr1::shared_ptr<Integer>( new Integer(a)){
	}
};
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
class LongPtr:public std::tr1::shared_ptr<Long>{
public:
	LongPtr():std::tr1::shared_ptr<Long>( new Long() ){
	}
	template<typename T1>
	LongPtr( const T1& a ):std::tr1::shared_ptr<Long>( new Long(a)){
	}
};
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
class DoublePtr:public std::tr1::shared_ptr<Double>{
public:
	DoublePtr():std::tr1::shared_ptr<Double>( new Double() ){
	}
	template<typename T1>
	DoublePtr( const T1& a ):std::tr1::shared_ptr<Double>( new Double(a)){
	}
};
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
class DatePtr:public std::tr1::shared_ptr<Date>{
public:
	DatePtr():std::tr1::shared_ptr<Date>( new Date() ){
	}
	template<typename T1>
	DatePtr( const T1& a ):std::tr1::shared_ptr<Date>( new Date(a)){
	}
};
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
class StringPtr:public std::tr1::shared_ptr<String>{
public:
	StringPtr():std::tr1::shared_ptr<String>( new String() ){
	}
	template<typename T1>
	StringPtr( const T1& a ):std::tr1::shared_ptr<String>( new String(a)){
	}
};
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
class BinaryPtr:public std::tr1::shared_ptr<Binary>{
public:
	BinaryPtr():std::tr1::shared_ptr<Binary>( new Binary() ){
	}
	template<typename T1>
	BinaryPtr( const T1& a ):std::tr1::shared_ptr<Binary>( new Binary(a)){
	}
};
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
class XmlPtr:public std::tr1::shared_ptr<Xml>{
public:
	XmlPtr():std::tr1::shared_ptr<Xml>( new Xml() ){
	}
	template<typename T1>
	XmlPtr( const T1& a ):std::tr1::shared_ptr<Xml>( new Xml(a)){
	}
};
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
class RemotePtr:public std::tr1::shared_ptr<Remote>{
public:
	RemotePtr():std::tr1::shared_ptr<Remote>( new Remote() ){
	}
	template<typename T1,typename T2>
	RemotePtr( const T1& a ,const T2& b):std::tr1::shared_ptr<Remote>( new Remote(a,b)){
	}
};
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
class ListPtr:public std::tr1::shared_ptr<List>{
public:
	ListPtr():std::tr1::shared_ptr<List>( new List() ){
	}
	template<typename T1,typename T2>
	ListPtr( const T1& a ,const T2& b):std::tr1::shared_ptr<List>( new List(a,b)){
	}
};
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
class MapPtr:public std::tr1::shared_ptr<Map>{
public:
	MapPtr():std::tr1::shared_ptr<Map>( new Map() ){
	}
	template<typename T1,typename T2>
	MapPtr( const T1& a ,const T2& b):std::tr1::shared_ptr<Map>( new Map(a,b)){
	}
};
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
class FaultPtr:public std::tr1::shared_ptr<Fault>{
public:
	FaultPtr():std::tr1::shared_ptr<Fault>( new Fault() ){
	}
	template<typename T1>
	FaultPtr( const T1& a ):std::tr1::shared_ptr<Fault>( new Fault(a)){
	}
};
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
class ReferencePtr:public std::tr1::shared_ptr<ReferencePtr>{
public:
	ReferencePtr():std::tr1::shared_ptr<ReferencePtr>( new ReferencePtr() ){
	}
	template<typename T1>
	ReferencePtr( const T1& a ):std::tr1::shared_ptr<ReferencePtr>( new ReferencePtr(a)){
	}
};
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
class HeaderPtr:public std::tr1::shared_ptr<Header>{
public:
	HeaderPtr():std::tr1::shared_ptr<Header>( new Header() ){
	}
	template<typename T1>
	HeaderPtr( const T1& a ):std::tr1::shared_ptr<Header>( new Header(a)){
	}
};
}

#endif