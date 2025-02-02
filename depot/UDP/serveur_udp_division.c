#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>


int traiter_commande_wrapper(int argc, char** argv) {
	traiter_commande(argc!=2, argv[0], "<port>\nmauvais nombre d'arguments");
	traiter_commande(argv[1] <1024, argv[0], "<port>\n<port> est un port non réservé");
}

int main(int argc, char** argv) {
	traiter_commande_wrapper(argc,argv);
	creer_socket("127.0.0.1",argv[1]);

	exit(0);
}

=======
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    SOCK sock;
    init_addr(&sock);
    creer_socket("127.0.0.1", atoi(argv[1]), &sock);
    attacher_socket(&sock);
    char buffer[1024];
    float result = 0;
	int i = 0;
	float nombres[100];
    while (1) {
        recevoir_message(&sock, buffer);
        if (strcmp(buffer, "=") == 0) {

            break;
        }
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            nombres[i++] = atof(token);
            token = strtok(NULL, " ");
        }
        if (i > 0) {
            result = nombres[0];
            for (int j = 0; j < i; j++) {
                if (nombres[j] == 0) {
                    envoyer_message(&sock, "Message reçu -> N/A");
                    i = 0;  
                    break;
                }
                result /= nombres[j];
            }
            char result_str[1024];
            sprintf(result_str, "%.6f", result);
            envoyer_message(&sock, result_str);
            i = 0; 
			break;
        }
    }
    fermer_connexion(&sock);
}
>>>>>>> 6f32960 (cr??ation serveur et client udp)
