//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Evolved slot and signal header
//
//======================================================================

#ifndef __AR_SLOT_MANAGER_HPP__
#define __AR_SLOT_MANAGER_HPP__
 
#include "basic_signal.hpp"

//!=================================================================
//!
//! \brief
//!     Class to implement a Evolved slot and signal mechanism.
//!
//==================================================================
template <typename... T>
class slot_manager : public basic_signal<T...>
{
    public:
 
        slot_manager() { }
 
        template <typename F, typename... A>
 
        //!=========================================================
        //!
        //! \brief
        //!      Connects an object function member to react when 
        //!      signal occurs , one or more can be connected to 
        //!      the same signal.
        //!
        //! \return
        //!     The slot number assigned
        //!
        unsigned short conn_member(F&& f, A&& ... a) 
        {
            this->m_slots.insert({ ++this->m_slot_id, std::bind(f, a...) });
            return this->m_slot_id;
        }     
}; 
 
#endif /* __AR_SLOT_MANAGER_HPP__ */
