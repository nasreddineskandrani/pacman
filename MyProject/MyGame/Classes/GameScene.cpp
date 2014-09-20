#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_pHero = CCSprite::create("sprites/hero/pacman.png");
	m_pHero->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	m_pHero->setScale(0.3);

	this->addChild(m_pHero, 0);

	scheduleUpdate();
 }   
	
void GameScene::update(float delta)
{
	m_pHero->setPositionX(m_pHero->getPositionX()+2);
}

void GameScene::draw(Renderer* renderer, const kmMat4& transform, uint32_t transformUpdated)
{
	//can't custom draw with this approch 
	//http://stackoverflow.com/questions/25096181/custom-draw-sprite-in-cocos2dx-v3-2
	//m_pHero->draw(renderer, transform, transformUpdated);
}