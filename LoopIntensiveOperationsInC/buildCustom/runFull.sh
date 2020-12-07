rm LoopIntensiveOperationsInC
rm LoopIntensiveOperationsInC.*
rm LoopIntensiveOperationsInC_map.out
make clean
make
jpar_all 4 LoopIntensiveOperationsInC > executionTrace.txt
