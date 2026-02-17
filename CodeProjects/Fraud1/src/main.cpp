/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 24 de octubre de 2025, 9:27
 */

#include <iostream>

#include "VectorLocation.h" 
#include "Clustering.h"

using namespace std;

/**
 * The purpose of this program is to read a set of locations from
 * standard input, to cluster them into K clusters using the K-means
 * algorithm, and to show the resulting clustering on the standard output.
 * 
 * This program first reads an integer K from standard input, which indicates
 * the number of clusters to be used in the clustering process. Then, it reads
 * a set of Location objects from standard input. After reading the data, it
 * performs the K-means clustering algorithm to group the locations into K
 * clusters. Finally, it displays the resulting clustering information,
 * including the cluster assignments for each location and the centroids of
 * each cluster.
 * 
 * Be careful to show the output as in the below example.
 * 
 * An example of data read from standard input is the following (see file
 * Datasets/dataP1/princeton.p1in):
5
21
3.3 9.1 Graduate College
11.8 6.9 Wawa Public Restrooms
12.6 7.3 Princeton Station
10.1 9.7 Forbes College
13.3 12.2 Dinky Bar & Kitchen
15.2 11.2 Whitman College
12.6 17.5 Admission Information Center
12.5 20 Rockefeller College
13.7 22.8 Art Museum Store
17 23.3 Princeton University Store
18.6 22.8 Labyrinth Books
20.9 15.4 Frist Campus Center
23.7 14.8 Cannon Dial Elm
24.8 14.9 Quadrangle
25.6 14.9 Ivy
26.4 14.9 Cottage
27.3 14.5 Cap & Gown
28.2 15 Cloister
29.1 15.2 Charter
28.8 18.7 Engineering Quadrangle
18.5 6.7 Yeh College
 * 
 * Running sintax:
 * > build/Fraud1 < <inputFile.p1in> 
 * 
 * Running example:
 * > build/Fraud1 < ../Datasets/dataP1/princeton.p1in
K=5
Sum of within-cluster variances: 161.136889
Number of iterations: 5
Cluster number for each location:
21
0 2 2 2 2 2 1 1 1 1 1 4 4 4 4 4 4 4 4 4 3
Centroids:
5
3.300000 9.100000 
14.880000 21.280000 
12.600000 9.460000 
18.500000 6.700000 
26.088889 15.366667 
Cluster 0 information:
0 3.300000 9.100000 Graduate College
Cluster 1 information:
6 12.600000 17.500000 Admission Information Center
7 12.500000 20.000000 Rockefeller College
8 13.700000 22.800000 Art Museum Store
9 17.000000 23.300000 Princeton University Store
10 18.600000 22.800000 Labyrinth Books
Cluster 2 information:
1 11.800000 6.900000 Wawa Public Restrooms
2 12.600000 7.300000 Princeton Station
3 10.100000 9.700000 Forbes College
4 13.300000 12.200000 Dinky Bar & Kitchen
5 15.200000 11.200000 Whitman College
Cluster 3 information:
20 18.500000 6.700000 Yeh College
Cluster 4 information:
11 20.900000 15.400000 Frist Campus Center
12 23.700000 14.800000 Cannon Dial Elm
13 24.800000 14.900000 Quadrangle
14 25.600000 14.900000 Ivy
15 26.400000 14.900000 Cottage
16 27.300000 14.500000 Cap & Gown
17 28.200000 15.000000 Cloister
18 29.100000 15.200000 Charter
19 28.800000 18.700000 Engineering Quadrangle
 */
int main(int argc, char* argv[]) {
    VectorLocation locations; // VectorLocation object to store the input locations
    Clustering clustering; // Clustering object
    int K; // number of clusters

    // Read de number of clusters

    // Read the locations directly into the VectorLocation object
    
    // Define the parameters of the clustering object

    // Execute the clustering algorithm
    
    // Show the resulting clustering in the standard output
    
    return 0;
}