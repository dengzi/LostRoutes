#include "HomeScene.h"

USING_NS_CC;

Scene *HomeMenuLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = HomeMenuLayer::create();
	scene->addChild(layer);
	return scene;
}

bool HomeMenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto bg = TMXTiledMap::create("map/rred_bg.tmx");
	addChild(bg);
	auto top = Sprite::createWithSpriteFrameName("home-top.png");
	top->setPosition(Vec2(visibleSize.width/2,visibleSize.height - top->getContentSize().height/2));
	addChild(top);

	auto end = Sprite::createWithSpriteFrameName("home-end.png");
	end->setPosition(Vec2(visibleSize.width/2,end->getContentSize().height/2));
	addChild(end);

	auto startSpriteNormal = Sprite::createWithSpriteFrameName("home.button.start.png");
	auto startSpriteSelected = Sprite::createWithSpriteFrameName("home.button.start-on.png");
	auto startmenuItem = MenuItemSprite::create(startSpriteNormal,startSpriteSelected,CC_CALLBACK_1(HomeMenuLayer::menuItemCallback,this));
	startmenuItem->setTag(ActionType::MenuItemStart);

	auto settingSpriteNormal = Sprite::createWithSpriteFrameName("home.button.setting.png");
	auto settingSpriteSelected = Sprite::createWithSpriteFrameName("home.button.setting-on.png");
	auto settingmenuItem = MenuItemSprite::create(settingSpriteNormal,settingSpriteSelected,CC_CALLBACK_1(HomeMenuLayer::menuItemCallback,this));
	settingmenuItem->setTag(ActionType::MenuItemSetting);

	auto helpSpriteNormal = Sprite::createWithSpriteFrameName("home.button.help.png");
	auto helpSpriteSelected = Sprite::createWithSpriteFrameName("home.button.help-on.png");
	auto helpmenuItem = MenuItemSprite::create(helpSpriteNormal,helpSpriteSelected,CC_CALLBACK_1(HomeMenuLayer::menuItemCallback,this));
	helpmenuItem->setTag(ActionType::MenuItemHelp);

	auto menu = Menu::create(startmenuItem,settingmenuItem,helpmenuItem,NULL);
	menu->setPosition(visibleSize.width/2,visibleSize.height/2);
	menu->alignItemsVerticallyWithPadding(12); //Ö¸¶¨¼ä¸ô
	addChild(menu);

	return true;
}

void HomeMenuLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HomeMenuLayer onEnterTransitionDidFinish");
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1,true);

	}
}

void HomeMenuLayer::menuItemCallback(cocos2d::Ref *psender)
{
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
	{
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
	Scene *tec = nullptr;

	MenuItem *menuItem = (MenuItem*)psender;
	log("MenuItemTag = %d",menuItem->getTag());
	switch (menuItem->getTag())
	{
	case ActionType::MenuItemStart:
		{
			tec = TransitionFade::create(1.0f,GamePlayLayer::CreateScalableFontResource());
			log("startCallback");
			break;
		}
	case ActionType::MenuItemSetting:
		{
			
			tec = TransitionFade::create(1.0f,SettingLayer::createScene());
			log("settingCallback");
			break;
		}
	case ActionType::MenuItemHelp:
		{
			tec = TransitionFade::create(1.0f,HelpLayer::createScene());
			log("helpCallback");
			break;
		}
	default:
		break;
	}
	if (tec)
	{
		Director::getInstance()->pushScene(tec);
	}
}