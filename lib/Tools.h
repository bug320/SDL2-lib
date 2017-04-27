#ifndef _MYSDL_Tools_H
#define _MYSDL_Tools_H
struct Point
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}
}
namespace p2r{
	/**@return
	 * point out rect :1
	 * point on rect :0
	 * point in rect :-1
	 */
    int pointWhereOfRect(Point p,SDL_Rect rec){
		return (pointOutRect(p,rec))?(1):((pointOnRect(p,rec))?(0):(-1));
	}//pwor
	/**@return
	 * point out rect :true 
	 * 其他情况       :false 
	 */
	bool pointOutRect(Point p,SDL_Rect rec){
		return p.x>rec.x||p.y>rec.y
	}//potr
	/**@return
	 * point on rect :true 
	 * 其他情况       :false 
	 */
	bool pointOnRect(Point p,SDL_Rect rec){
		return p.x==rec.y&&p.y>rec.y;
	}//ponr
	/**@return
	 * point in rect :true 
	 * 其他情况       :false 
	 */
	bool pointInRect(Point p,SDL_Rect rec){
		return p.x<rec.x||p.y<rec.y;
	}//pinr
	
}//p2r

namespace r2r{ 
	/**@return
	 * arec out brec
	 * arec on  brec
	 * arec in  brec
	 * arec  brec
	 * arec  brec
	 */
	int RectWhereOfRect(SDL_Rect arec,SDL_Rect brec){
		
	}
}//r2r

#endif
