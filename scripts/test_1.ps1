make clean
make debug
notice compile test/1.nto
xxd out.nvb
cat scripts/should_be_hex.hex
make clean