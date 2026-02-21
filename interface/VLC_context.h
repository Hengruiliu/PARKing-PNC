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
    void SetCurrentState(VLCStage current_stage);
    const VLCStage &GetCurrentStage() const;


    private:
    // 当前VLC状态
    VLCStage current_stage_;






};
}
}
}
#endif