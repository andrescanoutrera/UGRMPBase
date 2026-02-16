#include <iostream>
/**
 * @brief Mi primer programa usando solo el IDE
 *
 * @param argc
 * @param argv
 * @return int 0 siempre
 */
using namespace std;
int main(int argc, char **argv)
{
    cout << "hola mumundoooo" << endl;
    cout << "no me lo incluye" << endl;
    cout << " medio ké" << endl;

    if (argc > 1)
        cout << argv[1] << endl;
    return 0;
}