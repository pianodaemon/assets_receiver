//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Basic slot and signal header
//
//======================================================================

#ifndef __AR_BASIC_SIGNAL_HPP__
#define __AR_BASIC_SIGNAL_HPP__
 
#include <functional>
#include <unordered_map>

//!=================================================================
//!
//! \brief
//!     Class to implement a Basic slot and signal mechanism.
//!
//==================================================================
template <typename... A>
class basic_signal
{
    protected:
 
        std::unordered_map<int, std::function<void(A...)>> m_slots;
        unsigned short m_slot_id;
 
    public:
 
        basic_signal() : m_slot_id(0) {}

        //!=========================================================
        //!
        //! \brief
        //!      Connects a handler to react when signal occurs, 
        //!      one or more can be connected to the same signal.
        //!
        //! \return
        //!     The slot number assigned
        //!
        unsigned short conn(std::function<void(A...)> const& s)
        {
            this->m_slots.insert(std::make_pair(++this->m_slot_id, s));
            return this->m_slot_id;
        }
 
        //!=========================================================
        //!
        //! \brief
        //!      Disconnects a handler assigned to the slot number 
        //!      when signal occurs.
        //!
        //! \return
        //!     nothing
        //!
        void disconn(unsigned short id)
        {
            this->m_slots.erase(id);
        }
 
        //!=========================================================
        //!
        //! \brief
        //!      Disconnects the overall of handler assigned to 
        //!      the slot number when signal occurs.
        //!
        //! \return
        //!     nothing
        //!
        void disconn_all()
        {
            this->m_slots.clear();
        }
 

        //!=========================================================
        //!
        //! \brief
        //!      Yields a signal with ist data passed as arguments
        //!
        //! \return
        //!     nothing
        //!
        void trigger(A... p)
        {
            for (auto iter : this->m_slots) iter.second(p...);
        }
};
 
#endif /* __AR_BASIC_SIGNAL_HPP__ */
