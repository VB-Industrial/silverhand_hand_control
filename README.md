# silverhand_hand_control

Единый пакет `ros2_control`, аппаратного плагина и bringup для захвата Silverhand.
`ros_control` + `hwinterface` для захвата проекта SilverHand

## Запуск

Mock-режим:

```bash
ros2 launch silverhand_hand_control silverhand_hand_bringup.launch.py use_mock_hardware:=true
```

Режим реального железа:

```bash
ros2 launch silverhand_hand_control silverhand_hand_bringup.launch.py use_mock_hardware:=false can_iface:=vcan1.0 node_id:=11
```

## Вспомогательные скрипты

```bash
cd ~/silver_ws/src/silverhand_hand_control
./scripts/start_hand_mock.sh
./scripts/start_hand_real.sh
```

Поддерживаемые переменные окружения:

- `ROS_WS`
- `ROS_DISTRO`
- `SILVERHAND_HAND_CAN_IFACE` — по умолчанию `vcan1.0`
- `SILVERHAND_HAND_NODE_ID` — по умолчанию `11`

## systemd

Шаблон systemd-сервиса:

- `systemd/system/silverhand-hand-control@.service`

Установка:

```bash
sudo install -Dm644 systemd/system/silverhand-hand-control@.service /etc/systemd/system/silverhand-hand-control@.service
sudo systemctl daemon-reload
```

Запуск:

```bash
sudo systemctl enable --now silverhand-hand-control@mock.service
sudo systemctl enable --now silverhand-hand-control@real.service
```

Автозапуск без логина не нужен: system-сервис стартует без пользовательской сессии.

Логи:

```bash
journalctl -u silverhand-hand-control@mock.service -f
```
