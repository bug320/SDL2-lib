/**
 * 文件名 : codingtry.h
 * 编码   : utf-8 
 */
#include <iostream>
using namespace std;
/**
 *\class MSg 处理信息传递。 
 */
class Msg{
	
	public :
	 string sendMsg(){
		 return m_szMsg;
	 }
	 void setMsg(string msg){
		 m_szMsg = msg;
	 }
	protected:
	string m_szMsg;
} 