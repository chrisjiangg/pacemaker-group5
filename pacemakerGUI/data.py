import serial
import serial.tools.list_ports
import struct
import numpy as np
import sys

def endian_check():
    if sys.byteorder == "little":
        return True
    else:
        return False

# # Mac ports, for windows you have to find the ports yourself
frdm_port = "COM3"
# Text file data converted to integer data type

array =[]
Data = np.genfromtxt("data.txt",encoding=None)
for each in Data:
    array.append(each)

mode = array[0]
lower_rate_limit = array[1]
upper_rate_limit =array[2]
maximum_sensor_rate = array[3]
atrial_amplitude = array[4]
atrial_pulse_width = array[5]
atrial_sensitivity = array[6]
ventrical_amp = array[7]
ventrical_pulse_width = array[8]
ventrical_sensitivity = array[9]
arp = array[10]
vrp = array[11]
pvarp = array[12]
hyster = array[13]
rate_smoothing = array[14]
activity_thres = array[15]
reaction_time = array[16]
response_factor = array[17]
recovery_time = array[18]

Start = b'\x16' #unsigned 22
SYNC = b'\x22' #unsigned 34
Fn_set = b'\x55' #unsigned 85

if(endian_check()==True):
    # little endian
    mode_en = struct.pack("<B", int(mode))
    lower_rate_limit_en = struct.pack("<B", int(lower_rate_limit))
    upper_rate_limit_en =struct.pack("<B", int(upper_rate_limit))
    ventrical_amp_en = struct.pack("<f", float(ventrical_amp))
    ventrical_pulse_width_en = struct.pack("<f", float(ventrical_pulse_width))
    ventrical_sensitivity_en = struct.pack("<f", float(ventrical_sensitivity))
    vrp_en = struct.pack("<H", int(vrp))
    hyster_en = struct.pack("<B", int(hyster))
    rate_smoothing_en = struct.pack("<B", int(rate_smoothing))
    atrial_amplitude_en = struct.pack("<f", float(atrial_amplitude))
    atrial_pulse_width_en = struct.pack("<f", float(atrial_pulse_width))
    atrial_sensitivity_en = struct.pack("<f", float(atrial_sensitivity))
    arp_en = struct.pack("<H", int(arp))
    pvarp_en = struct.pack("<H", int(pvarp))
    maximum_sensor_rate_en = struct.pack("<B", int(maximum_sensor_rate))
    activity_thres_en = struct.pack("<B", int(activity_thres))
    reaction_time_en = struct.pack("<B", int(reaction_time))
    response_factor_en = struct.pack("<B", int(response_factor))
    recovery_time_en = struct.pack("<B", int(recovery_time))
else:
    # Big endian
    mode_en = struct.pack(">B", int(mode))
    lower_rate_limit_en = struct.pack(">B", int(lower_rate_limit))
    upper_rate_limit_en =struct.pack(">B", int(upper_rate_limit))
    ventrical_amp_en = struct.pack(">f", float(ventrical_amp))
    ventrical_pulse_width_en = struct.pack(">f", float(ventrical_pulse_width))
    ventrical_sensitivity_en = struct.pack(">f", float(ventrical_sensitivity))
    vrp_en = struct.pack(">H", int(vrp))
    hyster_en = struct.pack(">B", int(hyster))
    rate_smoothing_en = struct.pack(">B", int(rate_smoothing))
    atrial_amplitude_en = struct.pack(">f", float(atrial_amplitude))
    atrial_pulse_width_en = struct.pack(">f", float(atrial_pulse_width))
    atrial_sensitivity_en = struct.pack(">f", float(atrial_sensitivity))
    arp_en = struct.pack(">H", int(arp))
    pvarp_en = struct.pack(">H", int(pvarp))
    maximum_sensor_rate_en = struct.pack(">B", int(maximum_sensor_rate))
    activity_thres_en = struct.pack(">B", int(activity_thres))
    reaction_time_en = struct.pack(">B", int(reaction_time))
    response_factor_en = struct.pack(">B", int(response_factor))
    recovery_time_en = struct.pack(">B", int(recovery_time))

# print("Start: ", Start)
# print("SYNC: ", SYNC)
# print("Fn_set: ", Fn_set)
# print("mode_en: ", mode_en)
# print("lower_rate_limit_en: ", lower_rate_limit_en)
# print("upper_rate_limit_en: ", upper_rate_limit_en)
# print("maximum_sensor_rate_en: ", maximum_sensor_rate_en)
# print("atrial_amplitude_en: ", atrial_amplitude_en)
# print("atrial_pulse_width_en: ", atrial_pulse_width_en)
# print("atrial_sensitivity_en: ", atrial_sensitivity_en)
# print("ventrical_amp_en: ", ventrical_amp_en)
# print("ventrical_pulse_width_en: ", ventrical_pulse_width_en)
# print("ventrical_sensitivity_en: ", ventrical_sensitivity_en)
# print("arp_en: ", arp_en)
# print("vrp_en: ", vrp_en)
# print("pvarp_en: ", pvarp_en)
# print("hyster_en: ", hyster_en)
# print("rate_smoothing_en: ", rate_smoothing_en)
# print("activity_thres_en: ", activity_thres_en)
# print("reaction_time_en: ", reaction_time_en)
# print("response_factor_en: ", response_factor_en)
# print("recovery_time_en: ", recovery_time_en)

mode_de = struct.unpack("B", mode_en)
lower_rate_limit_de = struct.unpack("B", lower_rate_limit_en)
upper_rate_limit_de =struct.unpack("B", upper_rate_limit_en)
ventrical_amp_de = struct.unpack("f", ventrical_amp_en)
ventrical_pulse_width_de = struct.unpack("f", ventrical_pulse_width_en)
ventrical_sensitivity_de = struct.unpack("f", ventrical_sensitivity_en)
vrp_de = struct.unpack("H", vrp_en)
hyster_de = struct.unpack("B", hyster_en)
rate_smoothing_de = struct.unpack("B", rate_smoothing_en)
atrial_amplitude_de = struct.unpack("f", atrial_amplitude_en)
atrial_pulse_width_de = struct.unpack("f", atrial_pulse_width_en)
atrial_sensitivity_de = struct.unpack("f", atrial_sensitivity_en)
arp_de = struct.unpack("H", arp_en)
pvarp_de = struct.unpack("H", pvarp_en)
maximum_sensor_rate_de = struct.unpack("B", maximum_sensor_rate_en)
activity_thres_de = struct.unpack("B", activity_thres_en)
reaction_time_de = struct.unpack("B", reaction_time_en)
response_factor_de = struct.unpack("B", response_factor_en)
recovery_time_de = struct.unpack("B", recovery_time_en)

# print("mode_en: ", mode_de[0])
# print("lower_rate_limit_en: ", lower_rate_limit_de[0])
# print("upper_rate_limit_en: ", upper_rate_limit_de[0])
# print("maximum_sensor_rate_en: ", maximum_sensor_rate_de[0])
# print("atrial_amplitude_en: ", atrial_amplitude_de[0])
# print("atrial_pulse_width_en: ", atrial_pulse_width_de[0])
# print("atrial_sensitivity_en: ", atrial_sensitivity_de[0])
# print("ventrical_amp_en: ", ventrical_amp_de[0])
# print("ventrical_pulse_width_en: ", ventrical_pulse_width_de[0])
# print("ventrical_sensitivity_en: ", ventrical_sensitivity_de[0])
# print("arp_en: ", arp_de[0])
# print("vrp_en: ", vrp_de[0])
# print("pvarp_en: ", pvarp_de[0])
# print("hyster_en: ", hyster_de[0])
# print("rate_smoothing_en: ", rate_smoothing_de[0])
# print("activity_thres_en: ", activity_thres_de[0])
# print("reaction_time_en: ", reaction_time_de[0])
# print("response_factor_en: ", response_factor_de[0])
# print("recovery_time_en: ", recovery_time_de[0])

Signal_set = Start + Fn_set + mode_en + lower_rate_limit_en + upper_rate_limit_en + ventrical_amp_en + ventrical_pulse_width_en + ventrical_sensitivity_en  + vrp_en + hyster_en + rate_smoothing_en + atrial_amplitude_en + atrial_pulse_width_en + atrial_sensitivity_en + arp_en + pvarp_en + maximum_sensor_rate_en + activity_thres_en + reaction_time_en + response_factor_en + recovery_time_en
Signal_echo = Start + SYNC + mode_en + lower_rate_limit_en + upper_rate_limit_en + ventrical_amp_en + ventrical_pulse_width_en + ventrical_sensitivity_en  + vrp_en + hyster_en + rate_smoothing_en + atrial_amplitude_en + atrial_pulse_width_en + atrial_sensitivity_en + arp_en + pvarp_en + maximum_sensor_rate_en + activity_thres_en + reaction_time_en + response_factor_en + recovery_time_en

# print(Signal_set,"\n")
# print(Signal_echo,"\n")

# with serial.Serial(frdm_port, 115200) as pacemaker:
#     pacemaker.write(Signal_set)

# with serial.Serial(frdm_port, 115200) as pacemaker:
#     pacemaker.write(Signal_echo)
#     data = pacemaker.read(41)
    # red_rev = data[0]
    # green_rev = data[1]
    # blue_rev = data[2]
    # off_rev =  struct.unpack("f", data[3:7])[0]
    # switch_rev =  struct.unpack("H", data[7:9])[0]

# print("From the board:")
# print("red_en = ", red_rev)
# print("green_en = ", green_rev)
# print("blue_en = ", blue_rev)
# print("off_time = ",  off_rev)
# print("switch_time = ", switch_rev)


