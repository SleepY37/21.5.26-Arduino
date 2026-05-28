def fahrenheit_zu_celsius(F):
    C = (F - 32) * 5 / 9
    return C

f = 98.6
print("Celsius:", fahrenheit_zu_celsius(f))