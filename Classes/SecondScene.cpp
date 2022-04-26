#include "SecondScene.h"

USING_NS_CC;

Scene* SecondScene::createScene() {
    //����һ��Scene��Ķ���scene
    auto scene = Scene::create();
    //����һ��SecondScene��Ķ���layer
    auto layer = SecondScene::create();
    //��layer��ӵ�scene��
    scene->addChild(layer);
    //����scene
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

    Label* label = Label::createWithTTF("Second Test", "fonts/Marker Felt.ttf", 24);
    label->setPosition(
        Vec2(
            origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height
        )
    );

    this->addChild(label);	// Ĭ��z-order=0

    return true;
}

