import random

COUNT = 500          # сколько чисел
MIN_VAL = -10000
MAX_VAL = 10000

values = random.sample(range(MIN_VAL, MAX_VAL + 1), COUNT)

arg = " ".join(map(str, values))

cmd = f'ARG="{arg}"; ./push_swap $ARG | ./checker_linux $ARG'

print(cmd)
