import serial
import serial.tools.list_ports
import struct
import numpy as np
import sys
import time

def endian_check():
    if sys.byteorder == "little":
        return True
    else:
        return False

# Text file data converted to integer data type

array =[]
Data = np.genfromtxt("data.txt",encoding=None)
for each in Data:
    array.append(each)

Start = b'\x16' #unsigned 22
SYNC = b'\x22' #unsigned 34
Fn_set = b'\x55' #unsigned 85
mode=int(array[0])
lower_rate_limit=int(array[1])
upper_rate_limit=int(array[2])
maximum_sensor_rate=int(array[3])
atrial_amplitude=float(array[4])
atrial_pulse_width=float(array[5])
atrial_sensitivity=float(array[6])
ventrical_amp=float(array[7])
ventrical_pulse_width=float(array[8])
ventrical_sensitivity=float(array[9])
arp=int(array[10])
vrp=int(array[11])
pvarp=int(array[12])
hyster=int(array[13])
rate_smoothing=int(array[14])
activity_thres=int(array[15])
reaction_time=int(array[16])
response_factor=int(array[17])
recovery_time=int(array[18])

if(endian_check()==True):
    # little endian
    signal_set = struct.pack("<ccBBBBffffffHHHBBBBBB",Start , Fn_set, mode,lower_rate_limit,upper_rate_limit,maximum_sensor_rate,atrial_amplitude,atrial_pulse_width,atrial_sensitivity,ventrical_amp,ventrical_pulse_width,ventrical_sensitivity,arp,vrp,pvarp,hyster,rate_smoothing,activity_thres,reaction_time,response_factor,recovery_time)
    signal_echo = struct.pack("<ccBBBBffffffHHHBBBBBB",Start , SYNC, mode,lower_rate_limit,upper_rate_limit,maximum_sensor_rate,atrial_amplitude,atrial_pulse_width,atrial_sensitivity,ventrical_amp,ventrical_pulse_width,ventrical_sensitivity,arp,vrp,pvarp,hyster,rate_smoothing,activity_thres,reaction_time,response_factor,recovery_time)
else:
    # Big endian
    signal_set = struct.pack(">ccBBBBffffffHHHBBBBBB",Start , Fn_set, mode,lower_rate_limit,upper_rate_limit,maximum_sensor_rate,atrial_amplitude,atrial_pulse_width,atrial_sensitivity,ventrical_amp,ventrical_pulse_width,ventrical_sensitivity,arp,vrp,pvarp,hyster,rate_smoothing,activity_thres,reaction_time,response_factor,recovery_time)
    signal_echo = struct.pack(">ccBBBBffffffHHHBBBBBB",Start , SYNC, mode,lower_rate_limit,upper_rate_limit,maximum_sensor_rate,atrial_amplitude,atrial_pulse_width,atrial_sensitivity,ventrical_amp,ventrical_pulse_width,ventrical_sensitivity,arp,vrp,pvarp,hyster,rate_smoothing,activity_thres,reaction_time,response_factor,recovery_time)

# mode_de = struct.unpack("B", mode_en)
# lower_rate_limit_de = struct.unpack("B", lower_rate_limit_en)
# upper_rate_limit_de =struct.unpack("B", upper_rate_limit_en)
# ventrical_amp_de = struct.unpack("f", ventrical_amp_en)
# ventrical_pulse_width_de = struct.unpack("f", ventrical_pulse_width_en)
# ventrical_sensitivity_de = struct.unpack("f", ventrical_sensitivity_en)
# vrp_de = struct.unpack("H", vrp_en)
# hyster_de = struct.unpack("B", hyster_en)
# rate_smoothing_de = struct.unpack("B", rate_smoothing_en)
# atrial_amplitude_de = struct.unpack("f", atrial_amplitude_en)
# atrial_pulse_width_de = struct.unpack("f", atrial_pulse_width_en)
# atrial_sensitivity_de = struct.unpack("f", atrial_sensitivity_en)
# arp_de = struct.unpack("H", arp_en)
# pvarp_de = struct.unpack("H", pvarp_en)
# maximum_sensor_rate_de = struct.unpack("B", maximum_sensor_rate_en)
# activity_thres_de = struct.unpack("B", activity_thres_en)
# reaction_time_de = struct.unpack("B", reaction_time_en)
# response_factor_de = struct.unpack("B", response_factor_en)
# recovery_time_de = struct.unpack("B", recovery_time_en)

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

with serial.Serial("COM5", 115200) as pacemaker:
    print("MADE INTO SERIAL")
    pacemaker.write(signal_set)
    time.sleep(1)

with serial.Serial("COM5", 115200) as pacemaker:
    pacemaker.write(signal_echo)
    print("SENT SIGNAL")
    data = pacemaker.read(43)
    print(data)
    print("READ DATA")
    start_de = struct.unpack("B", data[0])[0]
    sync_de = struct.unpack("B", data[1])[0]
    mode_de = struct.unpack("B", data[2])[0]
    lower_rate_limit_de = struct.unpack("B", data[3])[0]
    upper_rate_limit_de =struct.unpack("B", data[4])[0]
    maximum_sensor_rate_de = struct.unpack("B", data[5])[0]
    atrial_amplitude_de = struct.unpack("f", data[6:9])[0]
    atrial_pulse_width_de = struct.unpack("f", data[10:13])[0]
    atrial_sensitivity_de = struct.unpack("f", data[14:17])[0]
    ventrical_amp_de = struct.unpack("f", data[18:21])[0]
    ventrical_pulse_width_de = struct.unpack("f", data[22:25])[0]
    ventrical_sensitivity_de = struct.unpack("f", data[26:29])[0]
    arp_de = struct.unpack("H", data[30:31])[0]
    vrp_de = struct.unpack("H", data[32:33])[0]
    pvarp_de = struct.unpack("H", data[34:35])[0]
    hyster_de = struct.unpack("B", data[36])[0]
    rate_smoothing_de = struct.unpack("B", data[37])[0]
    activity_thres_de = struct.unpack("B", data[38])[0]
    reaction_time_de = struct.unpack("B", data[39])[0]
    response_factor_de = struct.unpack("B", data[40])[0]
    recovery_time_de = struct.unpack("B", data[41])[0]
    print("From the board:")
    print("mode_en: ", mode_de)
    print("lower_rate_limit_en: ", lower_rate_limit_de)
    print("upper_rate_limit_en: ", upper_rate_limit_de)
    print("maximum_sensor_rate_en: ", maximum_sensor_rate_de)
    print("atrial_amplitude_en: ", atrial_amplitude_de)
    print("atrial_pulse_width_en: ", atrial_pulse_width_de)
    print("atrial_sensitivity_en: ", atrial_sensitivity_de)
    print("ventrical_amp_en: ", ventrical_amp_de)
    print("ventrical_pulse_width_en: ", ventrical_pulse_width_de)
    print("ventrical_sensitivity_en: ", ventrical_sensitivity_de)
    print("arp_en: ", arp_de)
    print("vrp_en: ", vrp_de)
    print("pvarp_en: ", pvarp_de)
    print("hyster_en: ", hyster_de)
    print("rate_smoothing_en: ", rate_smoothing_de)
    print("activity_thres_en: ", activity_thres_de)
    print("reaction_time_en: ", reaction_time_de)
    print("response_factor_en: ", response_factor_de)
    print("recovery_time_en: ", recovery_time_de)