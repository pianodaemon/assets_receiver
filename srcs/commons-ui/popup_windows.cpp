#include "commons-ui/popup_windows.hpp"

template <typename T>
extern const int
cmd_help_popup_window(
    int&& origin_x,
    int&& origin_y,
    std::vector<T>& cmds,
    std::function<int (const std::vector<T>&, WINDOW*, WINDOW*)> content_delegate
)
{
    int rc = 0;

    #define FRAME_SIZE_X(ORIGIN)     (COLS - ((ORIGIN + 1 ) << 1))
    #define FRAME_SIZE_Y(ORIGIN)     (LINES - ((ORIGIN + 1 ) << 1))
    #define CONTENT_SIZE_X(ORIGIN)   (FRAME_SIZE_X(ORIGIN) - 4)
    #define CONTENT_SIZE_Y(T)        ((sizeof(T)/sizeof(T[0])) + 2)

    WINDOW* prior_ptr = nullptr;
    WINDOW* frame_ptr = nullptr;
    WINDOW* content_ptr = nullptr;
     
    auto backup_prior_scr = [&](void)
    {
        doupdate();
        prior_ptr = dupwin(curscr);
    };

    auto eliminate_windows = [&](void)
    {
        werase(frame_ptr);
        wrefresh(frame_ptr);
        delwin(frame_ptr);
        delwin(content_ptr);
    };

    auto restore_prior_scr = [&](void)
    {
        touchwin(prior_ptr);
        wnoutrefresh(prior_ptr);
        doupdate();
        delwin(prior_ptr);
    };


    frame_ptr = newwin(
        FRAME_SIZE_Y(origin_y),
        FRAME_SIZE_X(origin_x),
        origin_y,
        origin_x
    );

        
    content_ptr = newpad(
        CONTENT_SIZE_Y(&cmds[0]),
        CONTENT_SIZE_X(origin_x)
    );

    backup_prior_scr();
    content_delegate(cmds, frame_ptr, content_ptr);
    eliminate_windows();
    restore_prior_scr();

    #undef FRAME_SIZE_X
    #undef FRAME_SIZE_Y
    #undef CONTENT_SIZE_X
    #undef CONTENT_SIZE_Y

    return rc;
}
