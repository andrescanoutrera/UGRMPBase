/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file Clustering.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 22 de octubre de 2025, 11:57
 */

 std::string Clustering::toString() const {
    string result = getStatistics();
    result += "Cluster number for each location:\n";
    result += _clusters.toString();
    result += "Centroids:\n";
    result += _centroids.toString();
    for(int i=0; i<_K; i++){
        result += "Cluster " + to_string(i) + " information:\n";
        result += clusterInfo(i);
    }

    return result;
}
