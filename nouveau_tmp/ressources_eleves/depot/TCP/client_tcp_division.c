#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int traiter_commande_wrapper(argc, argv) {
	//if (traiter_commande(/*A COMPLETER*/ , argv[0], "<adresse IP> <port>\nmauvais nombre d'arguments")) return 1;
	//if (traiter_commande(/*A COMPLETER*/, argv[0], "<adresse IP> <port>\n<adresse IP> est une adresse IP au format décimal pointé")) return 1;
	//if (traiter_commande(/*A COMPLETER*/, argv[0], "<adresse IP> <port>\n<port> est un port non réservé")) return 1;
	
	return 0
}

int main(int argc, char** argv) {
	if (traiter_commande_wrapper(argc, argv)) exit(1)

	/*A COMPLETER*/

	exit(0);
}
