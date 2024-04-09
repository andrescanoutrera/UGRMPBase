Very short DNA and RNA files
===========================
- unknownACGT2.dna: A DNA file with only 8 nucleotides
- unknownACGT.dna : A DNA file with only 9 nucleotides
- unknownACGU.rna : A RNA file with only 13 nucleotides
- unknownA.dna    : A DNA file with only 9 nucleotides (only nucleotide A appears)
- unknownAG.dna   : A DNA file with only 14 nucleotides (only nucleotides A and G appear)
- unknownT.dna    : A DNA file with only 9 nucleotides (only nucleotide T appears)

Short DNA files
===============
- ebola.dna: A DNA file with a part of the ebolavirus zaire genome (10000 nucleotides).

- fish1.dna: A DNA file with a part of the danio rerio (zebrafish) genome (10000 nucleotides).

- fly1.dna: A DNA file with a part of the drosophila melanogaster (fruit fly) genome, part of chromosome 2L (10000 nucleotides).

- fly2.dna: A DNA file with a part of the drosophila melanogaster (fruit fly) genome, part of chromosome 2L (10000 nucleotides).

- human1.dna: A DNA file with part of the homo sapiens genome, part of chromosome 9 (10000 nucleotides).

- human2.dna: A DNA file with part of the homo sapiens genome, part of chromosome 6 (10000 nucleotides).

- mouse1.dna: A DNA file with part of the mus musculus genome (mouse), part of chromosome 12 (10000 nucleotides).

- mouse2.dna: A DNA file with part of the mus musculus genome (mouse), part of chromosome 2, clone RP23-78O17 (10000 nucleotides).

- test_homoSP.dna: A DNA file with the first 1000 nucleotides in human1.dna

- worm1.dna: A DNA file with part of the caenorhabditis elegans genome (nematode), part of chromosome II (10000 nucleotides).

- worm2.dna: A DNA file with part of the caenorhabditis elegans genome (nematode), part of chromosome I (10000 nucleotides).

Wrong profiles
==============
- test_noHeader.prf: A profile file with a wrong magic string

Very short profiles for DNA or RNA
==================================
- 12pairsDNA.prf: A profile file for a DNA sequence with some kmers with the missing nucleotide.
  * The nucleotides appear in uppercase (it has been normalized).
  * It contains some kmers with the missing nucleotide (it has been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is sorted by frequency.

- 4pairsDNA.prf: A profile file for a DNA sequence, but with some kmers with invalid nucleotides for a DNA sequence. T
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * In the process of normalization of this profile we obtain identical kmers that should be merged.
  * It contains some kmers with invalid nucleotides for a DNA sequence (it has not been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is not sorted by frequency.

- 5pairsDNA.prf: A profile file for a DNA sequence, but with some kmers with invalid nucleotides for a DNA sequence.
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * It contains some kmers with invalid nucleotides for a DNA sequence (it has not been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is sorted by frequency.

- 5pairsRNA.prf: A profile file for a RNA sequence.
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * All nucleotides are valid for a RNA sequence.
  * It contains some kmers with frequency equal to 0.
  * It is not sorted by frequency nor kmer.

- 6pairs_5pairsDNA.prf: A profile file for a DNA sequence. It is the result of running kmer2 (join kmers) using 6pairsDNA.prf and 5pairsDNA.prf.
  * The nucleotides appear in uppercase (it has been normalized).
  * It contains some kmers with the missing nucleotide (it has been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is sorted by frequency.

- 6pairsbisDNA.prf: A profile file for a DNA sequence with some kmers with the missing nucleotide. It comes from the normalization of 6pairsDNA.prf
  * The nucleotides appear in uppercase (it has been normalized).
  * It contains some kmers with the missing nucleotide (it has been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is sorted by frequency.

- 6pairsDNA.prf: A profile file for a DNA sequence with some kmers with invalid nucleotides for a DNA sequence.
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * It contains some kmers with invalid nucleotides for a DNA sequence (it has not been normalized).
  * It does not contain any kmer with frequency equal to 0.
  * It is sorted by frequency.

- 6pairsRNA.prf: A profile file for a RNA sequence.
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * All nucleotides are valid for a RNA sequence.
  * It contains some kmers with frequency equal to 0.
  * It is not sorted by frequency nor kmer.

- 6pairsDNA_B.prf:A profile file for a RNA sequence. It is the same as 6pairsRNA.prf, but in binary format.

- 7pairsDNA_normalized_zipped.prf: A profile file for a DNA sequence. It is obtained by applying the kmer2 program to 7pairsDNA.prf.
  * The nucleotides appear in uppercase (it has been normalized).
  * All nucleotides are valid for a DNA sequence.
  * It does not contain any kmer with frequency equal to 0 (it has bean zipped).
  * It is sorted by frequency.

- 7pairsDNA.prf: A profile file for a DNA sequence.
  * The nucleotides appear in lowercase or uppercase (it has not been normalized).
  * All nucleotides are valid for a DNA sequence.
  * It contains some kmers with frequency equal to 0.
  * It is not sorted by frequency nor kmer.

- 7pairsDNA_B.prf: Profile file in binary format for a DNA sequence. It is the same as 7pairsDNA.prf, but in binary format.

- prep_chpz.prf: A manually modified profile for chimpanzee DNA obtained with some modifications of chimpanzee_chr6_s1_l500000.prf: Only the first 13 kmer-frequency pairs are included. Also the last digit of each frequency is discarded to obtain smaller numbers.

- prep_covid.prf: A manually modified profile for covid RNA obtained with some modifications of covidFullGenomeRNA.prf: Only the first 12 kmer-frequency pairs are included.

- prep_fly.prf: A manually modified profile for drosophila melanogaster DNA obtained with some modifications of drosophila_chr2L_s1_l500000.prf: Only the first 15 kmer-frequency pairs are included. Also the last digit of each frequency is discarded to obtain smaller numbers.

- prep_hmn.prf: A manually modified profile for human DNA obtained with some modifications of human1.prf: Only the first 15 kmer-frequency pairs are included.

- prep_xx.prf: A manually modified profile for drosophila melanogaster DNA obtained with some modifications of drosophila_chr3L_s1_l500000.prf: Only the first 10 kmer-frequency pairs are included; it is set "unknown" as identifier; and finally, the last digit of each frequency is discarded to obtain smaller numbers

Profiles for short DNA files
============================
- fly1.prf: Profile file obtained from fly1.dna using k=5.

- human1.prf: Profile file obtained from human1.dna using k=5.

- human1_k1.prf: Profile file obtained from human1.dna using k=1.

- human1_k2.prf: Profile file obtained from human1.dna using k=2.

- human1_k3.prf: Profile file obtained from human1.dna using k=3.

- human1_k4.prf: Profile file obtained from human1.dna using k=4.

- human1_k4_k5.prf: Profile file obtained from the join of human1.prf and human1_k4.prf (it contains kmers with k=4 and k=5).

- huma1_short.prf: Profile file obtained with the first 18 kmers in human1.prf using k=5.

- human2.prf: Profile file obtained from human2.dna using k=5.

- mouse1.prf: Profile file obtained from mouse1.dna using k=5.

- test_homoSP.prf: Profile file obtained from test_homoSP.dna using k=5.

- worm1.prf: Profile file obtained from worm1.dna using k=5.

Large DNA and RNA files
=======================
- chimpanzee_chr6_s1_l500000.dna: A DNA file with part of the pan troglodytes (chimpanzee) genome, part of chromosome 6 (500000 nucleotides).

- chimpanzee_chr9_s1_l500000.dna: A DNA file with part of the pan troglodytes (chimpanzee) genome, part of chromosome 9 (500000 nucleotides).

- brewers_yeast_chrVII.s1_l500000.dna: A DNA file with part of the saccharomyces cerevisiae (brewer's yeast) genome, part of chromosome VII (500000 nucleotides).

- brewers_yeast_chrX.s1_l500000.dna: A DNA file with part of the saccharomyces cerevisiae (brewer's yeast) genome, part of chromosome X (500000 nucleotides).

- covid.rna: A DNA file with  with a piece of the covid genome (4285 nucleotides).

- covidFullGenome.dna: A DNA file with the full genome of the severe acute respiratory syndrome coronavirus 2 (29903 nucleotides).

- covidFullGenome.rna: A RNA file with the full genome of the severe acute respiratory syndrome coronavirus 2 (29903 nucleotides).

- drosophila_chr2L_s1_l500000.dna: A DNA file with part of the drosophila melanogaster (fruit fly) genome, part of chromosome 2L (500000 nucleotides).

- drosophila_chr3L_s1_l500000.dna: A DNA file with part of the drosophila melanogaster (fruit fly) genome, part of chromosome 3L (500000 nucleotides).

- ebolaFullGenome.dna: A cDNA file with the full genome of the ebolavirus zaire (18957 nucleotides).

- ebolaFullGenome.rna: A RNA file with the full genome of the ebolavirus zaire (18957 nucleotides).

- human_chr6_s60000_l500000.dna: A DNA file with part of the homo sapiens genome, part of chromosome 6 (500000 nucleotides).

- human_chr9_s10000_l500000.dna: A DNA file with part of the homo sapiens genome, part of chromosome 9 (500000 nucleotides).

- monkeypoxFullGenome.dna: A DNA file with the full genome of the monkey pox virus (197209 nucleotides).

- monkeypoxFullGenome.rna: A RNA file with the full genome of the monkey pox virus (197209 nucleotides).

- mouse_chr6_s3050050_l500000.dna: A DNA file with part of the mus musculus (mouse) genome, part of chromosome 6 (500000 nucleotides).

- mouse_chr9_s3000000_l500000.dna: A DNA file with part of the mus musculus (mouse) genome, part of chromosome 9 (500000 nucleotides).

- nematode_chrI_s1l500000.dna: A DNA file with part of the caenorhabditis elegans (nematode) genome, part of chromosome I (500000 nucleotides).

- nematode_chrIV_s1l500000.dna: A DNA file with part of the caenorhabditis elegans (nematode) genome, part of chromosome IV (500000 nucleotides).

- rat_chr6_s1l500000.dna: A DNA file with part of the rattus norvegicus (common rat) genome, part of chromosome 6 (500000 nucleotides).

- rat_chr9_s1l500000.dna: A DNA file with part of the rattus norvegicus (common rat) genome, part of chromosome 9 (500000 nucleotides).

- zebrafish_chr6_s1l500000.dna: A DNA file with part of the danio rerio (zebrafish) genome, part of chromosome 6 (500000 nucleotides).

- zebrafish_chr9_s1l500000.dna: A DNA file with part of the danio rerio (zebrafish) genome, part of chromosome 9 (500000 nucleotides).

Profiles for large DNA and RNA files
====================================
- brewers_yeast_chrVII.s1_l500000.prf: Profile file obtained from brewers_yeast_chrVII.s1_l500000.dna using k=5.

- brewers_yeast_chrX.s1_l500000.prf: Profile file obtained from brewers_yeast_chrX.s1_l500000.dna using k=5.

- chimpanzee_chr6_s1_l500000.prf: Profile file obtained from chimpanzee_chr6_s1_l500000.dna using k=5.

- chimpanzee_chr9_s1_l500000.prf: Profile file obtained from chimpanzee_chr9_s1_l500000.dna using k=5.

- chimpanzee_chr6_s1_l500000_k4.prf: Profile file obtained from chimpanzee_chr9_s1_l500000.dna using k=4.

- chimpanzee_chr6_s1_l500000_k4_k5.prf: Profile file obtained from the join of chimpanzee_chr6_s1_l500000_k4.prf and chimpanzee_chr6_s1_l500000.prf (it contains kmers with k=4 and k=5).

- covidFullGenomeDNA.prf: Profile file obtained from covidFullGenome.dna using k=5.

- covidFullGenomeRNA.prf: Profile file obtained from covidFullGenome.rna using k=5.

- drosophila_chr2L_s1_l500000.prf: Profile file obtained from drosophila_chr2L_s1_l500000.dna using k=5.

- drosophila_chr3L_s1_l500000.prf: Profile file obtained from drosophila_chr3L_s1_l500000.dna using k=5.

- drosophila_chr2L_k2.prf: Profile file obtained from drosophila_chr2L_s1_l500000.dna using k=2.

- ebolaFullGenomeDNA.prf: Profile file obtained from ebolaFullGenome.dna using k=5.

- ebolaFullGenomeRNA.prf: Profile file obtained from ebolaFullGenome.rna using k=5.

- human_chr6_s60000_l500000.prf: Profile file obtained from human_chr6_s60000_l500000.dna using k=5.

- human_chr6_s60000_l500000_k1.prf: Profile file obtained from human_chr6_s60000_l500000.dna using k=1.

- human_chr6_s60000_l500000_k2.prf: Profile file obtained from human_chr6_s60000_l500000.dna using k=2.

- human_chr6_s60000_l500000_k3.prf: Profile file obtained from human_chr6_s60000_l500000.dna using k=3.

- human_chr6_s60000_l500000_k4.prf: Profile file obtained from human_chr6_s60000_l500000.dna using k=4.

- human_chr6_s60000_l500000_k4_k5.prf: Profile file obtained from the join of human_chr6_s60000_l500000_k4.prf and human_chr6_s60000_l500000_k5.prf (it contains kmers with k=4 and k=5).

- human_chr6_s60000_l500000_k1_k2_k3_k4_k5.prf: Profile file obtained from the join of the profiles human_chr6_s60000_l500000_k?.prf  (it contains kmers from k=1 to k=5).

- human_chr9_s10000_l500000.prf: Profile file obtained from human_chr9_s10000_l500000.dna using k=5.

- human_chr9_s10000_l500000B.prf: Profile file in binary format, obtained from human_chr9_s10000_l500000.dna using k=5. It contains the same profile as human_chr9_s10000_l500000.prf, but in binary format.

- monkeypoxFullGenomeDNA.prf: Profile file obtained from monkeypoxFullGenome.dna using k=5.

- monkeypoxFullGenomeRNA.prf: Profile file obtained from monkeypoxFullGenome.rna using k=5.

- mouse_chr6_s3050050_l500000.prf: Profile file obtained from mouse_chr6_s3050050_l500000.dna using k=5.

- mouse_chr9_s3000000_l500000.prf: Profile file obtained from mouse_chr9_s3000000_l500000.dna using k=5.

- nematode_chrI_s1l500000.prf: Profile file obtained from nematode_chrI_s1l500000.dna using k=5.

- nematode_chrIV_s1l500000.prf: Profile file obtained from nematode_chrIV_s1l500000.dna using k=5.

- rat_chr6_s1l500000.prf: Profile file obtained from rat_chr6_s1l500000.dna  using k=5.

- rat_chr9_s1l500000.prf: Profile file obtained from rat_chr9_s1l500000.dna  using k=5.

- zebrafish_chr6_s1l500000.prf: Profile file obtained from zebrafish_chr6_s1l500000.dna using k=5.

- zebrafish_chr9_s1l500000.prf: Profile file obtained from zebrafish_chr9_s1l500000.dna using k=5.


