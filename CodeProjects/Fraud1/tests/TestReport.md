# OUTCOME OF TESTS FOR PROJECT Fraud1_TEMPLATE

As of Feb 17 2026 19:11:12

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
| 41 | T01_Basics.VectorLocation_nearest_0 |  PASSED |```int sizeOriginal = 5; Location loc0; loc0.set(1,1,"1"); VectorLocation l1;l1.nearest(loc0)```|
| | | | should give ```-1```|
| 42 | T01_Basics.VectorLocation_nearest_1 |  PASSED |```int n = 5; Location loc1; loc1.set(0.0,0.0,"1"); VectorLocation l1(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); }l1.nearest(loc1)```|
| | | | should give ```0```|
| 43 | T01_Basics.VectorLocation_nearest_2 |  PASSED |```int n = 5; Location loc1; loc1.set(0.0,0.0,"1"); VectorLocation l1(n); for (int i = 0; i < n; i++) { l1._locations[n-(i+1)].set(i,i,std::to_string(i)); }l1.nearest(loc1)```|
| | | | should give ```4```|
| 44 | T01_Basics.VectorLocation_loadFromFile_0 |  PASSED |```int n=5; VectorLocation l1(n); VectorLocation l2; Location loc; for (int i = 0; i < n; i++) { loc.set(i,i,std::to_string(i)); l1.at(i) = loc; } const char* fileName = "tests/output/test_save1.loc"; ifstream fi; ofstream fo; fo.open(fileName); fo << l1.toString(); fo.close(); fi.open(fileName); l2.load(fi); fi.close();l2.inspectT().c_str()```|
| | | | should give ```"5 0.000000 0.000000 0 1.000000 1.000000 1 2.000000 2.000000 2 3.000000 3.000000 3 4.000000 4.000000 4 "```|
| 45 | T01_Basics.VectorLocation_loadFromCin_1 |  PASSED |```int n=1; VectorLocation l1(n); double d1; double d2; string name; string ss = std::string("1 ") + string(LOCATION_OTHER)+ " "; istringstream ssin(ss); l1.load(ssin);l1.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 46 | T01_Basics.VectorLocation_loadEmptyName_4 |  PASSED |```int n=1; VectorLocation l1(n); string ss = std::string("1 ") + string(LOCATION_DEFAULT)+ " "; istringstream ssin(ss); l1.load(ssin); l1.load(ssin);l1.inspectT().c_str()```|
| | | | should give ```"1 0.000000 0.000000 "```|
| 47 | T01_Basics.VectorInt_VectorInt_getCapacity |  PASSED |```VectorInt v; v._size=2;v.getCapacity()```|
| | | | should give ```100```|
| 48 | T01_Basics.VectorInt_VectorInt_def0 |  PASSED |```VectorInt v;v._size```|
| | | | should give ```0```|
| 49 | T01_Basics.VectorInt_VectorInt_def1 |  PASSED |```VectorInt v(5);v._size```|
| | | | should give ```5```|
| 50 | T01_Basics.VectorInt_getSize |  PASSED |```VectorInt v(5);v.getSize()```|
| | | | should give ```5```|
| 51 | T01_Basics.VectorInt_assign |  PASSED |```VectorInt v(4); v.assign(7); string ss="4 7 7 7 7 ";std::regex_replace(v.inspectT(),std::regex(ENDL), " ")```|
| | | | should give ```"4 7 7 7 7 "```|
| 52 | T01_Basics.VectorInt_append_0 |  PASSED |```VectorInt v(2); v.append(7);v._size```|
| | | | should give ```3```|
| 53 | T01_Basics.VectorInt_append_1 |  PASSED |```VectorInt v(2); v.append(7);v._values[2]```|
| | | | should give ```7```|
| 54 | T01_Basics.VectorInt_clear |  PASSED |```VectorInt v(5); v.clear();v.getSize()```|
| | | | should give ```0```|
| 55 | T01_Basics.VectorInt_at_0 |  PASSED |```VectorInt v(2); v._values[0]=7;v.at(0)```|
| | | | should give ```7```|
| 56 | T01_Basics.VectorInt_at_1 |  PASSED |```VectorInt v(2); v._values[1]=7;v.at(1)```|
| | | | should give ```7```|
| 57 | T01_Basics.VectorInt_at_2 |  PASSED |```string ss="2 0 7 "; VectorInt v(2); v.at(1)=7;v.inspectT().c_str()```|
| | | | should give ```"2 0 7 "```|
| 58 | T01_Basics.VectorInt_toString1 |  PASSED |```VectorInt v(5);v.inspectT().c_str()```|
| | | | should give ```"5 0 0 0 0 0 "```|
| 59 | T01_Basics.VectorInt_toString2 |  PASSED |```VectorInt v(5); v.assign(7);v.inspectT().c_str()```|
| | | | should give ```"5 7 7 7 7 7 "```|
| 60 | T01_Basics.VectorInt_distance0 |  PASSED |```VectorInt v1(3); VectorInt v2(3); for (int i=0; i<3;i++){ v1._values[i]=i+1; v2._values[i]=i+1; }v1.distance(v2)```|
| | | | should give ```0.000000```|
| 61 | T01_Basics.VectorInt_distance1 |  PASSED |```VectorInt v1(3); VectorInt v2(3); for (int i=0; i<3;i++){ v1._values[i]=i+1; v2._values[i]=i+1; } v2._values[2]=6;v1.distance(v2)```|
| | | | should give ```3.000000```|
| 62 | T01_Basics.VectorInt_countIdenticalElements0 |  PASSED |```VectorInt v1(3); VectorInt v2(3);v1.countIdenticalElements(v2)```|
| | | | should give ```3```|
| 63 | T01_Basics.VectorInt_countIdenticalElements1 |  PASSED |```VectorInt v1(3); VectorInt v2(3); for (int i=0; i<3;i++){ v1._values[i]=5; v2._values[i]=5; } v2._values[0]=1;v1.countIdenticalElements(v2)```|
| | | | should give ```2```|
| 64 | T01_Basics.Clustering_Clustering_def0 |  PASSED |```Clustering clt;clt._clusters.getSize()+clt._isDone+clt._K+clt._numIterations+clt._sumWCV;```|
| | | | should give ```0```|
| 65 | T01_Basics.Clustering_Clustering_def1 |  PASSED |```Clustering clt;(unsigned) clt._seed```|
| | | | should give ```1761560597```|
| 66 | T01_Basics.Clustering_Clustering_def2 |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations,2,12345); string ss="K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: ";std::regex_replace(clt.inspectT(), std::regex(ENDL), " ")```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 67 | T01_Basics.Clustering_Clustering_gets4 |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 68 | T01_Basics.Clustering_getCentroids |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 5, 12345); const VectorLocation centroids = clt.getCentroids();centroids.getSize()```|
| | | | should give ```5```|
| 69 | T01_Basics.Clustering_clusterOf_BeforeRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345);clt.clusterOf(1)```|
| | | | should give ```-1```|
| 70 | T01_Basics.Clustering_getSumWCV_BeforeRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345);clt.getSumWCV()```|
| | | | should give ```0.000000```|
| 71 | T01_Basics.Clustering_clusterInfo2_InvalidCluster |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345);std::regex_replace(clt.clusterInfo(2), std::regex(ENDL), " ")```|
| | | | should give ```""```|
| 72 | T01_Basics.Clustering_toString |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); string ss = "K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: ";std::regex_replace(clt.toString(), std::regex(ENDL), " ")```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 73 | T01_Basics.Clustering_set |  PASSED |```VectorLocation locations; fill_vlocation(locations,5); Clustering clt; clt.set(locations, 3, 12345);```|
| | | | should give ```"K=2 Sum of within-cluster variances: 0.000000 Number of iterations: 0 Cluster number for each location: 3 0 0 0 Centroids: 2 0.000000 0.000000 0.000000 0.000000 Cluster 0 information: Cluster 1 information: "```|
| 74 | T01_Basics.Clustering_set_InvalidK |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt;clt.set(locations, 0, 12345)```|
| | | | should THROW an exception std::invalid_argument|
| 75 | T02_Intermediate.VectorLocation_VectorLocation_def4 |  PASSED |```VectorLocation vloc(VectorLocation::DIM_VECTOR_LOCATIONS+1);```|
| | | | should THROW an exception std::out_of_range|
| 76 | T02_Intermediate.VectorLocation_findLocation_4 |  PASSED |```Location loc; loc.setName("OTHER"); VectorLocation vloc(VectorLocation::DIM_VECTOR_LOCATIONS); vloc._locations[VectorLocation::DIM_VECTOR_LOCATIONS - 1] = loc;vloc.findLocation(loc);```|
| | | | should give ```99```|
| 77 | T02_Intermediate.VectorLocation_out_of_range__append_4 |  PASSED |```Location loc; loc.set(37.2, -3.6,"Granada"); VectorLocation vloc; vloc._size = VectorLocation::DIM_VECTOR_LOCATIONS; vloc._locations[0]=loc; vloc.append(loc);vloc._size;```|
| | | | should give ```100```|
| 78 | T02_Intermediate.VectorLocation_out_of_range__append_5 |  PASSED |```Location loc; loc.set(0,0,"Terrace"); VectorLocation vloc; vloc._size = VectorLocation::DIM_VECTOR_LOCATIONS;vloc.append(loc);```|
| | | | should THROW an exception std::out_of_range|
| 79 | T02_Intermediate.VectorLocation_VectorLocation_def5 |  PASSED |```VectorLocation vloc(-1);```|
| | | | should THROW an exception std::out_of_range|
| 80 | T02_Intermediate.VectorLocation_append_2 |  PASSED |```Location loc; loc.set(37.2, -3.6, "Granada"); string ss = "1 " + string(LOCATION_OTHER)+" "; VectorLocation vloc; vloc.append(loc); vloc.append(loc);vloc.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 81 | T02_Intermediate.VectorLocation_at_exception0 |  PASSED |```VectorLocation vloc(2);vloc.at(-1).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 82 | T02_Intermediate.VectorLocation_at_exception1 |  PASSED |```VectorLocation vloc(2);vloc.at(2).inspectT()```|
| | | | should THROW an exception std::out_of_range|
| 83 | T02_Intermediate.VectorLocation_select_0 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc1.set(1,1,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n); VectorLocation l2; for (int i = 1; i <= n; i++) { l1._locations[i-1].set(-i,i,std::to_string(i)); } l2 = l1.select(loc0,loc2);l2._size;```|
| | | | should give ```0```|
| 84 | T02_Intermediate.VectorLocation_select_1 |  PASSED |```int sizeOriginal = 5; Location loc1; Location loc2; loc2.set(sizeOriginal,sizeOriginal,std::to_string(sizeOriginal)); VectorLocation l1(sizeOriginal); VectorLocation l2; for (int i = 1; i <= sizeOriginal; i++) { l1._locations[i-1].set(i,i,std::to_string(i)); } l2 = l1.select(loc1,loc2);l2._size;```|
| | | | should give ```5```|
| 85 | T02_Intermediate.VectorLocation_select_2 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc1.set(1.0,1.0,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n+1); VectorLocation l2; for (int i = 0; i <= n; i++) { l1._locations[i].set(i*(n+1),i*(n+1),std::to_string(i)); } l2 = l1.select(loc0,loc2);l2._size;```|
| | | | should give ```1```|
| 86 | T02_Intermediate.VectorLocation_select_3 |  PASSED |```int n = 5; Location loc0; Location loc1; Location loc2; loc0.set(0,0,"0"); loc1.set(1,1,"1"); loc2.set(n,n,std::to_string(n)); VectorLocation l1(n+1); VectorLocation l2; VectorLocation sol; sol.append(loc0); for (int i = 0; i <= n; i++) { l1._locations[i].set(i*(n+1),i*(n+1),std::to_string(i)); } l2 = l1.select(loc0,loc2);l2.inspectT().c_str()```|
| | | | should give ```"1 0.000000 0.000000 0 "```|
| 87 | T02_Intermediate.VectorLocation_select_4 |  PASSED |```int sizeOriginal = 5; Location loc0; Location loc1; Location loc2; loc1.set(1,1,"1"); loc2.set(sizeOriginal,sizeOriginal,std::to_string(sizeOriginal)); VectorLocation l1(sizeOriginal); VectorLocation l2; VectorLocation sol; for (int i = 1; i <= sizeOriginal; i++) { l1._locations[i-1].set(i,i,std::to_string(i)); sol.append(l1._locations[i-1]); } l2 = l1.select(loc1,loc2);l2.inspectT().c_str()```|
| | | | should give ```"5 1.000000 1.000000 1 2.000000 2.000000 2 3.000000 3.000000 3 4.000000 4.000000 4 5.000000 5.000000 5 "```|
| 88 | T02_Intermediate.VectorLocation_sort_1_no_change |  PASSED |```int sizeOriginal = 3; Location loc; VectorLocation l1(sizeOriginal); VectorLocation sol; for (int i = 0; i < sizeOriginal; i++) { loc.setName(std::to_string(i)); l1.at(i) = loc; sol.append(loc); } l1.sort();sol.inspectT() == l1.inspectT();```|
| | | | should give ```true```|
| 89 | T02_Intermediate.VectorLocation_sort_2 |  PASSED |```int sizeOriginal = 3; Location loc; VectorLocation l1(sizeOriginal); VectorLocation sol; for (int i = 0; i < sizeOriginal; i++) { loc.setName(std::to_string(i)); l1.at(sizeOriginal-(i+1)) = loc; sol.append(loc); } l1.sort();sol.inspectT() == l1.inspectT();```|
| | | | should give ```true```|
| 90 | T02_Intermediate.VectorLocatioin_join_intersection_empy_0 |  PASSED |```int n = 5; VectorLocation l1(n); VectorLocation l2(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); l2._locations[i].set((i+1)*n,(i+1)*n,std::to_string((i+1)*n)); } l1.join(l2);l1.getSize()```|
| | | | should give ```10```|
| 91 | T02_Intermediate.VectorLocatioin_joinShouldRemainEqual_1 |  PASSED |```int n = 5; VectorLocation l1(n); VectorLocation l2(n); for (int i = 0; i < n; i++) { l1._locations[i].set(i,i,std::to_string(i)); l2._locations[i].set(i,i,std::to_string(i)); } l1.join(l2);l1.getSize()```|
| | | | should give ```5```|
| 92 | T02_Intermediate.VectorLocatioin_joinShouldRemainEqual_2 |  PASSED |```string ss = "1 " + string(LOCATION_OTHER)+" "; VectorLocation l1(1); VectorLocation l2(1); l1._locations[0].set(37.2, -3.6,"Granada"); l2._locations[0].set(37.2, -3.6,"Granada"); l1.join(l2);l1.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 93 | T02_Intermediate.VectorLocation_assign_01 |  PASSED |```int n=5; Location loc; loc.set(37.2, -3.6,"Granada"); VectorLocation sol(n); VectorLocation l2(n); for (int i = 0; i < 5; i++) { sol._locations[i]= loc; } l2.assign(loc);l2.inspectT();```|
| | | | should give ```"5 37.200000 -3.600000 Granada 37.200000 -3.600000 Granada 37.200000 -3.600000 Granada 37.200000 -3.600000 Granada 37.200000 -3.600000 Granada "```|
| 94 | T02_Intermediate.VectorLocation_assign_02 |  PASSED |```int n=5; Location loc0; Location loc1; loc1.set(37.2, -3.6,"Granada"); VectorLocation sol(n); VectorLocation l2(n); for (int i = 0; i < 5; i++) { l2._locations[i]= loc1; } l2.assign(loc0);l2.inspectT();```|
| | | | should give ```"5 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 "```|
| 95 | T02_Intermediate.VectorLocation_loadLoad_2 |  PASSED |```int n=1; VectorLocation l1(n); string ss = std::string("1 ") + string(LOCATION_OTHER)+ " "; istringstream ssin(ss); l1.load(ssin); l1.load(ssin);l1.inspectT().c_str()```|
| | | | should give ```"1 37.200000 -3.600000 Granada "```|
| 96 | T02_Intermediate.VectorLocation_Load_3_exception |  PASSED |```int n=1; VectorLocation l1(n); double d1; double d2; string name; string ss = std::string("-1 ") + string(LOCATION_OTHER)+ " "; std::string sin=ss; istringstream ssin(sin);l1.load(ssin);```|
| | | | should THROW an exception std::out_of_range|
| 97 | T02_Intermediate.VectorLocation_Load_4_exception |  PASSED |```int n=1; VectorLocation l1(n); std::string sin= std::to_string(VectorLocation::DIM_VECTOR_LOCATIONS+1); istringstream ssin(sin);l1.load(ssin);```|
| | | | should THROW an exception std::out_of_range|
| 98 | T02_Intermediate.VectorInt_VectorInt_def3 |  PASSED |```VectorInt v(VectorInt::DIM_VECTOR_VALUES+1)```|
| | | | should THROW an exception std::out_of_range|
| 99 | T02_Intermediate.VectorInt_append_2_full |  PASSED |```VectorInt v(VectorInt::DIM_VECTOR_VALUES)v.append(7)```|
| | | | should THROW an exception std::out_of_range|
| 100 | T02_Intermediate.VectorInt_VectorInt_def2 |  PASSED |```VectorInt v(5);std::regex_replace(v.inspectT(), std::regex(ENDL), " ")```|
| | | | should give ```"5 0 0 0 0 0 "```|
| 101 | T02_Intermediate.VectorInt_at_exception0 |  PASSED |```VectorInt v(2);v.at(-1)```|
| | | | should THROW an exception std::out_of_range|
| 102 | T02_Intermediate.VectorInt_at_exception1 |  PASSED |```VectorInt v(2);v.at(2)```|
| | | | should THROW an exception std::out_of_range|
| 103 | T02_Intermediate.VectorInt_distance_fail1 |  PASSED |```VectorInt v1(3); VectorInt v2(5);v1.distance(v2)```|
| | | | should THROW an exception std::invalid_argument|
| 104 | T02_Intermediate.VectorInt__distance_fail2 |  PASSED |```VectorInt v1; VectorInt v2;v1.distance(v2)```|
| | | | should THROW an exception std::invalid_argument|
| 105 | T02_Intermediate.VectorInt_countIdenticalElements2_excep |  PASSED |```VectorInt v1(3); VectorInt v2(2);v1.countIdenticalElements(v2)```|
| | | | should THROW an exception std::invalid_argument|
| 106 | T02_Intermediate.Clustering_run_0 |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations,2,12345); clt.run(); string ss="K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 Cluster number for each location: 3 0 1 1 Centroids: 2 0.000000 0.000000 1.500000 1.500000 Cluster 0 information: 0 0.000000 0.000000 Location0 Cluster 1 information: 1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 ";std::regex_replace(clt.inspectT(), std::regex(ENDL), " ")```|
| | | | should give ```"K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 Cluster number for each location: 3 0 1 1 Centroids: 2 0.000000 0.000000 1.500000 1.500000 Cluster 0 information: 0 0.000000 0.000000 Location0 Cluster 1 information: 1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 "```|
| 107 | T02_Intermediate.Clustering_clusterOf_AfterRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();```|
| | | | should give ```"K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 Cluster number for each location: 3 0 1 1 Centroids: 2 0.000000 0.000000 1.500000 1.500000 Cluster 0 information: 0 0.000000 0.000000 Location0 Cluster 1 information: 1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 "```|
| 107 | T02_Intermediate.Clustering_clusterOf_AfterRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();```|
| | | | should give ```"K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 Cluster number for each location: 3 0 1 1 Centroids: 2 0.000000 0.000000 1.500000 1.500000 Cluster 0 information: 0 0.000000 0.000000 Location0 Cluster 1 information: 1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 "```|
| 107 | T02_Intermediate.Clustering_clusterOf_AfterRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();```|
| | | | should give ```"K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 Cluster number for each location: 3 0 1 1 Centroids: 2 0.000000 0.000000 1.500000 1.500000 Cluster 0 information: 0 0.000000 0.000000 Location0 Cluster 1 information: 1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 "```|
| 108 | T02_Intermediate.Clustering_getSumWCV_AfterRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();clt.getSumWCV()```|
| | | | should give ```1.000000```|
| 109 | T02_Intermediate.Clustering_getNumIterations_AfterRun |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();clt.getNumIterations()```|
| | | | should give ```2```|
| 110 | T02_Intermediate.Clustering_clusterInfo1 |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations,2, 12345); clt.run();std::regex_replace(clt.clusterInfo(1), std::regex(ENDL), " ")```|
| | | | should give ```"1 1.000000 1.000000 Location1 2 2.000000 2.000000 Location2 "```|
| 111 | T02_Intermediate.Clustering_getStatistics |  PASSED |```VectorLocation locations; fill_vlocation(locations,3); Clustering clt; clt.set(locations, 2, 12345); clt.run();std::regex_replace(clt.getStatistics(), std::regex(ENDL), " ")```|
| | | | should give ```"K=2 Sum of within-cluster variances: 1.000000 Number of iterations: 2 "```|
| 112| T03_Advanced.Integration_test01-valgrind | PASSED | NO LEAKS |
| 112 | T03_Advanced.Integration_test01 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_K4L3.p1in]: Test for K=3 less location than number of clusters|
| 113| T03_Advanced.Integration_test02-valgrind | PASSED | NO LEAKS |
| 113 | T03_Advanced.Integration_test02 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_K4L3.p1in]: Test for K=3 less location than number of clusters|
| 114| T03_Advanced.Integration_test03-valgrind | PASSED | NO LEAKS |
| 114 | T03_Advanced.Integration_test03 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_K3L0.p1in]: Test for K=3 with empty location|
| 115| T03_Advanced.Integration_test04-valgrind | PASSED | NO LEAKS |
| 115 | T03_Advanced.Integration_test04 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_K1.p1in]: Test for K=1 all the locations belong to the same cluster|
| 116| T03_Advanced.Integration_test05-valgrind | PASSED | NO LEAKS |
| 116 | T03_Advanced.Integration_test05 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_5locationsK2.p1in]: Test with 5 chosen locations using K=2 clusters|
| 117| T03_Advanced.Integration_test06-valgrind | PASSED | NO LEAKS |
| 117 | T03_Advanced.Integration_test06 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_5locationsK3.p1in]: Test with 5 chosen locations (the same as previously) using K=3 clusters|
| 118| T03_Advanced.Integration_test07-valgrind | PASSED | NO LEAKS |
| 118 | T03_Advanced.Integration_test07 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton_5locationsK5.p1in]: Test with 5 chosen locations (the same as previously) using K=5 clusters|
| 119| T03_Advanced.Integration_test08-valgrind | PASSED | NO LEAKS |
| 119 | T03_Advanced.Integration_test08 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/princeton.p1in]: Test to make clustering with K=5 with locations in princeton.p1in|
| 120| T03_Advanced.Integration_test09-valgrind | PASSED | NO LEAKS |
| 120 | T03_Advanced.Integration_test09 | PASSED | [Fraud1_TEMPLATE < ../Datasets/dataP1/simple_5Locations.p1in]: Test to make clustering with K=1 with simplified locations.|
