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
        map_choise_x = 16;
        map_choise_y = 9;
        create_start_button();
        create_background(display_size);
        create_text_style();
        create_settings_buttons();
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
        start_button->setPosition(size.x / 2 + shift / 2, size.y / 3);
        start_button->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            start_flag = true;
        }
        );
        //create_map_buttons();
    }

    size_t Menu::return_field_x()
    {
        return map_choise_x;
    }

    size_t Menu::return_field_y()
    {
        return map_choise_y;
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
        actor->addChild(settings_buttons);
    }

    void Menu::hide_start_button(oxygine::spActor actor)
    {
        actor->removeChild(start_button);
        actor->removeChild(menu);
        actor->removeChild(settings_buttons);
    }

    void Menu::create_text_style()
    {
        text_style.font = ViewHelper::res.getResFont("font");
        text_style.fontSize = 40 * 640 / display.y;
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
        timer_sprite->setPosition((display.x - shift) / 2, shift / 3);
        timer_sprite->setText(timer->now);
    };

    void Menu::create_settings_buttons()
    {
        settings_buttons = new Sprite();
        settings_buttons->setSize(size.x / 2, size.y / 2);
        settings_buttons->setAnchor(0.5,0.5);
        settings_buttons->setPosition(size.x / 2 + shift / 2, size.y / 3 * 2 + shift / 2);
        spTextField x_text = new TextField();
        x_text->setAnchor(0.5,0.5);
        x_text->setPosition(settings_buttons->getSize().x / 2, settings_buttons->getSize().y / 3);
        x_text->setStyle(text_style);
        x_text->setText(to_string(map_choise_x));
        x_text->attachTo(settings_buttons);
        spTextField y_text = new TextField();
        y_text->setAnchor(0.5,0.5);
        y_text->setPosition(settings_buttons->getSize().x / 2, settings_buttons->getSize().y / 3 * 2);
        y_text->setStyle(text_style);
        y_text->setText(to_string(map_choise_y));
        y_text->attachTo(settings_buttons);
        ResAnim* button = ViewHelper::res.getResAnim(("right_button"));
        spSprite button1 = new oxygine::Sprite();
        button1->setAnchor(0.5,0.5);
        button1->setResAnim(button);
        button1->setPosition(settings_buttons->getSize().x / 4 * 3, settings_buttons->getSize().y / 3);
        button1->setSize(settings_buttons->getSize() / 8);
        button1->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            if(map_choise_x < 20)// && map_choise_y * 4 < map_choise_x)
                map_choise_x++;
            else
                map_choise_x = 8;
        }
        );
        button1->attachTo(settings_buttons);
        spSprite button3 = new oxygine::Sprite();
        button3->setAnchor(0.5,0.5);
        button3->setResAnim(button);
        button3->setPosition(settings_buttons->getSize().x / 4, settings_buttons->getSize().y / 3);
        button3->setSize(settings_buttons->getSize() / 8);
        button3->setRotationDegrees(180);
        button3->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            if(map_choise_x > 8)// && map_choise_y < map_choise_x / 3 * 2)
                map_choise_x--;
            else
                map_choise_x = 20;
        }
        );
        button3->attachTo(settings_buttons);
        spSprite button2 = new oxygine::Sprite();
        button2->setAnchor(0.5,0.5);
        button2->setResAnim(button);
        button2->setPosition(settings_buttons->getSize().x / 4 * 3, settings_buttons->getSize().y / 3 * 2);
        button2->setSize(settings_buttons->getSize() / 8);
        button2->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            if(map_choise_y < 16)// && map_choise_x > map_choise_y / 3 * 2)
                map_choise_y++;
            else
                map_choise_y = 8;
        }
        );
        button2->attachTo(settings_buttons);
        spSprite button4 = new oxygine::Sprite();
        button4->setAnchor(0.5,0.5);
        button4->setResAnim(button);
        button4->setRotationDegrees(180);
        button4->setPosition(settings_buttons->getSize().x / 4, settings_buttons->getSize().y / 3 * 2);
        button4->setSize(settings_buttons->getSize() / 8);
        button4->addEventListener(TouchEvent::CLICK, [this](Event*)
        {
            if(map_choise_y > 8)// && map_choise_x < map_choise_y / 3 * 2)
                map_choise_y--;
            else
                map_choise_y = 16;
        }
        );
        button4->attachTo(settings_buttons);
    }

    void Menu::show_timer(oxygine::spActor actor)
    {
        //actor->removeChild(timer_sprite);
        timer_sprite->setText(timer->now);
        //actor->addChild(timer_sprite);
    };

    void Menu::update_timer(oxygine::spActor actor)
    {
        if(!timer_flag)
        {
            timer = new Timer(1);
            create_timer();
            actor->addChild(timer_sprite);
        }
        if(time(NULL) <= timer->end_point)
        {
            timer->update();
        }
    }
}
