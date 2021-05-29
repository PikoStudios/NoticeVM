import os

os.system("make clean")
os.system("make CC=gcc EXEC=bin/notice")
print("TEST 01")
os.system("./bin/notice compile test/0.nto")
os.system("make clean")