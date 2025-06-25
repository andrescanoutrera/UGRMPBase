# OUTCOME OF TESTS FOR PROJECT boston4_template

As of Jun  5 2025 13:32:25

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T02_Intermediate.Coordinates_read_ |  PASSED |```Coordinates crd; std::string sin=OTHER_COORD; istringstream ssin(sin); ssin >> crd;crd.toString().c_str();```|
| | | | should give ```"90.000000,180.000000"```|
| 2 | T02_Intermediate.Coordinates_print_ |  PASSED |```string sout; ostringstream ssout; Coordinates crd(90.0,180.0); ssout << crd; sout = ssout.str();sout.c_str();```|
| | | | should give ```"90.000000,180.000000"```|
| 3 | T02_Intermediate.Crime_read_ |  PASSED |```Crime cr; std::string sin=OTHER_CRM; istringstream ssin(sin); ssin >> cr;cr.toString().c_str();```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000"```|
| 4 | T02_Intermediate.Crime_print_ |  PASSED |```std::string sout; ostringstream ssout; Crime cr(OTHER_CRM); ssout << cr; sout = ssout.str();sout```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000"```|
| 5 | T02_Intermediate.Crime_operatorGreaterThan_1 |  PASSED |```Crime cr1; Crime cr2(OTHER_CRM);cr2>cr1```|
| | | | should give ```true```|
| 6 | T02_Intermediate.Crime_operatorGreaterThan_2 |  PASSED |```Crime cr1(OTHER_CRM); Crime cr2(OTHER_CRM); cr1.setId("333");cr1>cr2```|
| | | | should give ```true```|
| 7 | T02_Intermediate.Crime_operatorEqual_3 |  PASSED |```Crime cr1; Crime cr2;cr1==cr2```|
| | | | should give ```true```|
| 8 | T02_Intermediate.Crime_operatorLessThan_4 |  PASSED |```Crime cr1; Crime cr2(OTHER_CRM);cr2<cr1```|
| | | | should give ```false```|
| 9 | T02_Intermediate.Crime_operatorLessEqual_5 |  PASSED |```Crime cr1; Crime cr2(OTHER_CRM);cr1<=cr2```|
| | | | should give ```true```|
| 10 | T02_Intermediate.Crime_operatorNotEqual_1 |  PASSED |```Crime cr1; Crime cr2(OTHER_CRM);cr1!=cr2```|
| | | | should give ```true```|
| 11 | T02_Intermediate.CrimeSet_print_ |  PASSED |```string sout; string due=ENDL; due = to_string(MAX)+" "; ostringstream ssout; Crime cr1(OTHER_CRM); CrimeSet crmS; for (int i=1; i<= MAX; i++){ crmS.append(cr1); due+=cr1.toString()+" "; cr1.setId(to_string(i+1)); } ssout << crmS; sout = ssout.str(); sout = std::regex_replace(sout, std::regex(ENDL), " ");sout.c_str()```|
| | | | should give ```"5 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,5,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 12 | T02_Intermediate.CrimeSet_read_ |  PASSED |```Crime cr1(OTHER_CRM); CrimeSet crmS; string due = to_string(MAX)+ENDL; for (int i=1; i<= MAX; i++){ due+=cr1.toString()+ENDL; cr1.setId(to_string(i+1)); } std::string sin= due; istringstream ssin(sin); ssin >> crmS; string sout=crmS.toString(); sout = std::regex_replace(sout, std::regex(ENDL), " "); due = std::regex_replace(due, std::regex(ENDL), " ");sout```|
| | | | should give ```"5 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,5,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 13 | T02_Intermediate.CrimeSet_operatorat_0 |  PASSED |```Crime crm(OTHER_CRM); CrimeSet crmS(1); crmS._nCrimes = 1; crmS.at(0)=crm;crmS[0].inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000"```|
| 14 | T02_Intermediate.CrimeSet_operatorat_1 |  PASSED |```Crime crm1(OTHER_CRM); Crime crm2; CrimeSet crmS(2); crmS._nCrimes = 2; crmS.at(0) = crm1; crmS.at(1) = crm2;crmS[0].inspectT()```|
| | | | should give ```"1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000"```|
| 15 | T02_Intermediate.CrimeSet_operator_join_1 |  PASSED |```Crime cr1(OTHER_CRM); CrimeSet crmS(MAX); crmS._nCrimes = MAX; string due = to_string(MAX)+ENDL; for (int i=1; i<= MAX; i++){ due+=cr1.toString()+ENDL; crmS.at(i-1)= cr1; cr1.setId(to_string(i+1)); } crmS += crmS; string sout=crmS.toString(); sout = std::regex_replace(sout, std::regex(ENDL), " "); due = std::regex_replace(due, std::regex(ENDL), " ");sout```|
| | | | should give ```"5 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,5,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 "```|
| 16 | T02_Intermediate.CrimeSet_operator_join_2 |  PASSED |```Crime cr1(OTHER_CRM); CrimeSet crmS(MAX); crmS._nCrimes = MAX; CrimeSet crmS2(1); crmS2._nCrimes=1; string due; for (int i=1; i<= MAX; i++){ due+=cr1.toString()+" "; crmS.at(i-1)= cr1; cr1.setId(to_string(i+1)); } Crime cr; cr.setId("333"); due= +" "+to_string(MAX+1)+" "+due+cr.toString()+" "; crmS2.at(0)= cr; crmS += crmS2;crmS.inspectT()```|
| | | | should give ```" 6 1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,2,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,3,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,4,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 1,5,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 0,333,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,1,2017-01-20 02:00:00,UNKNOWN,181.000000,181.000000 "```|
| 17 | T02_Intermediate.Counter_operatorPar_1 |  PASSED |```int f=2; int c=4; CrimeCounter crmC(f, c); Crime crm(OTHER_CRM); crmC._frequency[0][c-1]=10;crmC(0,c-1)```|
| | | | should give ```10```|
| 18 | T02_Intermediate.Counter_operatorPar_2 |  PASSED |```int f=2; int c=4; CrimeCounter crmC(f, c); crmC(0,c-1)= 10;crmC(0,c-1);```|
| | | | should give ```10```|
| 19| T03_Advanced.Integration_InvalidArguments_1-valgrind | PASSED | NO LEAKS |
| 19 | T03_Advanced.Integration_InvalidArguments_1 | PASSED | [boston4]: Running without arguments.|
