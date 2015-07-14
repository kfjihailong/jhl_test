#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 /*
    auto role = Sprite::create("HelloWorld.png");
    addChild(role);
    role->setPosition(visibleSize/2);
    role->setScale(0.5);
    
//    role->runAction(MoveTo::create(2, Vec2(visibleSize.width-100,visibleSize.height/2)));
//    auto move1=MoveTo::create(2, Vec2(visibleSize.width-100,visibleSize.height/2));
//    auto move2=MoveBy::create(2, Vec2(-1000,visibleSize.height/2));
//      role->runAction(Sequence::create(move1,move2, NULL));
    
  auto move1=MoveBy::create(2, Vec2(1000,0));
    auto move2=move1->reverse();

    
    auto move = MoveBy::create(2, Vec2(1000,1));
    auto scale = ScaleTo::create(2, 1);
//    role->runAction(Spawn::create(move,scale, NULL));

    role->runAction(Sequence::create(Spawn::create(move,scale, NULL),CallFunc::create([](){
        CCLOG("jhl`~~~~~");
    }),NULL));
  role->runAction(Sequence::create(move1,move2, NULL));
  */
    
  /*
    auto role = NodeGrid::create();
    role->addChild(Sprite::create("HelloWorld.png"));
    addChild(role);
    role->setPosition(visibleSize/2);
    auto shaky = ShakyTiles3D::create(1, Size(50,50), 5, false);
    auto shuffle=ShuffleTiles::create(0.5, Size(50,50), 25);
    auto turn =TurnOffTiles::create(1, Size(50, 50),25);
    
    
//    role->runAction(Sequence::create(shaky,shuffle,turn, NULL));
//    role->runAction(Waves3D::create(2,Size(15, 10),4,40));
    auto W1=Waves3D::create(2,Size(15, 10),4,40);
    auto W2=Waves3D::create(2, Size(15,10), 5, 0);
    role->runAction(Sequence::create(W1,W2, NULL));
    */
    
    auto backgroun=Sprite::create("HelloWorld.png");
    backgroun->setPosition(visibleSize/2);
    addChild(backgroun);
    
    
    scheduleOnce([visibleSize,this](float f){
    
        auto newScene=Scene::create();
        auto newBackground = Sprite::create("CloseSelected.png");
        newBackground->setPosition(visibleSize/2);
        newScene->addChild(newBackground);
        auto transition = TransitionCrossFade::create(1, newScene);

        Director::getInstance()->replaceScene(transition);
    }, 2,"test");
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
