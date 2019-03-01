// ====================================================================== 
// \title  EpsSenderImpl.hpp
// \author slaferriere
// \brief  hpp file for EpsSender component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
// 
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ====================================================================== 

#ifndef EpsSender_HPP
#define EpsSender_HPP

#include "Ref/EPSHardwareController/components/EpsSenderComponentAc.hpp"

namespace Ref {

  class EpsSenderComponentImpl :
    public EpsSenderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object EpsSender
      //!
      EpsSenderComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object EpsSender
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object EpsSender
      //!
      ~EpsSenderComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for powerIn
      //!
      void powerIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result /*!< the result of the operation>*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for MS_FIND_POWER command handler
      //! Get power
      void MS_FIND_POWER_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val1, /*!< The first value*/
          F32 val2, /*!< The second value*/
          EpsOp operation /*!< The operation to perform*/
      );


    };

} // end namespace Ref

#endif
