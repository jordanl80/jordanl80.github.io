import matplotlib.pyplot as plt
import os.path
import numpy as np

# Set directory and open file in directory
directory = os.path.dirname(os.path.abspath(__file__))
filename = os.path.join(directory, "cars.csv")
datafile = open(filename, 'r')

# Initialize lists
mpgs=[]
horses=[]

# Skip first two lines in csv file
next(datafile)
next(datafile)

# Splits each line, grabs appropriate mpg and horsepower data, converts to floats
for line in datafile:
    mpg = float(line.split(";")[1])
    horse = float(line.split(";")[4])
    if mpg == 0 or horse == 0:
        pass #Skip data where mpg or horsepower is 0
    else:
        mpgs.append(mpg)
        horses.append(horse)

datafile.close()

# Create plots with labels on axes
fig, ax = plt.subplots(1,1)
ax.plot(mpgs, horses, "bs")
plt.ylabel("Horsepower")
plt.xlabel("MPG")
ax.set_title("Horsepower vs. MPG")
'''
# Optional line of best fit
fit = np.polyfit(mpgs,horses,2) # Quadratic curve of best fit, change to '1' for line of best fit
fit_fn=np.poly1d(fit)
plt.plot(mpgs,horses,'bs',mpgs, fit_fn(mpgs), '--r')
plt.xlim(0,50)
plt.ylim(0,250)
'''
# Show the figure
fig.show()