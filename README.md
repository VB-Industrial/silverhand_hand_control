# silverhand_hand_control

Unified ros2_control, hardware plugin, and bringup package for the Silverhand gripper.
ros_control + hwinterface for silverhand project gripper

## Launch

Mock hardware:

```bash
ros2 launch silverhand_hand_control silverhand_hand_bringup.launch.py use_mock_hardware:=true
```

Real hardware:

```bash
ros2 launch silverhand_hand_control silverhand_hand_bringup.launch.py use_mock_hardware:=false can_iface:=can0 node_id:=120
```

## Helper scripts

```bash
cd /home/r/silver_ws/src/silverhand_hand_control
./scripts/start_hand_mock.sh
./scripts/start_hand_real.sh
```

Поддерживаемые переменные окружения:

- `ROS_WS`
- `ROS_DISTRO`
- `SILVERHAND_HAND_CAN_IFACE`
- `SILVERHAND_HAND_NODE_ID`

## systemd

User-service template:

- `systemd/user/silverhand-hand-control@.service`

Установка:

```bash
mkdir -p ~/.config/systemd/user
cp /home/r/silver_ws/src/silverhand_hand_control/systemd/user/silverhand-hand-control@.service ~/.config/systemd/user/
systemctl --user daemon-reload
```

Запуск:

```bash
systemctl --user enable --now silverhand-hand-control@mock.service
systemctl --user enable --now silverhand-hand-control@real.service
```

Автозапуск без логина:

```bash
loginctl enable-linger "$USER"
```

Логи:

```bash
journalctl --user -u silverhand-hand-control@mock.service -f
```
