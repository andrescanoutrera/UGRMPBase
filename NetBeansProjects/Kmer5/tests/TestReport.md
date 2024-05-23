# OUTCOME OF TESTS FOR PROJECT kmer5_template

As of May 20 2024 09:28:12

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
| 38 | T01_Basics.Profile_toString |  PASSED |```Kmer km1("AA"); Kmer km2("CC"); KmerFreq kmf; Profile prf(2); kmf.setKmer(km1); kmf.setFrequency(10); prf._vectorKmerFreq[0]= kmf; kmf.setKmer(km2); prf._vectorKmerFreq[1]= kmf;std::regex_replace(prf.toString(),std::regex(ENDL)," ")```|
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
| 47 | T01_Basics.Profile_OperatorAssign_0 |  PASSED |```Profile profl; profl.setProfileId("bug"); string s; Profile profl2(10); profl2 = profl; s = profl2.inspectT()+ to_string(profl2.getCapacity());s.c_str()```|
| | | | should give ```"bug 0 10"```|
| 48 | T01_Basics.Profile_ProfileCopy_0 |  PASSED |```Profile profl; profl.setProfileId("bug"); Profile profl2(profl); string s = profl2.inspectT()+ to_string(profl2.getCapacity());s.c_str()```|
| | | | should give ```"bug 0 10"```|
| 49 | T01_Basics.Counter_Counter_0 |  PASSED |```KmerCounter kc; string s; string ss; int m; int n; m = kc._allNucleotides.size(); n = pow(m,kc._k); s = kc._allNucleotides +" "+ to_string(kc._k) +" "; for(int i=0; i< n; i++){ s += "0 ";}kc.inspectT()```|
| | | | should give ```"_ACGT 5 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 50 | T01_Basics.Counter_Counter_1 |  PASSED |```int k = 3; string s; string ss; int m; int n; KmerCounter kc(k); m = kc._allNucleotides.size(); n = pow(m,k); s = kc._allNucleotides +" "+ to_string(kc._k) +" "; for(int i=0; i< n; i++){ s += "0 ";}kc.inspectT()```|
| | | | should give ```"_ACGT 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 51 | T01_Basics.Counter_Counter_2 |  PASSED |```const string validChars = "AC"; int k = 3; KmerCounter kc(k,validChars); string s; string ss; int m; int n; m = kc._allNucleotides.size(); n = pow(m,k); s = kc._allNucleotides +" "+ to_string(kc._k) +" "; for(int i=0; i< n; i++){ s += "0 ";} ss = to_string(kc._k)+" "+to_string(m)+" "+to_string(n)+" "+to_string(s.size());kc.inspectT()```|
| | | | should give ```"_AC 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 52 | T01_Basics.Counter_getNumNucleotides |  PASSED |```const string validChars = "AC"; int k = 3; KmerCounter kc(k,validChars);kc.getNumNucleotides();```|
| | | | should give ```3```|
| 53 | T01_Basics.Counter_getK |  PASSED |```const string validChars = "AC"; int k = 3; KmerCounter kc(k,validChars);kc.getK();```|
| | | | should give ```3```|
| 54 | T01_Basics.Counter_getNumKmers |  PASSED |```const string validChars = "AC"; int k = 3; KmerCounter kc(k,validChars);kc.getNumKmers();```|
| | | | should give ```27```|
| 55 | T01_Basics.Counter_getNumRows |  PASSED |```KmerCounter kc; int m; int n; int k = ((kc._k + 1) /2 ); m = kc._allNucleotides.size(); n = pow(m,k);kc.getNumRows();```|
| | | | should give ```125```|
| 56 | T01_Basics.Counter_getNumCols |  PASSED |```KmerCounter kc; int m; int n; int k = (kc._k - (kc._k + 1)/2 ); m = kc._allNucleotides.size(); n = pow(m,k);kc.getNumCols();```|
| | | | should give ```25```|
| 57 | T01_Basics.Counter_getRowColumn_1 |  PASSED |```int fila=-1; int col=-1; KmerCounter kc; Kmer km("_____"); kc.getRowColumn(km,fila, col);(fila==0 && col==0)```|
| | | | should give ```true```|
| 58 | T01_Basics.Counter_getRowColumn_2 |  PASSED |```int fila=-1; int col=-1; bool iguales=false; KmerCounter kc; Kmer km("TTTTT"); kc.getRowColumn(km,fila, col); iguales = (fila==(kc.getNumRows()-1) and col==(kc.getNumCols()-1));iguales```|
| | | | should give ```true```|
| 59 | T01_Basics.Counter_getKmer_1 |  PASSED |```KmerCounter kc(2); Kmer km; int fila=0; int col=0; km=kc.getKmer(fila, col);km.toString()```|
| | | | should give ```"__"```|
| 60 | T01_Basics.Counter_getKmer_2 |  PASSED |```KmerCounter kc(2); Kmer km; int fila=kc.getNumRows()-1; int col=kc.getNumCols()-1; km=kc.getKmer(fila, col);km.toString()```|
| | | | should give ```"TT"```|
| 61 | T01_Basics.Counter_Counter_Copy01 |  PASSED |```const string validChars = "AC"; int k=2; Kmer b("AA"); KmerCounter ki(k,validChars); KmerCounter kc(ki); kc._frequency[2][2]= 10;kc.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 10 "```|
| 62 | T01_Basics.Counter_Counter_Copy02 |  PASSED |```const string validChars = "AC"; int k=2; Kmer b("AA"); KmerCounter ki(k,validChars); KmerCounter kc(ki); kc._frequency[2][2]= 10;ki.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 0 "```|
| 63 | T01_Basics.Counter_assign_01 |  PASSED |```const string validChars = "AC"; int k=2; Kmer b("AA"); KmerCounter ki(k,validChars); KmerCounter kc; ki._frequency[2][2]= 10; kc = ki;kc.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 10 "```|
| 64 | T01_Basics.Counter_assign_02 |  PASSED |```const string validChars = "AC"; int k=2; Kmer b("AA"); KmerCounter ki(k,validChars); KmerCounter kc; kc = ki; kc._frequency[2][2]= 10;ki.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 0 "```|
| 65 | T01_Basics.Counter_increaseFrequency_01 |  PASSED |```int k=2; const string validChars = "AC"; KmerCounter ki(k, validChars); Kmer b("CC"); for(int i=0; i < 10; i++) ki.increaseFrequency(b);ki.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 10 "```|
| 66 | T01_Basics.Counter_increaseFrequency_02 |  PASSED |```int k=2; const string validChars = "AC"; KmerCounter ki(k, validChars); Kmer b("CC"); for(int i=0; i < 10; i++) ki.increaseFrequency(b,10);ki.inspectT();```|
| | | | should give ```"_AC 2 0 0 0 0 0 0 0 0 100 "```|
| 67 | T01_Basics.Counter_increaseFrequency_2 |  PASSED |```int k=2; const string validChars = "AC"; KmerCounter ki(k, validChars); for(unsigned i=0; i < ki._allNucleotides.size(); i++){ for(unsigned j=0; j < ki._allNucleotides.size(); j++) { string s = string(1,ki._allNucleotides[i])+string(1,ki._allNucleotides[j]); Kmer b(s); ki.increaseFrequency(b); } }ki.inspectT();```|
| | | | should give ```"_AC 2 1 1 1 1 1 1 1 1 1 "```|
| 68 | T01_Basics.Counter_getNumberActive_01 |  PASSED |```KmerCounter ki;ki.getNumberActiveKmers();```|
| | | | should give ```0```|
| 69 | T01_Basics.Counter_getNumberActive_02 |  PASSED |```const string validChars = "ACGU"; int k=2; KmerCounter ki(k,validChars); for(int i=0; i < ki._allNucleotides.size(); i++) { string s = string(1,ki._allNucleotides[i])+ string(1,ki._allNucleotides[i]); Kmer b(s); ki.increaseFrequency(b,10); }ki.getNumberActiveKmers();```|
| | | | should give ```5```|
| 70 | T02_Intermediate.Kmer_Kmer_int_3 |  PASSED |```Kmer kmer(0);```|
| | | | should THROW an exception std::invalid_argument|
| 71 | T02_Intermediate.Kmer_Kmer_string_2 |  PASSED |```Kmer kmer("");```|
| | | | should THROW an exception std::invalid_argument|
| 72 | T02_Intermediate.Kmer_at_int_3_excep |  PASSED |```const Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 73 | T02_Intermediate.Kmer_at_int_3_var_excep |  PASSED |```Kmer kmer("AT");kmer.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 74 | T02_Intermediate.Kmer_normalize_2 |  PASSED |```Kmer kmer("at"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"AT"```|
| 75 | T02_Intermediate.Kmer_normalize_3 |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ADN);kmer.inspectT()```|
| | | | should give ```"__"```|
| 76 | T02_Intermediate.Kmer_normalize_4_ARN |  PASSED |```Kmer kmer("ux"); kmer.normalize(VALID_NUCLEOTIDES_ARN);kmer.inspectT()```|
| | | | should give ```"U_"```|
| 77 | T02_Intermediate.Kmer_complementary_2 |  PASSED |```Kmer kmer1("u_"); Kmer kmer2; kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, COMPLEMENTARY_NUCLEOTIDES_ADN);kmer2.inspectT()```|
| | | | should give ```"u_"```|
| 78 | T02_Intermediate.Kmer_complementary_3_excep |  PASSED |```Kmer kmer1("u_"); Kmer kmer2;kmer2 = kmer1.complementary(VALID_NUCLEOTIDES_ADN, "A");```|
| | | | should THROW an exception std::invalid_argument|
| 79 | T02_Intermediate.KmerFreq_setFrequency_exception |  PASSED |```KmerFreq km;km.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
| 80 | T02_Intermediate.Profile_Profile_3 |  PASSED |```Profile profl(-1);```|
| | | | should THROW an exception std::out_of_range|
| 81 | T02_Intermediate.Profile_at_exception |  PASSED |```Profile profl(2);profl.at(2).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 82 | T02_Intermediate.Profile_out_of_range__append_5 |  PASSED |```int n=1; Profile profl(n); Kmer km("AA"); KmerFreq kmf; kmf.setKmer(km); kmf.setFrequency(10); profl.append(kmf);profl._capacity```|
| | | | should give ```21```|
| 83 | T02_Intermediate.sort_3_tieByFreq |  PASSED |```Profile l1; int TOPE = 4; KmerFreq kmf; for(int i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*i); l1.append(kmf); } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 ___ 30 __ 20 _ 10 "```|
| 84 | T02_Intermediate.sort_4_mixed |  PASSED |```Profile l1; int TOPE = 4; int i=1; KmerFreq kmf; for(; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*i); l1.append(kmf); } Kmer km(i); kmf.setKmer(km); l1.append(kmf); l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 4 ___ 30 ____ 30 __ 20 _ 10 "```|
| 85 | T02_Intermediate.Normalize_1 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("AA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("CC"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("GG"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 4 _ 0 AA 10 CC 10 GG 10 "```|
| 86 | T02_Intermediate.Normalize_2 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("aa"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("cF"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("xu"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 4 _ 0 AA 10 C_ 10 __ 10 "```|
| 87 | T02_Intermediate.Normalize_3 |  PASSED |```Profile l1; KmerFreq kmf; Kmer km("aA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("cT"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("Ct"); kmf.setKmer(km3); l1.append(kmf); l1.normalize(VALID_NUCLEOTIDES_ADN);l1.inspectT();```|
| | | | should give ```"unknown 2 AA 10 CT 20 "```|
| 88 | T02_Intermediate.zip_1 |  PASSED |```Profile l1(10); l1.zip();l1._size```|
| | | | should give ```0```|
| 89 | T02_Intermediate.Profile_saveLoad_1 |  PASSED |```Profile l1; Profile l2; l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/test_save1.prf"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 90 | T02_Intermediate.Profile_saveLoad_2 |  PASSED |```Profile l1; Profile l2(10); l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/test_save1.prf"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 91 | T02_Intermediate.Profile_Save_1_exception |  PASSED |```Profile l1; const char* fileName = "tests/outp/imposibleToCreateFile.prf";l1.save(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 92 | T02_Intermediate.Profile_loadLoad |  PASSED |```Profile l1; int n; const char* fileName = "../Genomes/12pairsDNA.prf"; l1.load(fileName); n = l1.getSize(); l1.load(fileName);l1.getSize()```|
| | | | should give ```12```|
| 93 | T02_Intermediate.Profile_Save_2_exception |  PASSED |```Profile l1; const char* fileName = "tests/output/invalidFileMode.prf";l1.save(fileName, 'z');```|
| | | | should THROW an exception std::invalid_argument|
| 94 | T02_Intermediate.Profile_Load_2_exception |  PASSED |```Profile l1; const char* fileName = "../Genomes/test_noHeader.prf";l1.load(fileName);```|
| | | | should THROW an exception std::invalid_argument|
| 95 | T02_Intermediate.Profile_Load_3_exception |  PASSED |```Profile l1; const char* fileName = "tests/output/test_xxx.prf";l1.load(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 96 | T02_Intermediate.Profile_getDistance_emptyToOther_1 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile empty; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf);empty.getDistance(l1)```|
| | | | should THROW an exception std::invalid_argument|
| 97 | T02_Intermediate.Profile_getDistance_otherToEmpy_2 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile empty; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b3); l1.append(kmf); kmf.setKmer(b4); l1.append(kmf);l1.getDistance(empty)```|
| | | | should THROW an exception std::invalid_argument|
| 98 | T02_Intermediate.Profile_getDistance_4 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); Kmer b5("__"); Kmer b6("A_"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b4); l2.append(kmf); kmf.setKmer(b3); l2.append(kmf); kmf.setKmer(b5); l2.append(kmf); kmf.setKmer(b6); l2.append(kmf);l1.getDistance(l2)```|
| | | | should give ```0.875000```|
| 99 | T02_Intermediate.Profile_getDistance_5 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); Kmer b3("CC"); Kmer b4("TT"); Kmer b5("__"); KmerFreq kmf; kmf.setFrequency(10); Profile l1; Profile l2; kmf.setKmer(b1); l1.append(kmf); kmf.setKmer(b2); l1.append(kmf); kmf.setKmer(b4); l2.append(kmf); kmf.setKmer(b3); l2.append(kmf); kmf.setKmer(b5); l2.append(kmf); kmf.setKmer(b1); l2.append(kmf);l2.getDistance(l1)```|
| | | | should give ```0.750000```|
| 100 | T02_Intermediate.Profile_OperatorAssign_1 |  PASSED |```Profile p1; p1.setProfileId("bug"); int i; int TOPE = 4; KmerFreq kmf; for(i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*(TOPE - i)); p1.append(kmf); } Profile profl2; profl2 = p1; Kmer km(i); kmf.setKmer(km); p1.append(kmf);profl2.inspectT()```|
| | | | should give ```"bug 3 _ 30 __ 20 ___ 10 "```|
| 101 | T02_Intermediate.Profile_OperatorAssign_2 |  PASSED |```Profile p1; p1.setProfileId("bug"); int i; int TOPE = 4; KmerFreq kmf; for(i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*(TOPE - i)); p1.append(kmf); } Profile profl2; profl2 = p1; Kmer km(i); kmf.setKmer(km); profl2.append(kmf);p1.inspectT()```|
| | | | should give ```"bug 3 _ 30 __ 20 ___ 10 "```|
| 102 | T02_Intermediate.Profile_ProfileCopy_1 |  PASSED |```Profile p1; p1.setProfileId("bug"); int i; int TOPE = 4; KmerFreq kmf; for(i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*(TOPE - i)); p1.append(kmf); } Profile profl2(p1); Kmer km(i); kmf.setKmer(km); p1.append(kmf);profl2.inspectT()```|
| | | | should give ```"bug 3 _ 30 __ 20 ___ 10 "```|
| 103 | T02_Intermediate.Profile_ProfileCopy_2 |  PASSED |```Profile p1; p1.setProfileId("bug"); int i; int TOPE = 4; KmerFreq kmf; for(i=1; i < TOPE; i++) { Kmer km(i); kmf.setKmer(km); kmf.setFrequency(10*(TOPE - i)); p1.append(kmf); } Profile profl2(p1); Kmer km(i); kmf.setKmer(km); profl2.append(kmf);p1.inspectT()```|
| | | | should give ```"bug 3 _ 30 __ 20 ___ 10 "```|
| 104 | T02_Intermediate.Counter_getRowColumn_exception_1 |  PASSED |```KmerCounter kc(2); Kmer km; int fila=-1; int col=-1;km=kc.getKmer(fila, col);```|
| | | | should THROW an exception std::invalid_argument|
| 105 | T02_Intermediate.Counter_getRowColumn_exception_2 |  PASSED |```KmerCounter kc(2); Kmer km; int fila=kc.getNumRows(); int col=kc.getNumCols();km=kc.getKmer(fila, col);```|
| | | | should THROW an exception std::invalid_argument|
| 106 | T02_Intermediate.Counter_calculateFrequencies_EN_0 |  PASSED |```const char nfE[50] = "tests/validation/test_homoSP.dna"; const char nfS[50] = "tests/validation/test_homoSP.prf"; bool iguales = true; string s; int posi; int posj; int freq; int freql; KmerCounter ki; ki.calculateFrequencies(nfE); Profile l; l.load(nfS); if (ki.getNumberActiveKmers() != l.getSize()) iguales= false; for(int i=0; i < l.getSize() && iguales; i++){ s = l.at(i).getKmer().toString(); ki.getRowColumn(s,posi, posj); freql = l.at(i).getFrequency(); freq = ki._frequency[posi][posj]; if (freq != freql) iguales = false; }iguales```|
| | | | should give ```true```|
| 107 | T02_Intermediate.Counter_toProfile_1 |  PASSED |```const char nfE[50] = "tests/validation/test_homoSP.dna"; const char nfS[50] = "tests/validation/test_homoSP.prf"; KmerCounter ki; ki.calculateFrequencies(nfE); Profile lr; Profile lo; lr.load(nfS); lo = ki.toProfile(); lo.sort(); bool iguales = true; if (lr.getSize() != lo.getSize()) iguales= false; for(int i=0; i < lo.getSize() && iguales; i++){ if ((lr.at(i).getKmer().toString() != lo.at(i).getKmer().toString()) || (lr.at(i).getFrequency() != lo.at(i).getFrequency())) iguales =false; }iguales```|
| | | | should give ```true```|
| 108 | T02_Intermediate.Kmer_read_ |  PASSED |```Kmer b; std::string sin="AA"; istringstream ssin(sin); ssin >> b;b.toString()```|
| | | | should give ```"AA"```|
| 109 | T02_Intermediate.kmer_print_ |  PASSED |```std::string sout; ostringstream ssout; Kmer b("AA"); ssout << b; sout = ssout.str();sout```|
| | | | should give ```"AA"```|
| 110 | T02_Intermediate.Kmer_oper_at_int_1 |  PASSED |```const Kmer kmer("ab");kmer[0];```|
| | | | should give ```"a"```|
| 111 | T02_Intermediate.Kmer_oper_at_int_2 |  PASSED |```const Kmer kmer("ab");kmer[1];```|
| | | | should give ```"b"```|
| 112 | T02_Intermediate.Kmer_oper_at_int_3 |  PASSED |```Kmer kmer("cb"); kmer[0]='A';kmer[0];```|
| | | | should give ```"A"```|
| 113 | T02_Intermediate.Kmer_oper_at_int_4 |  PASSED |```Kmer kmer("ag");kmer[1]; kmer[1]='T';```|
| | | | should give ```"T"```|
| 114 | T02_Intermediate.KmerFreq_read_ |  PASSED |```KmerFreq bfr; std::string sin="aa 10"; istringstream ssin(sin); ssin >> bfr;bfr.toString()```|
| | | | should give ```"aa 10"```|
| 115 | T02_Intermediate.kmerFreq_print_ |  PASSED |```std::string sout; ostringstream ssout; Kmer b("AA"); KmerFreq bf; bf.setKmer(b); bf.setFrequency(10); ssout << bf; sout = ssout.str();sout```|
| | | | should give ```"AA 10"```|
| 116 | T02_Intermediate.KmerFreq_operatorGreaterThan_1 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b2); bf1.setFrequency(10); bf2.setFrequency(20);bf2>bf1```|
| | | | should give ```true```|
| 117 | T02_Intermediate.KmerFreq_operatorGreaterThan_2 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b2); bf1.setFrequency(10); bf2.setFrequency(10);bf1>bf2```|
| | | | should give ```true```|
| 118 | T02_Intermediate.KmerFreq_operatorEqual_3 |  PASSED |```Kmer b1("AA"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b1); bf1.setFrequency(10); bf2.setFrequency(10);bf1==bf2```|
| | | | should give ```true```|
| 119 | T02_Intermediate.KmerFreq_operatorLessThan_4 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b2); bf1.setFrequency(10); bf2.setFrequency(20);bf2<bf1```|
| | | | should give ```false```|
| 120 | T02_Intermediate.KmerFreq_operatorLessEqual_5 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b2); bf1.setFrequency(10); bf2.setFrequency(10);bf1<=bf2```|
| | | | should give ```false```|
| 121 | T02_Intermediate.KmerFreq_operatorNotEqual_1 |  PASSED |```Kmer b1("AA"); Kmer b2("gg"); KmerFreq bf1; KmerFreq bf2; bf1.setKmer(b1); bf2.setKmer(b2); bf1.setFrequency(10); bf2.setFrequency(10);bf1!=bf2```|
| | | | should give ```true```|
| 122 | T02_Intermediate.Profile_operatorat_0 |  PASSED |```Kmer b("AA"); KmerFreq bf; bf.setKmer(b); bf.setFrequency(10); Profile prf; prf.append(bf);prf[0].inspectT()```|
| | | | should give ```"AA 10"```|
| 123 | T02_Intermediate.Profile_operatorat_1 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf; bf.setKmer(b1); bf.setFrequency(10); Profile prf; prf.append(bf); bf.setKmer(b2); prf.append(bf);prf[0].inspectT()```|
| | | | should give ```"AA 10"```|
| 124 | T02_Intermediate.Profile_operatorat_2 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; bf1.setKmer(b1); bf1.setFrequency(10); Profile prf; prf.append(bf1); bf1.setKmer(b2); prf.append(bf1); prf[0]=bf1;prf[0].inspectT()```|
| | | | should give ```"GG 10"```|
| 125 | T02_Intermediate.Profile_operatorat_3 |  PASSED |```Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf1; bf1.setKmer(b1); bf1.setFrequency(10); KmerFreq bf2; bf2.setKmer(b2); bf2.setFrequency(20); Profile prf; prf.append(bf1); prf.append(bf2); prf[1]=bf1;prf[1].inspectT()```|
| | | | should give ```"AA 10"```|
| 126 | T02_Intermediate.profile_print_ |  PASSED |```std::string sout; ostringstream ssout; Kmer b1("AA"); Kmer b2("GG"); KmerFreq bf; bf.setKmer(b1); bf.setFrequency(10); Profile prf; prf.append(bf); prf.append(bf); bf.setKmer(b2); prf.append(bf); std::streambuf *old = std::cout.rdbuf(ssout.rdbuf()); ssout << prf; sout = ssout.str(); sout = std::regex_replace(sout, std::regex(ENDL), " "); std::cout.rdbuf(old);sout```|
| | | | should give ```"unknown 2 AA 20 GG 10 "```|
| 127 | T02_Intermediate.Profile_read_ |  PASSED |```Profile prf; std::string sin="unknown"; sin=sin+ENDL+" 3 aa 10 ab 10 ac 10"; istringstream ssin(sin); ssin >> prf;prf.inspectT()```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 128 | T02_Intermediate.Profile_saveLoad_parameter_t |  PASSED |```Profile l1; Profile l2; l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/test_save1.prf"; l1.save(fileName,'t'); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 129 | T02_Intermediate.Profile_saveLoad_parameter_b |  PASSED |```Profile l1; Profile l2; l1.setProfileId("Test1"); KmerFreq kmf; for(int i=0; i < 10; i++) { Kmer kmer(i+1); kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); kmer.at(0)='A'; kmf.setKmer(kmer); kmf.setFrequency(10-i); l1.append(kmf); } l1.sort(); const char* fileName = "tests/output/testb_save.bgr"; l1.save(fileName,'b'); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 130 | T02_Intermediate.Counter_operator_joinCounter_1 |  PASSED |```int k = 2; string validChars = "GU"; KmerCounter ki(k,validChars); validChars = "_GU"; for(int i=0; i < validChars.size(); i++) for(int j=0; j < validChars.size(); j++) { Kmer b(string(1,validChars[i])+string(1,validChars[j])); ki.increaseFrequency(b,3); } ki += ki;ki.inspectT()```|
| | | | should give ```"_GU 2 6 6 6 6 6 6 6 6 6 "```|
| 131 | T02_Intermediate.Counter_operatorAt_1 |  PASSED |```int f; int c; KmerCounter ki(2); Kmer b("TT"); ki.increaseFrequency(b,10); ki.getRowColumn(b,f,c);ki(f,c)```|
| | | | should give ```10```|
| 132 | T03_Advanced.zip_2 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("AA"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("C_"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("_G"); kmf.setKmer(km3); l1.append(kmf); l1.zip();l1.inspectT();```|
| | | | should give ```"unknown 3 AA 10 C_ 10 _G 10 "```|
| 133 | T03_Advanced.zip_3 |  PASSED |```Profile l1(1); KmerFreq kmf; Kmer km("A_"); kmf.setKmer(km); kmf.setFrequency(10); l1.append(kmf); Kmer km2("__"); kmf.setKmer(km2); l1.append(kmf); Kmer km3("TT"); kmf.setKmer(km3); l1.append(kmf); l1.zip(true);l1.inspectT();```|
| | | | should give ```"unknown 1 TT 10 "```|
| 134| T03_Advanced.Integration_LEARN_missingParameters1-valgrind | PASSED | NO LEAKS |
| 134 | T03_Advanced.Integration_LEARN_missingParameters1 | PASSED | [LEARN]: Running without arguments|
| 135| T03_Advanced.Integration_LEARN_missingParameters2-valgrind | PASSED | NO LEAKS |
| 135 | T03_Advanced.Integration_LEARN_missingParameters2 | PASSED | [LEARN -p human -o tests/output/human1.prf]: Running with missing arguments|
| 136| T03_Advanced.Integration_LEARN_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 136 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments1 | PASSED | [LEARN -T -p human -o tests/output/human1.prf ../Genomes/human1.dna]: Running with invalid arguments (-T is not valid)|
| 137| T03_Advanced.Integration_LEARN_RunWithInvalidArguments2-valgrind | PASSED | NO LEAKS |
| 137 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments2 | PASSED | [LEARN -K 1 -p human -o tests/output/human1.prf ../Genomes/human1.dna]: Running with invalid arguments (-K is not valid)|
| 138| T03_Advanced.Integration_LEARN_RunWithInvalidArguments3-valgrind | PASSED | NO LEAKS |
| 138 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments3 | PASSED | [LEARN -k 1 -N ATGC -p human -o tests/output/human1.prf ../Genomes/human1.dna]: Running with invalid arguments (-N is not valid)|
| 139| T03_Advanced.Integration_LEARN_1unknownACGT-valgrind | PASSED | NO LEAKS |
| 139 | T03_Advanced.Integration_LEARN_1unknownACGT | PASSED | [LEARN -p bug -o tests/output/unknownACGT.prf ../Genomes/unknownACGT.dna]: Learn from unknownACGT.dna (a very short DNA file) using the default value for k [LEARN -p bug -o tests/output/unknownACGT.prf ../Genomes/unknownACGT.dna]|
| 140| T03_Advanced.Integration_LEARN_unknownACGT2_k1-valgrind | PASSED | NO LEAKS |
| 140 | T03_Advanced.Integration_LEARN_unknownACGT2_k1 | PASSED | Learn from unknownACGT.dna (a very short DNA file) using k=1 [LEARN -k 1 -o tests/output/unknownACGT_k1.prf ../Genomes/unknownACGT.dna]|
| 141| T03_Advanced.Integration_LEARN_unknowACGT2-valgrind | PASSED | NO LEAKS |
| 141 | T03_Advanced.Integration_LEARN_unknowACGT2 | PASSED | [LEARN -k 2 -p bug -o tests/output/unknownACGT+unknownACGT2_k2.prf ../Genomes/unknownACGT.dna ../Genomes/unknownACGT2.dna]: Learn from two very short DNA files (unknownACGT.dna and unknownACGT2.dna) using k=2|
| 142| T03_Advanced.Integration_LEARN_unknownACGU-valgrind | PASSED | NO LEAKS |
| 142 | T03_Advanced.Integration_LEARN_unknownACGU | PASSED | [LEARN -n ACGU -p bug -o tests/output/unknownACGU.prf ../Genomes/unknownACGU.rna]: Learn from a very short RNA file (unknownACGU.rna) using the default value for k|
| 143| T03_Advanced.Integration_LEARN_unknownACGUk2-valgrind | PASSED | NO LEAKS |
| 143 | T03_Advanced.Integration_LEARN_unknownACGUk2 | PASSED | [LEARN -k 2 -n ACGU -p bug -o tests/output/unknownACGU_k2.prf ../Genomes/unknownACGU.rna]: Learn from a very short RNA file (unknownACGU.rna) using k=2|
| 144| T03_Advanced.Integration_LEARN_unknownACGUk3-valgrind | PASSED | NO LEAKS |
| 144 | T03_Advanced.Integration_LEARN_unknownACGUk3 | PASSED | [LEARN -k 3 -n ACGU -p bug -o tests/output/unknownACGU_k3.prf ../Genomes/unknownACGU.rna]: Learn from a very short RNA file (unknownACGU.rna) using k=3|
| 145| T03_Advanced.Integration_LEARN_human1k5-valgrind | PASSED | NO LEAKS |
| 145 | T03_Advanced.Integration_LEARN_human1k5 | PASSED | [LEARN -p 'homo sapiens' -o tests/output/human1_k5.prf ../Genomes/human1.dna]: Learn from a short DNA file (human1.dna) using the default value for k|
| 146| T03_Advanced.Integration_LEARN_human1k1-valgrind | PASSED | NO LEAKS |
| 146 | T03_Advanced.Integration_LEARN_human1k1 | PASSED | [LEARN -k 1 -p 'homo sapiens' -o tests/output/human1_k1.prf ../Genomes/human1.dna]: Learn from a short DNA file (human1.dna) using k=1|
| 147| T03_Advanced.Integration_LEARN_human1k2-valgrind | PASSED | NO LEAKS |
| 147 | T03_Advanced.Integration_LEARN_human1k2 | PASSED | [LEARN -k 2 -p 'homo sapiens' -o tests/output/human1_k2.prf ../Genomes/human1.dna]: Learn from a short DNA file (human1.dna) using k=2|
| 148| T03_Advanced.Integration_LEARN_worm1-valgrind | PASSED | NO LEAKS |
| 148 | T03_Advanced.Integration_LEARN_worm1 | PASSED | [LEARN -p 'caenorhabditis elegans' -o tests/output/worm1.prf ../Genomes/worm1.dna]: Learn from a short DNA file (worm1.dna) using the default value for k|
| 149| T03_Advanced.Integration_LEARN_learn_humanchr6-valgrind | PASSED | NO LEAKS |
| 149 | T03_Advanced.Integration_LEARN_learn_humanchr6 | PASSED | [LEARN -p 'homo sapiens' -o tests/output/human_chr6.prf ../Genomes/human_chr6_s60000_l500000.dna]: Learn from a large DNA file (human_chr6_s60000_l500000.dna) using the default value for k|
| 150| T03_Advanced.Integration_LEARN_covidFullGenomerna-valgrind | PASSED | NO LEAKS |
| 150 | T03_Advanced.Integration_LEARN_covidFullGenomerna | PASSED | [LEARN -n ACGU -p 'severe acute respiratory syndrome coronavirus 2' -o tests/output/covidFullGenomeRNA.prf ../Genomes/covidFullGenome.rna]: Learn from a large RNA file (covidFullGenome.rna) using the default value for k|
| 151| T03_Advanced.Integration_LEARN_binary-valgrind | PASSED | NO LEAKS |
| 151 | T03_Advanced.Integration_LEARN_binary |  PASSED |```[LEARN -b -p 'homo sapiens' -o tests/output/human_chr9_s10000_l500000B.prf ../Genomes/human_chr9_s10000_l500000.dna]: Learn the homo sapiens as a binary profile from human_chr9_s10000_l500000.dna```|
| | | | should give ```"unknown 1 TT 10 "```|
| 152| T03_Advanced.Integration_CLASSIFY_missingParameters1-valgrind | PASSED | NO LEAKS |
| 152 | T03_Advanced.Integration_CLASSIFY_missingParameters1 | PASSED | [CLASSIFY]: Classify with missing parameters|
| 153| T03_Advanced.Integration_CLASSIFY_missingParameters2-valgrind | PASSED | NO LEAKS |
| 153 | T03_Advanced.Integration_CLASSIFY_missingParameters2 | PASSED | [CLASSIFY ../Genomes/human1.dna]: Classify with missing parameters|
| 154| T03_Advanced.Integration_CLASSIFY_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 154 | T03_Advanced.Integration_CLASSIFY_RunWithInvalidArguments1 | PASSED | [CLASSIFY -K 5 ../Genomes/human1.dna ../Genomes/human2.prf ../Genomes/mouse1.prf]: Running with invalid arguments (-K is not valid)|
| 155| T03_Advanced.Integration_CLASSIFY_RunWithInvalidArguments2-valgrind | PASSED | NO LEAKS |
| 155 | T03_Advanced.Integration_CLASSIFY_RunWithInvalidArguments2 | PASSED | [CLASSIFY -N ACGT ../Genomes/human1.dna ../Genomes/human2.prf ../Genomes/mouse1.prf]: Running with invalid arguments (-N is not valid)|
| 156| T03_Advanced.Integration_CLASSIFY_unknownACGT-valgrind | PASSED | NO LEAKS |
| 156 | T03_Advanced.Integration_CLASSIFY_unknownACGT | PASSED | [CLASSIFY ../Genomes/unknownACGT.dna ../Genomes/human_chr6_s60000_l500000.prf ../Genomes/drosophila_chr2L_s1_l500000.prf]: Classify a very short DNA file (unknownACGT.dna) using the default value for k|
| 157| T03_Advanced.Integration_CLASSIFY_human2_k2-valgrind | PASSED | NO LEAKS |
| 157 | T03_Advanced.Integration_CLASSIFY_human2_k2 | PASSED | [CLASSIFY -k 2 ../Genomes/human1.dna ../Genomes/human_chr6_s60000_l500000_k2.prf ../Genomes/drosophila_chr2L_k2.prf]: Classify a short DNA file (human1.dna) using k=2|
| 158| T03_Advanced.Integration_CLASSIFY_human_chr6-valgrind | PASSED | NO LEAKS |
| 158 | T03_Advanced.Integration_CLASSIFY_human_chr6 | PASSED | [CLASSIFY ../Genomes/human_chr6_s60000_l500000.dna ../Genomes/brewers_yeast_chrVII.s1_l500000.prf ../Genomes/chimpanzee_chr9_s1_l500000.prf ../Genomes/covidFullGenomeDNA.prf ../Genomes/drosophila_chr2L_s1_l500000.prf ../Genomes/ebolaFullGenomeDNA.prf ../Genomes/human_chr9_s10000_l500000.prf ../Genomes/monkeypoxFullGenomeDNA.prf ../Genomes/mouse_chr6_s3050050_l500000.prf ../Genomes/nematode_chrI_s1l500000.prf ../Genomes/rat_chr6_s1l500000.prf ../Genomes/zebrafish_chr6_s1l500000.prf]: Classify a large DNA file (human_chr6_s60000_l500000.dna) using the default value for k|
| 159| T03_Advanced.Integration_CLASSIFY_covidrna-valgrind | PASSED | NO LEAKS |
| 159 | T03_Advanced.Integration_CLASSIFY_covidrna | PASSED | [CLASSIFY -n ACGU ../Genomes/covid.rna ../Genomes/covidFullGenomeRNA.prf ../Genomes/ebolaFullGenomeRNA.prf ../Genomes/monkeypoxFullGenomeRNA.prf]: Classify a short RNA file (covid.rna) using the default value for k|
| 160| T03_Advanced.Integration_CLASSIFY_binary-valgrind | PASSED | NO LEAKS |
| 160 | T03_Advanced.Integration_CLASSIFY_binary | PASSED | [CLASSIFY ../Genomes/human_chr6_s60000_l500000.dna ../Genomes/brewers_yeast_chrVII.s1_l500000.prf ../Genomes/chimpanzee_chr9_s1_l500000.prf ../Genomes/covidFullGenomeDNA.prf ../Genomes/drosophila_chr2L_s1_l500000.prf ../Genomes/ebolaFullGenomeDNA.prf ../Genomes/human_chr9_s10000_l500000B.prf ../Genomes/monkeypoxFullGenomeDNA.prf ../Genomes/mouse_chr6_s3050050_l500000.prf ../Genomes/nematode_chrI_s1l500000.prf ../Genomes/rat_chr6_s1l500000.prf ../Genomes/zebrafish_chr6_s1l500000.prf]: Classify ../Genomes/human_chr6_s60000_l500000.dna using several profiles, one of them in binary format|
