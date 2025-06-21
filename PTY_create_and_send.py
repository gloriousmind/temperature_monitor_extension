import subprocess
import re
import time
import serial
import random

# 启动 socat，并获取输出
proc = subprocess.Popen(
    ["socat", "-d", "-d", "PTY,raw,echo=0", "PTY,raw,echo=0"],
    stdout=subprocess.PIPE,
    stderr=subprocess.STDOUT,
    text=True
)

# 记录串口路径
ports = []

# 从 socat 的输出中提取设备名
while True:
    line = proc.stdout.readline()
    print(line.strip())  # 可选：打印调试信息
    match = re.search(r'PTY is (/dev/pts/\d+)', line)
    if match:
        ports.append(match.group(1))
    if len(ports) == 2:
        break

# 保存串口名
with open("vport1.txt", "w") as f:
    f.write(ports[0])
with open("vport2.txt", "w") as f:
    f.write(ports[1])

print(f"虚拟串口创建完成: {ports[0]} <--> {ports[1]}")

# 读取串口名
with open("vport1.txt", "r") as f:
    port = f.read().strip()

# 打开串口
ser = serial.Serial(port, 9600, timeout=1)

try:
    while True:
        temp = round(random.uniform(-50, 150), 1)
        data = f"{temp}\n"
        ser.write(data.encode())
        print(f"发送: {data.strip()}")
        time.sleep(1)
except KeyboardInterrupt:
    print("发送结束")
finally:
    ser.close()
