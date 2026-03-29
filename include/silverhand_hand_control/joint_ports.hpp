#ifndef SILVERHAND_HAND_CONTROL__JOINT_PORTS_HPP_
#define SILVERHAND_HAND_CONTROL__JOINT_PORTS_HPP_

#include <array>
#include <cstdint>

namespace silverhand_hand_control
{

constexpr std::size_t kJointCount = 2;
constexpr std::uint16_t kAgentJointStatePort = 1001;
constexpr std::uint8_t kFirstGripperNodeId = 7;

// Continue the Silverhand arm command-port range for the gripper joints.
constexpr std::array<std::uint16_t, kJointCount> kJointCommandPorts = {
  1127,
  1128,
};

}  // namespace silverhand_hand_control

#endif  // SILVERHAND_HAND_CONTROL__JOINT_PORTS_HPP_
