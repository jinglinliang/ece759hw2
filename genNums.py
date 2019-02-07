import random

intmax = 10
intmin = -10

size = 1 << 3

file = open('problem2.in','w') 

file.write(str(size))
file.write('\n')

for x in range(size):
  file.write(str(random.randint(intmin,intmax)))
  file.write('\n')

quit()