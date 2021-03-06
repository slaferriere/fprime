// ====================================================================== 
// \title  Warnings.cpp
// \author bocchino
// \brief  cpp file for FileUplink::Warnings
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
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

#include <Svc/FileUplink/FileUplink.hpp>

namespace Svc {

  void FileUplink::Warnings ::
    invalidReceiveMode(const Fw::FilePacket::Type packetType)
  {
    this->fileUplink->log_WARNING_HI_FileUplink_InvalidReceiveMode(
        static_cast<U32>(packetType),
        static_cast<U32>(fileUplink->receiveMode)
    );
    this->warning();
  }

  void FileUplink::Warnings ::
    fileOpen(Fw::LogStringArg& fileName)
  {
    this->fileUplink->log_WARNING_HI_FileUplink_FileOpenError(fileName);
    this->warning();
  }

  void FileUplink::Warnings ::
    packetOutOfBounds(
        const U32 sequenceIndex,
        Fw::LogStringArg& fileName
    )
  {
    this->fileUplink->log_WARNING_HI_FileUplink_PacketOutOfBounds(
        sequenceIndex,
        fileName
    );
    this->warning();
  }

  void FileUplink::Warnings ::
    packetOutOfOrder(
        const U32 sequenceIndex,
        const U32 lastSequenceIndex
    )
  {
    this->fileUplink->log_WARNING_HI_FileUplink_PacketOutOfOrder(
        sequenceIndex,
        lastSequenceIndex
    );
    this->warning();
  }

  void FileUplink::Warnings ::
    fileWrite(Fw::LogStringArg& fileName)
  {
    this->fileUplink->log_WARNING_HI_FileUplink_FileWriteError(fileName);
    this->warning();
  }

  void FileUplink::Warnings ::
    badChecksum(
        const U32 computed,
        const U32 read
    )
  {
    this->fileUplink->log_WARNING_HI_FileUplink_BadChecksum(
        this->fileUplink->file.name,
        computed,
        read
    );
    this->warning();
  }

}
