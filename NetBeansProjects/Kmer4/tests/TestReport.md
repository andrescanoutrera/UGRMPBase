# OUTCOME OF TESTS FOR PROJECT kmer4_template

As of Feb 13 2024 17:34:59

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
| 18 | T01_Basics.KmerFreq_KmerFreq |  PASSED |```KmerFreq km;km.toString()```|
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
| 24 | T01_Basics.Profile_Profile_1 |  PASSED |```Profile profl; string s; s = profl.inspectT()+ to_string(profl.getCapacity());s.c_str()```|
| | | | should give ```"unknown 0 10"```|
| 25 | T01_Basics.Profile_Profile_2 |  PASSED |```Profile profl(2);string s; s = profl.inspectT()+ to_string(profl.getCapacity());s.c_str()```|
| | | | should give ```"unknown 2 _ 0 _ 0 2"```|
| 26 | T01_Basics.Profile_getProfileId |  PASSED |```Profile profl(2);profl.getProfileId()```|
| | | | should give ```"unknown"```|
| 27 | T01_Basics.Profile_getSize |  PASSED |```Profile profl(DIM_VECTOR_KMER_FREQ+1);profl.getSize()```|
| | | | should give ```2001```|
| 28 | T01_Basics.Profile_getCapacity1 |  PASSED |```int n = 2; Profile profl(n);profl.getCapacity()```|
| | | | should give ```2```|
| 29 | T01_Basics.Profile_getCapacity2 |  PASSED |```Profile profl1; int n = profl1.INITIAL_CAPACITY*3; Profile profl(n);profl.getCapacity()```|
| | | | should give ```30```|
| 30 | T01_Basics.Profile_setProfileId_1 |  PASSED |```Profile profl; profl.setProfileId("english");profl.getProfileId()```|
| | | | should give ```"english"```|
| 31 | T01_Basics.Profile_at_0 |  PASSED |```Profile profl(2);profl.at(0).inspectT()```|
| | | | should give ```"_ 0"```|
| 32 | T01_Basics.Profile_at_1 |  PASSED |```Profile profl(2)profl.at(1).inspectT()```|
| | | | should give ```"_ 0"```|
| 33 | T01_Basics.Profile_findKmer_0 |  PASSED |```Kmer km("AA"); Profile profl;profl.findKmer(km);```|
| | | | should give ```-1```|
| 34 | T01_Basics.Profile_findKmer_1 |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); KmerFreq kmf; kmf.setKmer(km1); kmf.setFrequency(10); Profile prf(2); prf._vectorKmerFreq[0]= kmf; kmf.setKmer(km2); prf._vectorKmerFreq[1]= kmf;prf.findKmer(km1);```|
| | | | should give ```0```|
| 35 | T01_Basics.Profile_findKmer_2 |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); KmerFreq kmf; kmf.setKmer(km1); kmf.setFrequency(10); Profile prf(2); prf._vectorKmerFreq[0]= kmf; kmf.setKmer(km2); prf._vectorKmerFreq[1]= kmf;prf.findKmer(km2);```|
| | | | should give ```1```|
| 36 | T01_Basics.Profile_findKmer_3 |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); KmerFreq kmf; kmf.setKmer(km1); kmf.setFrequency(10); Profile prf(5); prf._vectorKmerFreq[0]= kmf; kmf.setKmer(km2);prf.findKmer(km2);```|
| | | | should give ```-1```|
| 37 | T01_Basics.Profile_findKmer_4 |  PASSED |```Profile prf(DIM_VECTOR_KMER_FREQ); Kmer km; KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10);prf.findKmer(km);```|
| | | | should give ```0```|
| 38 | T01_Basics.Profile_toString |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); KmerFreq kmf; Profile prf(2); kmf.setKmer(km1); kmf.setFrequency(10); prf._vectorKmerFreq[0]= kmf; kmf.setKmer(km2); prf._vectorKmerFreq[1]= kmf;std::regex_replace(prf.toString(),std::regex("\n")," ")```|
| | | | should give ```"unknown 2 AA 10 CC 10 "```|
| 39 | T01_Basics.Profile_append_0 |  PASSED |```Kmer km("AA"); string s; KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10); Profile prf; prf.append(kmf); s = prf.inspectT()+ to_string(prf.getCapacity());s.c_str()```|
| | | | should give ```"unknown 1 AA 10 10"```|
| 40 | T01_Basics.Profile_append_1 |  PASSED |```Kmer km("AA"); string s; KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10); Profile profl; profl.append(kmf); profl.append(kmf); s = profl.inspectT()+ to_string(profl.getCapacity());profl.inspectT()```|
| | | | should give ```"unknown 1 AA 20 "```|
| 41 | T01_Basics.Profile_append_2 |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); string s; KmerFreq kmf; kmf.setKmer(km1); kmf.setFrequency(10); Profile profl; profl.append(kmf); kmf.setKmer(km2); profl.append(kmf); s = profl.inspectT()+ to_string(profl.getCapacity());profl.inspectT()```|
| | | | should give ```"unknown 2 AA 10 CC 10 "```|
| 42 | T01_Basics.Profile_findKmer |  PASSED |```Profile prf(DIM_VECTOR_KMER_FREQ); Kmer km; KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10);prf.findKmer(km);```|
| | | | should give ```0```|
| 43 | T01_Basics.sort_1_orderbyFreq |  PASSED |```Profile l1; int TOPE = 4; KmerFreq kmf; for(int i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*(TOPE - i)); l1.append(kmf); } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 _ 30 __ 20 ___ 10 "```|
| 44 | T01_Basics.sort_2_orderbyFreq |  PASSED |```Profile l1; int TOPE = 4; KmerFreq kmf; for(int i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*i); l1.append(kmf); } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 ___ 30 __ 20 _ 10 "```|
| 45 | T01_Basics.Profile_getDistance_lg2lg_0 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf);l1.getDistance(l1)```|
| | | | should give ```0.000000```|
| 46 | T01_Basics.Profile_getDistance_allPresentButInReverseOrder_3 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf); kmf.setKmer(b4); l2.append(kmf); kmf.setKmer(b3); l2.append(kmf); kmf.setKmer(b2); l2.append(kmf); kmf.setKmer(b1); l2.append(kmf);l1.getDistance(l2)```|
| | | | should give ```0.500000```|
| 47 | T02_Intermediate.Kmer_Kmer_int_3 |  PASSED |```Kmer kmer(0);```|
| | | | should THROW an exception std::invalid_argument|
| 48 | T02_Intermediate.Kmer_Kmer_string_2 |  PASSED |```Kmer kmer("");```|
| | | | should THROW an exception std::invalid_argument|
| 49 | T02_Intermediate.Kmer_at_int_3_excep |  PASSED |```const Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 50 | T02_Intermediate.Kmer_at_int_3_var_excep |  PASSED |```Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 51 | T02_Intermediate.Kmer_normalize_2 |  PASSED |```Kmer kmer("at"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 52 | T02_Intermediate.Kmer_normalize_3 |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"__"```|
| 53 | T02_Intermediate.Kmer_normalize_4_ARN |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ARN);kmer.inspectT()```|
| | | | should give ```"U_"```|
| 54 | T02_Intermediate.Kmer_complementary_2 |  PASSED |```Kmer kmer1("u_"); Kmer kmer2; kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN);kmer2.inspectT()```|
| | | | should give ```"u_"```|
| 55 | T02_Intermediate.Kmer_complementary_3_excep |  PASSED |```Kmer kmer1("u_"); Kmer kmer2;kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, "A");```|
| | | | should THROW an exception std::invalid_argument|
| 56 | T02_Intermediate.KmerFreq_setFrequency_exception |  PASSED |```KmerFreq km;km.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
| 57 | T02_Intermediate.Profile_Profile_3 |  PASSED |```Profile profl(-1);```|
| | | | should THROW an exception std::out_of_range|
| 58 | T02_Intermediate.Profile_at_exception |  PASSED |```Profile profl(2);profl.at(2).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 59 | T02_Intermediate.Profile_out_of_range__append_5 |  PASSED |```int n=1; Profile profl(n); Kmer km("AA"); KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10); profl.append(kmf);profl._capacity```|
| | | | should give ```21```|
| 60 | T02_Intermediate.sort_3_tieByFreq |  PASSED |```Profile l1; int TOPE = 4; KmerFreq kmf; for(int i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*i); l1.append(kmf); } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 ___ 30 __ 20 _ 10 "```|
| 61 | T02_Intermediate.sort_4_mixed |  PASSED |```Profile l1; int TOPE = 4; int i=1; KmerFreq kmf; for(; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*i); l1.append(kmf); } Kmer km(i); kmf.setKmer(km); l1.append(kmf); l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 4 ___ 30 ____ 30 __ 20 _ 10 "```|
| 62 | T02_Intermediate.Normalize_1 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("AA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("CC"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("GG"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 4 _ 0 AA 10 CC 10 GG 10 "```|
| 63 | T02_Intermediate.Normalize_2 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("aa"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("cF"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("xu"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 4 _ 0 AA 10 C_ 10 __ 10 "```|
| 64 | T02_Intermediate.Normalize_3 |  PASSED |```Profile l1; KmerFreq kmf; Kmer km("aA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("cT"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("Ct"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 2 AA 10 CT 20 "```|
| 65 | T02_Intermediate.zip_1 |  PASSED |```Profile l1(10); l1.zip();l1._size```|
| | | | should give ```0```|
| 66 | T02_Intermediate.Profile_join_intersection_empy_1 |  PASSED |```Kmer kmer1("aa"); Kmer kmer2("bb"); Kmer kmer3("cc"); Kmer kmer4("dd"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(kmer1); l1.append(kmf); kmf.setKmer(kmer2); l1.append(kmf); kmf.setKmer(kmer3); l2.append(kmf); kmf.setKmer(kmer4); l2.append(kmf); int initialSize = l1.getSize(); l1.join(l2);l1._size```|
| | | | should give ```4```|
| 67 | T02_Intermediate.Profile_joinShouldIncreaseFrequencyWhenKmerIsAlreadyInProfile_2 |  PASSED |```Kmer kmer1("aa"); Kmer kmer2("bb"); Kmer kmer3("cc"); Kmer kmer4("dd"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(kmer1); l1.append(kmf); l2.append(kmf); kmf.setKmer(kmer2); l1.append(kmf); l2.append(kmf); kmf.setKmer(kmer3); l1.append(kmf); l2.append(kmf); kmf.setKmer(kmer4); l1.append(kmf); l2.append(kmf); l1.join(l2); int sum=0; for (int i= 0; i < l1.getSize(); i++) sum += l1.at(i).getFrequency();l1._size*20```|
| | | | should give ```80```|
| 68 | T02_Intermediate.Profile_saveLoad_1 |  PASSED |```Profile l1; Profile l2; l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/test_save1.prf"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 69 | T02_Intermediate.Profile_saveLoad_2 |  PASSED |```Profile l1; Profile l2(10); l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/test_save1.prf"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 70 | T02_Intermediate.Profile_Save_1_exception |  PASSED |```Profile l1; const char* fileName = "tests/outp/imposibleToCreateFile.prf";l1.save(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 71 | T02_Intermediate.Profile_Load_2_exception |  PASSED |```Profile l1; const char* fileName = "tests/validation/test_noHeader.prf";l1.load(fileName);```|
| | | | should THROW an exception std::invalid_argument|
| 72 | T02_Intermediate.Profile_Load_3_exception |  PASSED |```Profile l1; const char* fileName = "tests/output/test_xxx.prf";l1.load(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 73 | T02_Intermediate.Profile_getDistance_emptyToOther_1 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile empty; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf);empty.getDistance(l1)```|
| | | | should THROW an exception std::invalid_argument|
| 74 | T02_Intermediate.Profile_getDistance_otherToEmpy_2 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile empty; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf);l1.getDistance(empty)```|
| | | | should THROW an exception std::invalid_argument|
| 75 | T02_Intermediate.Profile_getDistance_4 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); Kmer b5("__"); Kmer b6("A_"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b4); l2.append(kmf); kmf.setKmer(b3); l2.append(kmf); kmf.setKmer(b5); l2.append(kmf); kmf.setKmer(b6); l2.append(kmf);l1.getDistance(l2)```|
| | | | should give ```0.875000```|
| 76 | T02_Intermediate.Profile_getDistance_5 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); Kmer b5("__"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b4); l2.append(kmf); kmf.setKmer(b3); l2.append(kmf); kmf.setKmer(b5); l2.append(kmf); kmf.setKmer(b1); l2.append(kmf);l2.getDistance(l1)```|
| | | | should give ```0.750000```|
| 77 | T03_Advanced.zip_2 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("AA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("C_"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("_G"); kmf.setKmer(km3); l1.append(kmf); l1.zip();l1.inspectT();```|
| | | | should give ```"unknown 3 AA 10 C_ 10 _G 10 "```|
| 78 | T03_Advanced.zip_3 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("A_"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("__"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("TT"); kmf.setKmer(km3); l1.append(kmf); l1.zip(true);l1.inspectT();```|
| | | | should give ```"unknown 1 TT 10 "```|
| 79| T03_Advanced.Integration_RunWithMissingArguments1-valgrind | PASSED | NO LEAKS |
| 79 | T03_Advanced.Integration_RunWithMissingArguments1 | PASSED | [kmer4]: Running without arguments.|
| 80| T03_Advanced.Integration_RunWithMissingArguments_2-valgrind | PASSED | NO LEAKS |
| 80 | T03_Advanced.Integration_RunWithMissingArguments_2 | PASSED | [kmer4 ../Genomes/7pairsDNA.prf]: Running with missing arguments|
| 81| T03_Advanced.Integration_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 81 | T03_Advanced.Integration_RunWithInvalidArguments1 | PASSED | [kmer4 -f ../Genomes/7pairsDNA.prf ../Genomes/7pairsDNA.prf]: Running with invalid arguments (-f)|
| 82| T03_Advanced.Integration_RunWithInvalidArguments2-valgrind | PASSED | NO LEAKS |
| 82 | T03_Advanced.Integration_RunWithInvalidArguments2 | PASSED | [kmer4 -t MIN ../Genomes/7pairsDNA.prf ../Genomes/7pairsDNA.prf]: Running with invalid arguments (MIN)|
| 83| T03_Advanced.Integration_7pairsDNA_7pairsDNA_1-valgrind | PASSED | NO LEAKS |
| 83 | T03_Advanced.Integration_7pairsDNA_7pairsDNA_1 | PASSED | [kmer4 ../Genomes/7pairsDNA.prf ../Genomes/7pairsDNA.prf]: Min distance from 7pairsDNA.prf to 7pairsDNA.prf|
| 84| T03_Advanced.Integration_7pairsDNA_7pairsDNA_2-valgrind | PASSED | NO LEAKS |
| 84 | T03_Advanced.Integration_7pairsDNA_7pairsDNA_2 | PASSED | [kmer4 -t max ../Genomes/7pairsDNA.prf ../Genomes/7pairsDNA.prf]: Max distance from 7pairsDNA.prf to 7pairsDNA.prf|
| 85| T03_Advanced.Integration_7pairsDNA_others_1-valgrind | PASSED | NO LEAKS |
| 85 | T03_Advanced.Integration_7pairsDNA_others_1 | PASSED | [kmer4 ../Genomes/7pairsDNA.prf ../Genomes/5pairsDNA.prf ../Genomes/6pairsDNA.prf ../Genomes/5pairsRNA.prf]: Min distance from 7pairsDNA.prf to other profiles|
| 86| T03_Advanced.Integration_7pairsDNA_others_2-valgrind | PASSED | NO LEAKS |
| 86 | T03_Advanced.Integration_7pairsDNA_others_2 | PASSED | [kmer4 -t max ../Genomes/7pairsDNA.prf ../Genomes/5pairsDNA.prf ../Genomes/6pairsDNA.prf ../Genomes/5pairsRNA.prf]: Max distance from 7pairsDNA.prf to other profiles|
| 87| T03_Advanced.Integration_human1others-valgrind | PASSED | NO LEAKS |
| 87 | T03_Advanced.Integration_human1others | PASSED | [kmer4 ../Genomes/human1.prf ../Genomes/human2.prf ../Genomes/fly1.prf ../Genomes/worm1.prf]: Min distance from human1.prf to other profiles|
| 88| T03_Advanced.Integration_human1_othersk4_k5-valgrind | PASSED | NO LEAKS |
| 88 | T03_Advanced.Integration_human1_othersk4_k5 | PASSED | [kmer4 ../Genomes/human1_k4_k5.prf ../Genomes/chimpanzee_chr6_s1_l500000_k4_k5.prf ../Genomes/human_chr6_s60000_l500000_k4_k5.prf]: Min distance from human1_k4_k5.prf to other profiles with kmers with k=4 and k=5|
| 89| T03_Advanced.Integration_human1others_k4k5-valgrind | PASSED | NO LEAKS |
| 89 | T03_Advanced.Integration_human1others_k4k5 | PASSED | [kmer4 ../Genomes/human1_k1.prf ../Genomes/human1.prf ../Genomes/human2.prf]: Min distance from human1_k1.prf to other profiles of kmers with k=5|
