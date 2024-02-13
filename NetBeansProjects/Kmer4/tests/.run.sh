touch tests//.timeout
CMD="valgrind --leak-check=full /home/gte/acu/Latex/Docencia/MP/MP_2023_2024/Github/MP2324/NetBeans/Kmer4Teacher/dist/Debug/GNU-Linux/kmer4teacher  ../Genomes/human1_k4_k5.prf ../Genomes/chimpanzee_chr6_s1_l500000_k4_k5.prf ../Genomes/human_chr6_s60000_l500000_k4_k5.prf 1> tests//.out10 2>&1"
eval $CMD
rm tests//.timeout
