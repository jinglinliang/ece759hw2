import random

intmax = 1 << 30
intmin = -(1 << 30)

size = 1 << 10

file = open('problem1.in','w') 
file.write(str(size))
file.write('\n')

for x in range(size):
  file.write(str(random.randint(intmin,intmax)))
  file.write('\n')

quit()