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
ros2 launch silverhand_hand_control silverhand_hand_bringup.launch.py use_mock_hardware:=false can_iface:=vcan1.0 node_id:=11
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
- `SILVERHAND_HAND_CAN_IFACE` — по умолчанию `vcan1.0`
- `SILVERHAND_HAND_NODE_ID` — по умолчанию `11`

## systemd

System service template:

- `systemd/system/silverhand-hand-control@.service`

Установка:

```bash
sudo install -Dm644 /home/r/silver_ws/src/silverhand_hand_control/systemd/system/silverhand-hand-control@.service /etc/systemd/system/silverhand-hand-control@.service
sudo systemctl daemon-reload
```

Запуск:

```bash
sudo systemctl enable --now silverhand-hand-control@mock.service
sudo systemctl enable --now silverhand-hand-control@real.service
```

Автозапуск без логина не нужен: system service стартует без user session.

Логи:

```bash
journalctl -u silverhand-hand-control@mock.service -f
```
