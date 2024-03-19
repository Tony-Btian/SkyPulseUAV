import matplotlib.pyplot as plt
from drawnow import drawnow
import numpy as np
from serial import Serial  # Explicitly import Serial from serial

# Function to create the plot
def plot_data():
    plt.title('Real-time Serial Data Plot')
    plt.xlabel('Time')
    plt.ylabel('Data')
    plt.grid(True)
    plt.plot(x_data, label='X')
    plt.plot(y_data, label='Y')
    plt.plot(z_data, label='Z')
    plt.legend()

# Initialize serial port
ser = Serial('/dev/ttyUSB0', 115200)  # Change '/dev/ttyUSB0' to your serial port

# Initialize empty data lists
x_data = []
y_data = []
z_data = []

# Function to read data from serial port
def read_data():
    while True:
        # Read a line of data from the serial port
        line = ser.readline().decode().strip()
        
        # Split the line into x, y, z values
        values = line.split(',')
        if len(values) == 3:
            try:
                x = float(values[0])
                y = float(values[1])
                z = float(values[2])
                
                # Append the data to the respective lists
                x_data.append(x)
                y_data.append(y)
                z_data.append(z)
            except ValueError:
                pass  # Ignore invalid data
        
        # Plot the data in real-time
        drawnow(plot_data)

# Start reading data from serial port in a separate thread
import threading
read_thread = threading.Thread(target=read_data)
read_thread.start()
# Keep the plot alive
plt.ion()
plt.show()