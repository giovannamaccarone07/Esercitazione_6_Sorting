#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <unistd.h>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"
#include "Eigen/Eigen"
#include <iomanip>

using namespace std;
using namespace chrono;
using namespace SortLibrary;
using namespace Eigen;


//Creo la funzione che genera un vettore di componenti casuali
vector<int> vettoreRandom(unsigned int& dim)
{
    unsigned int n = 0;
    vector<int> vettoreRandom(dim);
    generate(vettoreRandom.begin(), vettoreRandom.end(), [&n] () {return n++;});

    for(unsigned int i=0; i < dim; i++){
        vettoreRandom[i] = rand() % 100;
    }
    return vettoreRandom;
}


int main()
{
    //TEST1: Vettore disordinato di dimensione piccola.
    //Chiedo in input all'utente la dimensione:
    unsigned int dimensione1;
    cout << "Inserire una dimensione abbastanza piccola: " << endl;
    cin >> dimensione1;

    //BUBBLE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoBS_1 = 0;
    double mediaBS_1 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore:
        vector<int> vettore1_BS = vettoreRandom(dimensione1);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_BS = steady_clock::now();
        BubbleSort(vettore1_BS);
        steady_clock::time_point t_end_BS = steady_clock::now();
        double intervalloTempoBS_1 = duration_cast<microseconds>(t_end_BS-t_begin_BS).count();
        tempoBS_1 = tempoBS_1 + intervalloTempoBS_1;
    }
    //Calcolo la media:
    mediaBS_1 = tempoBS_1/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento BubbleSort per un vettore di dimensione piccola è: " << fixed << setprecision(2) << mediaBS_1 << " microsecondi" << endl;


    //MERGE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoMS_1 = 0;
    double mediaMS_1 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore:
        vector<int> vettore1_MS = vettoreRandom(dimensione1);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_MS = steady_clock::now();
        MergeSort(vettore1_MS);
        steady_clock::time_point t_end_MS = steady_clock::now();
        double intervalloTempoMS_1 = duration_cast<microseconds>(t_end_MS-t_begin_MS).count();
        tempoMS_1 = tempoMS_1 + intervalloTempoMS_1;
    }
    //Calcolo la media:
    mediaMS_1 = tempoMS_1/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento MergeSort per un vettore di dimensione piccola è: " << fixed << setprecision(2) << mediaMS_1 << " microsecondi" << endl;

    if(mediaBS_1<mediaMS_1){
        cout << "Per un vettore disordinato di dimensione piccola, l'algoritmo di ordinamento più veloce è Bubble Sort." << endl << endl;
    }
    else{
        cerr << "Errore: per un vettore di dimensione piccola dovrebbe essere più veloce Bubble Sort." << endl << endl;;
    }


    //TEST2: Vettore disordinato di dimensione grande.
    //Chiedo in input all'utente la dimensione:
    unsigned int dimensione2;
    cout << "Inserire una dimensione abbastanza grande: " << endl;
    cin >> dimensione2;

    //BUBBLE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoBS_2 = 0;
    double mediaBS_2 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore
        vector<int> vettore2_BS = vettoreRandom(dimensione2);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_BS = steady_clock::now();
        BubbleSort(vettore2_BS);
        steady_clock::time_point t_end_BS = steady_clock::now();

        double intervalloTempoBS_2 = duration_cast<microseconds>(t_end_BS-t_begin_BS).count();
        tempoBS_2 = tempoBS_2 + intervalloTempoBS_2;
    }
    //Calcolo la media:
    mediaBS_2 = tempoBS_2/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento BubbleSort per un vettore di dimensione grande è: " << fixed << setprecision(2) << mediaBS_2 << " microsecondi" << endl;

    //MERGE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoMS_2 = 0;
    double mediaMS_2 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore:
        vector<int> vettore2_MS = vettoreRandom(dimensione2);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_MS = steady_clock::now();
        MergeSort(vettore2_MS);
        steady_clock::time_point t_end_MS = steady_clock::now();
        double intervalloTempoMS_2 = duration_cast<microseconds>(t_end_MS-t_begin_MS).count();
        tempoMS_2 = tempoMS_2 + intervalloTempoMS_2;
    }
    //Calcolo la media:
    mediaMS_2 = tempoMS_2/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento MergeSort per un vettore di dimensione grande è: " << fixed << setprecision(2) << mediaMS_2 << " microsecondi" << endl;
    if(mediaBS_2>mediaMS_2){
        cout << "Per un vettore disordinato di dimensione grande, l'algoritmo di ordinamento più veloce è Merge Sort." << endl << endl;
    }
    else{
        cerr << "Errore: per un vettore di dimensione grande dovrebbe essere più veloce Bubble Sort." << endl << endl;
    }

    //TEST: Vettore ordinato.
    //Chiedo in input all'utente la dimensione:
    unsigned int dimensione3;
    cout << "Inserire una dimensione generica: " << endl;
    cin >> dimensione3;

    //BUBBLE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoBS_3 = 0;
    double mediaBS_3 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore e lo ordino immediatamente così da lavorare con un vettore ordinato:
        vector<int> vettore3_BS = vettoreRandom(dimensione3);
        BubbleSort(vettore3_BS);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_BS = steady_clock::now();
        BubbleSort(vettore3_BS);
        steady_clock::time_point t_end_BS = steady_clock::now();
        double intervalloTempoBS_3 = duration_cast<microseconds>(t_end_BS-t_begin_BS).count();
        tempoBS_3 = tempoBS_3 + intervalloTempoBS_3;
    }
    //Calcolo la media:
    mediaBS_3 = tempoBS_3/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento BubbleSort per un vettore ordinato è: " << fixed << setprecision(2) << mediaBS_3 << " microsecondi" << endl;

    //BUBBLE_SORT
    //Inizializzo le variabili associate alle tempistiche:
    double tempoMS_3 = 0;
    double mediaMS_3 = 0;
    for(unsigned int i=0; i< 100; i++){
        //Inizializzo il vettore e lo ordino immediatamente così da lavorare con un vettore ordinato:
        vector<int> vettore3_MS = vettoreRandom(dimensione3);
        MergeSort(vettore3_MS);
        //Misuro l'intervallo di tempo per l'ordinamento:
        steady_clock::time_point t_begin_MS = steady_clock::now();
        MergeSort(vettore3_MS);
        steady_clock::time_point t_end_MS = steady_clock::now();
        double intervalloTempoMS_3 = duration_cast<microseconds>(t_end_MS-t_begin_MS).count();
        tempoMS_3 = tempoMS_3 + intervalloTempoMS_3;
    }
    //Calcolo la media:
    mediaMS_3 = tempoMS_3/100;
    cout << "La media dei tempi dell'algoritmo di ordinamento MergeSort per un vettore ordinato è: " << fixed << setprecision(2) << mediaMS_3 << " microsecondi" << endl;

    return 0;
}

