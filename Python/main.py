# dieses python-Skript kann z.B. im Terminal (bei Linux und MacOS) ueber "python3 A11a_Plot.py" aufgerufen werden
import matplotlib.pyplot as plt
# import numpy as np

infile = "./Data.csv"

t = []
Temp = []
RH = []

with open(infile, "r") as f:
    inlines = f.readlines()

i = 0
for line in inlines:
    if i == 3:
        i = 0

    if i == 0:
        t.append(float(line))
    elif i == 1:
        Temp.append(float(line))
    else:
        RH.append(float(line))
    i += 1

print(t)

# Definition der ermittelten Funktion
# def func_x_beschl(t,x_0,v_0,a):
#     return x_0 + v_0*t + 0.5 * a * t * t

# t_eval = np.linspace(0,3,100) # 100 Punkte zwischen 0 und 3 s

plt.plot(t, Temp, label="Temp")
plt.plot(t, RH, label="RH")
# # plt.scatter(t_Werte,x_Werte,marker='x',color='red')
plt.xlabel('t in s')
plt.ylabel('T in C°\nRH in %')
plt.savefig('new.png')
plt.legend()
plt.show()
