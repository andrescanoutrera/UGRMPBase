# OUTCOME OF TESTS FOR PROJECT kmer0_template

As of Feb 13 2024 10:01:01

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
| 11 | T01_Basics.Kmer_normalize_1 |  PASSED |```Kmer kmer("AT"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 12 | T01_Basics.Kmer_complementary_1 |  PASSED |```Kmer kmer1(VALID_NUCLEOTIDES_ADN); Kmer kmer2(kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN)); string skmer3 = COMPLEMENTARY_NUCLEOTIDES_ADN;kmer2.inspectT()```|
| | | | should give ```"TGCA"```|
| 13 | T01_Basics.IsValidNucleotide_ACGT |  PASSED |```int i; int n = VALID_NUCLEOTIDES_ADN.length(); char c; string ss; for (i = 0; i < n; i++) { c = VALID_NUCLEOTIDES_ADN.at(i); if (IsValidNucleotide(c, VALID_NUCLEOTIDES_ADN)) ss += VALID_NUCLEOTIDES_ADN.at(i); }ss```|
| | | | should give ```"ACGT"```|
| 14 | T01_Basics.IsValidNucleotide_ACGU |  PASSED |```int i; int n = VALID_NUCLEOTIDES_ARN.length(); char c; string ss; for (i = 0; i < n; i++) { c = VALID_NUCLEOTIDES_ARN.at(i); if (IsValidNucleotide(c, VALID_NUCLEOTIDES_ARN)) ss += VALID_NUCLEOTIDES_ARN.at(i); }ss```|
| | | | should give ```"ACGU"```|
| 15 | T01_Basics.IsValidNucleotide_X |  PASSED |```char c='X';IsValidNucleotide(c,VALID_NUCLEOTIDES_ADN);```|
| | | | should give ```false```|
| 16 | T01_Basics.ToUpper_au |  PASSED |```Kmer kmer("au");ToUpper(kmer);kmer.inspectT();```|
| | | | should give ```"AU"```|
| 17 | T01_Basics.ToLower_AU |  PASSED |```Kmer kmer("AU");ToLower(kmer);kmer.inspectT();```|
| | | | should give ```"au"```|
| 18 | T02_Intermediate.Kmer_Kmer_int_3 |  PASSED |```Kmer kmer(0);```|
| | | | should THROW an exception std::invalid_argument|
| 19 | T02_Intermediate.Kmer_Kmer_string_2 |  PASSED |```Kmer kmer("");```|
| | | | should THROW an exception std::invalid_argument|
| 20 | T02_Intermediate.Kmer_at_int_3_excep |  PASSED |```const Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 21 | T02_Intermediate.Kmer_at_int_3_var_excep |  PASSED |```Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 22 | T02_Intermediate.Kmer_normalize_2 |  PASSED |```Kmer kmer("at"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 23 | T02_Intermediate.Kmer_normalize_3 |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"__"```|
| 24 | T02_Intermediate.Kmer_normalize_4_ARN |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ARN);kmer.inspectT()```|
| | | | should give ```"U_"```|
| 25 | T02_Intermediate.Kmer_complementary_2 |  PASSED |```Kmer kmer1("u_"); Kmer kmer2; kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN);kmer2.inspectT()```|
| | | | should give ```"u_"```|
| 26 | T02_Intermediate.Kmer_complementary_3_excep |  PASSED |```Kmer kmer1("u_"); Kmer kmer2;kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, "A");```|
| | | | should THROW an exception std::invalid_argument|
| 27| T03_Advanced.Integration_easyDNA2_missing-valgrind | PASSED | NO LEAKS |
| 27 | T03_Advanced.Integration_easyDNA2_missing | PASSED | [kmer0 < data/easyDNA2_missing.k0in]: Easy test with a few nucleotides. There are some missing nucleotides. K=2|
| 28| T03_Advanced.Integration_easyDNA3-valgrind | PASSED | NO LEAKS |
| 28 | T03_Advanced.Integration_easyDNA3 | PASSED | [kmer0 < data/easyDNA3.k0in]: Easy test with a few nucleotides. K=3|
| 29| T03_Advanced.Integration_easyDNA5_missing-valgrind | PASSED | NO LEAKS |
| 29 | T03_Advanced.Integration_easyDNA5_missing | PASSED | [kmer0 < data/easyDNA5_missing.k0in]: Easy test with a few nucleotides. There are some missing nucleotides. K=5|
| 30| T03_Advanced.Integration_easyDNA5-valgrind | PASSED | NO LEAKS |
| 30 | T03_Advanced.Integration_easyDNA5 | PASSED | [kmer0 < data/easyDNA5.k0in]: Easy test with a few nucleotides. K=5|
| 31| T03_Advanced.Integration_shortDNA1_missing-valgrind | PASSED | NO LEAKS |
| 31 | T03_Advanced.Integration_shortDNA1_missing | PASSED | [kmer0 < data/shortDNA1_missing.k0in]: Short test with 37 nucleotides. There are some missing nucleotides. K=1|
| 32| T03_Advanced.Integration_shortDNA20_missing-valgrind | PASSED | NO LEAKS |
| 32 | T03_Advanced.Integration_shortDNA20_missing | PASSED | [kmer0 < data/shortDNA20_missing.k0in]: Short test with 20 nucleotides. There are some missing nucleotides. K=20|
| 33| T03_Advanced.Integration_shortDNA25_no-valgrind | PASSED | NO LEAKS |
| 33 | T03_Advanced.Integration_shortDNA25_no | PASSED | [kmer0 < data/shortDNA25_no.k0in]: Short test with 19 nucleotides. There are some missing nucleotides. K=25|
| 34| T03_Advanced.Integration_shortDNA5_missing-valgrind | PASSED | NO LEAKS |
| 34 | T03_Advanced.Integration_shortDNA5_missing | PASSED | [kmer0 < data/shortDNA5_missing.k0in]: Short test with 37 nucleotides. There are some missing nucleotides. K=5|
| 35| T03_Advanced.Integration_simpleDNA250-valgrind | PASSED | NO LEAKS |
| 35 | T03_Advanced.Integration_simpleDNA250 | PASSED | [kmer0 < data/simpleDNA250.k0in]: Short test with 250 nucleotides. There are some missing nucleotides. K=250|
| 36| T03_Advanced.Integration_simpleDNA5-valgrind | PASSED | NO LEAKS |
| 36 | T03_Advanced.Integration_simpleDNA5 | PASSED | [kmer0 < data/simpleDNA5.k0in]: Simple test with 250 nucleotides. There are some missing nucleotides. The array of kmers will be completely filled and some kmers will be left unsaved (from 100 onwards). K=5|
