#include "VLC_Handshake.h"
#include <memory>

namespace byd{
namespace adas{
namespace VLC{


VLCHandShake::VLCHandShake(void){
}


VLCHSOutput VLCHandShake::UpdateVLCHandShake(){ 
    const VLCHSOutput& current_HS_output = VLCContext::Instance().GetCurrentHSState();  
    const VLCInput& input = VLCContext::Instance().GetInputData();
    VLCHSState current_HS_stage = current_HS_output.hs_state;  
    VLCHSOutput output;
    output.VLC_error_code = 0;  //TODO:故障诊断
    
    switch(current_HS_stage)  
    {
        //从Standby跳转
        case VLC_Standby:
        if(input.LSMSubMTReq == 2 && (input.LSMSubMTLevel == 2 || input.LSMSubMTLevel == 1) && output.VLC_error_code == 0)
        {
            output.hs_state = VLC_Active;
        }
        else if(output.VLC_error_code != 0)
        {
            output.hs_state = VLC_Error;

        }
            break;
        //从Active跳转
        case VLC_Active:
        if(input.LSMSubMTReq == 0 || input.LSMSubMTLevel == 0 && output.VLC_error_code == 0)
        {
            output.hs_state = VLC_Standby;
        }
        else if(output.VLC_error_code != 0)
        {
            output.hs_state = VLC_Error;

        }
            break;
        //从Error跳转
        case VLC_Error:
        if(output.VLC_error_code == 0)
        {
            output.hs_state = VLC_Standby;
        }
            break;
        default: 
            output.hs_state = VLC_Standby;
            break;
    }
    
    return output;
}

}
}
}
