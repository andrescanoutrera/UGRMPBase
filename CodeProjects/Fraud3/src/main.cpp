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

#include "DataSet.h"
#include "Clustering.h"

using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 * @param message Additional message to show with the help
 */
void showHelp(std::ostream& outputStream, const string &message) {
    outputStream << "ERROR in Fraud3 parameters. " << message << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "Fraud3 [-K <K>] [-o <outputFile.dts>] <inputFile.dts>" << 
        endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-K <K>: an integer with the number of clusters to use " << 
        "(5 by default)" << endl;
    outputStream << "-o <outputFile.dts>: name of the output dataset file " << 
        "(tests/output/output.dts by default)" << endl;
    outputStream << "<inputFile.dts>: name of the input dataset file" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to read a dataset from a dts file, to reduce 
 * its dimensionality using clustering, and to save the resulting dataset in 
 * another dts file.
 * 
 * The number of clusters K to be used in the clustering process can be provided
 * as an optional argument (if not provided, K=5 is used). 
 * The name of the output dts file can be provided to the program as an optional
 * argument (if not provided, the output file is tests/output/output.dts). 
 * The name of the input dts file is passed as the last argument to the program.
 * See below the Running sintax.
 * 
 * The program begins by processing the command line arguments. Then, it loads 
 * the input dataset from the given dts file. After that, it performs a  
 * clustering of the locations in the dataset using the K-means algorithm with
 * the provided K value. Then, using the calculated clustering, it obtains a new 
 * dataset with reduced dimensionality. Finally, it saves the resulting dataset 
 * in the given output dts file.
 * 
 * Running sintax:
 * > build/Fraud3 [-K <K>] [-o <outputFile.dts>] <inputFile.dts>  
 * 
 * Running example:
 * > build/Fraud3 -K 5 -o /tmp/princeton_training_reduced.dts ../Datasets/princeton_training.dts
 */
int main(int argc, char* argv[]) {
    DataSet inputDataset, // Input dataset
        outputDataset; // Output dataset with reduced dimensionality

    // Name of the output file (tests/output/output.dts by default)
    string outputFileName="tests/output/output.dts";
    int K = 5; // Number of clusters (5 by default)
    Clustering clustering; // Clustering object

    // Indicates if all the parameters starting with - has been read
    bool hasBeenReadInitialParameters = false; 
    int indexInputFile = -1; // index of the input file in argv

    // Loop to process program arguments

    // Load the input dataset from the given file
    
    // Set the location vector and K in the clustering object. Use the default
    // seed value.

    // Run the clustering algorithm
    
    // Get the dataset with reduced dimensionality

    // Save the output dataset in the given file
    
    return 0;
}
