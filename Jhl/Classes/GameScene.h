//
//  GameScene.h
//  Jhl
//
//  Created by 姬94 on 15/7/12.
//
//

#ifndef __Jhl__GameScene__
#define __Jhl__GameScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class GameScene:public Layer
{
public:
    GameScene();
    virtual ~GameScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    static Scene* createScene();
};

#endif /* defined(__Jhl__GameScene__) */
