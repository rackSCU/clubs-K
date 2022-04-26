#ifndef __THIRD_SCENE_H__
#define __THIRD_SCENE_H__

#include "cocos2d.h"

class ThirdScene : public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ThirdScene);
	//暂时不需要回调函数
};

#endif // __THIRD_SCENE_H__
#pragma once
