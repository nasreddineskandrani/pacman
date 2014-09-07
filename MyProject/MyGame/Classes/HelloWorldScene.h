#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void addTarget();
	void spriteMoveFinished(CCNode* sender);
	void gameLogic(float dt);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	virtual void update(float delta);
	virtual void draw(Renderer* renderer, const kmMat4& transform, uint32_t transformUpdated);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
