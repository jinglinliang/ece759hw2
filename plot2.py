import matplotlib.pyplot as plt

x = [5,6,7,8,9,10,11,12]
y = [0,0,0,0,0,3,13,46]
plt.plot(x, y, 'r-')
plt.axis([5, 12, 0, 50])
plt.ylabel('Time in ms')
plt.xlabel('Order of input size')
plt.show()
quit()