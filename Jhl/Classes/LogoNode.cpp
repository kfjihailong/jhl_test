//
//  LogoNodes.cpp
//  Jhl
//
//  Created by 姬94 on 15/7/12.
//
//

#include "LogoNode.h"
LogoNode::LogoNode():_logo(nullptr),_cocosLogo(nullptr)
{
    
};
LogoNode:: ~LogoNode(){};
bool LogoNode:: init(){

    if (!Node::init()) {
        return false;
    }
    _logo=Sprite::create("HelloWorld.png");
    _cocosLogo=Sprite::create("CloseSelected.png");
    
    addChild(_logo);
    addChild(_cocosLogo);
    _cocosLogo->setVisible(false);
    schedule([this](float f){
        _logo->setVisible(!_logo->isVisible());
        _cocosLogo->setVisible(!_cocosLogo->isVisible());

    },1, "test");
    
    return true;
};