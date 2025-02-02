#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
	//traiter_commande(/*A COMPLETER*/, argv[0], "<adresse IP> <port>\nmauvais nombre d'arguments");
	//traiter_commande(/*A COMPLETER*/, argv[0], "<adresse IP> <port>\n<adresse IP> est une adresse IP au format décimal pointé");
	//traiter_commande(/*A COMPLETER*/, argv[0], "<adresse IP> <port>\n<port> est un port non réservé");

	/*A COMPLETER*/

	exit(0);
=======
#include <netinet/in.h>

int traiter_commande_wrapper(int argc, char** argv) {
    traiter_commande(argc != 3, argv[0], "<adresse IP> <port>\nmauvais nombre d'arguments");
    traiter_commande(est_une_adresse_IP(argv[1]) == 0, argv[0], "<adresse IP> <port>\n<adresse IP> est une adresse IP au format décimal pointé");
    traiter_commande(atoi(argv[2]) < 1024, argv[0], "<adresse IP> <port>\n<port> est un port non réservé");
}

int main(int argc, char** argv) {
    traiter_commande_wrapper(argc, argv);
    
    SOCK sock;
    init_addr(&sock);
    creer_socket(argv[1], atoi(argv[2]), &sock);
    
    char message[1024];
    
    while (1) {
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';        
        if (strcmp(message, "=") == 0) {
            break;
        }
        if (est_un_nombre(message) == 0) {
            break;
        }

        envoyer_message(&sock, message); 
    }
    recevoir_message(&sock, message);
    printf("Message reçu -> %s\n", message);
    fermer_connexion(&sock);
    return 0;
>>>>>>> 6f32960 (cr??ation serveur et client udp)
}
