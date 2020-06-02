// Menu.h for Graphics

#ifndef MENU_H
#define MENU_H

#include "oxygine-framework.h"
#include "../ViewHelper.h"
#include "../Presenter/Game_presenter.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Menu, spMenu)
    class Menu : public oxygine::EventDispatcher
    {
        private:
            int shift;
            Vector2 size;
            Vector2 display;
            pair<int, int> position;
            spSprite background;
            spSprite menu;
            spSprite pause_button;
            spSprite start_button;
            spTextField timer_sprite;
            spSprite settings_buttons;
            TextStyle text_style;
            class Timer
            {
                public:
                    time_t start_point;
                    time_t end_point;
                    time_t interval;
                    string now;
                    Timer(int new_interval)
                    {
                        interval = new_interval * 60;
                        start_point = time(NULL);
                        end_point = start_point + interval;
                        update();
                    };
                    void update()
                    {
                        now = ViewHelper::getTimeStringFromTimestamp(time(NULL), start_point);
                    };
            };
            Timer* timer;
            bool start_flag;
            bool pause_flag;
            bool stop_flag;
            bool timer_flag;
            int counter;
            int start_point;
            int end_point;
            int interval;
            size_t map_choise_x;
            size_t map_choise_y;
        public:
            Menu(oxygine::Point display_size);
            void show_start_button(oxygine::spActor actor);
            void show_pause_menu(oxygine::spActor actor);
            void show_timer(oxygine::spActor actor);
            void hide_start_button(oxygine::spActor actor);
            void create_background(Point display_size);
            void create_start_button();
            void create_timer();
            void create_text_style();
            void create_settings_buttons();
            void update_timer(oxygine::spActor actor); 
            size_t return_field_x();
            size_t return_field_y();
            // void end_menu();
            bool get_start_flag();
            bool get_pause_flag();
            bool get_stop_flag();
    };
}
#endif // MENU_H
