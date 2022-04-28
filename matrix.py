#!/usr/bin/env python
# coding=utf-8
import time

def init(a, b, c):
    for i in range(4096):
        for j in range(4096):
            a[i][j] = i * 2 + j
            b[i][j] = i + j * 2
            c[i][j] = 0

def run(a, b, c):
    for i in range(4096):
        for j in range(4096):
            for k in range(4096):
                c[i][j] += a[i][k] * b[k][j]

if __name__ == '__main__':
    a = [[0 for i in range(4096)] for j in range(4096)]
    b = [[0 for i in range(4096)] for j in range(4096)]
    c = [[0 for i in range(4096)] for j in range(4096)]
    begin = time.time_ns()
    run(a, b, c)
    end = time.time_ns()
    print("time comsume", (end - begin) / 1000000000)
