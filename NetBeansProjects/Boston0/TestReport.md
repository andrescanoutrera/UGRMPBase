# OUTCOME OF TESTS FOR PROJECT boston0_template

As of Mar  4 2025 18:14:13

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
| 42 | T02_Intermediate.Crime_Crime_parcial2 |  PASSED |```string s="1,  111  ,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; string due="1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"; Crime crime(s);crime.inspectT()```|
| | | | should give ```"1,111,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000"```|
| 43 | T02_Intermediate.Crime_Crime_parcial1_exception |  PASSED |```string s="1,,,,,,,1,2025-02-17 12:30:00,,180.000000,180.000000";Crime crime(s)```|
| | | | should THROW an exception std::invalid_argument|
| 44 | T02_Intermediate.Crime_Normalize0_nochange |  PASSED |```string s="1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,180.000000,180.000000"```|
| 45 | T02_Intermediate.Crime_Normalize1_nochange |  PASSED |```string s="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 46 | T02_Intermediate.Crime_Normalize2 |  PASSED |```string s="1,111,222b,333c,444d,555e,666f,1,2025-02-17 12:30:00,999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 47 | T02_Intermediate.Crime_Normalize3_whitesp |  PASSED |```string s="1,111,  222b,  333c,  444d,  555e,  666f,1,2025-02-17 12:30:00,  999i,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 48 | T02_Intermediate.Crime_Normalize4_whitesp |  PASSED |```string s="1,111,  222b  ,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,222B,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 49 | T02_Intermediate.Crime_Normalize5_empty |  PASSED |```string s="1,111,,  333c  ,  444d  ,  555e  ,  666f  ,1,2025-02-17 12:30:00,  999i  ,180.000000,180.000000"; string due="1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"; Crime crime(s); Normalize(crime);crime.inspectT();```|
| | | | should give ```"1,111,,333C,444D,555E,666F,1,2025-02-17 12:30:00,999I,180.000000,180.000000"```|
| 50| T03_Advanced.Integration_input00-valgrind | PASSED | NO LEAKS |
| 50 | T03_Advanced.Integration_input00 | PASSED | [boston0_template < data/input00.b0in]: Easy test with 6 Crimes almost complete to read, already capitalized without any whiteSpace to be trimed|
| 51| T03_Advanced.Integration_input01-valgrind | PASSED | NO LEAKS |
| 51 | T03_Advanced.Integration_input01 | PASSED | [boston0 < data/input01.b0in]: Test to read 6 Crimes to be normalized. Most the fields have to be modified to be capitalized and whiteSpace to be trimed|
| 52| T03_Advanced.Integration_input02-valgrind | PASSED | NO LEAKS |
| 52 | T03_Advanced.Integration_input02 | PASSED | [boston0 < data/input02.b0in]: Test to control coordinates, resulting 4 crimes inserted but 0 outcomes due to outside coordinates|
| 53| T03_Advanced.Integration_input03-valgrind | PASSED | NO LEAKS |
| 53 | T03_Advanced.Integration_input03 | PASSED | [boston0_template < data/input03.b0in]: Test to control period of time, no crimes inserted in in the array, no outcomes|
| 54| T03_Advanced.Integration_input04-valgrind | PASSED | NO LEAKS |
| 54 | T03_Advanced.Integration_input04 | PASSED | [boston0 < data/input04.b0in]: 2 crimes to read, 0 inserted ones in the array and no resulting outcomes|
| 55| T03_Advanced.Integration_input05-valgrind | PASSED | NO LEAKS |
| 55 | T03_Advanced.Integration_input05 | PASSED | [boston0 < data/input05.b0in]: Test for control of range, only 10 to be inserted in the array. The accepted crimes exceed the array capacity|
