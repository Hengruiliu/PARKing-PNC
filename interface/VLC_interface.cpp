#include <memory> 
#include "VLC_context.h"
#include "VLC_internal_def.h"
#include "VLC_interface.h"  

namespace byd{
namespace adas{
namespace VLC{

VLCInterface::VLCInterface() : 
    VLC_Stage_Machine_(std::make_shared<VLCStageMachine>()),
    VLC_Hand_Shake_(std::make_shared<VLCHandShake>()) {
}

VLCInterface::~VLCInterface(){
}


void VLCInterface::VLCFunction(){
    // 1. 更新故障诊断，握手状态
    VLCContext::Instance().SetCurrentHSState(VLC_Hand_Shake_->UpdateVLCHandShake());
    
    // 2. 更新VLC状态机
    VLCContext::Instance().SetCurrentState(VLC_Stage_Machine_->UpdateVLCStage());
}


}
}
}