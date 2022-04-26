#include "ThirdScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* ThirdScene::createScene() {
    //创建一个Scene类的对象scene
    auto scene = Scene::create();
    //创建一个SecondScene类的对象layer
    auto layer = ThirdScene::create();
    //把layer添加到scene里
    scene->addChild(layer);
    //返回scene
    return scene;
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ThirdScene::init() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Label* label = Label::createWithTTF("rule", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label);

    auto Item = MenuItemImage::create(
        "1.jpg",
        "1.jpg",
        [&](Ref* pSender)
        {
        });

    if (Item == nullptr ||
        Item->getContentSize().width <= 0 ||
        Item->getContentSize().height <= 0)
    {
        problemLoading("'1.jpg' and '1.jpg'");
    }
    else
    {
        float x = 250;
        float y = 150 ;
        Item->setPosition(Vec2(x, y));
    }

    auto returnItem = MenuItemImage::create(
        "return.png",
        "return.png",
        [&](Ref* pSender)
        {
            Director::getInstance()->replaceScene(TransitionSlideInT::create(3.0f, HelloWorld::createScene()));
        });

    if (returnItem == nullptr ||
        returnItem->getContentSize().width <= 0 ||
        returnItem->getContentSize().height <= 0)
    {
        problemLoading("'return.png' and 'return.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - returnItem->getContentSize().width / 2;
        float y = origin.y + returnItem->getContentSize().height / 2;
        returnItem->setPosition(Vec2(x, y));
    }
    auto menu = Menu::create(Item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    auto menu1 = Menu::create(returnItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);
    return true;
}

