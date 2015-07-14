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
 
//   绘制矩形
  /*    auto rect=DrawNode::create();
    rect->drawRect(Vec2(0, 0), Vec2(300,300), Color4F(1.0,1.0,1.0,1.0));
    addChild(rect);
    rect->setPosition(visibleSize/2);
    
//    绘制点
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,0,0,1.0));
    rect->addChild(dot);
    rect->setContentSize(Size(300,300));
    rect->setAnchorPoint(Vec2(0.5,0.5));//锚点
    
    dot->setPosition(Vec2(10, 10));
    schedule([dot,rect](float f){
        rect->setRotation(rect->getRotation()+1);
        auto p=dot->convertToWorldSpace(Vec2(0,0));
        CCLOG("%f,%f",p.x,p.y);
    }, "Test");

    _angle=0;
    auto dot=DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    schedule([dot,this,visibleSize](float f){
        dot->setPositionY(visibleSize.height/2+sin(_angle)*100);
        dot->setPositionX(visibleSize.width/2+cos(_angle)*100);

        _angle+=0.1;
        
    }, "Test");
  
    _direction.set(random(-1.0f,1.0f), random(-1.0f,1.0f));
    _direction.normalize();
    
    auto dot=DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    dot->setPosition(visibleSize/2);

    addChild(dot);
    
    schedule([dot,this,visibleSize](float f){
        auto p = dot->getPosition();
        if (p.x<0||p.x>visibleSize.width) {
            _direction.x*=-1;
        }else if (p.y<0||p.y>visibleSize.height){
            _direction.y*=-1;
        }
        dot->setPosition(p+_direction*10);
        
    }, "test");
   
    
    
    auto logo = Sprite::create("HelloWorld.png");
    auto img = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
   
    auto logo = Sprite::createWithTexture(img);
    addChild(logo);
    logo->setPosition(visibleSize/2);*/
    
    auto layer1 =Layer::create();
    auto layer2 =Layer::create();
    auto layer3 =Layer::create();

    auto img1=Sprite::create("HelloWorld.png");
    auto img2=Sprite::create("HelloWorld.png");
    auto img3=Sprite::create("HelloWorld.png");
    
    img1->setAnchorPoint(Vec2(0,0));
    img2->setAnchorPoint(Vec2(0,0));
     img3->setAnchorPoint(Vec2(0,0));
    
    layer1->addChild(img1);
    
    layer2->addChild(img2);
    layer3->addChild(img3);

    addChild(layer1);
    addChild(layer2);
    addChild(layer3);

    layer1->setPosition(Vec2(100,100));
    layer2->setPosition(Vec2(200,200));
    layer3->setPosition(Vec2(300,300));

    scheduleOnce([visibleSize,this](float f){
        auto scene2=Scene::create();
        auto scene2Layer=Layer::create();
        scene2->addChild(scene2Layer);
        auto logo = Sprite::create("HelloWorld.png");
        logo->setPosition(visibleSize/2);
        scene2Layer->addChild(logo);
        Director::getInstance()->replaceScene(scene2);

    }, 3,"test");
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
