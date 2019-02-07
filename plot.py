import matplotlib.pyplot as plt

x = [10,11,12,13,14,15,16,17,18,19]
y1 = [3,13,47,149,473,1547,5505,21384,84908,338697]
y2 = [0,0,1,2,5,11,21,41,77,142]
plt.plot(x, y1, 'b-', x, y2, 'r-')
plt.axis([9, 20, 0, 5000])
plt.ylabel('Time in ms')
plt.xlabel('Order of input size')
plt.show()
quit()