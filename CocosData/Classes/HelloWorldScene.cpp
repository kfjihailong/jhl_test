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
    
     visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
 /*   auto icon = Sprite::create("CloseNormal.png");
    addChild(icon);
    icon->setPosition(visibleSize/2);
    
    
    schedule([icon](float f){
        auto size=icon->getContentSize();

        CCLOG("SIZE:%f  %f",size.width,size.height);

    
    },"test");
    
    Vector<Label*> vec;
    auto lable1= Label::create();
    auto lable2= Label::create();
    lable1->setString("Lable 1");
    lable2->setString("Lable 2");

    lable1->setSystemFontSize(50);
    lable2->setSystemFontSize(50);
    
    vec.pushBack(lable1);
    vec.pushBack(lable2);
    
    int i=0;
    for (auto label:vec) {
        i++;
        
        label->setPosition(Vec2(visibleSize.width/2, i*100));
        addChild(label);
    }
    
  
    
    cocos2d::Map<std::string, Label*> map;
    auto lable1= Label::create();
    auto lable2= Label::create();
    lable1->setString("Lable 1");
    lable2->setString("Lable 2");
    
    lable1->setSystemFontSize(50);
    lable2->setSystemFontSize(50);
    
    lable1->setPosition(Vec2(visibleSize.width/2, 1*100));
    lable2->setPosition(Vec2(visibleSize.width/2, 2*100));
   
    map.insert("lable1", lable1);
    map.insert("lable2", lable2);
    addChild(map.at("lable1"));
  
    
    Value value1= Value("abc");
    Value value2= Value(123);
    Value value3= Value(true);

    CCLOG("%s %d %s",value1.asString().c_str(),value2.asInt(),value3.asBool()==true?"true":"false");
    CCLOG("%s %s %s",value1.asString().c_str(),value2.asString().c_str(),value3.asString().c_str());
    
    Value value4= Value::Null;
    value4=value1;
    value4=value2;
    value4=value3;
    
    ValueVector verctor;
    verctor.push_back(Value("hello"));
    verctor.push_back(value1);
    verctor.push_back(value2);
    for (auto v:verctor) {
        CCLOG("Verctor %s",v.asString().c_str());
    }
    
    ValueMap map;
    map["a"]=value2;
    map["b"]=value3;
    for (auto m:map) {
        CCLOG("map %s %s",m.first.c_str(),m.second.asString().c_str());
 
    }
    cocos2d::Value intVar(40);
    CCLOG("%d   ",intVar.asInt());
     */
    
    schedule(schedule_selector(HelloWorld::addBall),0.1f);
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float t){
    Ball *b;
    for (auto it=balls.begin(); it!=balls.end(); it++) {
        b=*it;
        b->move();
        if (b->getPositionX()>visibleSize.width
            ||b->getPositionX()<0||
            b->getPositionY()<0||
            b->getPositionY()>visibleSize.height
            ) {
            balls.eraseObject(b);
            removeChild(b);
            break;
        }
    }

}

void HelloWorld::addBall(float dt)
{
    
    auto ball = Ball::create();
    addChild(ball);
    ball->setPosition(visibleSize/2);
 
    balls.pushBack(ball);
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
