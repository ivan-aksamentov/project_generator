import numpy as np
import pyplchldr as m

print("Hello, this is ", m.__name__)
print("Today is ", m.day_of_week_today())
print("Here is some integer: ", m.add(1, 3))
print("Here is some float: ",
      m.cuda_sum(np.array([0.0, 1.0, 2.0, 3.0, 4.0, 5.0])))
