//
//  LogoNodes.h
//  Jhl
//
//  Created by 姬94 on 15/7/12.
//
//

#ifndef __Jhl__LogoNode__
#define __Jhl__LogoNode__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class LogoNode:public Node
{
protected:
    Sprite* _logo;
    Sprite* _cocosLogo;
public:
    LogoNode();
    virtual ~LogoNode();
    virtual bool init();
    CREATE_FUNC(LogoNode);
};
#endif /* defined(__Jhl__LogoNodes__) */
