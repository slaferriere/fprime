// ====================================================================== 
// \title  EpsSenderImpl.cpp
// \author slaferriere
// \brief  cpp file for EpsSender component implementation class
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


#include <Ref/EPSHardwareController/components/EpsSenderComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  EpsSenderComponentImpl ::
#if FW_OBJECT_NAMES == 1
    EpsSenderComponentImpl(
        const char *const compName
    ) :
      EpsSenderComponentBase(compName)
#else
    EpsSenderImpl(void)
#endif
  {

  }

  void EpsSenderComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    EpsSenderComponentBase::init(queueDepth, instance);
  }

  EpsSenderComponentImpl ::
    ~EpsSenderComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void EpsSenderComponentImpl ::
    powerIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
    this->tlmWrite_MS_RES(result);
    this->log_ACTIVITY_HI_MS_RESULT(result);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations 
  // ----------------------------------------------------------------------

  void EpsSenderComponentImpl ::
    MS_FIND_POWER_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val1,
        F32 val2,
        EpsOp operation
    )
  {
    EpsOpTlm opTlm;
    EpsOperation opPort;
    EpsOpEv opEv;
    switch (operation) {
      case ADD:
          opTlm = ADD_TLM;
          opPort = MATH_ADD;
          opEv = ADD_EV;
          break;
      case SUBTRACT:
          opTlm = SUB_TLM;
          opPort = MATH_SUB;
          opEv = SUB_EV;
          break;
      case MULTIPLY:
          opTlm = MULT_TLM;
          opPort = MATH_MULTIPLY;
          opEv = MULT_EV;
          break;
      case DIVIDE:
          opTlm = DIV_TLM;
          opPort = MATH_DIVIDE;
          opEv = DIV_EV;
          break;
      default:
          FW_ASSERT(0,operation);
          break;
    }

    this->tlmWrite_MS_OP(opTlm);
    this->tlmWrite_MS_VAL1(val1);
    this->tlmWrite_MS_VAL2(val2);
    this->log_ACTIVITY_LO_MS_COMMAND_RECV(val1,val2,opEv);
    this->powerOut_out(0,val1,val2,opPort);
    // reply with completion status
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
