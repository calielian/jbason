#ifndef UI_HPP
#define UI_HPP

#include <ncurses.h>
#include <menu.h>

void draw_app_name();

class Menu {
    public:
        int width, height, menu_itens_count;

        Menu();
        ~Menu();

        MENU *get_menu();
    private:
        MENU *menu;
        ITEM **menu_items;
};

#endif // UI_HPP