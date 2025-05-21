# OUTCOME OF TESTS FOR PROJECT boston4_template

As of Apr 29 2025 18:38:19

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Coordinates_Coordinates_def1 |  PASSED |```Coordinates coord; string s=to_string(INVALID_COORDINATE)+string(",")+to_string(INVALID_COORDINATE);coord.inspectT()```|
| | | | should give ```"181.000000,181.000000"```|
| 2 | T01_Basics.Coordinates_Coordinates_ValidCoordinates1 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord(f1,f2); string s=to_string(f1)+string(",")+to_string(f2);coord.inspectT()```|
| | | | should give ```"37.178055,-3.600833"```|
| 3 | T01_Basics.Coordinates_Coordinates_InvalidCoordinates2 |  PASSED |```float f1=91.0; float f2=-180.0001; Coordinates coord(f1,f2); string s=to_string(f1)+string(",")+to_string(f2);coord.inspectT()```|
| | | | should give ```"91.000000,-180.000107"```|
| 4 | T01_Basics.Coordinates_getLatitude_ValidCoordinates1 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord(f1,f2);coord.getLatitude()```|
| | | | should give ```37.178055```|
| 5 | T01_Basics.Coordinates_getLongitude_ValidCoordinates1 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord(f1,f2);coord.getLongitude()```|
| | | | should give ```-3.600833```|
| 6 | T01_Basics.Coordinates_isValid_valid0 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```true```|
| 7 | T01_Basics.Coordinates_isValid_valid1 |  PASSED |```float f1=90.0; float f2=180.0; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```true```|
| 8 | T01_Basics.Coordinates_isValid_valid2 |  PASSED |```float f1=-90.0; float f2=-180.0; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```true```|
| 9 | T01_Basics.Coordinates_isValid_invalid0 |  PASSED |```float f1=-90.001; float f2=180.0; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```false```|
| 10 | T01_Basics.Coordinates_isValid_invalid1 |  PASSED |```float f1=90.001; float f2=180.0; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```false```|
| 11 | T01_Basics.Coordinates_isValid_invalid2 |  PASSED |```float f1=90.0; float f2=-180.001; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```false```|
| 12 | T01_Basics.Coordinates_isValid_invalid3 |  PASSED |```float f1=90.0; float f2=180.001; Coordinates coord(f1,f2);coord.isValid();```|
| | | | should give ```false```|
| 13 | T01_Basics.Coordinates_set_ValidCoordinates1 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord; coord.set(f1,f2); string s=to_string(f1)+string(",")+to_string(f2);coord.inspectT()```|
| | | | should give ```"37.178055,-3.600833"```|
| 14 | T01_Basics.Coordinates_set_InvalidCoordinates2 |  PASSED |```float f1=-91.0; float f2=-180.0001; Coordinates coord(0,0); coord.set(f1,f2); string s=to_string(f1)+string(",")+to_string(f2);coord.inspectT()```|
| | | | should give ```"-91.000000,-180.000107"```|
| 15 | T01_Basics.Coordinates_setLatitude_ValidCoordinates1 |  PASSED |```float f1=37.178056; Coordinates coord; coord.setLatitude(f1); string s=to_string(f1)+string(",")+to_string(INVALID_COORDINATE);coord.inspectT()```|
| | | | should give ```"37.178055,181.000000"```|
| 16 | T01_Basics.Coordinates_setLongitude_ValidCoordinates1 |  PASSED |```float f2=-3.600833; Coordinates coord; coord.setLongitude(f2); string s=to_string(INVALID_COORDINATE)+string(",")+to_string(f2);coord.inspectT()```|
| | | | should give ```"181.000000,-3.600833"```|
| 17 | T01_Basics.Coordinates_toString |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord(f1,f2); string s=to_string(f1)+string(",")+to_string(f2);coord.toString();```|
| | | | should give ```"37.178055,-3.600833"```|
| 18 | T01_Basics.Coordinates_length_l0 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord1(f1,f2); Coordinates r = coord1.length(coord1); Coordinates sol(0,0); string s= sol.inspectT();r.inspectT()```|
| | | | should give ```"0.000000,0.000000"```|
| 19 | T01_Basics.Coordinates_length_l1 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord1(f1+1,f2+1); Coordinates coord2(f1,f2); Coordinates r = coord1.length(coord2); Coordinates sol(1,1); string s = sol.inspectT();r.inspectT()```|
| | | | should give ```"1.000000,1.000000"```|
| 20 | T01_Basics.Coordinates_length_l2 |  PASSED |```float f1=37.178056; float f2=-3.600833; Coordinates coord1(f1+1,f2+1); Coordinates coord2(f1,f2); Coordinates r = coord2.length(coord1); Coordinates sol(1,1); string s = sol.inspectT();r.inspectT()```|
| | | | should give ```"1.000000,1.000000"```|
| 21 | T01_Basics.Coordinates_isInsideArea_in0 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4);coord1.isInsideArea(coord1,coord2);```|
| | | | should give ```true```|
| 22 | T01_Basics.Coordinates_isInsideArea_in1 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4);coord2.isInsideArea(coord1,coord2);```|
| | | | should give ```true```|
| 23 | T01_Basics.Coordinates_isInsideArea_in2 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4); Coordinates coord3(f1+0.2,f2+0.2);coord3.isInsideArea(coord1,coord2);```|
| | | | should give ```true```|
| 24 | T01_Basics.Coordinates_isInsideArea_out0 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4); Coordinates coord3(f3+0.2,f4);coord3.isInsideArea(coord1,coord2)```|
| | | | should give ```false```|
| 25 | T01_Basics.Coordinates_isInsideArea_out1 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4); Coordinates coord3(f3,f4+0.2);coord3.isInsideArea(coord1,coord2)```|
| | | | should give ```false```|
| 26 | T01_Basics.Coordinates_isInsideArea_out2 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4); Coordinates coord3(f1-0.2,f2);coord3.isInsideArea(coord1,coord2)```|
| | | | should give ```false```|
| 27 | T01_Basics.Coordinates_isInsideArea_out3 |  PASSED |```float f1=37.178056; float f2=-3.600833; float f3=39.47; float f4=-0.376389; Coordinates coord1(f1,f2); Coordinates coord2(f3,f4); Coordinates coord3(f1,f2-0.2);coord3.isInsideArea(coord1,coord2)```|
| | | | should give ```false```|
| 28 | T01_Basics.Crime_Crime_def1 |  PASSED |```Crime crime; string s=CRIME_DEFAULT;crime.inspectT()```|
| | | | should give ```"0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000"```|
| 29 | T01_Basics.Crime_Crime_full1 |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 30 | T01_Basics.Crime_Crime_full2_dateInvalid |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-30 12:30:00,999,180.000000,180.000000"; string due="1,111,222,333,444,555,666,1,"; due+= DATETIME_CLASS_DEFAULT; due+=",999,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2000-01-01 00:00:00,999,180.000000,180.000000"```|
| 31 | T01_Basics.Crime_Crime_parcial1 |  PASSED |```string s="1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"```|
| 32 | T01_Basics.Crime_gets_full1 |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s); string sreal=to_string(crime.getCounter())+","+crime.getId()+","+crime.getCode()+","; sreal+=crime.getGroup()+","+crime.getDescription()+","+crime.getDistrict()+","; sreal+=crime.getAreaReport()+",1,2025-02-17 12:30:00,"+crime.getStreet()+",180.000000,180.000000";crime.inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 33 | T01_Basics.Crime_gets_full2 |  PASSED |```float f1=180; DateTime dd("2025-02-17 12:30:00"); string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.isShooting() && crime.getLocation().getLatitude()==f1 && crime.getLocation().getLongitude()==f1 && crime.getDateTime()==dd;```|
| | | | should give ```true```|
| 34 | T01_Basics.Crime_sets_def1 |  PASSED |```Crime crime; string s="1,111,222,333,444,555,666,1,"; s += DATETIME_DEFAULT; s += ",999,181.000000,181.000000"; crime.setCounter(1); crime.setId("111"); crime.setCode("222"); crime.setGroup("333"); crime.setDescription("444"); crime.setDistrict("555"); crime.setAreaReport("666"); crime.setStreet("999");crime.inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2017-01-20 02:00:00,999,181.000000,181.000000"```|
| 35 | T01_Basics.Crime_sets_def2 |  PASSED |```Crime crime; string sd="2025-02-17 12:30:00"; DateTime dd(sd); float f1= 0; Coordinates coord(f1,f1); crime.setShooting(false); crime.setLocation(coord); crime.setDateTime(sd);!crime.isShooting() && crime.getLocation().getLatitude()==f1 && crime.getLocation().getLongitude()==f1 && crime.getDateTime()==dd;```|
| | | | should give ```true```|
| 36 | T01_Basics.Crime_set_full1 |  PASSED |```Crime crime; string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; crime.set(s);crime.inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 37 | T01_Basics.Crime_isIDUnknown_true0 |  PASSED |```Crime crime;crime.isIDUnknown();```|
| | | | should give ```true```|
| 38 | T01_Basics.Crime_isIDUnknown_true1 |  PASSED |```string s="1,UNKNOWN,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.isIDUnknown();```|
| | | | should give ```true```|
| 39 | T01_Basics.Crime_isIDUnknown_false0 |  PASSED |```Crime crime; crime.setId("1111")crime.isIDUnknown();```|
| | | | should give ```false```|
| 40 | T01_Basics.Crime_isIDUnknown_false1 |  PASSED |```string s="1,unknown,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.isIDUnknown();```|
| | | | should give ```false```|
| 41 | T01_Basics.Crime_toString |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.toString();```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 42 | T01_Basics.Crime_getField_Counter |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Counter");```|
| | | | should give ```"1"```|
| 43 | T01_Basics.Crime_getField_ID |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("ID")```|
| | | | should give ```"111"```|
| 44 | T01_Basics.Crime_getField_code |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Code")```|
| | | | should give ```"222"```|
| 45 | T01_Basics.Crime_getField_group |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Group")```|
| | | | should give ```"333"```|
| 46 | T01_Basics.Crime_getField_description |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Description")```|
| | | | should give ```"444"```|
| 47 | T01_Basics.Crime_getField_district |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("District")```|
| | | | should give ```"555"```|
| 48 | T01_Basics.Crime_getField_area |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Area")```|
| | | | should give ```"666"```|
| 49 | T01_Basics.Crime_getField_street |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Street")```|
| | | | should give ```"999"```|
| 50 | T01_Basics.Crime_getField_shooting |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Shooting")```|
| | | | should give ```"1"```|
| 51 | T01_Basics.Crime_getField_DateTime |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("DateTime")```|
| | | | should give ```"2025-02-17 12:30:00"```|
| 52 | T01_Basics.Crime_getField_location |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Location")```|
| | | | should give ```"180.000000,180.000000"```|
| 53 | T01_Basics.Crime_getField_unknown |  PASSED |```string s = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s);crime.getField("Unknown");```|
| | | | should THROW an exception std::invalid_argument|
| 54 | T01_Basics.Crime_normalize0_nochange |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 55 | T01_Basics.Crime_normalize1_nochange |  PASSED |```string s="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 56 | T01_Basics.CrimeSet_CrimeSet_1 |  PASSED |```CrimeSet crimSet;crimSet.inspectT()```|
| | | | should give ```" 0 "```|
| 57 | T01_Basics.CrimeSet_CrimeSet_2 |  PASSED |```string s = " 0 "; CrimeSet crimSet(1);crimSet.inspectT().c_str()```|
| | | | should give ```" 0 "```|
| 58 | T01_Basics.CrimeSet_CrimeSet_3 |  PASSED |```CrimeSet crimSet(DIM_VECTOR_CRIMES_LOC);crimSet._capacity```|
| | | | should give ```2000```|
| 59 | T01_Basics.CrimeSet_getComment_1 |  PASSED |```CrimeSet crimSet(2);crimSet.getComment()```|
| | | | should give ```""```|
| 60 | T01_Basics.CrimeSet_getSize_1 |  PASSED |```CrimeSet crimSet(5);crimSet.getSize()```|
| | | | should give ```0```|
| 61 | T01_Basics.CrimeSet_getSize_2 |  PASSED |```CrimeSet crimSet(5); crimSet._nCrimes = 5;crimSet.getSize()```|
| | | | should give ```5```|
| 62 | T01_Basics.CrimeSet_getComment_2 |  PASSED |```CrimeSet crimSet(2); string s = "COMMENT"; crimSet._comment = s;crimSet.getComment().c_str()```|
| | | | should give ```"COMMENT"```|
| 63 | T01_Basics.CrimeSet_setComment |  PASSED |```CrimeSet crimSet(2); string s = "COMMENT"; s = s + ENDL; crimSet.setComment(s);std::regex_replace(crimSet.getComment(),std::regex(ENDL)," ")```|
| | | | should give ```"COMMENT "```|
| 64 | T01_Basics.CrimeSet_toString |  PASSED |```string s="2 "+OTHER+OTHER; Crime crm1(OTHER); Crime crm2(OTHER); CrimeSet crimeSet(2); crimeSet._nCrimes = 2; crimeSet._crimes[0]= crm1; crimeSet._crimes[1]= crm2;std::regex_replace(crimeSet.toString(),std::regex(ENDL)," ")```|
| | | | should give ```"2 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 65 | T01_Basics.CrimeSet_Clear_0 |  PASSED |```CrimeSet crimSet; crimSet.clear();crimSet._nCrimes;```|
| | | | should give ```0```|
| 66 | T01_Basics.CrimeSet_Clear_1 |  PASSED |```CrimeSet crimSet(DIM_VECTOR_CRIMES_LOC); crimSet.clear();crimSet.getSize()```|
| | | | should give ```0```|
| 67 | T01_Basics.CrimeSet_append_0 |  PASSED |```Crime crm(OTHER); CrimeSet crimeSet; string s = " 1 " + OTHER; crimeSet.append(crm);crimeSet.inspectT().c_str()```|
| | | | should give ```" 1 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 68 | T01_Basics.CrimeSet_append_1 |  PASSED |```Crime crm1; Crime crm2(OTHER); string ss = " 2 "+ CRIME_DEFAULT+" " +OTHER; CrimeSet crimeSet; crimeSet.append(crm1);crimeSet.append(crm2);crimeSet.inspectT().c_str()```|
| | | | should give ```" 2 0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 69 | T01_Basics.CrimeSet_at_0 |  PASSED |```CrimeSet crimSet(2); crimSet._nCrimes = 2;crimSet.at(0).inspectT().c_str()```|
| | | | should give ```"0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000"```|
| 70 | T01_Basics.CrimeSet_at_1 |  PASSED |```CrimeSet crimSet(2); crimSet._nCrimes = 2;crimSet.at(1).inspectT().c_str()```|
| | | | should give ```"0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000"```|
| 71 | T01_Basics.CrimeSet_findCrime_0 |  PASSED |```Crime crm; CrimeSet crimSet;crimSet.findCrime(crm);```|
| | | | should give ```-1```|
| 72 | T01_Basics.CrimeSet_findCrime_1 |  PASSED |```Crime crm1(OTHER); Crime crm2; string s2 = "222"; crm2.setId(s2); CrimeSet crimeSet(2); crimeSet._nCrimes = 2; crimeSet._crimes[0] = crm1; crimeSet._crimes[2] = crm2;crimeSet.findCrime(crm1);```|
| | | | should give ```0```|
| 73 | T01_Basics.CrimeSet_findCrime_2 |  PASSED |```Crime crm1(OTHER); Crime crm2; string s2 = "222"; crm2.setId(s2); CrimeSet crimeSet(2); crimeSet._nCrimes = 2; crimeSet._crimes[0] = crm1; crimeSet._crimes[1] = crm2;crimeSet.findCrime(crm2);```|
| | | | should give ```1```|
| 74 | T01_Basics.CrimeSet_findCrime_3 |  PASSED |```Crime crm(OTHER); CrimeSet crimeSet(5);crimeSet.findCrime(crm);```|
| | | | should give ```-1```|
| 75 | T01_Basics.CrimeSet_findCrime_4 |  PASSED |```CrimeSet crimeSet(DIM_VECTOR_CRIMES_LOC); crimeSet._nCrimes = DIM_VECTOR_CRIMES_LOC; Crime crm(OTHER); crimeSet._crimes[DIM_VECTOR_CRIMES_LOC - 1] = crm;crimeSet.findCrime(crm);```|
| | | | should give ```1999```|
| 76 | T01_Basics.CrimeSet_CrimeSet_11 |  PASSED |```CrimeSet crimSet(2); crimSet._nCrimes=2;crimSet._capacity;```|
| | | | should give ```8```|
| 77 | T01_Basics.CrimeSet_CrimeSet_6 |  PASSED |```CrimeSet crimSet(CrimeSet::INITIAL_CAPACITY+2);crimSet._capacity;```|
| | | | should give ```10```|
| 78 | T01_Basics.Counter_Counter_0 |  PASSED |```CrimeCounter crmC; string s; s = to_string(CrimeCounter::DEFAULT_ROWS) + "x" + to_string(CrimeCounter::DEFAULT_COLUMNS) + " "; for (int i = 0; i < CrimeCounter::DEFAULT_ROWS * CrimeCounter::DEFAULT_COLUMNS; i++) { s += "0 "; }crmC.inspectT()```|
| | | | should give ```"15x10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 79 | T01_Basics.Counter_Counter_1 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc); string s; s = to_string(nr) + "x" + to_string(nc) + " "; for (int i = 0; i < nr * nc; i++) { s += "0 "; }crmC.inspectT()```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 80 | T01_Basics.Counter_Counter_2 |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0,0); Coordinates dos(10,10); CrimeCounter crmC(nr, nc,una,dos); string s; s = to_string(nr) + "x" + to_string(nc) + " "; for (int i = 0; i < nr * nc; i++) { s += "0 "; }crmC.inspectT()```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 81 | T01_Basics.Counter_getNumRows |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc);crmC.getNumRows();```|
| | | | should give ```2```|
| 82 | T01_Basics.Counter_getNumCols |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc);crmC.getNumCols();```|
| | | | should give ```4```|
| 83 | T01_Basics.Counter_getLeftLocation |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0,0); Coordinates dos(10,10); CrimeCounter crmC(nr,nc,una,dos); string s; s = una.toString();crmC.getLeftLocation().toString()```|
| | | | should give ```"0.000000,0.000000"```|
| 84 | T01_Basics.Counter_getRightLocation |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0,0); Coordinates dos(10,10); CrimeCounter crmC(nr,nc,una,dos); string s; s = dos.toString();crmC.getRightLocation().toString()```|
| | | | should give ```"10.000000,10.000000"```|
| 85 | T01_Basics.Counter_getMaxFrequency_1 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc);crmC.getMaxFrequency()```|
| | | | should give ```0```|
| 86 | T01_Basics.Counter_getMaxFrequency_2 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc); crmC._frequency[0][0]=nc;crmC.getMaxFrequency();```|
| | | | should give ```4```|
| 87 | T01_Basics.Counter_getMaxFrequency_3 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC(nr, nc); crmC._frequency[nr-1][nc-1]=nc;crmC.getMaxFrequency();```|
| | | | should give ```4```|
| 88 | T01_Basics.Counter_clear |  PASSED |```int nr = 2; int nc = 4; string s; CrimeCounter crmC(nr, nc); int count = 0; for (int i = 0; i < nr; i++) { for (int j = 0; j < nc; j++) { crmC._frequency[i][j] = count; count++; } } crmC.clear(); s = to_string(nr) + "x" + to_string(nc) + " "; for (int i = 0; i < nr * nc; i++) { s += "0 "; }crmC.inspectT()```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 89 | T01_Basics.Counter_increaseFrequency_0 |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0, 0); Coordinates dos(10, 10); CrimeCounter crmC(nr, nc, una, dos); Crime crm; float stepLat = 0; for (int i = 0; i < nr; i++) { float stepLong = 0; for (int j = 0; j < nc; j++, stepLong += 2.5) { Coordinates cood(stepLat, stepLong); crm.setId(to_string(i * nc + j)); crmC.increaseFrequency(crm); } }crmC.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 90 | T01_Basics.Counter_increaseFrequency_1 |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0, 0); Coordinates dos(10, 10); CrimeCounter crmC(nr, nc, una, dos); Crime crm; float stepLat = 0; for (int i = 0; i < nr; i++) { float stepLong = 0; for (int j = 0; j < nc; j++, stepLong += 2.5) { Coordinates cood(stepLat, stepLong); crm.setId(to_string(i * nc + j )); crm.setLocation(una); crmC.increaseFrequency(crm); } }crmC.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 8 0 0 0 "```|
| 91 | T01_Basics.Counter_increaseFrequency_2 |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0, 0); Coordinates dos(10, 10); CrimeCounter crmC(nr, nc, una, dos); Crime crm; float stepLat = 0; for (int i = 0; i < nr; i++) { float stepLong = 0; for (int j = 0; j < nc; j++, stepLong += 2.5) { Coordinates cood(stepLat, stepLong); crm.setId(to_string(i * nc + j )); crm.setLocation(dos); crmC.increaseFrequency(crm); } }crmC.inspectT();```|
| | | | should give ```"2x4 0 0 0 8 0 0 0 0 "```|
| 92 | T01_Basics.Counter_increaseFrequency_3 |  PASSED |```int nr = 2; int nc = 4; Coordinates una(0, 0); Coordinates dos(10, 10); CrimeCounter crmC(nr, nc, una, dos); Crime crm; float stepLat = 0; crmC.increaseFrequency(crm); for (int i = 0; i <= nr; i++) { float stepLong = 0; for (int j = 0; j <= nc; j++, stepLong += 2.5) { Coordinates cood(stepLat, stepLong); crm.setId(to_string(i * nc + j )); crm.setLocation(cood); crmC.increaseFrequency(crm); } stepLat += 5.0; }crmC.inspectT();```|
| | | | should give ```"2x4 1 1 1 2 2 2 2 4 "```|
| 93 | T01_Basics.Counter_calculateFrequencies3 |  PASSED |```int nr = 2; int nc = 4; int id = 0; Coordinates una(0, 0); Coordinates dos(10, 10); CrimeCounter crmC(nr, nc, una, dos); Crime crm; float stepLat = 0; CrimeSet crmS((nr+1)*(nc+1)+1); crmS._nCrimes= (nr+1)*(nc+1)+1; crmS.at(id++) = crm; for (int i = 0; i <= nr; i++) { float stepLong = 0; for (int j = 0; j <= nc; j++, stepLong += 2.5) { Coordinates cood(stepLat, stepLong); crm.setId(to_string(id)); crm.setLocation(cood); crmS.at(id++) = crm; } stepLat += 5.0; } crmC.calculateFrequencies(crmS);crmC.inspectT();```|
| | | | should give ```"2x4 1 1 1 2 2 2 2 4 "```|
| 94 | T02_Intermediate.Crime_Crime_parcial2 |  PASSED |```string s="1,  111  ,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; string due="1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"```|
| 95 | T02_Intermediate.Crime_Crime_parcial1_exception |  PASSED |```string s="1,,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000";Crime crime(s)```|
| | | | should THROW an exception std::invalid_argument|
| 96 | T02_Intermediate.Crime_normalize2 |  PASSED |```string s="1,111,222b,333c,444d,555e,666f,1,2025-02-17 12:30:00,999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 97 | T02_Intermediate.Crime_normalize3_whitesp |  PASSED |```string s="1,111,  222b,  333c,  444d,  555e,  666f,1,2025-02-17 12:30:00,  999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 98 | T02_Intermediate.Crime_normalize4_whitesp |  PASSED |```string s="1,111,  222b  ,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 99 | T02_Intermediate.Crime_normalize5_empty |  PASSED |```string s="1,111,,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 100 | T02_Intermediate.CrimeSet_CrimeSet_4 |  PASSED |```CrimeSet crimSet(-1);```|
| | | | should THROW an exception std::out_of_range|
| 101 | T02_Intermediate.CrimeSet_at_exception |  PASSED |```CrimeSet crimSet(2); crimSet._nCrimes = 2;crimSet.at(2).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 102 | T02_Intermediate.CrimeSet_saveLoad |  PASSED |```CrimeSet l1(10); CrimeSet l2(10); l1._nCrimes=10; l2._nCrimes=10; l1.setComment("Test1"); Crime crm(OTHER); for (int i = 0; i < 10; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } const char* fileName = "tests/output/test_save1.crm"; l1.save(fileName); l2.load(fileName);l1.inspectT() == l2.inspectT();```|
| | | | should give ```true```|
| 103 | T02_Intermediate.CrimeSet_loadLoad |  PASSED |```CrimeSet l1; int n; const char* fileName = "../DataSets/crimes_20.crm"; l1.load(fileName); n = l1.getSize(); l1.load(fileName);l1.getSize()```|
| | | | should give ```20```|
| 104 | T02_Intermediate.CrimeSet_Save_1_exception |  PASSED |```CrimeSet l1; string fileName; fileName= "tests/outp/imposibleToCreateFile.crm";l1.save(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 105 | T02_Intermediate.CrimeSet_Load_2_exception |  PASSED |```CrimeSet l1; string fileName; fileName = "../DataSets/test_noHeader.crm";l1.load(fileName);```|
| | | | should THROW an exception std::invalid_argument|
| 106 | T02_Intermediate.CrimeSet_Load_3_exception |  PASSED |```CrimeSet l1; string fileName; fileName = "tests/output/test_xxx.crm";l1.load(fileName);```|
| | | | should THROW an exception std::ios_base::failure|
| 107 | T02_Intermediate.CrimeSet_join_intersection_empy_1 |  PASSED |```Crime crm; CrimeSet l1(5); CrimeSet l2(5); l1._nCrimes=5; l2._nCrimes=5; for (int i = 0; i < 5; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } for (int i = 0; i < 5; i++) { crm.setId(to_string(i+5)); l2.at(i) = crm; } int initialSize; initialSize = l1._nCrimes;; l1.join(l2);l1.getSize()```|
| | | | should give ```10```|
| 108 | T02_Intermediate.CrimeSet_joinShouldRemainEqual_1 |  PASSED |```Crime crm; CrimeSet l1(5); CrimeSet l2(5); l1._nCrimes=5; l2._nCrimes=5; for (int i = 0; i < 5; i++) { crm.setId(to_string(i)); l1.at(i) = crm; l2.at(i) = crm; } int initialSize; initialSize = l1._nCrimes; l1.join(l2);l1.getSize()```|
| | | | should give ```5```|
| 109 | T02_Intermediate.CrimeSet_normalize_0 |  PASSED |```CrimeSet l1(2); l1._nCrimes=2; Crime crm(OTHER); l1._crimes[1]= crm; l1.normalize(); string s=" 2 "+CRIME_DEFAULT+" "+OTHER;l1.inspectT();```|
| | | | should give ```" 2 0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 110 | T02_Intermediate.CrimeSet_normalize_1 |  PASSED |```CrimeSet l1(2); l1._nCrimes=2; Crime crm; crm.setCode(" unknown "); crm.setDescription(" unknown "); l1._crimes[0]= crm; l1._crimes[1]= crm; l1.normalize(); string s=" 2 "+CRIME_DEFAULT+" "+CRIME_DEFAULT+" ";l1.inspectT();```|
| | | | should give ```" 2 0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 0,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 "```|
| 111 | T02_Intermediate.CrimeSet_selectWhereEQ_1 |  PASSED |```int sizeOriginal = 5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm; for (int i = 0; i < sizeOriginal; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } CrimeSet l2; l2 = l1.selectWhereEQ("Code",EMPTY_FIELD);l2._nCrimes;```|
| | | | should give ```5```|
| 112 | T02_Intermediate.CrimeSet_selectWhereEQ_2 |  PASSED |```int sizeOriginal = 5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm; for (int i = 0; i < sizeOriginal; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } CrimeSet l2; l2 = l1.selectWhereEQ("Shooting","0");l2._nCrimes;```|
| | | | should give ```0```|
| 113 | T02_Intermediate.CrimeSet_selectWhereEQ_3 |  PASSED |```int sizeOriginal=5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm; for (int i = 0; i < sizeOriginal; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } CrimeSet l2; l2 = l1.selectWhereEQ("Code",EMPTY_FIELD); l2.setComment("");l1.inspectN() == l2.inspectN();```|
| | | | should give ```true```|
| 114 | T02_Intermediate.CrimeSet_selectValidLocation_1 |  PASSED |```int sizeOriginal = 5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm; CrimeSet l2; l2 = l1.selectValidLocation();l2.getSize()```|
| | | | should give ```0```|
| 115 | T02_Intermediate.CrimeSet_selectValidLocation_2 |  PASSED |```int sizeOriginal = 5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm(OTHER); for (int i = 0; i < sizeOriginal; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } CrimeSet l2; l2 = l1.selectValidLocation();l2._nCrimes;```|
| | | | should give ```5```|
| 116 | T02_Intermediate.CrimeSet_selectValidLocation_3 |  PASSED |```int sizeOriginal = 5; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm(OTHER); for (int i = 0; i < sizeOriginal; i++) { crm.setId(to_string(i)); l1.at(i) = crm; } CrimeSet l2; l2 = l1.selectValidLocation(); l2.setComment("");l1.inspectN() == l2.inspectN();```|
| | | | should give ```true```|
| 117 | T02_Intermediate.CrimeSet_sort_1_no_change |  PASSED |```int sizeOriginal = 3; string ss=" 3 "; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm(OTHER); for (int i = 0; i < sizeOriginal; i++) { crm.setId(std::to_string(i+1)); l1.at(i) = crm; ss += crm.toString(); ss += " "; } l1.sort();l1.inspectT();```|
| | | | should give ```" 3 1,1,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 118 | T02_Intermediate.CrimeSet_sort_2 |  PASSED |```int sizeOriginal = 3; string ss; CrimeSet l1(sizeOriginal); l1._nCrimes=sizeOriginal; Crime crm(OTHER); for (int i = 0; i < sizeOriginal; i++) { crm.setId(std::to_string(sizeOriginal - i)); l1.at(i) = crm; ss = crm.toString() + " " + ss; } ss = " 3 " + ss; l1.sort();l1.inspectT();```|
| | | | should give ```" 3 1,1,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 119 | T02_Intermediate.CrimeSet_assign_01 |  PASSED |```Crime crm(OTHER); int sizeOriginal = 5; CrimeSet crmS1(sizeOriginal); crmS1._nCrimes=sizeOriginal; CrimeSet crmS2; string ss; for (int i = 0; i < 5; i++) { crm.setId(std::to_string(i)); crmS1.at(i) = crm; ss = crm.toString() + " " + ss; } crmS2=crmS1;crmS2.inspectT();```|
| | | | should give ```" 5 1,0,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,1,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 120 | T02_Intermediate.CrimeSet_assign_02 |  PASSED |```Crime crm(OTHER); int sizeOriginal=5; CrimeSet crmS1(sizeOriginal); crmS1._nCrimes=sizeOriginal; CrimeSet crmS2; string ss; for (int i = 0; i < 5; i++) { crm.setId(std::to_string(i)); crmS1.at(i) = crm; ss = crm.toString() + " " + ss; } crmS2=crmS1; ss = crmS1.inspectT(); crmS1.at(0) = crm;crmS2.inspectT();```|
| | | | should give ```" 5 1,0,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,1,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 121 | T02_Intermediate.Counter_Counter_exception_1 |  PASSED |```int nr = 2; int nc = 4; Coordinates una; Coordinates dos(10,10);CrimeCounter crmC(nr, nc,una,dos);```|
| | | | should THROW an exception std::invalid_argument|
| 122 | T02_Intermediate.Counter_Counter_exception_2 |  PASSED |```int nr = 2; int nc = 4; Coordinates una; Coordinates dos(10,10);CrimeCounter crmC(nr, nc,dos,una);```|
| | | | should THROW an exception std::invalid_argument|
| 123 | T02_Intermediate.Counter_Counter_Copy01 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC1(nr, nc); crmC1._frequency[nr-1][nc-1]= 10; CrimeCounter crmC2(crmC1);crmC2.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 10 "```|
| 124 | T02_Intermediate.Counter_Counter_Copy02 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC1(nr, nc); CrimeCounter crmC2(crmC1); crmC1._frequency[nr-1][nc-1]= 10;crmC2.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 125 | T02_Intermediate.Counter_assign_01 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC1(nr, nc); CrimeCounter crmC2(crmC1); crmC1._frequency[nr-1][nc-1]= 10; crmC2=crmC1;crmC2.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 10 "```|
| 126 | T02_Intermediate.Counter_assign_02 |  PASSED |```int nr = 2; int nc = 4; CrimeCounter crmC1(nr, nc); CrimeCounter crmC2(crmC1); crmC2=crmC1; crmC1._frequency[nr-1][nc-1]= 10;crmC2.inspectT();```|
| | | | should give ```"2x4 0 0 0 0 0 0 0 0 "```|
| 127 | T02_Intermediate.Counter_saveAsPPMTextImage |  PASSED |```CrimeCounter crmC1; ColorPalette pal;crmC1.saveAsPPMTextImage("/home/Doe",pal)```|
| | | | should THROW an exception std::ios_base::failure|
| 128| T03_Advanced.Integration_InvalidArguments_1-valgrind | PASSED | NO LEAKS |
| 128 | T03_Advanced.Integration_InvalidArguments_1 | PASSED | [boston4]: Running without arguments.|
| 129| T03_Advanced.Integration_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 129 | T03_Advanced.Integration_RunWithInvalidArguments1 | PASSED | [boston4 -f ../DataSets/crimes_easy01.crm ../DataSets/crimes_easy01.crm]: Running with invalid arguments (-f)|
| 130| T03_Advanced.Integration_RunWithMissingArguments-valgrind | PASSED | NO LEAKS |
| 130 | T03_Advanced.Integration_RunWithMissingArguments | PASSED | [boston4 -c ]: Running with invalid arguments (-c without valid value)|
| 131| T03_Advanced.Integration00_emptyfile-valgrind | PASSED | NO LEAKS |
| 131 | T03_Advanced.Integration00_emptyfile | PASSED | [Boston4 -h 3 -w 3 -o tests/output/output.ppm ../DataSets/empty.crm]: 3x3 all red, empty file with no crimes.|
| 132| T03_Advanced.Integration01_novalidCoords-valgrind | PASSED | NO LEAKS |
| 132 | T03_Advanced.Integration01_novalidCoords | PASSED | [Boston4 -h 3 -w 3 -o tests/output/output.ppm ../DataSets/crimes_04invalid.crm]: 3x3 all red, file with invalid coordinates for crimes.|
| 133| T03_Advanced.Integration02_outsideCoords-valgrind | PASSED | NO LEAKS |
| 133 | T03_Advanced.Integration02_outsideCoords | PASSED | [Boston4 -h 3 -w 3 -o tests/output/output.ppm ../DataSets/crimes_04inSpain.crm]: 3x3 all red, file with coordinates from Spain for crimes.|
| 134| T03_Advanced.Integration03_allINCoords-valgrind | PASSED | NO LEAKS |
| 134 | T03_Advanced.Integration03_allINCoords | PASSED | [Boston4 -h 3 -w 3 -o tests/output/output.ppm ../DataSets/crimes_05.crm]: 3x3, all coordinates are INTO, but only two cells are reached with frequency 4 and 1.|
| 135| T03_Advanced.Integration04_onlyOne-valgrind | PASSED | NO LEAKS |
| 135 | T03_Advanced.Integration04_onlyOne | PASSED | [Boston4 -h 4 -w 3 -o tests/output/output.ppm ../DataSets/crimes_20.crm]: 4x3, maximum frequency 9, 20 crimes entry but only 17 computed.|
| 136| T03_Advanced.Integration05_onlyOneWithComment-valgrind | PASSED | NO LEAKS |
| 136 | T03_Advanced.Integration05_onlyOneWithComment | PASSED | [Boston4 -h 4 -w 3 -o tests/output/output.ppm -c 'array 2D 1 2 0 3 9 0 1 1 0 0 0 0' ../DataSets/crimes_20.crm]: 4x3, a specific comment is set in the image 20 crimes entry but only 17 computed.|
| 137| T03_Advanced.Integration06_onlyOnechangePalette-valgrind | PASSED | NO LEAKS |
| 137 | T03_Advanced.Integration06_onlyOnechangePalette | PASSED | [Boston4 -h 4 -w 3 -d 1 -b 0 -y 15 -o tests/output/output.ppm ../DataSets/crimes_20.crm]: 4x3, maximum frequency 9, 20 crimes entry but only 17 computed.|
| 138| T03_Advanced.Integration07_FusionOf2Files-valgrind | PASSED | NO LEAKS |
| 138 | T03_Advanced.Integration07_FusionOf2Files | PASSED | [Boston4 -h 4 -w 3 -o tests/output/output.ppm ../DataSets/crimes_20.crm ../DataSets/crimes_20.crm]: fusion of x2 crimes_20, the outcome is similar to outcome5.ppm.|
| 139| T03_Advanced.Integration08_FusionOf2Files-valgrind | PASSED | NO LEAKS |
| 139 | T03_Advanced.Integration08_FusionOf2Files | PASSED | [Boston4 -h 3 -w 3 -o tests/output/output.ppm ../DataSets/empty.crm ../DataSets/crimes_05b.crm]: The first file is empty, the second one is ordered.|
| 140| T03_Advanced.Integration09_FusionOf2Files-valgrind | PASSED | NO LEAKS |
| 140 | T03_Advanced.Integration09_FusionOf2Files | PASSED | [Boston4 -h 4 -w 3 -o tests/output/output.ppm ../DataSets/crimes_15.crm ../DataSets/crimes_20.crm]: 4x3, interseccion not null between the 2 datasets.|
| 141| T03_Advanced.Integration10_FusionOf3Files-valgrind | PASSED | NO LEAKS |
| 141 | T03_Advanced.Integration10_FusionOf3Files | PASSED | [Boston4 -h 4 -w 3 -o tests/output/output.ppm ../DataSets/crimes_15.crm ../DataSets/crimes_20.crm ../DataSets/crimes_100.crm]: 4x3, interseccion not null between the 3 datasets.|
| 142| T03_Advanced.Integration11_FusionOf3Files-valgrind | PASSED | NO LEAKS |
| 142 | T03_Advanced.Integration11_FusionOf3Files | PASSED | [Boston4 -h 4 -w 3 ../DataSets/crimes_15.crm ../DataSets/crimes_20.crm ../DataSets/crimes_100.crm]: 4x3, interseccion not null between the 3 datasets.|
| 143 | T03_Advanced.Integration12_TheBigOne | PASSED | [Boston4 -h 37 -w 45 -o tests/output/output.ppm ../DataSets/crimes_all.crm]: 37x45, with the complete BostonCrime datasets, max freq 8679.|
