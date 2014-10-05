#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "NSEngine.h"

#include <list>
#include <map>

#include "cocos2d.h"
using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	float m_fMoveDirectionX;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	virtual void update(float delta);
	virtual void draw(Renderer* renderer, const kmMat4& transform, uint32_t transformUpdated);

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

	static GameScene* me;

private:
	NSEngine* m_pEngine;
	std::list<cocos2d::EventKeyboard::KeyCode>* m_pListPressedKey;
	std::list<cocos2d::EventKeyboard::KeyCode>* m_pListReleasedKey;
	std::map<std::string,CCSprite*>* m_pMapSprites;
};

#endif // __GAME_SCENE_H__
