//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Popup windows header.
//      Common chunks of code to implement popup windows.
//
//======================================================================

#ifndef __COMMON_UI_POPUP_WINDOWS_HPP__
#define __COMMON_UI_POPUP_WINDOWS_HPP__

#include <curses.h>
#include <functional>
#include <vector>

template <typename T>
extern const int
cmd_help_popup_window(
    int&& origin_x,
    int&& origin_y,
    std::vector<T>& cmds,
    std::function<int (const std::vector<T>&, WINDOW*, WINDOW*)> content_delegate
);


#endif /* __COMMON_UI_POPUP_WINDOWS_HPP__ */
