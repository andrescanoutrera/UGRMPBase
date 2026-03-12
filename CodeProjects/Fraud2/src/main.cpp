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
#include <string>
#include <fstream>

#include "VectorLocation.h"
#include "Clustering.h"
#include "ArrayClustering.h"

using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 * @param message Additional message to show with the help
 */
void showHelp(std::ostream& outputStream, const string &message) {
    outputStream << "ERROR in Fraud2 parameters. " << message << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "Fraud2 <K> <minSeed> <maxSeed> <inputFile.loc>" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "<K>: an integer with the number of clusters to use in the K-means algorithm" << endl;
    outputStream << "<minSeed>: an integer with the minimum seed value to use" << endl;
    outputStream << "<maxSeed>: an integer with the maximum seed value to use" << endl;
    outputStream << "<inputFile.loc>: name of the location file" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to read a set of locations from
 * a loc file and make different clustering processes of these locations, 
 * showing some statistics of the resulting clusterings on the standard output.
 * 
 * The program first reads the locations from a file whose name is provided as 
 * the last command line argument. It also reads from the command line an 
 * integer K to set the number of clusters to be used in the clustering
 * processes. It also reads from the command line two integers minSeed and 
 * maxSeed  to set a range of seeds to be used in the different clustering 
 * processes. 
 * The program performs different clustering processes using the K-means 
 * algorithm with seeds in the range from minSeed to maxSeed 
 * (both included). The resulting Clustering objects are stored in an 
 * ArrayClustering object, that represents a dynamic array of Clustering 
 * objects. At the end, the program sorts the different Clustering objects
 * stored in the ArrayClustering object in ascending order of the sum of 
 * within-cluster variances. If two Clustering objects have the same sum of
 * within-cluster variances, they are further sorted by their number of
 * iterations in ascending order.
 * Finally, the program shows some statistics about each of clustering stored
 * in the ArrayClustering object, including the value of K, the sum of the 
 * within-cluster variances, and the number of iterations used by the 
 * clustering algorithm until convergence.
 * 
 * Be careful to show the output as in the below example.
 *  
 * Running sintax:
 * > build/Fraud2 <K> <minSeed> <maxSeed> <inputFile.loc>
 * 
 * Running example:
 * > build/Fraud2 5 0 3 ../Datasets/dataP2/princeton_names.loc
Clustering 0:
K=5
Sum of within-cluster variances: 194.455556
Number of iterations: 3

Clustering 1:
K=5
Sum of within-cluster variances: 233.319889
Number of iterations: 3

Clustering 2:
K=5
Sum of within-cluster variances: 250.044571
Number of iterations: 3
 */
int main(int argc, char* argv[]) {
    ArrayClustering arrayClustering; // Object to store the different clusterings
    VectorLocation locations; // Object to store the input locations
    Clustering clustering; // Clustering object
    int K; // Number of clusters to use
    unsigned int minSeed, maxSeed; // Range of seeds
    ifstream inputFile; // Input file stream for the loc file

    // Check if the number of arguments is valid.

    // Read K from the command line arguments

    // Read the seed range from the command line arguments 
    // (use stoul to convert string to unsigned int)

    // Read from the input file the locations directly into the VectorLocation object

    // Initialize the arrayClustering object with an initial capacity of 2
    
    // For each seed in the given range, perform a clustering and store it in
    // arrayClustering


    // Sort the different Clustering objects stored in arrayClustering

    // Show statistics of each clustering in the sorted order

    // Deallocate the dynamic memory used by arrayClustering
    
    return 0;
}