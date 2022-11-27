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



# mode=int(array[0])
# lower_rate_limit=float(array[1])
# upper_rate_limit=float(array[2])
# maximum_sensor_rate=int(array[3])
# atrial_amplitude= float(array[4])
# atrial_pulse_width=float(array[5])
# atrial_sensitivity=float(array[6])
# ventrical_amp=float(array[7])
# ventrical_pulse_width=float(array[8])
# ventrical_sensitivity=float(array[9])
# arp=float(array[10])
# vrp=float(array[11])
# pvarp=float(array[12])
# hyster=int(array[13])
# rate_smoothing=int(array[14])
# activity_thres=int(array[15])
# reaction_time=int(array[16])
# response_factor=int(array[17])
# recovery_time=int(array[18])

if(endian_check()==True):
    # little endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    mode = struct.pack("<B", int(array[0]))
    lower_rate_limit = struct.pack("<f", float(array[1]))
    upper_rate_limit =struct.pack("<f", float(array[2]))
    maximum_sensor_rate = struct.pack("<B", int(array[3]))
    atrial_amplitude = struct.pack("<f", float(array[4]))
    atrial_pulse_width = struct.pack("<f", float(array[5]))
    atrial_sensitivity = struct.pack("<f", float(array[6]))
    ventrical_amp = struct.pack("<f", float(array[7]))
    ventrical_pulse_width = struct.pack("<f", float(array[8]))
    ventrical_sensitivity = struct.pack("<f", float(array[9]))
    arp = struct.pack("<f", float(array[10]))
    vrp = struct.pack("<f", float(array[11]))
    pvarp = struct.pack("<f", float(array[12]))
    hyster = struct.pack("<B", int(array[13]))
    rate_smoothing = struct.pack("<B", int(array[14]))
    activity_thres = struct.pack("<B", int(array[15]))
    reaction_time = struct.pack("<B", int(array[16]))
    response_factor = struct.pack("<B", int(array[17]))
    recovery_time = struct.pack("<B", int(array[18]))
    signal_set = Start + Fn_set + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time
    signal_echo = Start + SYNC + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time
else:
    # Big endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    mode = struct.pack(">B", int(array[0]))
    lower_rate_limit = struct.pack(">f", float(array[1]))
    upper_rate_limit =struct.pack(">f", float(array[2]))
    maximum_sensor_rate = struct.pack(">B", int(array[3]))
    atrial_amplitude = struct.pack(">f", float(array[4]))
    atrial_pulse_width = struct.pack(">f", float(array[5]))
    atrial_sensitivity = struct.pack(">f", float(array[6]))
    ventrical_amp = struct.pack(">f", float(array[7]))
    ventrical_pulse_width = struct.pack(">f", float(array[8]))
    ventrical_sensitivity = struct.pack(">f", float(array[9]))
    arp = struct.pack(">f", float(array[10]))
    vrp = struct.pack(">f", float(array[11]))
    pvarp = struct.pack(">f", float(array[12]))
    hyster = struct.pack(">B", int(array[13]))
    rate_smoothing = struct.pack(">B", int(array[14]))
    activity_thres = struct.pack(">B", int(array[15]))
    reaction_time = struct.pack(">B", int(array[16]))
    response_factor = struct.pack(">B", int(array[17]))
    recovery_time = struct.pack(">B", int(array[18]))
    signal_set = Start + Fn_set + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time
    signal_echo = Start + SYNC + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time

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

with serial.Serial("COM3", 115200) as pacemaker:
    print("MADE INTO SERIAL")
    pacemaker.write(signal_set)
    time.sleep(1)

with serial.Serial("COM3", 115200) as pacemaker:
    pacemaker.write(signal_echo)
    print("SENT SIGNAL")
    # data = pacemaker.read(52)
    # print(data)
    # print("READ DATA")

    # mode_de = struct.unpack("B", data[0])[0]
    # lower_rate_limit_de = struct.unpack("f", data[1:5])[0]
    # upper_rate_limit_de =struct.unpack("f", data[5:9])[0]
    # maximum_sensor_rate_de = struct.unpack("B", data[9])[0]
    # atrial_amplitude_de = struct.unpack("f", data[10:14])[0]
    # atrial_pulse_width_de = struct.unpack("f", data[14:18])[0]
    # atrial_sensitivity_de = struct.unpack("f", data[18:22])[0]
    # ventrical_amp_de = struct.unpack("f", data[22:26])[0]
    # ventrical_pulse_width_de = struct.unpack("f", data[26:30])[0]
    # ventrical_sensitivity_de = struct.unpack("f", data[30:34])[0]
    # arp_de = struct.unpack("f", data[34:38])[0]
    # vrp_de = struct.unpack("f", data[38:42])[0]
    # pvarp_de = struct.unpack("f", data[42:46])[0]
    # hyster_de = struct.unpack("B", data[46])[0]
    # rate_smoothing_de = struct.unpack("B", data[47])[0]
    # activity_thres_de = struct.unpack("B", data[48])[0]
    # reaction_time_de = struct.unpack("B", data[49])[0]
    # response_factor_de = struct.unpack("B", data[50])[0]
    # recovery_time_de = struct.unpack("B", data[51])[0]
    # print("From the board:")
    # print("mode_en: ", mode_de)
    # print("lower_rate_limit_en: ", lower_rate_limit_de)
    # print("upper_rate_limit_en: ", upper_rate_limit_de)
    # print("maximum_sensor_rate_en: ", maximum_sensor_rate_de)
    # print("atrial_amplitude_en: ", atrial_amplitude_de)
    # print("atrial_pulse_width_en: ", atrial_pulse_width_de)
    # print("atrial_sensitivity_en: ", atrial_sensitivity_de)
    # print("ventrical_amp_en: ", ventrical_amp_de)
    # print("ventrical_pulse_width_en: ", ventrical_pulse_width_de)
    # print("ventrical_sensitivity_en: ", ventrical_sensitivity_de)
    # print("arp_en: ", arp_de)
    # print("vrp_en: ", vrp_de)
    # print("pvarp_en: ", pvarp_de)
    # print("hyster_en: ", hyster_de)
    # print("rate_smoothing_en: ", rate_smoothing_de)
    # print("activity_thres_en: ", activity_thres_de)
    # print("reaction_time_en: ", reaction_time_de)
    # print("response_factor_en: ", response_factor_de)
    # print("recovery_time_en: ", recovery_time_de)