#include "term-ui/inceptor.hpp"
#include "term-ui/error_codes.hpp"
#include <curses.h>

enum screen_ui
{
    SUI_MAIN_MENU,
    SUI_RECV_MENU,
    //SUI_RECV_ASN_STEP_LOCATION,
   //SUI_RECV_ASN_STEP_SCAN,
};


static inline void
ncurses_ui_init()
{
    initscr();

    cbreak();
    noecho();
    raw();

    // lets us read ^M's
    nonl();

    intrflush( stdscr, FALSE );

    keypad( stdscr, TRUE );

    if ( has_colors() )
    {
        start_color();
        init_pair( 1, COLOR_WHITE, COLOR_BLUE );
        init_pair( 2, COLOR_GREEN, COLOR_BLACK );
        init_pair( 3, COLOR_CYAN, COLOR_BLACK );
        bkgd( (chtype) COLOR_PAIR(1) );
        refresh();
    }
}

extern int
ncurses_ui_go( const char* app_name , const char* erp_user )
{
    int rc = TERM_UI_SUCCEED;

    ncurses_ui_init();

    enum screen_ui current = SUI_MAIN_MENU;

    for(;;)
    {
        switch( current )
        {
            case SUI_MAIN_MENU:
            {

                break;
            }
            case SUI_RECV_MENU:
            {

                break;
            }
        }
    }

    return rc;
}

