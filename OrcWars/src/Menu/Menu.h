// Menu.h for Graphics

#ifndef MENU_H
#define MENU_H

#include "oxygine-framework.h"
#include "../ViewHelper.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Menu, spMenu)
    class Menu : public oxygine::EventDispatcher
    {
        private:
            int shift;
            Vector2 size;
            pair<int, int> position;
            spSprite background;
            spSprite menu;
            spSprite pause_button;
            spSprite start_button;
            spTextField timer;
            bool start_flag;
            bool pause_flag;
            bool stop_flag;
            int counter;
        public:
            Menu(oxygine::Point display_size);
            void show_start_button(oxygine::spActor actor);
            void show_pause_menu(oxygine::spActor actor);
            void show_pause_button(oxygine::spActor actor);
            void hide_start_button(oxygine::spActor actor);
            void hide_pause_button(oxygine::spActor actor);
            void create_background(Point display_size);
            void create_start_button();
            void create_pause_button();
            void create_timer();
            void update_time();
            // void end_menu();
            bool get_start_flag();
            bool get_pause_flag();
            bool get_stop_flag();
    };
}
#endif // MENU_H
