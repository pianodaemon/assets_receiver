#include "term-ui/inceptor.hpp"
#include "term-ui/error_codes.hpp"
#include <curses.h>

//typedef void ( *proc_flow_event )( ar_context* ar_cxt_ptr, uint8_t mode, va_list ap );

enum screen_ui
{
    SUI_MAIN_MENU,
    SUI_MAIN_SCREEN,
    SUI_RECV_MENU,
    //SUI_RECV_EDIT,
    //SUI_RECV_ASN_STEP_LOCATION,
   //SUI_RECV_ASN_STEP_SCAN,
};


/*
enum recv_bp_flow
{
    RECV_BP_NEW_FLOW,
//    RECV_BP_EDIT_FLOW,
    RECV_BP_DELETE_FLOW,
    RECV_BP_SEARCH_FLOW,
    RECV_BP_MAX_FLOW,
};

enum recv_bp_event
{
    RECV_BP_SHOW_FORM,
    
};


static const proc_flow_event
recv_bp_table[RECV_BP_MAX_FLOW][RECV_BP_MAX_EVENT] = {  // [y] [x] 
    // display  
    { nullptr , nullptr , nullptr, nullptr },
    { nullptr , nullptr , nullptr, nullptr },
    { nullptr , nullptr , nullptr, nullptr },
    { nullptr , nullptr , nullptr, nullptr },
//    { NULL, &SingleSendEncodeSendPDU, NULL, NULL },
//    { &SingleSendNotifyAckNak, NULL, &SingleSendResendPDU, &SingleSendNotifyTimeout },
//    { NULL, NULL, NULL, NULL }
};*/

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
            case SUI_MAIN_SCREEN:
            {

                break;
            }
            case SUI_RECV_MENU:
            {

                break;
            }
        }
    }

    if ( endwin() == ERR ) rc = -5001;

    return rc;
}

