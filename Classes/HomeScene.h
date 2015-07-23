typedef enum 
{
	MenuItemStart,
	MenuItemSetting,
	MenuItemHelp

}ActionType;

#include "cocos2d.h"
#include "SettingScence.h"
#include "HelpScene.h"
#include "GamePlayScene.h"
#include "SystemHeader.h"

class HomeMenuLayer: public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuItemCallback(cocos2d::Ref *psender);
	CREATE_FUNC(HomeMenuLayer);
};