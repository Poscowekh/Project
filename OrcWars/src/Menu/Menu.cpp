// Menu.cpp for Graphics

#include "Menu.h"

namespace GameGraphics
{
    Menu::Menu(oxygine::Point display_size)
    {
        shift = 40;
        display = display_size;
        size = Vector2(display_size.x - shift * 2, display_size.y - shift * 2);
        menu = new ColorRectSprite();
        menu->setSize(size);
        menu->setPosition(shift,shift);
        menu->setColor(Color(0x869CB5FF));
        start_flag = false;
        timer_flag = false;
        create_start_button();
        create_background(display_size);
    }

    void Menu::create_background(Point display_size)
    {
        background = new ColorRectSprite();
        spColorRectSprite tmp = new ColorRectSprite();
        tmp->setSize(display_size.x - 2 * shift + 8, display_size.y - 2 * shift + 8);
        tmp->setPosition(shift - 4, shift - 4);
        tmp->setColor(Color(0x3B2505FF));
        tmp->attachTo(background);
        background->setColor(Color(0x855000FF));
        background->setSize(display_size);
    }

    void Menu::create_start_button()
    {
        start_flag = false;
        ResAnim* res_button = ViewHelper::res.getResAnim(("start_button"));
        start_button = new oxygine::Sprite();
        oxygine::Point sprite_size(size.x / 2, size.y / 2);
        start_button->setAnchor(0.5,0.5);
        start_button->setResAnim(res_button);
        start_button->setPosition(size.x / 2 + shift / 2, size.y / 2);
        start_button->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            start_flag = true;
        }
        );
    }

    bool Menu::get_start_flag()
    {
        return start_flag;
    }

    bool Menu::get_stop_flag()
    {
        return stop_flag;
    }

    void Menu::show_start_button(oxygine::spActor actor)
    {
        actor->addChild(background);
        actor->addChild(menu);
        actor->addChild(start_button);
    }

    void Menu::hide_start_button(oxygine::spActor actor)
    {
        actor->removeChild(start_button);
        actor->removeChild(menu);
    }

    void Menu::create_text_style()
    {
        text_style.font = ViewHelper::res.getResFont("main");
        text_style.fontSize = 18;
        text_style.color = Color(0xFFFFFFFF);
        text_style.vAlign = TextStyle::VALIGN_MIDDLE;
        text_style.hAlign = TextStyle::HALIGN_MIDDLE;
    };

    void Menu::create_timer()
    {
        timer_flag = true;
        timer_sprite = new TextField();
        timer_sprite->setStyle(text_style);
        timer_sprite->setAnchor(0.5,0.5);
        timer_sprite->setPosition(display.x / 2, shift / 2);
        timer_sprite->setText(timer->now);
    };

    void Menu::create_end_menu()
    {

    }

    void Menu::show_timer(oxygine::spActor actor)
    {
        //actor->removeChild(timer_sprite);
        create_timer();
        actor->addChild(timer_sprite);
    };

    void Menu::update_timer(oxygine::spActor actor)
    {
        if(!timer_flag)
            timer = new Timer(1);
        if(time(NULL) <= timer->end_point)
        {
            timer->update();
        }
    }
}
