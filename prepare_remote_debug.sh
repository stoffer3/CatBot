#!/bin/bash

cd build
ssh pi@192.168.0.2 killall gdbserver
scp RobotController pi@192.168.0.2:~/rpi_programs
ssh pi@192.168.0.2 "gdbserver :9091 ~/rpi_programs/RobotController" &
sleep 3s
exit 0

