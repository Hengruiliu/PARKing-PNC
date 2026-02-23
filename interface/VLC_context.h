#ifndef VLC_CONTEXT_H
#define VLC_CONTEXT_H
#include "VLC_internal_def.h"
namespace byd{
namespace adas{
namespace VLC{

class VLCContext{
    private:
    VLCContext() = default;
    ~VLCContext() = default;

    VLCContext(const VLCContext &) = delete;

    VLCContext &operator = (VLCContext &) = delete;

    public:
    static VLCContext &Instance();
    void reset();
    //握手
    void SetCurrentHSState(VLCHSOutput hs_state);  
    const VLCHSOutput &GetCurrentHSState() const; 
    
    //状态机
    void SetCurrentState(VLCStage current_stage);
    const VLCStage &GetCurrentStage() const;

    //输入数据
    const VLCInput& GetInputData() const;

    private:
    // 当前VLC状态
    VLCStage current_stage_;
    // 输入数据
    VLCInput input_data_;
    // 握手状态 
    VLCHSOutput current_HS_state_;



};
}
}
}
#endif