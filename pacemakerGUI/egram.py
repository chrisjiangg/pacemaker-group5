import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import mpld3
from mpld3 import plugins
import plotly.express as px
import pandas as pd


# generate df
graph_data = open('graph.txt', 'r').read()
lines = graph_data.split('\n')
xs = []
ys = []
for line in lines:
    if len(line) > 1:
        x, y = line.split(',')
        xs.append(x)
        ys.append(y)



df = pd.DataFrame(dict(
    x = xs,
    y = ys
))
fig = px.line(df, x="x", y="y", title="Egram Plot") 
fig.show()
