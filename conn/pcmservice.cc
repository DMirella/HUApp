#include "pcmservice.h"

#include <vector>
#include <algorithm>

#include <QDebug>

#include "main/service_accessor.h"


HMIPCMDeviceInfo ConvertPCMLibInfoToHMIPCMDeviceInfo(const PCMDeviceInfo& info) {
  HMIPCMDeviceInfo result;
  result.device_id = info.device_id;
  result.device_name = info.device_name;
  for (auto it : info.enable_technologies_) {
    result.enable_technologies_.push_back(static_cast<HMIPhoneTechology>(it));
  }
  return result;
}

namespace pcm {

PCMService::PCMService()
{

}

void PCMService::Init()
{
    hmi_reciever_ = ServiceAccessor::GetInstance().GetHMIService();
}

void PCMService::OnDeviceDetected(const PCMDeviceInfo &info)
{
  hmi_reciever_->OnPCMDeviceDetected(ConvertPCMLibInfoToHMIPCMDeviceInfo(info));
}

void PCMService::OnConnectPhoneRequest(ConnectRequestPhoneInfo info)
{
  qDebug() << "PCMService::OnConnectPhoneRequest";
  qDebug() << info.device_id << " " << info.technology;
}

}  // namespace pcm
