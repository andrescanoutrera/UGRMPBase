# OUTCOME OF TESTS FOR PROJECT Fraud0_TEMPLATE

As of Feb 17 2026 13:13:19

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Location_Location_def1 |  PASSED |```Location loc; string s=to_string(0.0)+string(" ")+to_string(0.0);loc.inspectT()```|
| | | | should give ```"0.000000 0.000000"```|
| 2 | T01_Basics.Location_get_XY |  PASSED |```Location loc;loc.getX()+loc.getY()+loc.getX()*loc.getY()```|
| | | | should give ```0.000000```|
| 3 | T01_Basics.Location_getName |  PASSED |```Location loc;loc.getName()```|
| | | | should give ```""```|
| 4 | T01_Basics.Location_set_Onelocation |  PASSED |```float f1=37.2; float f2=-3.6; string nam="Granada"; Location loc; loc.set(f1,f2,nam); string s=to_string(f1)+string(" ")+to_string(f2)+string(" ")+nam;loc.inspectT()```|
| | | | should give ```"37.200001 -3.600000 Granada"```|
| 5 | T01_Basics.Location_set_XY |  PASSED |```float f1=37.2; float f2=-3.6; Location loc; loc.setX(f1); loc.setY(f2); string s=to_string(f1)+string(" ")+to_string(f2);loc.inspectT()```|
| | | | should give ```"37.200001 -3.600000"```|
| 6 | T01_Basics.Location_setName |  PASSED |```Location loc; string name="Granada"; loc.setName(name); string s=to_string(0.0)+string(" ")+to_string(0.0)+string(" ")+name;loc.inspectT()```|
| | | | should give ```"0.000000 0.000000 Granada"```|
| 7 | T01_Basics.Location_isInsideArea_in0 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; loc1.set(f1,f2,""); loc2.set(f3,f4,"");loc1.isInsideArea(loc1,loc2);```|
| | | | should give ```true```|
| 8 | T01_Basics.Location_isInsideArea_in1 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; loc1.set(f1,f2,""); loc2.set(f3,f4,"");loc2.isInsideArea(loc1,loc2);```|
| | | | should give ```true```|
| 9 | T01_Basics.Location_isInsideArea_in2 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; Location loc3; loc1.set(f1,f2,""); loc2.set(f3,f4,""); loc3.set(f1+0.2,f2+0.2,"");loc3.isInsideArea(loc1,loc2);```|
| | | | should give ```true```|
| 10 | T01_Basics.Location_isInsideArea_out0 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; Location loc3; loc1.set(f1,f2,""); loc2.set(f3,f4,""); loc3.set(f3+0.2,f4,"");loc3.isInsideArea(loc1,loc2)```|
| | | | should give ```false```|
| 11 | T01_Basics.Location_isInsideArea_out1 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; Location loc3; loc1.set(f1,f2,""); loc2.set(f3,f4,""); loc3.set(f3,f4+0.2,"");loc3.isInsideArea(loc1,loc2)```|
| | | | should give ```false```|
| 12 | T01_Basics.Location_isInsideArea_out2 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; Location loc3; loc1.set(f1,f2,""); loc2.set(f3,f4,""); loc3.set(f1-0.2,f2,"");loc3.isInsideArea(loc1,loc2)```|
| | | | should give ```false```|
| 13 | T01_Basics.Location_isInsideArea_out3 |  PASSED |```float f1=37.2; float f2=-3.6; float f3=39.47; float f4=-0.37; Location loc1; Location loc2; Location loc3; loc1.set(f1,f2,""); loc2.set(f3,f4,""); loc3.set(f1,f2-0.2,"");loc3.isInsideArea(loc1,loc2)```|
| | | | should give ```false```|
| 14 | T01_Basics.Location_squaredDistance_l0 |  PASSED |```float f1=37.2; float f2=-3.6; Location loc1; loc1.set(f1,f2,"");loc1.squaredDistance(loc1)```|
| | | | should give ```0.000000```|
| 15 | T01_Basics.Location_squaredDistance_l1 |  PASSED |```Location loc1; Location loc2; loc2.set(2.0,2.0,"");loc1.squaredDistance(loc2)```|
| | | | should give ```8.000000```|
| 16 | T01_Basics.Location_distance_l0 |  PASSED |```float f1=37.2; float f2=-3.6; Location loc1; loc1.set(f1,f2,"");loc1.distance(loc1)```|
| | | | should give ```0.000000```|
| 17 | T01_Basics.Location_distance_l1 |  PASSED |```Location loc1; Location loc2; loc2.set(2.0,2.0,""); double r=sqrt(8.0);loc1.distance(loc2)```|
| | | | should give ```2.828427```|
| 18 | T01_Basics.Location_distance_l2 |  PASSED |```Location loc1; Location loc2; loc2.set(2.0,2.0,""); double r=sqrt(8.0);loc2.distance(loc1)```|
| | | | should give ```2.828427```|
| 19 | T01_Basics.Location_load_0 |  PASSED |```Location loc; const string LOCATION_OTHER="37.200000 -3.600000"; istringstream ssin(LOCATION_OTHER); loc.load(ssin);loc.inspectT().c_str()```|
| | | | should give ```"37.200000 -3.600000"```|
| 20 | T01_Basics.Location_load_1 |  PASSED |```Location loc; const string LOCATION_OTHER="37.200000 -3.600000 Granada"; istringstream ssin(LOCATION_OTHER); loc.load(ssin);loc.inspectT().c_str()```|
| | | | should give ```"37.200000 -3.600000 Granada"```|
| 21 | T01_Basics.VectorLocation_getCapacity |  PASSED |```VectorLocation vloc; vloc._size = 2;vloc.getCapacity()```|
| | | | should give ```100```|
| 22 | T01_Basics.VectorLocation_getCapacity2 |  PASSED |```int n=10; VectorLocation vloc(n); vloc._size = 2;vloc.getCapacity()```|
| | | | should give ```100```|
| 23 | T01_Basics.VectorLocation_Clear_1 |  PASSED |```VectorLocation vloc; vloc._size = VectorLocation::DIM_VECTOR_LOCATIONS; vloc.clear();vloc.getSize();```|
| | | | should give ```0```|
| 24 | T01_Basics.VectorLocation_VectorLocation_def3 |  PASSED |```VectorLocation vloc(VectorLocation::DIM_VECTOR_LOCATIONS);vloc._size```|
| | | | should give ```100```|
| 25 | T01_Basics.VectorLocation_VectorLocation_def1 |  PASSED |```VectorLocation vloc;std::regex_replace(vloc.inspectT(), std::regex(ENDL), " ")```|
| | | | should give ```"0 "```|
| 26 | T01_Basics.VectorLocation_VectorLocation_def2 |  PASSED |```string s = "1 " + string(LOCATION_DEFAULT) +" "; VectorLocation vloc(1);vloc.inspectT().c_str()```|
| | | | should give ```"1 0.000000 0.000000 "```|
| 27 | T01_Basics.VectorLocation_getSize0 |  PASSED |```VectorLocation vloc;vloc.getSize()```|
| | | | should give ```0```|
| 28 | T01_Basics.VectorLocation_getSize1 |  PASSED |```VectorLocation vloc(2);vloc.getSize()```|
| | | | should give ```2```|
| 29 | T01_Basics.VectorLocation_toString |  PASSED |```string s = "2 " + string(LOCATION_DEFAULT)+ " " + string(LOCATION_OTHER)+ " "; Location loc1; Location loc2; loc2.set(37.2, -3.6,"Granada"); VectorLocation vloc(2); vloc._locations[0] = loc1; vloc._locations[1] = loc2;std::regex_replace(vloc.toString(), std::regex(ENDL), " ")```|
| | | | should give ```"2 0.000000 0.000000 37.200000 -3.600000 Granada "```|
| 30 | T01_Basics.VectorLocation_Clear_0 |  PASSED |```VectorLocation vloc; vloc.clear();vloc.getSize();```|
| | | | should give ```0```|
| 31 | T01_Basics.VectorLocation_append_0 |  PASSED |```Location loc; loc.set(37.2, -3.6, "Granada"); VectorLocation vloc; string s = std::string("1 ") + string(LOCATION_OTHER)+ " "; vloc.append(loc);vloc.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 32 | T01_Basics.VectorLocation_append_1 |  PASSED |```string ss = string("2 ") + string(LOCATION_DEFAULT) + string(" ") + string(LOCATION_OTHER)+ " "; Location loc1; Location loc2; loc2.set(37.2, -3.6, "Granada"); VectorLocation vloc; vloc.append(loc1); vloc.append(loc2);vloc.inspectT().c_str()```|
| | | | should give ```"2 0.000000 0.000000 37.200000 -3.600000 Granada "```|
| 33 | T01_Basics.VectorLocation_at_0 |  PASSED |```VectorLocation vloc(2);vloc.at(0).inspectT().c_str()```|
| | | | should give ```"0.000000 0.000000"```|
| 34 | T01_Basics.VectorLocation_at_1 |  PASSED |```VectorLocation vloc(2);vloc.at(1).inspectT().c_str()```|
| | | | should give ```"0.000000 0.000000"```|
| 35 | T01_Basics.VectorLocation_at_2 |  PASSED |```Location loc; VectorLocation vloc(2); loc.set(37.2, -3.6, "Granada"); vloc.at(0)=loc;vloc.at(0).inspectT().c_str()```|
| | | | should give ```"37.200000 -3.600000 Granada"```|
| 36 | T01_Basics.VectorLocation_at_3 |  PASSED |```Location loc; VectorLocation vloc(2); loc.set(37.2, -3.6, "Granada"); vloc.at(1)=loc;vloc.at(1).inspectT().c_str()```|
| | | | should give ```"37.200000 -3.600000 Granada"```|
| 37 | T01_Basics.VectorLocation_findLocation_0 |  PASSED |```Location loc; VectorLocation vloc;vloc.findLocation(loc);```|
| | | | should give ```-1```|
| 38 | T01_Basics.VectorLocation_findLocation_1 |  PASSED |```Location loc1; Location loc2; loc2.set(37.2, -3.6, "Granada"); VectorLocation vloc(2); vloc._locations[0] = loc2;vloc.findLocation(loc2);```|
| | | | should give ```0```|
| 39 | T01_Basics.VectorLocation_findLocation_2 |  PASSED |```Location loc1; Location loc2; loc2.set(37.2, -3.6, "Granada"); VectorLocation vloc(2); vloc._locations[1] = loc2;vloc.findLocation(loc2);```|
| | | | should give ```1```|
| 40 | T01_Basics.VectorLocation_findLocation_3 |  PASSED |```Location loc; loc.setName("OTHER"); VectorLocation vloc(5);vloc.findLocation(loc);```|
| | | | should give ```-1```|
| 41 | T02_Intermediate.VectorLocation_VectorLocation_def4 |  PASSED |```VectorLocation vloc(VectorLocation::DIM_VECTOR_LOCATIONS+1);```|
| | | | should THROW an exception std::out_of_range|
| 42 | T02_Intermediate.VectorLocation_findLocation_4 |  PASSED |```Location loc; loc.setName("OTHER"); VectorLocation vloc(VectorLocation::DIM_VECTOR_LOCATIONS); vloc._locations[VectorLocation::DIM_VECTOR_LOCATIONS - 1] = loc;vloc.findLocation(loc);```|
| | | | should give ```99```|
| 43 | T02_Intermediate.VectorLocation_out_of_range__append_4 |  PASSED |```Location loc; loc.set(37.2, -3.6,"Granada"); VectorLocation vloc; vloc._size = VectorLocation::DIM_VECTOR_LOCATIONS; vloc._locations[0]=loc; vloc.append(loc);vloc._size;```|
| | | | should give ```100```|
| 44 | T02_Intermediate.VectorLocation_out_of_range__append_5 |  PASSED |```Location loc; loc.set(0,0,"Terrace"); VectorLocation vloc; vloc._size = VectorLocation::DIM_VECTOR_LOCATIONS;vloc.append(loc);```|
| | | | should THROW an exception std::out_of_range|
| 45 | T02_Intermediate.VectorLocation_VectorLocation_def5 |  PASSED |```VectorLocation vloc(-1);```|
| | | | should THROW an exception std::out_of_range|
| 46 | T02_Intermediate.VectorLocation_append_2 |  PASSED |```Location loc; loc.set(37.2, -3.6, "Granada"); string ss = "1 " + string(LOCATION_OTHER)+" "; VectorLocation vloc; vloc.append(loc); vloc.append(loc);vloc.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 47 | T02_Intermediate.VectorLocation_at_exception0 |  PASSED |```VectorLocation vloc(2);vloc.at(-1).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 48 | T02_Intermediate.VectorLocation_at_exception1 |  PASSED |```VectorLocation vloc(2);vloc.at(2).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 49 | T02_Intermediate.VectorLocation_select_0 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc1.set(1,1,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n); VectorLocation l2; for (int i = 1; i <= n; i++) { l1._locations[i-1].set(-i,i,std::to_string(i)); } l2 = l1.select(loc0,loc2);l2._size;```|
| | | | should give ```0```|
| 50 | T02_Intermediate.VectorLocation_select_1 |  PASSED |```int sizeOriginal = 5; Location loc1; Location loc2; loc2.set(sizeOriginal,sizeOriginal,std::to_string(sizeOriginal)); VectorLocation l1(sizeOriginal); VectorLocation l2; for (int i = 1; i <= sizeOriginal; i++) { l1._locations[i-1].set(i,i,std::to_string(i)); } l2 = l1.select(loc1,loc2);l2._size;```|
| | | | should give ```5```|
| 51 | T02_Intermediate.VectorLocation_select_2 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc1.set(1.0,1.0,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n+1); VectorLocation l2; for (int i = 0; i <= n; i++) { l1._locations[i].set(i*(n+1),i*(n+1),std::to_string(i)); } l2 = l1.select(loc0,loc2);l2._size;```|
| | | | should give ```1```|
| 52 | T02_Intermediate.VectorLocation_select_3 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc0.set(0,0,"0"); loc1.set(1,1,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n+1); VectorLocation l2; VectorLocation sol; sol.append(loc0); for (int i = 0; i <= n; i++) { l1._locations[i].set(i*(n+1),i*(n+1),std::to_string(i)); } l2 = l1.select(loc0,loc2);l2.inspectT().c_str()```|
| | | | should give ```"1 0.000000 0.000000 0 "```|
| 53 | T02_Intermediate.VectorLocation_select_4 |  PASSED |```int sizeOriginal = 5; Location loc0; Location loc1; Location loc2; loc1.set(1,1,"1"); loc2.set(sizeOriginal,sizeOriginal,std::to_string(sizeOriginal)); VectorLocation l1(sizeOriginal); VectorLocation l2; VectorLocation sol; for (int i = 1; i <= sizeOriginal; i++) { l1._locations[i-1].set(i,i,std::to_string(i)); sol.append(l1._locations[i-1]); } l2 = l1.select(loc1,loc2);l2.inspectT().c_str()```|
| | | | should give ```"5 1.000000 1.000000 1 2.000000 2.000000 2 3.000000 3.000000 3 4.000000 4.000000 4 5.000000 5.000000 5 "```|
| 54 | T02_Intermediate.VectorLocation_sort_1_no_change |  PASSED |```int sizeOriginal = 3; Location loc; VectorLocation l1(sizeOriginal); VectorLocation sol; for (int i = 0; i < sizeOriginal; i++) { loc.setName(std::to_string(i)); l1.at(i) = loc; sol.append(loc); } l1.sort();sol.inspectT() == l1.inspectT();```|
| | | | should give ```true```|
| 55 | T02_Intermediate.VectorLocation_sort_2 |  PASSED |```int sizeOriginal = 3; Location loc; VectorLocation l1(sizeOriginal); VectorLocation sol; for (int i = 0; i < sizeOriginal; i++) { loc.setName(std::to_string(i)); l1.at(sizeOriginal-(i+1)) = loc; sol.append(loc); } l1.sort();sol.inspectT() == l1.inspectT();```|
| | | | should give ```true```|
| 56 | T02_Intermediate.VectorLocatioin_join_intersection_empy_0 |  PASSED |```int n = 5; VectorLocation l1(n); VectorLocation l2(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); l2._locations[i].set((i+1)*n,(i+1)*n,std::to_string((i+1)*n)); } l1.join(l2);l1.getSize()```|
| | | | should give ```10```|
| 57 | T02_Intermediate.VectorLocatioin_joinShouldRemainEqual_1 |  PASSED |```int n = 5; VectorLocation l1(n); VectorLocation l2(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); l2._locations[i].set(i,i,std::to_string(i)); } l1.join(l2);l1.getSize()```|
| | | | should give ```5```|
| 58 | T02_Intermediate.VectorLocatioin_joinShouldRemainEqual_2 |  PASSED |```string ss = "1 " + string(LOCATION_OTHER)+" "; VectorLocation l1(1); VectorLocation l2(1); l1._locations[0].set(37.2, -3.6,"Granada"); l2._locations[0].set(37.2, -3.6,"Granada"); l1.join(l2);l1.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 59 | T02_Intermediate.ArrayLocation_ToArrayLocation_0 |  PASSED |```const int DIM=10; Location array[DIM]; int n=5; int size=0; VectorLocation l1(DIM); VectorLocation l2(DIM); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); } ToArrayLocation(l1,array,DIM,size); for (int i = 0; i < size; i++) { l2._locations[i] = array[i]; }l2.inspectT();```|
| | | | should give ```"10 0.000000 0.000000 0 1.000000 1.000000 1 2.000000 2.000000 2 3.000000 3.000000 3 4.000000 4.000000 4 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 "```|
| 60 | T02_Intermediate.ArrayLocation_ToArrayLocation_1 |  PASSED |```const int DIM=10; Location array[DIM]; int n=5; int size=0; VectorLocation l1(DIM); VectorLocation l2(DIM); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); }ToArrayLocation(l1,array,n,size)```|
| | | | should THROW an exception std::invalid_argument|
| 61 | T02_Intermediate.ArrayLocation_ToVectorLocation_0 |  PASSED |```const int DIM=10; Location array[DIM]; int n=5; int size=0; VectorLocation l1(n); VectorLocation l2; for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); array[i]=l1._locations[i]; } size=n; l2=ToVectorLocation(array,size);l2.inspectT();```|
| | | | should give ```"5 0.000000 0.000000 0 1.000000 1.000000 1 2.000000 2.000000 2 3.000000 3.000000 3 4.000000 4.000000 4 "```|
| 62 | T02_Intermediate.ArrayLocation_ToVectorLocation_1 |  PASSED |```const int DIM=10; Location array[DIM]; int n=5; int size=0; VectorLocation l1(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); array[i]=l1._locations[i]; } size=-1;ToVectorLocation(array,size);```|
| | | | should THROW an exception std::out_of_range|
| 63| T03_Advanced.Integration_test00-valgrind | PASSED | NO LEAKS |
| 63 | T03_Advanced.Integration_test00 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_5locations.p0in]: Test to read a set of 5 locations|
| 64| T03_Advanced.Integration_test01-valgrind | PASSED | NO LEAKS |
| 64 | T03_Advanced.Integration_test01 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_5blocations.p0in]: Test to read a set of 5 b-locations all aways|
| 65| T03_Advanced.Integration_test02-valgrind | PASSED | NO LEAKS |
| 65 | T03_Advanced.Integration_test02 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_4locations_1side.p0in]: Test to read a set of 4 locations from 1 side|
| 66| T03_Advanced.Integration_test03-valgrind | PASSED | NO LEAKS |
| 66 | T03_Advanced.Integration_test03 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_4blocations_1side.p0in]: Test to read a set of 4 locations from 1 side|
| 67| T03_Advanced.Integration_test04-valgrind | PASSED | NO LEAKS |
| 67 | T03_Advanced.Integration_test04 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_6locations.p0in]: Test to read a set of 6 locations, one duplicated|
| 68| T03_Advanced.Integration_test05-valgrind | PASSED | NO LEAKS |
| 68 | T03_Advanced.Integration_test05 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_6locations.p0in]: Test to read a set of 6 locations, one empty named|
| 69| T03_Advanced.Integration_test06-valgrind | PASSED | NO LEAKS |
| 69 | T03_Advanced.Integration_test06 | PASSED | [FraudDetection0_TEMPLATE < ../Datasets/dataP0/princeton_0locations.p0in]: Test to read 0 locations|
