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

	std::string sMap1 =		"111111111111111111111111" 
							"100000000000000000000001" 
							"101111111111111111111101"
							"100000000000000000000001"
							"101111111111111111111101"
							"100000000000000000000001"
							"100000110011001100000001"
							"100000100000000100000001"
							"100000111111111100000001"
							"100000000000000000000001"
							"101111111111111111111101"
							"100000000000000000000001"
							"101111111111111111111101"
							"100010000001100011000001"
							"100000011000001000001001" 
							"111111111111111111111111" ;

	int size = 40;
	int k = 0;
	for (int i = 15; i >= 0; --i) 
	{
		for (int j = 0; j < 24; ++j) 
		{
			if ( sMap1.at(k) == '1')
			{
				std::string sPathWall = "sprites/wall.png";
				CCSprite* p_pSprite = p_pSprite = CCSprite::create(sPathWall);
				p_pSprite->setPosition((j*size) + size/2, i*size + size/2);
				addChild(p_pSprite);
				NSEntity* pWall = NSEntityFactory::CreateWall(p_pSprite, j, i);
				m_lEntities.push_back(pWall);
			}
			else
			if ( sMap1.at(k) == '0')
			{
				std::string sPathEmpty = "sprites/empty.png";
				CCSprite* p_pSprite = p_pSprite = CCSprite::create(sPathEmpty);
				p_pSprite->setPosition((j*size) + size/2, (i*size) + size/2);
				addChild(p_pSprite);
				NSEntity* pEmpty = NSEntityFactory::CreateEmpty(p_pSprite, j, i);;
				m_lEntities.push_back(pEmpty);
			}
			k++;
		}
	}

	std::string sPathHero = "sprites/hero.png";
	CCSprite* p_pSprite = CCSprite::create(sPathHero);
	p_pSprite->setPosition((1*size) + size/2, (5*size) + size/2);
	int v = p_pSprite->getPositionY();
	addChild(p_pSprite);
	NSEntity* pHero = NSEntityFactory::CreateHero(p_pSprite, 1, 5);
	m_lEntities.push_back(pHero);

	std::string sPathEnemy1 = "sprites/enemy1.png";
	p_pSprite = CCSprite::create(sPathEnemy1);
	addChild(p_pSprite);
	NSEntity* pEnemy1 = NSEntityFactory::CreateEnemy(p_pSprite, 10, 8);
	p_pSprite->setPosition((10*size) + size/2, (8*size) + size/2);
	m_lEntities.push_back(pEnemy1);

	std::string sPathEnemy2 = "sprites/enemy2.png";
	p_pSprite = CCSprite::create(sPathEnemy2);
	addChild(p_pSprite);
	NSEntity* pEnemy2 = NSEntityFactory::CreateEnemy(p_pSprite, 14, 8);
	p_pSprite->setPosition((14*size) + size/2, (8*size) + size/2);
	m_lEntities.push_back(pEnemy2);

	std::string sPathEnemy3 = "sprites/enemy3.png";
	p_pSprite = CCSprite::create(sPathEnemy3);
	addChild(p_pSprite);
	NSEntity* pEnemy3 = NSEntityFactory::CreateEnemy(p_pSprite, 11, 8);
	p_pSprite->setPosition((11*size) + size/2, (8*size) + size/2);
	m_lEntities.push_back(pEnemy3);

	std::string sPathEnemy4 = "sprites/enemy4.png";
	p_pSprite = CCSprite::create(sPathEnemy4);
	addChild(p_pSprite);
	NSEntity* pEnemy4 = NSEntityFactory::CreateEnemy(p_pSprite, 12, 8);
	p_pSprite->setPosition((12*size) + size/2, (8*size) + size/2);
	m_lEntities.push_back(pEnemy4);



	////create Systems
	//not needed be cause cocos2d.x draw auto the sprite when addChild
	/* 
	NSGraphicSystem* pGraphicSystem = new NSGraphicSystem(); 
	Add(pGraphicSystem);
	*/
	NSInputActionSystem* pInputActionSystem = new NSInputActionSystem(m_pListPressedKey, m_pListReleasedKey); 
	m_vSystems.push_back(pInputActionSystem);
	NSIAActionSystem* pIAActionSystem = new NSIAActionSystem(); 
	m_vSystems.push_back(pIAActionSystem);
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
	//CCLog("test");
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