//
//  Ball.h
//  CocosBase
//
//  Created by 姬94 on 15/7/14.
//
//

#ifndef __CocosBase__Ball__
#define __CocosBase__Ball__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Ball :public Sprite{


public:
    virtual bool init();
    
    CREATE_FUNC(Ball);
//    static Ball* create(){
//        Ball *b= new Ball();
//        b->init();
//        b->autorelease();
//        return b;
//    }
};


#endif /* defined(__CocosBase__Ball__) */
