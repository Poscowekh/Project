#ifndef EVENTS_H
#define EVENTS_H

using namespace std;
namespace OwnEvents
{
    enum KeyMoveEvent
    {
        KEY_MOVE_UP = oxygine::EventID('UP') oxygine::EventIDc11(str),
        KEY_MOVE_DOWN =
    };

    class KeyMoveEvent : public SDL_KeyboardEvent
    {
        public:
            Events();
            SDL_KeyboardEvent* data;
            KeyEvent(KEY_EVENT k, SDL_KeyboardEvent* d) : Event(k), data(d) {}

    };

#endif // EVENTS_H
