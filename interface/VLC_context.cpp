#include "VLC_context.h"

namespace byd{
namespace adas{
namespace VLC{

void VLCContext::reset(){
    current_stage_ = VLC_Stage_None;
}

VLCContext &VLCContext::Instance(){
    static VLCContext instance;
    return instance;
}
void VLCContext::SetCurrentState(VLCStage current_stage){
    current_stage_ = current_stage;
}

const VLCStage &VLCContext::GetCurrentStage() const {return current_stage_;}




}
}
}