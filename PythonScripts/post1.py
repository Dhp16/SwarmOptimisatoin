import matplotlib
import matplotlib.pyplot as plt
import numpy as np

case = "../OutputFiles/positions.txt"

allData = []

with open(case) as file:
    for line in file:
        line = line.split();
        line = [float(i) for i in line]
        allData.append(line)
        
sums = []

for iteration in allData:
    sums.append(sum(iteration))

##
fig, ax = plt.subplots()
ax.plot(sums)

ax.set(xlabel='Iterations [-]', ylabel='Sum of every particle cost [-]',
       title='Decrease in cost with each iteration')
fig.savefig("../OutputFiles/totalCost.png")
plt.show()