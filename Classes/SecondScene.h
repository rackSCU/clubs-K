#ifndef __SECOND_SCENE_H__
#define __SECOND_SCENE_H__

#include "cocos2d.h"

class SecondScene : public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SecondScene);
	//暂时不需要回调函数
};

#endif // __SECOND_SCENE_H__
