import matplotlib.pyplot as plt

x = [10,11,12,13,14,15,16,17,18,19]
y1 = [1,4,9,16,23,24,25,26,27,28]
y2 = [1,5,9,18,23,27,28,29,30,31]
plt.plot(x, y1, 'r-', x, y2, 'b-')
plt.axis([9, 20, 0, 32])
plt.ylabel('Time in ms')
plt.xlabel('Order of input size')
plt.show()
quit()