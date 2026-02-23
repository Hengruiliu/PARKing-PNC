#include "VLC_Stage.h"
#include <memory>

namespace byd{
namespace adas{
namespace VLC{

VLCStageMachine::VLCStageMachine(void){
}

VLCStage VLCStageMachine::UpdateVLCStage(){
    // 获取当前状态和输入数据
    VLCStage current_stage = VLCContext::Instance().GetCurrentStage();
    const VLCInput& input = VLCContext::Instance().GetInputData();
    const VLCHSOutput& current_HS_output = VLCContext::Instance().GetCurrentHSState();  
    VLCHSState current_HS_stage = current_HS_output.hs_state;  

    // TODO: 泊车过程中发生故障的处理
    switch(current_stage) {
        case VLC_Stage_None:
            // 从None状态跳转
            if(current_HS_stage == VLC_Active && input.VehSpd < 5.0f) {
                return VLC_Stage_Drvoff;
            }
            break;
            
        case VLC_Stage_Drvoff:
            // 从Drvoff状态跳转
            if(input.VehSpd > 10.0f && input.LSMSubMTReq == 1) {
                return VLC_Stage_Closeloop;
            } else if(input.StopReq == 1) {
                return VLC_Stage_Hold;
            }
            break;
            
        case VLC_Stage_Closeloop:
            // 从Closeloop状态跳转
            if(input.StopReq == 1 || input.VehSpd < 2.0f) {
                return VLC_Stage_Hold;
            } else if(input.LSMBrakeEmgcyReq == 1) {
                return VLC_Stage_Hold;
            }
            break;
            
        case VLC_Stage_Hold:
            // 从Hold状态跳转
            if(input.DrvoffReq == 1 && input.EPBSystemStatus == 0) {
                return VLC_Stage_Drvoff;
            }
            break;
            
        default:
            return VLC_Stage_None;
    }
    return current_stage;
}


}
}
}