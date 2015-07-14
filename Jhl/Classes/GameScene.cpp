//
//  GameScene.cpp
//  Jhl
//
//  Created by 姬94 on 15/7/12.
//
//

#include "GameScene.h"
#include "LogoNode.h"
GameScene::GameScene(){

};
GameScene::~GameScene(){

};
bool GameScene::init(){
    if (!Layer::init()) {
        return false;
    }
    auto logo = LogoNode::create();
    addChild(logo);
    logo->setPosition(Director::getInstance()->getVisibleSize()/2);
    
    return true;
};
Scene *GameScene::createScene(){

    auto scene =Scene::create();
    auto layer = GameScene::create();
    
    scene ->addChild(layer);
    return scene;
};
