#include "player.h"
#include "../../console/console.h"
#include <iostream>

player::player()
{
}

player::~player()
{
}

void player::draw()
{
    auto print = [](i16 w, i16 h, const char *txt) {
        cls::gotoxy(w, h);
        std::cout << txt;
    };

    const char *a = R"( @ )";
    const char *b = R"(/|\)";
    const char *c = R"(/ \)";

    i16 w = get_pos();

    print(w, 0, a);
    print(w, 1, b);
    print(w, 2, c);
}

i16 player::get_pos()
{
    return i16();
}

i16 player::get_width()
{
    return i16();
}
