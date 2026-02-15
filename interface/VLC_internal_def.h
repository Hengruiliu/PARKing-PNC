#ifndef VLC_INTERFACE_DEF_H
#define VLC_INTERFACE_DEF_H
#include <iostream>
using namespace std;

namespace byd{
namespace adas{
namespace VLC{
    /*数据接收*/
    /*输入*/
struct VLCInput
{
    u_int8_t LSMSubMTReq;
    u_int8_t LSMSubMTLevel;
    u_int8_t LSMSubMTLong;
    u_int8_t LSMComfotbrakeReq;
    u_int8_t LSMBrakeEmgcyReq;
    u_int8_t SafeDrvHandOverReq;
    u_int8_t APAParkMod;
    u_int8_t MEBStatus;
    u_int8_t LSMVehSecReq;
    u_int8_t LSMVehDirReq;
    u_int8_t FLWhlRotateDir;
    u_int8_t FRWhlRotateDir;
    u_int8_t RLWhlRotateDir;
    u_int8_t RRWhlRotateDir;
    u_int8_t BrakePedalStatus;
    u_int8_t EPBSystemStatus;
    u_int8_t AxSnsrStatus;
    u_int8_t VehSpdStatus;
    u_int8_t EBDActv;
    u_int8_t EBDFault;
    u_int8_t ABSActv;
    u_int8_t ABSFault;
    u_int8_t TCSActv;
    u_int8_t TCSFault;
    u_int8_t ESCActv;
    u_int8_t ESCFault;
    u_int8_t VCUErrorEb;
    u_int8_t BrkTqCtrlAvl;
    u_int8_t VcuTqCtrlAvl;
    u_int8_t GearRegognizeSt;
    u_int8_t DrvoffReq;
    u_int8_t StopReq;
    u_int16_t FLWheelPulse;
    u_int16_t FRWheelPulse;
    u_int16_t RRWheelPulse;
    u_int16_t RLWheelPulse;
    float MaxSpdLimit;
    float DistToStop;
    float FLWheelSpd;
    float FRWheelSpd;
    float RLWheelSpd;
    float RRWheelSpd;
    float VehSpd;
    float EPSStrAng;
    float SpdRank;
};
    
    
}
}
}



#endif