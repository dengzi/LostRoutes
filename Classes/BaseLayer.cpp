#include "BaseLayer.h"

USING_NS_CC;

 bool BaseLayer::init()
 {
	 if (!Layer::init())
	 {
		 return false;
	 }
	 Size visibleSize = Director::getInstance()->getVisibleSize();
	 Vec2 origin = Director::getInstance()->getVisibleOrigin();
	// SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");

	 auto bg = TMXTiledMap::create("map/red_bg.tmx");
	 this->addChild(bg);

	/* auto logo = Sprite::createWithSpriteFrameName("logo.png");
	 this->addChild(logo);
	 logo->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

	 auto sprite = Sprite::createWithSpriteFrameName("loding4.png");
	 this->addChild(sprite);
	 sprite->setPosition(logo->getPosition() - Vec2(0,logo->getContentSize().height/2 +30));*/

	 auto glasssprite = Sprite::createWithSpriteFrameName("setting.glasses.png");
	 glasssprite->setPosition(Vec2(visibleSize.width - glasssprite->getContentSize().width/2,160));
	 addChild(glasssprite);

	 auto handSprite = Sprite::createWithSpriteFrameName("setting.hand.png");
	 handSprite->setPosition(Vec2(handSprite->getContentSize().width/2,60));
	 addChild(handSprite);

	 auto okNormal = Sprite::createWithSpriteFrameName("setting.button.ok.png");
	 auto okSelected = Sprite::createWithSpriteFrameName("setting.button.ok-on.png");

	 auto okMenuItem = MenuItemSprite::create(okNormal,okSelected,CC_CALLBACK_1(BaseLayer::menuBackCallback,this));
	 auto mu = Menu::create(okMenuItem,NULL);
	 mu->setPosition(Vec2(visibleSize.width - mu->getContentSize().width/2 + 60,60));
	 addChild(mu);

	 return true;

 }
 void BaseLayer::onEnterTransitionDidFinish()
 {
	Layer::onEnterTransitionDidFinish();
	log("BaseLayer onEnterTransisionDidFinish");
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1,true);
	}
 }
 void BaseLayer::menuBackCallback(cocos2d::Ref *psender)
 {
	 Director::getInstance()->popScene();
	 if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
	 {
		 SimpleAudioEngine::getInstance()->playEffect(sound_1);
	 }
 }