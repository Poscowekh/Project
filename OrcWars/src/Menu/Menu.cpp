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
        /*
        ResAnim* res_background = ViewHelper::res.getResAnim(("background"));
        background = new Sprite();
        background->setResAnim(res_background);
        */
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
        oxygine::spTextField text = new oxygine::TextField();
        /*text->setText("START");
        text->setColor(Color(0xFFFFFFFF));
        text->setSize(Vector2(size.x / 4, size.y / 4));
        text->setAnchor(0.5,0.5);
        text->setPosition(size.x / 2, size.y / 2);
        menu->addChild(text);*/
        start_button->addEventListener(TouchEvent::CLICK, [this](Event*){
            start_flag = true;
            counter = 0;
        }
        );
    }

    void Menu::create_pause_button()
    {
        ResAnim* res_pause_button = ViewHelper::res.getResAnim("pause_button");
        pause_button = new Sprite();
        pause_button->setResAnim(res_pause_button);
        pause_button->setPosition(size.x / 2 - shift / 2,0);
        pause_button->addEventListener(TouchEvent::CLICK, [this](Event*){
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
        actor->removeChild(menu);
        //actor->addChild(pause_button);
    }

    void Menu::hide_pause_button(oxygine::spActor actor)
    {
        actor->removeChild(pause_button);
        show_start_button(actor);
    }

    void Menu::create_timer()
    {
        timer = new TextField();
    }

    void Menu::update_time()
    {
        counter++;
        int seconds = counter % 60;
        int minutes = counter / 60;
    }
}
