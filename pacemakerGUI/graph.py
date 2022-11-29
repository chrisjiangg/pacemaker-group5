import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.widgets import Button, RadioButtons, CheckButtons
import mpld3
from matplotlib.pyplot import figure

style.use('fivethirtyeight')
pause = False
figure = plt.figure()
ax1 = figure.add_subplot(1,1,1)



def onClick(event):
    global pause
    pause ^= True
figure.canvas.mpl_connect('button_press_event', onClick)
  

def animate(i):
    graph_data = open('graphatrium.txt', 'r').read()
    lines = graph_data.split('\n')
    xs = []
    ys = []
    for line in lines:
        if len(line) > 1:
            x, y = line.split(',')
            xs.append(x)
            ys.append(y)
    ax1.clear()
    ax1.plot(xs, ys)

ani = animation.FuncAnimation(figure, animate, interval=1000)
if pause:
    print("Animation is paused")
    ani.pause()
else:
    ani.resume()
    
plt.show()