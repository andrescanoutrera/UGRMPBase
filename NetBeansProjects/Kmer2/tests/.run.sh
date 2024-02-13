touch tests//.timeout
CMD="valgrind --leak-check=full /home/gte/acu/Latex/Docencia/MP/MP_2023_2024/Github/MP2324/NetBeans/Kmer2Teacher/dist/Debug/GNU-Linux/kmer2teacher  tests/output/human_chr6_s60000_l500000_k1_k2_k3_k4_k5.prf ../Genomes/human_chr6_s60000_l500000_k1.prf ../Genomes/human_chr6_s60000_l500000_k2.prf ../Genomes/human_chr6_s60000_l500000_k3.prf ../Genomes/human_chr6_s60000_l500000_k4.prf ../Genomes/human_chr6_s60000_l500000.prf 1> tests//.out10 2>&1"
eval $CMD
rm tests//.timeout
