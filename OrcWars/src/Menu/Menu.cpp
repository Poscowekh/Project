// Menu.cpp for Graphics

#include "Menu.h"

namespace GameGraphics
{
    Menu::Menu(oxygine::Point display_size)
    {
        shift = 40;
        size = Vector2(display_size.x - shift * 2, display_size.y - shift * 2);
        menu = new ColorRectSprite();
        menu->setSize(size);
        menu->setPosition(shift,shift);
        menu->setColor(Color(0x869CB5FF));
        start_flag = false;
        timer_flag = false;
        create_start_button();
        create_pause_button();
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

    void Menu::create_pause_button()
    {
        ResAnim* res_pause_button = ViewHelper::res.getResAnim("pause_button");
        pause_button = new Sprite();
        pause_button->setResAnim(res_pause_button);
        pause_button->setPosition(size.x / 2 - shift / 2,0);
        pause_button->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            pause_flag = true;
            start_flag = false;
        }
        );
    }

    bool Menu::get_start_flag()
    {
        return start_flag;
    }

    bool Menu::get_pause_flag()
    {
        return pause_flag;
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

    void Menu::show_pause_button(oxygine::spActor actor)
    {
        actor->addChild(pause_button);
    }

    void Menu::hide_start_button(oxygine::spActor actor)
    {
        //actor->removeChild(background);
        actor->removeChild(start_button);
        actor->removeChild(menu);
        //actor->addChild(pause_button);
    }

    void Menu::hide_pause_button(oxygine::spActor actor)
    {
        actor->removeChild(pause_button);
        show_start_button(actor);
    }

    bool Menu::create_timer()
    {
        start_point = time(NULL);
        interval = 5 * 60;
        end_point = start_point + interval;
    }

    void Menu::update_time()
    {
        start_point = time(NULL);
        interval = 5 * 60;
        end_point = start_point + interval;
        int seconds = counter % 60;
        int minutes = counter / 60;
    }
}
