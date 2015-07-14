#include "HelloWorldScene.h"
#include "Ball.h"


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
    
    /* TextFieldTTF *tf =  TextFieldTTF::textFieldWithPlaceHolder("姬海龙是个美男子", "宋体", 50);
     tf->setPosition(visibleSize/2);
     
     addChild(tf);
     
     auto listener =  EventListenerTouchOneByOne::create();
     listener->onTouchBegan=[tf](Touch *t,Event *e){
     
     if (tf->getBoundingBox().containsPoint(t->getLocation())) {
     tf->attachWithIME();
     log("<<<<<<<<<<<<<<");
     }else{
     tf->detachWithIME();
     }
     
     return false;
     };
     
     Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tf);
     
     
     
    auto b =Ball::create();
    b->setPosition(200,200);
    addChild(b);
  
    auto menu =Menu::create(MenuItemImage::create("CloseNormal.png", "CloseSelected.png",  [](Ref* f){
    
        log("<<<<<<<<<<<<<<<<<<");
    }),NULL );
    addChild(menu);
    
    menu->setPosition(200,200);
      */
    
    TableView * TV =  TableView::create(this, Size(300,300));
    addChild(TV);
    TV->setAnchorPoint(Point(0,0));
    
    TV->setPosition(visibleSize/2);
    
    
    TV->setDelegate(this);
    return true;
}

Size HelloWorld::cellSizeForTable(cocos2d::extension::TableView *table){


    return  Size(300,30);
}

TableViewCell* HelloWorld::tableCellAtIndex(TableView *table, ssize_t idx) {

    
   TableViewCell* cell= table->dequeueCell();
    Label *label;
    
    if (cell==NULL) {
        cell=TableViewCell::create();
        label=Label::create();
        label->setTag(2);
        label->setSystemFontSize(20);
        cell->addChild(label);
        label->setAnchorPoint(Point(0,0));
        
        
    }else{
        label=(Label*)cell->getChildByTag(2);
        
    }
    cell->setColor(Color3B(159, 168, 176));
    label->setString(StringUtils::format("Lable->> %ld",idx));
    
    return cell;
    
}
ssize_t HelloWorld::numberOfCellsInTableView(cocos2d::extension::TableView *table){

    return 100;
}

void HelloWorld::tableCellTouched(TableView* table, TableViewCell* cell){

    Label *lable =  (Label*)cell->getChildByTag(2);
    log("from  %s",lable->getString().c_str());
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
