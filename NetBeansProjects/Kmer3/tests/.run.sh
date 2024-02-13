touch tests//.timeout
CMD="valgrind --leak-check=full /home/gte/acu/Latex/Docencia/MP/MP_2023_2024/Github/MP2324/NetBeans/Kmer3Teacher/dist/Debug/GNU-Linux/kmer3teacher  ../Genomes/human1_k1.prf ../Genomes/human1.prf ../Genomes/human2.prf 1> tests//.out11 2>&1"
eval $CMD
rm tests//.timeout
