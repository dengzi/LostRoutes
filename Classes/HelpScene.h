#ifndef __HelpScene_H__
#define __HelpScene_H__

#include "cocos2d.h"
#include "BaseLayer.h"
#include "SystemHeader.h"
#include "MyUtility.h"

class HelpLayer : public BaseLayer
{
public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(HelpLayer);
};
#endif // !__HelpScene_H__
