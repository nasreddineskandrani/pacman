#include "GameScene.h"
#include "NSEntityFactory.h"
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

	//keyboard handling 
	//http://discuss.cocos2d-x.org/t/tutorial-how-to-get-multi-platform-keyboard-events/9893/7
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	
	m_pListPressedKey = new std::list<cocos2d::EventKeyboard::KeyCode>();
	m_pListReleasedKey = new std::list<cocos2d::EventKeyboard::KeyCode>();

	////create sprites
	m_pMapSprites = new std::map<std::string,CCSprite*>();

	std::string sPathHero = "sprites/hero/pacman.png";
	CCSprite* p_pSprite = CCSprite::create(sPathHero);
	p_pSprite->setPosition(440, 440);
	p_pSprite->setScale(0.3);
	(*m_pMapSprites)["HERO"] = p_pSprite;
	addChild(p_pSprite);

	std::string sPathEnemy1 = "sprites/enemies/enemy1.png";
	p_pSprite = CCSprite::create(sPathEnemy1);
	p_pSprite->setPosition(580, 540);
	p_pSprite->setScale(0.6);
	(*m_pMapSprites)["Enemy1"] = p_pSprite;
	addChild(p_pSprite);

	////create Enteties
	NSEntity* pHero = NSEntityFactory::CreateHero((*m_pMapSprites)["HERO"]);
	NSEntity* pSecondHero = NSEntityFactory::CreateEnemy((*m_pMapSprites)["Enemy1"]);
	m_lEntities = std::list<NSEntity*>();
	m_lEntities.push_back(pHero);
	m_lEntities.push_back(pSecondHero);
	 
	////create Systems
	//not needed be cause cocos2d.x draw auto the sprite when addChild
	/* 
	NSGraphicSystem* pGraphicSystem = new NSGraphicSystem(); 
	Add(pGraphicSystem);
	*/
	NSInputActionSystem* pInputActionSystem = new NSInputActionSystem(m_pListPressedKey, m_pListReleasedKey); 
	m_vSystems.push_back(pInputActionSystem);
	NSSpeedDirectionSystem* pSpeedDirectionSystem = new NSSpeedDirectionSystem(); 
	m_vSystems.push_back(pSpeedDirectionSystem);
	NSCollisionSystem* pCollisionSystem= new NSCollisionSystem(); 
	m_vSystems.push_back(pCollisionSystem);
	NSMoveSystem* pMoveSystem = new NSMoveSystem(); 
	m_vSystems.push_back(pMoveSystem);
	
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
	for(unsigned i = 0; i < m_vSystems.size( ); ++i)
	{
		m_vSystems[i]->Update(delta, m_lEntities);
	}

	for(unsigned i = 0; i < m_vSystems.size( ); ++i)
	{
		m_vSystems[i]->Clear(delta, m_lEntities);
	}

	m_pListPressedKey->clear();
	m_pListReleasedKey->clear();
}

void GameScene::draw(Renderer* renderer, const kmMat4& transform, uint32_t transformUpdated)
{
	//can't custom draw with this approch 
	//http://stackoverflow.com/questions/25096181/custom-draw-sprite-in-cocos2dx-v3-2
	//m_pHero->draw(renderer, transform, transformUpdated);
}