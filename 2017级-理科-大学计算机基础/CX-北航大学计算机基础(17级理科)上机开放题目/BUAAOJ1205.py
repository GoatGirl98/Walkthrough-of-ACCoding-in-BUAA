n = int(input())
res = float(0)
if n <= 150:
    res = float(n * 0.4463)
else:
    if n <= 400:
        res = float(150 * 0.4463 + (n - 150) * 0.4663)
    else:
        res = float(150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663)
print("%.3f" % res)
