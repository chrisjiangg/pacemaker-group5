import serial
import serial.tools.list_ports
import struct
import numpy as np

# # Mac ports, for windows you have to find the ports yourself
frdm_port = "COM3"
# Text file data converted to integer data type

array =[]
Data = np.genfromtxt("data.txt", dtype=int,encoding=None, delimiter=",")
for each in Data:
    array.append(each)

lower_rate_limit = array[0]
upper_rate_limit =array[1]
ventrical_amp = array[2]
ventrical_pulse_width = array[3]
ventrical_sensitivity = array[4]
vrp = array[5]
hyster = array[6]
rate_smoothing = array[7]
atrial_amplitude = array[8]
atrial_pulse_width = array[9]
atrial_sensitivity = array[10]
arp = array[11]
pvarp = array[12]
maximum_sensor_rate = array[13]
activity_thres = array[14]
reaction_time = array[15]
response_factor = array[16]
recovery_time = array[17]
 
    
Start = b'\x16'
SYNC = b'\x22'
Fn_set = b'\x55'
lower_rate_limit_en = struct.pack("f", lower_rate_limit)
upper_rate_limit_en =struct.pack("f", upper_rate_limit)
ventrical_amp_en = struct.pack("f", ventrical_amp)
ventrical_pulse_width_en = struct.pack("f", ventrical_pulse_width)
ventrical_sensitivity_en = struct.pack("f", ventrical_sensitivity)
vrp_en = struct.pack("f", vrp)
hyster_en = struct.pack("f", hyster)
rate_smoothing_en = struct.pack("f", rate_smoothing)
atrial_amplitude_en = struct.pack("f", atrial_amplitude)
atrial_pulse_width_en = struct.pack("f", atrial_amplitude)
atrial_sensitivity_en = struct.pack("f", atrial_sensitivity)
arp_en = struct.pack("f", arp)
pvarp_en = struct.pack("f", pvarp)
maximum_sensor_rate_en = struct.pack("f", maximum_sensor_rate)
activity_thres_en = struct.pack("f", activity_thres)
reaction_time_en = struct.pack("f", reaction_time)
response_factor_en = struct.pack("f", response_factor)
recovery_time_en = struct.pack("f", recovery_time)

Signal_set = Start + Fn_set + lower_rate_limit_en + upper_rate_limit_en + ventrical_amp_en + ventrical_pulse_width_en + ventrical_sensitivity_en  + vrp_en + hyster_en + rate_smoothing_en + atrial_amplitude_en + atrial_pulse_width_en + atrial_sensitivity_en + arp_en + pvarp_en + maximum_sensor_rate_en + activity_thres_en + reaction_time_en + response_factor_en + recovery_time_en
Signal_echo = Start + SYNC + lower_rate_limit_en + upper_rate_limit_en + ventrical_amp_en + ventrical_pulse_width_en + ventrical_sensitivity_en  + vrp_en + hyster_en + rate_smoothing_en + atrial_amplitude_en + atrial_pulse_width_en + atrial_sensitivity_en + arp_en + pvarp_en + maximum_sensor_rate_en + activity_thres_en + reaction_time_en + response_factor_en + recovery_time_en
print (struct.unpack(Signal_echo))
# with serial.Serial(frdm_port, 115200) as pacemaker:
#     pacemaker.write(Signal_set)

# with serial.Serial(frdm_port, 115200) as pacemaker:
#     pacemaker.write(Signal_echo)
#     data = pacemaker.read(9)
#     red_rev = data[0]
#     green_rev = data[1]
#     blue_rev = data[2]
#     off_rev =  struct.unpack("f", data[3:7])[0]
#     switch_rev =  struct.unpack("H", data[7:9])[0]

# print("From the board:")
# print("red_en = ", red_rev)
# print("green_en = ", green_rev)
# print("blue_en = ", blue_rev)
# print("off_time = ",  off_rev)
# print("switch_time = ", switch_rev)


