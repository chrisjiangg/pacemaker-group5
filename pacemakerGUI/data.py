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

# flag = 0

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
    # flag = struct.pack("<B", int(flag))
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
    # flag = struct.pack(">B", int(flag))
    signal_set = Start + Fn_set + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time
    signal_echo = Start + SYNC + mode + lower_rate_limit + upper_rate_limit + maximum_sensor_rate + atrial_amplitude + atrial_pulse_width + atrial_sensitivity + ventrical_amp + ventrical_pulse_width + ventrical_sensitivity + arp + vrp + pvarp + hyster + rate_smoothing + activity_thres + reaction_time + response_factor + recovery_time

with serial.Serial("COM5", 115200) as pacemaker:
    pacemaker.write(signal_set)

with serial.Serial("COM5", 115200) as pacemaker:
    # pacemaker.write(signal_echo)
    # data = pacemaker.read(16)
    # mode_de = data[0]
    # lower_rate_limit_de = struct.unpack("f", data[1:5])[0]
    # upper_rate_limit_de =struct.unpack("f", data[5:9])[0]
    # maximum_sensor_rate_de =data[9]
    # atrial_amplitude_de = struct.unpack("f", data[10:14])[0]
    # atrial_pulse_width_de = struct.unpack("f", data[14:18])[0]
    # atrial_sensitivity_de = struct.unpack("f", data[18:22])[0]
    # ventrical_amp_de = struct.unpack("f", data[22:26])[0]
    # ventrical_pulse_width_de = struct.unpack("f", data[26:30])[0]
    # ventrical_sensitivity_de = struct.unpack("f", data[30:34])[0]
    # arp_de = struct.unpack("f", data[34:38])[0]
    # vrp_de = struct.unpack("f", data[38:42])[0]
    # pvarp_de = struct.unpack("f", data[42:46])[0]
    # hyster_de = data[46]
    # rate_smoothing_de = data[47]
    # activity_thres_de = data[48]
    # reaction_time_de = data[49]
    # response_factor_de = data[50]
    # recovery_time_de = data[51]
    # flag_de = data[52]
    print("From the board:")
    print("\n")
    # print("mode_en: ", mode_de)
    # print("\n")
    # print("lower_rate_limit_en: ", lower_rate_limit_de)
    # print("\n")
    # print("upper_rate_limit_en: ", upper_rate_limit_de)
    # print("\n")
    # print("maximum_sensor_rate_en: ", maximum_sensor_rate_de)
    # print("\n")
    # print("atrial_amplitude_en: ", atrial_amplitude_de)
    # print("\n")
    # print("atrial_pulse_width_en: ", atrial_pulse_width_de)
    # print("\n")
    # print("atrial_sensitivity_en: ", atrial_sensitivity_de)
    # print("\n")
    # print("ventrical_amp_en: ", ventrical_amp_de)
    # print("\n")
    # print("ventrical_pulse_width_en: ", ventrical_pulse_width_de)
    # print("\n")
    # print("ventrical_sensitivity_en: ", ventrical_sensitivity_de)
    # print("\n")
    # print("arp_en: ", arp_de)
    # print("\n")
    # print("vrp_en: ", vrp_de)
    # print("\n")
    # print("pvarp_en: ", pvarp_de)
    # print("\n")
    # print("hyster_en: ", hyster_de)
    # print("\n")
    # print("rate_smoothing_en: ", rate_smoothing_de)
    # print("\n")
    # print("activity_thres_en: ", activity_thres_de)
    # print("\n")
    # print("reaction_time_en: ", reaction_time_de)
    # print("\n")
    # print("response_factor_en: ", response_factor_de)
    # print("\n")
    # print("recovery_time_en: ", recovery_time_de)
    # print("\n")
    i=0
    x=0
    while(1):
        pacemaker.write(signal_echo)
        data = pacemaker.read(16)
        atr_signal_de = struct.unpack("d", data[0:8])[0]
        vent_signal_de = struct.unpack("d", data[8:16])[0]
        # print("atrial_signal: ", atr_signal_de)
        # print("\n")
        # print("ventrical_signal: ", vent_signal_de)
        # print("\n")
        i=i+1
        x=x+1
        time.sleep(1)
        text = str(x) + ", " + str(atr_signal_de) + "\n"
        text2 = str(x) + ", " + str(vent_signal_de) + "\n"
        print(text)
        afile = open("graphatrium.txt", "a")
        afile.write(text)
        if(i==1000):
            afile.close()
            break  
        
   
    print("Done")
