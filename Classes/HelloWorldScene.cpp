#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist"); //会自动加载一个同名.png的纹理文件

	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);

	auto logo = Sprite::createWithSpriteFrameName("logo.png");
	this->addChild(logo);
	logo->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

	auto sprite = Sprite::createWithSpriteFrameName("loading4.png");
	this->addChild(sprite);
	sprite->setPosition(logo->getPosition() - Vec2(0,logo->getContentSize().height/2 + 30));

	////////////////////////loading animation///////////////////////////

	Animation *animation = Animation::create();
	for (int i = 1;i<=4;i++)
	{
		__String *frameName = __String::createWithFormat("loading%d.png",i);
		log("frameName = %s",frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.5f); //两帧播放时间
	animation->setRestoreOriginalFrame(true);// 动画执行后恢复原来状态
	Animate *action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));
	

	/////////////////////// 纹理缓存异步加载

	m_nNumberOfLoaded = 0;

	Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png",CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png",CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png",CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));


	///////////////////////////异步预处理声音
    _loadingAudioThread = new std::thread(&HelloWorld::loadingAudio,this);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object
 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = LabelTTF::create("Hello World", "Arial", 24);
    //
    //// position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    //// add the label as a child to this layer
    //this->addChild(label, 1);

    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //// position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //// add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::loadingTextureCallBack(cocos2d::Texture2D *texture)
{
	switch (m_nNumberOfLoaded++)
	{
	case 0:
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist",texture);
		    log("home texture ok");
			break;
		}
	case 1:
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist",texture);
			log("setting texture ok");
			break;
	
		}
	case 2:
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist",texture);
			log("gameplay texture ok");
			this->schedule(schedule_selector(HelloWorld::delayCall),1,1,3);
			break;
		}
	default:
		break;
	}
}

void HelloWorld::delayCall(float dt)
{
auto sc = HomeMenuLayer::CreateScene();
Director::getInstance()->replaceScene(sc);
}

void HelloWorld::loadingAudio()
{
	log("loading audio");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);

}

void HelloWorld::onExit()
{
	Layer::onExit();
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(HelloWorld::delayCall));
}