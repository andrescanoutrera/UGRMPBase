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

#include <cstring>
#include <string>

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
    outputStream << "ERROR in Fraud4 parameters. " << message << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "Fraud4 [-K1 <K1>] [-K2 <K2>] [-nr] " <<  
        "[-o <classifiedDataset.dts>] <trainingDataset.dts> <testClassify.dts>" << 
        endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-K1 <K1>: an integer with the number of clusters to " << 
        "use in the reduction dimensionality algorithm (5 by default)" << endl;
    outputStream << "-K2 <K2>: an integer with the number of neighbouring " << 
        "instances to use in the KNN algorithm (6 by default)" << endl;
    outputStream << "-nr: Indicates that dimensionality reduction " << 
        "should not be applied in the clustering algorithm " << 
        "(by default dimensionality reduction is done)" << endl;
    outputStream << "[-o <classifiedDataset.dts>]: name of the file where " <<
        "the classified dataset will be saved " << 
        "(tests/output/output.dts by default)" << endl;
    outputStream << "<trainingDataset.dts>: name of the dataset file used as " << 
        "model (training dataset)" << endl;
    outputStream << "<testClassify.dts>: name of the dataset file " << 
        "to be classified (test dataset)" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to read two DataSet objects from dts files, 
 * a training dataset and a test dataset, and to classify the instances in the
 * test dataset using the training dataset as model for the KNN algorithm.
 * 
 * The number of clusters K1 to be used in the reduction dimensionality process
 * can be provided as an optional command line argument (if not provided, 
 * K=5 is used). 
 * The number of neighbours K2 to be used in the KNN algorithm can be provided
 * as an optional command line argument (if not provided, K=6 is used).
 * The name of the output dts file (classified dataset) can be provided to 
 * the program as an optional command line argument (if not provided, the 
 * output file is tests/output/output.dts). 
 * Additionally, an optional argument can be provided to indicate that
 * dimensionality reduction should not be applied in the classification.
 * The name of the file with the training dataset is passed as the
 * penultimate command line argument.
 * The name of the file with the test dataset is passed as the last argument.
 * See below the Running sintax.
 * 
 * The program begins by processing the command line arguments. Then, it loads
 * the training and test datasets from the given dts files. After that, it 
 * classifies the instances in the test dataset using the KNN algorithm with the
 * provided K2 value and the training dataset as model. If indicated, before
 * classifying, the dimensionality of both datasets is reduced using clustering
 * with the provided K1 value. Finally, it saves the classified test dataset
 * in the given output dts file.
 * 
 * Running sintax:
 * > build/Fraud4 [-K1 <K1>] [-K2 <K2>] [-nr] [-o <classifiedTestDataset.dts>] 
 *                <trainingDataset.dts> <testDataset.dts>
 * 
 * Running example:
 * > build/Fraud4 -K1 2 -K2 6 -o /tmp/dataset.dts ../Datasets/princeton_training.dts 
 *                ../Datasets/princeton_test.dts
 */
int main(int argc, char* argv[]) {
    DataSet trainingDataset, // Dataset used as model to classify
        testDataset;    // Dataset to be classified

    // Name of the output file (tests/output/output.dts by default)
    string outputFileName="tests/output/output.dts";
    int K1 = 5, // Number of clusters for dimensionality reduction
        K2 = 6; // Number of nearest neighbours for KNN
    bool doReduction = true; // Indicates whether or not to do reduction dimensionality

    // Indicates if all the parameters starting with - has been read
    bool hasBeenReadInitialParameters = false; 
    int indexInputFile = -1; // index of the input file in argv

    // Loop to process program arguments

    // Load training and test datasets

    // Classify the test dataset

    // Save the classified test dataset in the given output file

    return 0;
}