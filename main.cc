#include "include/parse.hpp"
#include "include/utils.hpp"
#include "include/operations.hpp"
#include "include/ui.hpp"

#include <ncurses.h>
#include <string>
#include <iostream>
#include <menu.h>

int main() {

    std::string select_test = "FROM table; SELECT number; WHERE number = 10";
    std::string insert_test = "INSERT_INTO table; VALUES {10, jane_doe, 40}";
    std::string create_test = "CREATE table; TYPE {int, string, int}; COLUMNS { number, name, other_number }";

    std::cout << select_column("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(select_test))) << std::endl;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(0);
	
    int terminal_max_y, terminal_max_x;
    int command;

    getmaxyx(stdscr,terminal_max_y, terminal_max_x);

    Menu *menu = new Menu();

    const int WIN_MENU_HEIGHT = menu->height * 2, WIN_MENU_WIDTH = menu->width + 5, WIN_MENU_PADDING = 2;

    WINDOW *win_menu = newwin(WIN_MENU_HEIGHT, WIN_MENU_WIDTH, (terminal_max_y - WIN_MENU_HEIGHT )/2, (terminal_max_x - WIN_MENU_WIDTH)/2);
    set_menu_win(menu->get_menu(), win_menu);
    set_menu_sub(menu->get_menu(), derwin(win_menu, menu->height, menu->width + 1, WIN_MENU_PADDING, WIN_MENU_PADDING));
    set_menu_mark(menu->get_menu(), "> ");

    draw_app_name();
    move(terminal_max_y/2, 0);

    keypad(win_menu, TRUE);
    box(win_menu, 1, 0);
    mvwaddstr(win_menu, 0, (WIN_MENU_WIDTH - strlen("Main Menu") - 1)/2 , "Main Menu");

    post_menu(menu->get_menu());

    wrefresh(win_menu);
    refresh();

    while (true) {
        command = wgetch(win_menu);

        switch (command) {
            case KEY_DOWN: menu_driver(menu->get_menu(), REQ_DOWN_ITEM); break;
            case KEY_UP: menu_driver(menu->get_menu(), REQ_UP_ITEM); break;
            default: goto END;
        }

        wrefresh(win_menu);
        refresh();
    }
    END:

    unpost_menu(menu->get_menu());
    delete menu;
    delwin(win_menu);
    endwin();


    // std::cout << insert_table("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(insert_test))) << std::endl;

    // std::cout << create_database("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(create_test))) << std::endl;

    /*
    auto command_parsed = parse_command(trim_string(select_test));
    
    if (command_parsed.empty()) {
        std::cout << "Command parsed is empty" << std::endl;
    }

    for (auto it = command_parsed.begin(); it != command_parsed.end(); it++) {
        std::cout << "Key:" << '\'' << it->first << '\'' << std::endl;

        for (std::string value : it->second) {
            std::cout << "Values:" << '\'' << value << '\'' << std::endl;
        }
    }
    */
    return 0;
}