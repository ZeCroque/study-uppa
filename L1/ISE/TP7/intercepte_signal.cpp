// Programme intercepte_signal
 #include <iostream>
 #include <cstdlib>
 #include <csignal>
 #include <unistd.h>

 void traiteSignal( int signum )
 {
    std::cout << " Signal (" << signum << ") intercepté !" << std::endl;
    exit(signum);
 }

 int main ()
 {
    // appeler traiteSignal quand le programme reçoit :
    signal(SIGINT, traiteSignal);  // le signal SIGINT (kill -2 ou ctrl-c)
    signal(SIGBUS, traiteSignal);  // le signal SIGBUS (kill -7)

    while(true){  // boucle sans fin qui peut toutefois être interrompue par un signal
        std::cout << "Dormir 2 secondes..." << std::endl;
        sleep(2);
    }
    return 0; // code de retour si les signaux ne sont ni 2, ni 7
 }
