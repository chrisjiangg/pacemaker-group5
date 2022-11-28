import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.widgets import Button, RadioButtons, CheckButtons
import mpld3
from matplotlib.pyplot import figure

style.use('fivethirtyeight')

figure = plt.figure()
ax1 = figure.add_subplot(1,1,1)

def animate(i):

    graph_data = open('graph.txt', 'r').read()
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
plt.show()