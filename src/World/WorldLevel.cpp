#include <Geode/Geode.hpp>
#include "WorldLevel.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;


class WorldLevelPopup : public geode::Popup {
protected:
    bool setup(std::string const& value) {
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        this->setID("worldLevelPopup"_spr);
    
        this->setTitle("");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        label->setPosition(winSize / 2);
        this->addChild(label);

        return true;
    }

public:
    static WorldLevelPopup* create(std::string const& text) {
        auto ret = new WorldLevelPopup();

        
        if (ret && ret->init(300.f, 260.f) && ret->setup(text)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
