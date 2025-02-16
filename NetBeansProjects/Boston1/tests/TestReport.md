# OUTCOME OF TESTS FOR PROJECT boston1_template

As of Feb 15 2025 21:33:59

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
| 56 | T01_Basics.ArrayCrimes_PosMinArray_1 |  PASSED |```Crime arrayC[MAX]; fillACrimes(arrayC);PosMinArrayCrimes(arrayC,0,2);```|
| | | | should give ```0```|
| 57 | T02_Intermediate.Crime_Crime_parcial2 |  PASSED |```string s="1,  111  ,,,,,,7,2025-02-17 12:30:00,,180.000000,180.000000"; string due="1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"```|
| 58 | T02_Intermediate.Crime_Crime_parcial1_exception |  PASSED |```string s="1,,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000";Crime crime(s)```|
| | | | should THROW an exception std::invalid_argument|
| 59 | T02_Intermediate.Crime_normalize2 |  PASSED |```string s="1,111,222b,333c,444d,555e,666f,1,2025-02-17 12:30:00,999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 60 | T02_Intermediate.Crime_normalize3_whitesp |  PASSED |```string s="1,111,  222b,  333c,  444d,  555e,  666f,1,2025-02-17 12:30:00,  999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 61 | T02_Intermediate.Crime_normalize4_whitesp |  PASSED |```string s="1,111,  222b  ,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 62 | T02_Intermediate.Crime_normalize5_empty |  PASSED |```string s="1,111,,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); crime.normalize();crime.inspectT();```|
| | | | should give ```"1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 63 | T02_Intermediate.ArrayCrimes_Initialize_0 |  PASSED |```int arrayI[MAX]; bool cero=false; InitializeArrayInts(arrayI,MAX); for (int i = 0; i < MAX; i++) { cero = cero || arrayI[i]; }cero;```|
| | | | should give ```false```|
| 64 | T02_Intermediate.ArrayCrimes_Initialize_1 |  PASSED |```int arrayI[MAX]; bool cero=false; InitializeArrayInts(arrayI,MAX/2); arrayI[MAX-1]=1; for (int i = 0; i < MAX/2; i++) { cero = cero || arrayI[i]; }cero;```|
| | | | should give ```false```|
| 65 | T02_Intermediate.ArrayCrimes_ComputeMaxPos_0 |  PASSED |```bool ok=false; int posM=-1; int max=-1; int arrayI[MAX]; InitializeArrayInts(arrayI,MAX); ComputeMaxPosArrayInts(arrayI,MAX,posM,max); ok = posM == 0 && max==0;ok;```|
| | | | should give ```true```|
| 66 | T02_Intermediate.ArrayCrimes_ComputeMaxPos_1 |  PASSED |```bool ok=false; int posM=-1; int max=-1; int arrayI[MAX]; for (int i = 0; i < MAX; i++) arrayI[i] = i; ComputeMaxPosArrayInts(arrayI,MAX,posM,max); ok = posM == MAX-1 && max== MAX-1;ok;```|
| | | | should give ```true```|
| 67 | T02_Intermediate.ArrayCrimes_PosMinArray_0 |  PASSED |```Crime arrayC[MAX];PosMinArrayCrimes(arrayC,0,MAX-1);```|
| | | | should give ```0```|
| 68 | T02_Intermediate.ArrayCrimes_PosMinArray_2 |  PASSED |```Crime arrayC[MAX]; fillACrimes(arrayC,"333","222","111","30","30","30");PosMinArrayCrimes(arrayC,0,2);```|
| | | | should give ```2```|
| 69 | T02_Intermediate.ArrayCrimes_PosMinArray_3 |  PASSED |```Crime arrayC[MAX]; fillACrimes(arrayC,"111","222","333","30","20","10");PosMinArrayCrimes(arrayC,0,2);```|
| | | | should give ```2```|
| 70 | T02_Intermediate.ArrayCrimes_Print |  PASSED |```Crime arrayC[MAX]; std::string sout; ostringstream ssout; std::streambuf *old = std::cout.rdbuf(ssout.rdbuf()); fillACrimes(arrayC); PrintArrayCrimes(arrayC, 3); sout = ssout.str(); sout = std::regex_replace(sout, std::regex(ENDL), " "); std::cout.rdbuf(old);sout```|
| | | | should give ```"0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:10,UNKNOWN,181.000000,181.000000 0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:20,UNKNOWN,181.000000,181.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 "```|
| 71 | T02_Intermediate.ArrayCrimes_Swap_0 |  PASSED |```string res; Crime arrayC[MAX]; fillACrimes(arrayC); SwapElementsArrayCrimes(arrayC, 2, 0, 1); res = toStringCrimes(arrayC,2);res.c_str()```|
| | | | should give ```"0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:20,UNKNOWN,181.000000,181.000000 0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:10,UNKNOWN,181.000000,181.000000 "```|
| 72 | T02_Intermediate.ArrayCrimes_Swap_1 |  PASSED |```string res; Crime arrayC[MAX]; fillACrimes(arrayC); SwapElementsArrayCrimes(arrayC, 3, 1, 2); SwapElementsArrayCrimes(arrayC, 3, 1, 2); res = toStringCrimes(arrayC,3);res.c_str()```|
| | | | should give ```"0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:10,UNKNOWN,181.000000,181.000000 0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:20,UNKNOWN,181.000000,181.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 "```|
| 73 | T02_Intermediate.ArrayCrimes_FindCrime_0 |  PASSED |```Crime crime; Crime arrayC[MAX]; fillACrimes(arrayC);FindCrimeInArrayCrimes(arrayC,crime,0,2);```|
| | | | should give ```-1```|
| 74 | T02_Intermediate.ArrayCrimes_FindCrime_1 |  PASSED |```Crime crime ; Crime arrayC[MAX];FindCrimeInArrayCrimes(arrayC,crime,0,2);```|
| | | | should give ```0```|
| 75 | T02_Intermediate.ArrayCrimes_FindCrime_2 |  PASSED |```string ss="222"; Crime crime; crime.setId(ss); Crime arrayC[MAX]; fillACrimes(arrayC);FindCrimeInArrayCrimes(arrayC,crime,0,2);```|
| | | | should give ```1```|
| 76 | T02_Intermediate.ArrayCrimes_FindCrime_3 |  PASSED |```string ss="333"; Crime crime; crime.setId(ss); Crime arrayC[MAX]; fillACrimes(arrayC);FindCrimeInArrayCrimes(arrayC,crime,0,2);```|
| | | | should give ```2```|
| 77 | T02_Intermediate.ArrayCrimes_sort_0 |  PASSED |```string res; Crime arrayC[MAX]; fillACrimes(arrayC); SortArrayCrimes(arrayC, 3); res = toStringCrimes(arrayC,3);res.c_str();```|
| | | | should give ```"0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:10,UNKNOWN,181.000000,181.000000 0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:20,UNKNOWN,181.000000,181.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 "```|
| 78 | T02_Intermediate.ArrayCrimes_ComputeHistogram_1 |  PASSED |```string res; int arrayI[MAXH]; Crime arrayC[MAX]; InitializeArrayInts(arrayI,7); ComputeHistogramArrayCrimes(arrayC,MAX,0,arrayI); for (int i = 0; i < 7; i++) { res += to_string(arrayI[i]) + " "; }res.c_str();```|
| | | | should give ```"0 0 0 0 0 10 0 "```|
| 79 | T02_Intermediate.ArrayCrimes_ComputeHistogram_2 |  PASSED |```string res; int arrayI[MAXH]; Crime arrayC[MAX]; InitializeArrayInts(arrayI,MAXH); ComputeHistogramArrayCrimes(arrayC,MAX,1,arrayI); for (int i = 0; i < MAXH; i++) { res += to_string(arrayI[i]) + " "; }res.c_str();```|
| | | | should give ```"0 0 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 80 | T02_Intermediate.ArrayCrimes_ComputeHistogram_3 |  PASSED |```string res; string sdate; string s; int arrayI[MAXH]; Crime arrayC[MAX]; InitializeArrayInts(arrayI, 7); sdate = arrayC[0].getDateTime().toString(); for (int i = 0; i < MAX; i++) { s = to_string(10 + i); sdate.replace(sdate.begin() + 8, sdate.begin() + 10, s); arrayC[i].setDateTime(sdate); } ComputeHistogramArrayCrimes(arrayC, MAX, 0, arrayI); for (int i = 0; i < 7; i++) { res += to_string(arrayI[i]) + " "; }res.c_str();```|
| | | | should give ```"1 1 2 2 2 1 1 "```|
| 81 | T02_Intermediate.ArrayCrimes_ComputeHistogram_4 |  PASSED |```string res; string sdate; string s; int arrayI[MAXH]; Crime arrayC[MAX]; InitializeArrayInts(arrayI, MAX); sdate = arrayC[0].getDateTime().toString(); for (int i = 0; i < MAX; i++) { s = to_string(i); sdate.replace(sdate.end() -7, sdate.end() -6, s); arrayC[i].setDateTime(sdate); } ComputeHistogramArrayCrimes(arrayC, MAX, 1, arrayI); for (int i = 0; i < MAXH; i++) { res += to_string(arrayI[i]) + " "; }res.c_str();```|
| | | | should give ```"1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 82 | T02_Intermediate.ArrayCrimes_SelectWhereEQ0_0 |  PASSED |```int nS; string res; string sfield = "Code"; Crime arrayC[MAX]; Crime arrayS[MAX]; SelectWhereEQArrayCrimes(arrayC, MAX, sfield, "222", arrayS, nS); res=toStringCrimes(arrayS, nS);res.c_str();```|
| | | | should give ```""```|
| 83 | T02_Intermediate.ArrayCrimes_SelectWhereEQ0_1 |  PASSED |```int nS=-1; string res; string sfield = "Code"; Crime arrayC[MAX]; Crime arrayS[MAX]; SelectWhereEQArrayCrimes(arrayC, MAX, sfield, "222", arrayS, nS); res=toStringCrimes(arrayS, nS);nS;```|
| | | | should give ```0```|
| 84 | T02_Intermediate.ArrayCrimes_SelectWhereEQ_1 |  PASSED |```int nS=-1; string res; string sfield="Code"; Crime arrayC[MAX]; Crime arrayS[MAX]; arrayC[MAX-1].setCode("222"); SelectWhereEQArrayCrimes(arrayC, MAX, sfield, "222", arrayS, nS); res=toStringCrimes(arrayS, nS);res.c_str();```|
| | | | should give ```"0,UNKNOWN,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 "```|
| 85 | T02_Intermediate.ArrayCrimes_SelectWhereEQ_2 |  PASSED |```int nS = -1; string res; string sfield = "Code"; Crime arrayC[MAX]; Crime arrayS[MAX]; for (int i = 0; i < MAX; i++) { arrayC[i].setCode("222"); } SelectWhereEQArrayCrimes(arrayC, MAX, sfield, "222", arrayS, nS); res = toStringCrimes(arrayS, nS);nS;```|
| | | | should give ```10```|
| 86 | T03_Advanced.ArrayCrimes_sort_1_tie |  PASSED |```string res; Crime arrayC[MAX]; fillACrimes(arrayC,"333","222","111","30","30","30"); SortArrayCrimes(arrayC, 3); res = toStringCrimes(arrayC,3);res.c_str();```|
| | | | should give ```"0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 "```|
| 87 | T03_Advanced.ArrayCrimes_sort_2 |  PASSED |```string res; Crime arrayC[MAX]; fillACrimes(arrayC,"333","222","111","30","20","10"); SortArrayCrimes(arrayC, 3); res = toStringCrimes(arrayC,3);res.c_str();```|
| | | | should give ```"0,111,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:10,UNKNOWN,181.000000,181.000000 0,222,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:20,UNKNOWN,181.000000,181.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:30,UNKNOWN,181.000000,181.000000 "```|
| 88 | T03_Advanced.ArrayCrimes_ComputeHistogram_0 |  PASSED |```int arrayI[MAX]; InitializeArrayInts(arrayI,7); Crime arrayC[MAX];ComputeHistogramArrayCrimes(arrayC,MAX,7,arrayI);```|
| | | | should THROW an exception std::out_of_range|
| 89| T03_Advanced.Integration_input00-valgrind | PASSED | NO LEAKS |
| 89 | T03_Advanced.Integration_input00 | PASSED | [boston1_template < data/crimes2.b1in]: Easy test with 2 Crimes to read, only one to store and nothing to select|
| 90| T03_Advanced.Integration_input01-valgrind | PASSED | NO LEAKS |
| 90 | T03_Advanced.Integration_input01 | PASSED | [boston1_template < data/crimes2_bis.b1in]: Easy test with 2 Crimes to read, only one to store and one to select|
| 91| T03_Advanced.Integration_input02-valgrind | PASSED | NO LEAKS |
| 91 | T03_Advanced.Integration_input02 | PASSED | [boston1_template < data/crimes6.b1in]: Test with 6 Crimes to read, filtered by default coordinates|
| 92| T03_Advanced.Integration_input03-valgrind | PASSED | NO LEAKS |
| 92 | T03_Advanced.Integration_input03 | PASSED | [boston1_template < data/crimes7.b1in]: Test with only 7 Crimes to read sequenced of days and hours, 7 to store and selected 2|
| 93| T03_Advanced.Integration_input05-valgrind | PASSED | NO LEAKS |
| 93 | T03_Advanced.Integration_input05 | PASSED | [boston1_template < data/crimes22.b1in]: Advanced test with 22 Crimes to read, filtered by Code 619|
| 94| T03_Advanced.Integration_input06-valgrind | PASSED | NO LEAKS |
| 94 | T03_Advanced.Integration_input06 | PASSED | [boston1_template < data/crimes22_all.b1in]: Advanced test with 22 Crimes to read, with unknow Group value, resulting the original array|
