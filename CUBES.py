cube = [i * i * i for i in range(101)]
has = [0] * 1000001
for i in range(101):
    has[cube[i]] = i
for i in range(1, 101):
    for j in range(2, i):
        for k in range(j + 1, i):
            if cube[j] + cube[k] > cube[i]:
                break
            if has[cube[i] - cube[j] - cube[k]] > k:
                print('Cube = %d, Triple = (%d,%d,%d)' %(i, j, k, has[cube[i] - cube[j] - cube[k]]))