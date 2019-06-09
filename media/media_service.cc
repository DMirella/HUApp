#include "media_service.h"

#include "btmedialib.h"
#include "hmi/media/media_service_reciever.h"
#include "main/service_accessor.h"

namespace  {

HMIMediaDeviceInfo ConvertBTMediaLibInfoToHMIMediaDeviceInfo(const BTMediaDeviceInfo& info) {
  HMIMediaDeviceInfo result;
  result.device_id = info.device_id;
  result.device_name = info.device_name;
  return result;
}

}  // namespace

namespace media {

MediaService::MediaService()
{

}

void MediaService::Init()
{
  reciever_ = ServiceAccessor::GetInstance().GetHMIService();
}

void MediaService::OnDeviceDetected(const BTMediaDeviceInfo &info)
{
  reciever_->OnBTMediaDeviceDetected(ConvertBTMediaLibInfoToHMIMediaDeviceInfo(info));
}

}  // media
