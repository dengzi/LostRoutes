#include "HelpScene.h"
USING_NS_CC;


Scene *HelpLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = HelpLayer::create();
	scene->addChild(layer);
	return scene;
}

bool HelpLayer::init()
{

	if (!BaseLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto top = Sprite::createWithSpriteFrameName("help-top.png");
	top->setPosition(Vec2(visibleSize.width/2,visibleSize.height - top->getContentSize().height/2));
	addChild(top);

	auto textTest = Label::createWithTTF(MyUtility::getUTF8Char("test"),"fonts/hanyi.ttf",18);
	textTest->setColor(Color3B(14,83,204));
	textTest->setPosition(95,top->getPosition().y - 70);
	textTest->setAnchorPoint(Vec2(0,0));
	addChild(textTest,1);

	auto test = Label::createWithTTF("51work6","fonts/hanyi.tts",18);
	test->setAnchorPoint(Vec2(0,0));
	Vec2 p1 = textTest->convertToWorldSpace(Vec2(0,-20));
	test->setColor(Color3B(198,12,0));
	test->setPosition(p1);
	addChild(test,1);

	auto txtMusic = Label::createWithTTF(MyUtility::getUTF8Char("music"),"fonts/hanyi.tts",18);
	txtMusic->setAnchorPoint(Vec2(0,0));
	Vec2 p2 = test->convertToWorldSpace(Vec2(0,-40));
	txtMusic->setColor(Color3B(14,83,204));
	txtMusic->setPosition(p2);
	addChild(txtMusic,1);

	auto music1 = Label::createWithTTF("Mr.Guan","fonts/hanyi.tts",18);
	music1->setAnchorPoint(Vec2(0,0));
	Vec2 p3 = txtMusic->convertToWorldSpace(Vec2(0,-20));
	music1->setColor(Color3B(198,12,0));
	music1->setPosition(p3);
	addChild(music1,1);

	auto music2 = Label::createWithTTF("YunLong","fonts/hanyi.tts",18);
	music2->setAnchorPoint(Vec2(0,0));
	Vec2 p4 = music1->convertToWorldSpace(Vec2(0,-20));
	music2->setColor(Color3B(198,12,0));
	music2->setPosition(p4);
	addChild(music2,1);

	auto txtSound = Label::createWithTTF(MyUtility::getUTF8Char("sound"),"fonts/hanyi.tts",18);
	txtSound->setAnchorPoint(Vec2(0,0));
	Vec2 p5 = music2->convertToWorldSpace(Vec2(0,-40));
	txtSound->setColor(Color3B(14,83,204));
	txtSound->setPosition(p5);
	addChild(txtSound,1);

	auto sound1 = Label::createWithTTF("Mr.zhao","fonts/hanyi.tts",18);
	sound1->setAnchorPoint(Vec2(0,0));
	Vec2 p6 = txtSound->convertToWorldSpace(Vec2(0,-20));
	sound1->setColor(Color3B(198,12,0));
	sound1->setPosition(p6);
	addChild(sound1,1);

	auto sound2 = Label::createWithTTF("YunLong","fonts/hanyi.tts",18);
	sound2->setAnchorPoint(Vec2(0,0));
	Vec2 p7 = sound1->convertToWorldSpace(Vec2(0,-20));
	sound2->setColor(Color3B(198,12,0));
	sound2->setPosition(p7);
	addChild(sound2,1);

	auto txtInfoService = Label::createWithTTF(MyUtility::getUTF8Char("info_service"),"fonts/hanyi.tts",18);
	txtInfoService->setAnchorPoint(Vec2(0,0));
	Vec2 p8 = sound2->convertToWorldSpace(Vec2(0,-40));
	txtInfoService->setColor(Color3B(14,83,204));
	txtInfoService->setPosition(p8);
	addChild(txtInfoService,1);

	auto infoService = Label::createWithTTF("www.51work6.com","fonts/hanyi.tts",18);
	infoService->setAnchorPoint(Vec2(0,0));
	Vec2 p9 = txtInfoService->convertToWorldSpace(Vec2(0,-20));
	infoService->setColor(Color3B(198,12,0));
	infoService->setPosition(p9);
	addChild(infoService,1);

	return true;
}

