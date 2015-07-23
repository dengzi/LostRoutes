#ifndef __BaseLayer_H__
#define __BaseLayer_H__

#include "cocos2d.h"
#include "SystemHeader.h"

class BaseLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuBackCallback(cocos2d::Ref *psender);
};
#endif // !__BaseLayer_H__
