#include "VLC_context.h"

namespace byd{
namespace adas{
namespace VLC{

void VLCContext::reset(){
    current_stage_ = VLC_Stage_None;
    current_HS_state_.hs_state = VLC_Standby;  
}

VLCContext &VLCContext::Instance(){
    static VLCContext instance;
    return instance;
}

const VLCInput& VLCContext::GetInputData() const {
    return input_data_;
}
void VLCContext::SetCurrentState(VLCStage current_stage){
    current_stage_ = current_stage;
}

const VLCStage &VLCContext::GetCurrentStage() const {return current_stage_;}

void VLCContext::SetCurrentHSState(VLCHSOutput hs_state) {
    current_HS_state_ = hs_state;
}

const VLCHSOutput &VLCContext::GetCurrentHSState() const {
    return current_HS_state_;
}


const VLCInput& VLCContext::GetInputData() const {
    return input_data_;
}



}
}
}