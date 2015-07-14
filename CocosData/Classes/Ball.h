//
//  Ball.h
//  CocosData
//
//  Created by 姬94 on 15/7/13.
//
//

#ifndef CocosData_Ball_h
#define CocosData_Ball_h

#include <cocos2d.h>

class Ball: public cocos2d::Sprite{
private:
    float speedX,speedY;
    
public:
    
    virtual bool init(){
        speedX=CCRANDOM_0_1()*10-5;
        speedY=CCRANDOM_0_1()*10-5;
        
        Sprite::initWithFile("CloseSelected.png");
        
        return true;
    };
    CREATE_FUNC(Ball);
    void move(){
        setPositionX(getPositionX()+speedX);
        setPositionY(getPositionY()+speedY);
        
    }
};

#endif
