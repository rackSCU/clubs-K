#include "HelloWorldScene.h"
#include "SecondScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    auto audio = SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("Lyn - Life Will Change.mp3", true);


    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"

    auto sprite = Sprite::create("yingjiemian.png");
    if (sprite == nullptr)
    {
        problemLoading("yingjiemian.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
        auto moveBy = MoveBy::create(2, Vec2(50, 10));
        auto moveTo = MoveTo::create(2, Vec2(50, 10));
        auto tintTo = TintTo::create(2.0f, 120.0f, 232.0f, 254.0f);
        auto rotateBy = RotateBy::create(2.0f, 40.0f);
        auto delay = DelayTime::create(1);
        auto seq = Sequence::create(moveBy, tintTo, delay, rotateBy, moveTo, delay->clone(), nullptr);
        auto sp = Spawn::create(moveBy, tintTo, delay, rotateBy, moveTo, delay->clone(), nullptr);
        sprite->runAction(seq);
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    auto mySprite = Sprite::create("bche.png");
    if (mySprite == nullptr)
    {
        problemLoading("bche.png");
    }
    else
    {
        // position the sprite on the center of the screen
        mySprite->setPosition(50, 56);

        // create a few Actions
        auto moveBy = MoveBy::create(2.0f, Vec2(100, 0));
        auto scaleBy = ScaleBy::create(2.0f, 2.0f);
        auto delay = DelayTime::create(2.0f);

        // create a sequence
        auto delaySequence = Sequence::create(delay, delay->clone(), delay->clone(),
            delay->clone(), nullptr);

        auto sequence = Sequence::create(moveBy, delay, scaleBy, delaySequence, nullptr);

        // run it
        mySprite->runAction(sequence);

        // reverse it
        mySprite->runAction(sequence->reverse());
        this->addChild(mySprite, 2);
    }
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(
        TransitionSlideInT::create(
            3.0f, SecondScene::createScene()
        )
    );

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
