#ifndef __SettingScence_H__
#define __SettingScence_H__

#include "cocos2d.h"
#include "SystemHeader.h"
#include "MyUtility.h"
#include "BaseLayer.h"

class SettingLayer : public BaseLayer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuSoundToggleCallback(cocos2d::Ref *psender);
	void menuMusicToggleCallback(cocos2d::Ref *psender);

	CREATE_FUNC(SettingLayer);
};
#endif // !__SettingScence_H__
