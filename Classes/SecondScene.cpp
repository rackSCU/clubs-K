#include "SecondScene.h"

USING_NS_CC;

Scene* SecondScene::createScene() {
    //创建一个Scene类的对象scene
    auto scene = Scene::create();
    //创建一个SecondScene类的对象layer
    auto layer = SecondScene::create();
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
bool SecondScene::init() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Label* label = Label::createWithTTF("CLUBS-K", "fonts/Marker Felt.ttf", 24);
    label->setPosition(
        Vec2(
            origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height
        )
    );

    this->addChild(label);	// 默认z-order=0
    /*auto sprite = Sprite::create("1.png");
    if (sprite == nullptr)
    {
        problemLoading("1.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + origin.y));
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
    auto mySprite = Sprite::create("2.png");
    if (mySprite == nullptr)
    {
        problemLoading("2.png");
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
    }*/
    return true;
}

