#include "cocos2d.h"
#include "SushiSprite.h"


USING_NS_CC;

#define TOTAL_SUSHI (7)

static const char *sushiNormal[TOTAL_SUSHI] = {
	"n_bmw.png",
	"n_mazda.png",
	"n_fiat.png",
	//"n_landrover.png",
	"n_saab.png",
    "n_vw.png",
	"n_alfa.png",
	"n_lambo.png"
};

static const char *sushiVertical[TOTAL_SUSHI] = {
	"n_bmw.png",
	"n_mazda.png",
	"n_fiat.png",
	//"n_landrover.png",
	"n_saab.png",
	"n_vw.png",
	"n_alfa.png",
	"n_lambo.png"

};

static const char *sushiHorizontal[TOTAL_SUSHI] = {
	"n_bmw.png",
	"n_mazda.png",
	"n_fiat.png",
	//"n_landrover.png",
	"n_saab.png",
	"n_vw.png",
	"n_alfa.png",
	"n_lambo.png"

};

float SushiSprite::getContentWidth()
{
    static float itemWidth = 0;
    if (0 == itemWidth) {
        Sprite *sprite = CCSprite::createWithSpriteFrameName(sushiNormal[0]);
        itemWidth = sprite->getContentSize().width;
    }
    return itemWidth;
}

SushiSprite::SushiSprite()
: m_col(0)
, m_row(0)
, m_imgIndex(0)
, m_isNeedRemove(false)
, m_ignoreCheck(false)
, m_displayMode(DISPLAY_MODE_NORMAL)
{
}

SushiSprite *SushiSprite::create(int row, int col)
{
	SushiSprite *sushi = new SushiSprite();
	sushi->m_row = row;
	sushi->m_col = col;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 
	srand(rand() + GetTickCount());
#else
	srand(rand() + 1199);
#endif
    sushi->m_imgIndex = rand() % TOTAL_SUSHI;
    sushi->initWithSpriteFrameName(sushiNormal[sushi->m_imgIndex]);
	sushi->autorelease();
	return sushi;
}

void SushiSprite::setDisplayMode(DisplayMode mode)
{
    m_displayMode = mode;
    
    SpriteFrame *frame;
    switch (mode) {
        case DISPLAY_MODE_VERTICAL:
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sushiVertical[m_imgIndex]);
            break;
        case DISPLAY_MODE_HORIZONTAL:
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sushiHorizontal[m_imgIndex]);
            break;
        default:
            return;
    }
    setDisplayFrame(frame);
}