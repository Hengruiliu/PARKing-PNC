#ifndef VLC_INTERFACE_H
#define VLC_INTERFACE_H
#include <iostream>
#include <memory> 
#include "VLC_context.h"
#include "VLC_internal_def.h"
#include "VLC_Stage.h"  
#include "VLC_Handshake.h"

namespace byd{
namespace adas{
namespace VLC{

class VLCInterface{
  public:
  VLCInterface(void);
  ~VLCInterface();
  
  void VLCFunction();



  private:
  std::shared_ptr<VLCStageMachine> VLC_Stage_Machine_;  
  std::shared_ptr<VLCHandShake> VLC_Hand_Shake_;  
};

}
}
}
#endif