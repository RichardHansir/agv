/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CLUSTER_GENERAL_INFO_701_H_
#define CLUSTER_GENERAL_INFO_701_H_

#include "protocol_data.h"
#include "conti_radar.hpp"


//using apollo::drivers::ContiRadar;

class ClusterGeneralInfo701
    : public ProtocolData<ContiRadar> {
 public:
  static const uint32_t ID;
  ClusterGeneralInfo701();
  void Parse(const std::uint8_t* bytes, int32_t length,
             ContiRadar& conti_radar) const override;

 private:
  int obstacle_id(const std::uint8_t* bytes, int32_t length) const;

  double longitude_dist(const std::uint8_t* bytes, int32_t length) const;

  double lateral_dist(const std::uint8_t* bytes, int32_t length) const;

  double longitude_vel(const std::uint8_t* bytes, int32_t length) const;

  double lateral_vel(const std::uint8_t* bytes, int32_t length) const;

  double rcs(const std::uint8_t* bytes, int32_t length) const;

  int dynprop(const std::uint8_t* bytes, int32_t length) const;
};


#endif  // MODULES_DRIVERS_RADAR_CONTI_RADAR_PROTOCOL_CLUSTER_GENERAL_INFO_701_H
