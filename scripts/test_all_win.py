import os

os.system("make clean")
os.system("make")
print("TEST 01")
os.system("notice.exe compile test/0.nto")
os.system("make clean")