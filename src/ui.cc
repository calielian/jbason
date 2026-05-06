#include "../include/ui.hpp"
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <menu.h>

// move(y, x)

void draw_app_name() {
    const std::string APP_NAME { "JbaSON" };
    const int SPACE = 8;
    const int BOX_HORIZONTAL_SIZE = APP_NAME.length() - 1 + SPACE*2;
    int x { 0 }, y { 1 };

    addch(ACS_ULCORNER);
    for (int i = 0; i < BOX_HORIZONTAL_SIZE; i++) {
        addch(ACS_HLINE);
    }
    addch(ACS_URCORNER);
    move(y, x);

    addch(ACS_VLINE);
    x += SPACE;
    move(y, x);
    printw("%s", APP_NAME.c_str());
    x = BOX_HORIZONTAL_SIZE + 1;
    move(y, x);
    addch(ACS_VLINE);

    x = 0;
    y++;
    move(y, x);
    addch(ACS_LLCORNER);
    for (int i = 0; i < BOX_HORIZONTAL_SIZE; i++) {
        addch(ACS_HLINE);
    }
    addch(ACS_LRCORNER);

    refresh();
}

MENU *create_main_menu() {
    const char *item_text_description[4][2] {
        // Item text, item description
        "Query table content", "Write SELECT statements",
        "Insert new values into table", "Write INSERT_INTO statements",
        "Create new tables", "Write CREATE statements",
        "Create a new database", "Create a new database"
    };

    ITEM **items = (ITEM **) calloc(4, sizeof(ITEM *));

    for (int i = 0; i < 4; i++) {
        items[i] = new_item(item_text_description[i][0], item_text_description[i][1]);
    }

    return new_menu(items);
}