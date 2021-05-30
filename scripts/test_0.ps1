make clean
make debug
notice compile test/0.nto
echo Expected:
cat scripts/expected_0.hex
echo Output:
xxd out.nvb
make clean