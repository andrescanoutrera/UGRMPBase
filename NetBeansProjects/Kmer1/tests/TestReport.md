# OUTCOME OF TESTS FOR PROJECT kmer1_template

As of Feb 13 2024 10:09:59

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Kmer_Kmer_int_1 |  PASSED |```Kmer kmer;kmer.inspectT()```|
| | | | should give ```"_"```|
| 2 | T01_Basics.Kmer_Kmer_int_2 |  PASSED |```Kmer kmer(3);kmer.inspectT()```|
| | | | should give ```"___"```|
| 3 | T01_Basics.Kmer_Kmer_string_1 |  PASSED |```Kmer kmer("ATG");kmer.inspectT()```|
| | | | should give ```"ATG"```|
| 4 | T01_Basics.Kmer_getK |  PASSED |```Kmer kmer("AT");kmer.getK()```|
| | | | should give ```2```|
| 5 | T01_Basics.Kmer_size |  PASSED |```Kmer kmer;kmer.size()```|
| | | | should give ```1```|
| 6 | T01_Basics.Kmer_toString |  PASSED |```Kmer b("ab");b.toString();```|
| | | | should give ```"ab"```|
| 7 | T01_Basics.Kmer_at_int_1 |  PASSED |```const Kmer kmer("ab");kmer.at(0);```|
| | | | should give ```"a"```|
| 8 | T01_Basics.Kmer_at_int_2 |  PASSED |```const Kmer kmer("ab");kmer.at(1);```|
| | | | should give ```"b"```|
| 9 | T01_Basics.Kmer_at_int_1_var |  PASSED |```Kmer kmer("AT"); kmer.at(0) = 'C';kmer.inspectT()```|
| | | | should give ```"CT"```|
| 10 | T01_Basics.Kmer_at_int_2_var |  PASSED |```Kmer kmer("AT"); kmer.at(1) = 'C';kmer.inspectT()```|
| | | | should give ```"AC"```|
| 11 | T01_Basics.toUpper_au |  PASSED |```Kmer kmer("au");kmer.toUpper();kmer.inspectT();```|
| | | | should give ```"AU"```|
| 12 | T01_Basics.toLower_AU |  PASSED |```Kmer kmer("AU");kmer.toLower();kmer.inspectT();```|
| | | | should give ```"au"```|
| 13 | T01_Basics.Kmer_normalize_1 |  PASSED |```Kmer kmer("AT"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 14 | T01_Basics.Kmer_complementary_1 |  PASSED |```Kmer kmer1(VALID_NUCLEOTIDES_ADN); Kmer kmer2(kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN)); string skmer3 = COMPLEMENTARY_NUCLEOTIDES_ADN;kmer2.inspectT()```|
| | | | should give ```"TGCA"```|
| 15 | T01_Basics.IsValidNucleotide_ACGT |  PASSED |```int i; int n = VALID_NUCLEOTIDES_ADN.length(); char c; string ss; for (i = 0; i < n; i++) { c = VALID_NUCLEOTIDES_ADN.at(i); if (IsValidNucleotide(c, VALID_NUCLEOTIDES_ADN)) ss += VALID_NUCLEOTIDES_ADN.at(i); }ss```|
| | | | should give ```"ACGT"```|
| 16 | T01_Basics.IsValidNucleotide_ACGU |  PASSED |```int i; int n = VALID_NUCLEOTIDES_ARN.length(); char c; string ss; for (i = 0; i < n; i++) { c = VALID_NUCLEOTIDES_ARN.at(i); if (IsValidNucleotide(c, VALID_NUCLEOTIDES_ARN)) ss += VALID_NUCLEOTIDES_ARN.at(i); }ss```|
| | | | should give ```"ACGU"```|
| 17 | T01_Basics.IsValidNucleotide_X |  PASSED |```char c='X';IsValidNucleotide(c,VALID_NUCLEOTIDES_ADN);```|
| | | | should give ```false```|
| 18 | T01_Basics.KmerFreq_KmerFreq_ |  PASSED |```KmerFreq km;km.toString()```|
| | | | should give ```"_ 0"```|
| 19 | T01_Basics.KmerFreq_getKmer_ |  PASSED |```KmerFreq km;km.getKmer().toString()```|
| | | | should give ```"_"```|
| 20 | T01_Basics.KmerFreq_getFreq_ |  PASSED |```KmerFreq km;km.getFrequency()```|
| | | | should give ```0```|
| 21 | T01_Basics.KmerFreq_setKmer_ |  PASSED |```Kmer b("XY");KmerFreq km;km.setKmer(b);km.getKmer().toString()```|
| | | | should give ```"XY"```|
| 22 | T01_Basics.KmerFreq_setFrequency_ |  PASSED |```KmerFreq km; km.setFrequency(10);km.getFrequency();```|
| | | | should give ```10```|
| 23 | T01_Basics.KmerFreq_toString_ |  PASSED |```KmerFreq km;km.toString()```|
| | | | should give ```"_ 0"```|
| 24 | T02_Intermediate.Kmer_Kmer_int_3 |  PASSED |```Kmer kmer(0);```|
| | | | should THROW an exception std::invalid_argument|
| 25 | T02_Intermediate.Kmer_Kmer_string_2 |  PASSED |```Kmer kmer("");```|
| | | | should THROW an exception std::invalid_argument|
| 26 | T02_Intermediate.Kmer_at_int_3_excep |  PASSED |```const Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 27 | T02_Intermediate.Kmer_at_int_3_var_excep |  PASSED |```Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 28 | T02_Intermediate.Kmer_normalize_2 |  PASSED |```Kmer kmer("at"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 29 | T02_Intermediate.Kmer_normalize_3 |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"__"```|
| 30 | T02_Intermediate.Kmer_normalize_4_ARN |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ARN);kmer.inspectT()```|
| | | | should give ```"U_"```|
| 31 | T02_Intermediate.Kmer_complementary_2 |  PASSED |```Kmer kmer1("u_"); Kmer kmer2; kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN);kmer2.inspectT()```|
| | | | should give ```"u_"```|
| 32 | T02_Intermediate.Kmer_complementary_3_excep |  PASSED |```Kmer kmer1("u_"); Kmer kmer2;kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, "A");```|
| | | | should THROW an exception std::invalid_argument|
| 33 | T02_Intermediate.KmerFreq_setFrequency_exception |  PASSED |```KmerFreq km;km.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
| 34 | T02_Intermediate.AKFF_printAKF_ |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; std::string sout; ostringstream ssout; std::streambuf *old = std::cout.rdbuf(ssout.rdbuf()); fillAKF_aa_cc_gg(kfa, nKmers); PrintArrayKmerFreq(kfa, nKmers); sout = ssout.str(); sout = std::regex_replace(sout, std::regex(ENDL), " "); std::cout.rdbuf(old);sout```|
| | | | should give ```"3 aa 1 cc 11 gg 111 "```|
| 35 | T02_Intermediate.AKFF_swapAKF_ |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers); SwapElementsArrayKmerFreq(kfa, nKmers, 0, 1);printAKF(kfa, nKmers);```|
| | | | should give ```"3 cc 11 aa 1 gg 111 "```|
| 36 | T02_Intermediate.AKFF_sortAKF_1 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"aa","cc","gg",3,2,1); SortArrayKmerFreq(kfa, nKmers);printAKF(kfa, nKmers);```|
| | | | should give ```"3 aa 3 cc 2 gg 1 "```|
| 37 | T02_Intermediate.AKFF_NormalizeAKF_1 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"AA","CC","GG"); NormalizeArrayKmerFreq(kfa, nKmers, VALID_NUCLEOTIDES_ADN);printAKF(kfa, nKmers);```|
| | | | should give ```"3 AA 1 CC 11 GG 111 "```|
| 38 | T02_Intermediate.AKFF_zipAKF_1 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers); ZipArrayKmerFreq(kfa, nKmers);printAKF(kfa,nKmers);```|
| | | | should give ```"3 aa 1 cc 11 gg 111 "```|
| 39 | T03_Advanced.AKFF_readAKF_ |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; std::string sin="3 aa 1 bb 11 cc 111"; istringstream ssin(sin); std::streambuf *old = std::cin.rdbuf(ssin.rdbuf()); ReadArrayKmerFreq(kfa, MAX, nKmers); std::cin.rdbuf(old);printAKF(kfa,nKmers);```|
| | | | should give ```"3 aa 1 bb 11 cc 111 "```|
| 40 | T03_Advanced.AKFF_sortAKF_2_tie |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"gg","cc","aa",1,1,1); SortArrayKmerFreq(kfa, nKmers);printAKF(kfa, nKmers);```|
| | | | should give ```"3 aa 1 cc 1 gg 1 "```|
| 41 | T03_Advanced.AKFF_sortAKF_3 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"aa","cc","gg",1,2,3); SortArrayKmerFreq(kfa, nKmers);printAKF(kfa, nKmers);```|
| | | | should give ```"3 gg 3 cc 2 aa 1 "```|
| 42 | T03_Advanced.AKFF_NormalizeAKF_2 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"aa","Cf","xu", 1,2,0); NormalizeArrayKmerFreq(kfa, nKmers, VALID_NUCLEOTIDES_ADN);printAKF(kfa, nKmers);```|
| | | | should give ```"3 AA 1 C_ 2 __ 0 "```|
| 43 | T03_Advanced.AKFF_NormalizeAKF_3 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"aA","cT","Ct"); NormalizeArrayKmerFreq(kfa, nKmers, VALID_NUCLEOTIDES_ADN);printAKF(kfa, nKmers);```|
| | | | should give ```"2 AA 1 CT 122 "```|
| 44 | T03_Advanced.AKFF_zipAKF_2 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"_A","C_","TT", 1,2,0); ZipArrayKmerFreq(kfa, nKmers, true);printAKF(kfa,nKmers);```|
| | | | should give ```"0 "```|
| 45 | T03_Advanced.AKFF_zipAKF_3 |  PASSED |```KmerFreq kfa[MAX]; int nKmers = 0; fillAKF_aa_cc_gg(kfa, nKmers,"AA","__","TT", 1,2,0); ZipArrayKmerFreq(kfa, nKmers, false, 1);printAKF(kfa,nKmers);```|
| | | | should give ```"1 __ 2 "```|
| 46| T03_Advanced.Integration_4pairsDNA_normalize-valgrind | PASSED | NO LEAKS |
| 46 | T03_Advanced.Integration_4pairsDNA_normalize | PASSED | [kmer1 < data/4pairsDNA.k1in]: 4 pairs. In the process of normalization, duplicated kmers are obtained, and so they should be removed|
| 47| T03_Advanced.Integration_5pairsDNA_missing-valgrind | PASSED | NO LEAKS |
| 47 | T03_Advanced.Integration_5pairsDNA_missing | PASSED | [kmer1 < data/5pairsDNA_missing.k1in]: 5 pairs. There are some missing nucleotides.|
| 48| T03_Advanced.Integration_6pairsDNA_missing-valgrind | PASSED | NO LEAKS |
| 48 | T03_Advanced.Integration_6pairsDNA_missing | PASSED | [kmer1 < data/6pairsDNA_missing.k1in]: 6 pairs. There are some missing nucleotides.|
| 49| T03_Advanced.Integration_6pairsDNAsorted-valgrind | PASSED | NO LEAKS |
| 49 | T03_Advanced.Integration_6pairsDNAsorted | PASSED | [kmer1 < data/6pairsDNAsorted.k1in]: 6 pairs that are already ordered by frequency. There are no missing nucleotides and no frequencies equals to zero|
| 50| T03_Advanced.Integration_6pairsDNA-valgrind | PASSED | NO LEAKS |
| 50 | T03_Advanced.Integration_6pairsDNA | PASSED | [kmer1 < data/6pairsDNA.k1in]: 6 pairs. There are no missing nucleotides and no frequencies equals to zero|
| 51| T03_Advanced.Integration_humanPairs_short_disordered-valgrind | PASSED | NO LEAKS |
| 51 | T03_Advanced.Integration_humanPairs_short_disordered | PASSED | [kmer1 < data/humanPairs_short_disordered.k1in]: 108 pairs. There are some pairs with frequency=0. Note that the array in main() has capacity for only 100 pairs, so only the first 100 pairs will be read.|
| 52| T03_Advanced.Integration_zeroPairs-valgrind | PASSED | NO LEAKS |
| 52 | T03_Advanced.Integration_zeroPairs | PASSED | [kmer1 < data/zeroPairs.k1in]: 0 pairs. Empty output will be obtained|
