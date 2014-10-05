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

	//keyboard handling 
	//http://discuss.cocos2d-x.org/t/tutorial-how-to-get-multi-platform-keyboard-events/9893/7
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create sprites
	m_pMapSprites = new std::map<std::string,CCSprite*>();
	std::string sPathHero = "sprites/hero/pacman.png";
	CCSprite* p_pSprite = CCSprite::create(sPathHero);
	p_pSprite->setPosition(440, 440);
	p_pSprite->setScale(0.3);
	(*m_pMapSprites)["HERO"] = p_pSprite;
	addChild(p_pSprite);

	m_pListPressedKey = new std::list<cocos2d::EventKeyboard::KeyCode>();
	m_pListReleasedKey = new std::list<cocos2d::EventKeyboard::KeyCode>();

	m_pEngine = new NSEngine(m_pMapSprites, m_pListPressedKey, m_pListReleasedKey);
	
	scheduleUpdate();
 }   

void GameScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	m_pListPressedKey->push_back(keyCode);
}

void GameScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	m_pListReleasedKey->push_back(keyCode);
}

void GameScene::update(float delta)
{
	m_pEngine->Update(delta);
	m_pListPressedKey->clear();
	m_pListReleasedKey->clear();
}

void GameScene::draw(Renderer* renderer, const kmMat4& transform, uint32_t transformUpdated)
{
	//can't custom draw with this approch 
	//http://stackoverflow.com/questions/25096181/custom-draw-sprite-in-cocos2dx-v3-2
	//m_pHero->draw(renderer, transform, transformUpdated);
}