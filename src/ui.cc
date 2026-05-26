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

Menu::Menu() {
    const char *item_text_description[5][2] {
        // Item text, item description
        "Query table content", "Write SELECT statements",
        "Insert new values into table", "Write INSERT_INTO statements",
        "Create new tables", "Write CREATE statements",
        "Create a new database", "Create a new database",
        "Exit JbaSON", "Close JbaSON"
    };

    menu_itens_count = sizeof(item_text_description) / sizeof(item_text_description[0]);

    menu_items = (ITEM **) calloc(menu_itens_count + 1, sizeof(ITEM *));

    for (int i = 0; i < menu_itens_count; i++) {
        menu_items[i] = new_item(item_text_description[i][0], item_text_description[i][1]);
    }

    menu = new_menu(menu_items);
    set_menu_mark(menu, "> ");

    scale_menu(menu, &height, &width);
}

Menu::~Menu() {
    free_menu(menu);
    
    for (int i = 0; i < menu_itens_count; i++) {
        free_item(menu_items[i]);
    }

    free(menu_items);
}

MENU *Menu::get_menu() {
    return menu;
}