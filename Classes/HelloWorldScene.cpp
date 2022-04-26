#include "HelloWorldScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"

USING_NS_CC;
//using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        [&](Ref* pSender)
        {
            Director::getInstance()->end();
        });

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    auto startItem = MenuItemImage::create(
        "start.jpg",
        "start.jpg",
        [&](Ref* pSender)
        {
            Director::getInstance()->replaceScene(TransitionSlideInT::create(3.0f, SecondScene::createScene()));
        });

    if (startItem == nullptr ||
        startItem->getContentSize().width <= 0 ||
        startItem->getContentSize().height <= 0)
    {
        problemLoading("'start.jpg' and 'start.jpg'");
    }
    else
    {
        float x = origin.x -startItem->getContentSize().width/8;
        float y = origin.y ;
        startItem->setPosition(Vec2(x, y));
    }

    auto Intro = MenuItemImage::create(
        "intro.png",
        "intro.png",
        [&](Ref* pSender)
        {
            Director::getInstance()->replaceScene(TransitionSlideInT::create(3.0f, ThirdScene::createScene()));
        });

    if (Intro == nullptr ||
        Intro->getContentSize().width <= 0 ||
        Intro->getContentSize().height <= 0)
    {
        problemLoading("'intro.png' and 'intro.png'");
    }
    else
    {
        float x =  Intro->getContentSize().width - visibleSize.width/2;
        float y =  Intro->getContentSize().height - visibleSize.height/2;
        Intro->setPosition(Vec2(x, y));
    }
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO); 
    this->addChild(menu, 1);
    auto menu2 = Menu::create(startItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);
    auto menu3 = Menu::create(Intro, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);

    auto audio = SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("Lyn - Life Will Change.mp3", true);


    auto label = Label::createWithTTF("Clubs K", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

}

