#include "erreur.h"
#include "tcp.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Créer une socket */
int creer_socket(char* adresseIP, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        traiter_erreur(__FUNCTION__);
        return -1;
    }
    return sock;
}

/* Connecter une socket */
void connecter_socket(int sock) {
    struct sockaddr_in adresse;
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(0); // Utiliser un port par défaut ou un autre mécanisme pour définir le port
    adresse.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr*)&adresse, sizeof(adresse)) == -1) {
        traiter_erreur(__FUNCTION__);
        close(sock);
    }
}

/* Attacher une socket */
void attacher_socket(int sock, int port) {
    struct sockaddr_in adresse;
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(port);
    adresse.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&adresse, sizeof(adresse)) == -1) {
        traiter_erreur(__FUNCTION__);
        close(sock);
    }
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int sock) {
    if (listen(sock, 5) == -1) { // Utiliser une taille par défaut pour la file d'attente
        traiter_erreur(__FUNCTION__);
        close(sock);
    }
}

/* Initialiser la structure adresse client */
void init_addr_client(struct sockaddr_in* adresse, char* adresseIP, int port) {
    adresse->sin_family = AF_INET;
    adresse->sin_port = htons(port);
    adresse->sin_addr.s_addr = inet_addr(adresseIP);
}

/* Attendre une connexion */
int attendre_connexion(int sock) {
    struct sockaddr_in adresse_client;
    socklen_t longueur_adresse = sizeof(adresse_client);
    int socktraitement = accept(sock, (struct sockaddr*)&adresse_client, &longueur_adresse);
    if (socktraitement == -1) {
        traiter_erreur(__FUNCTION__);
    }
    return socktraitement;
}

/* Recevoir un message */
void recevoir_message(int socktraitement, char* buffer) {
    int verif = recv(socktraitement, buffer, 1024, 0);
    if (verif == -1) {
        traiter_erreur(__FUNCTION__);
    }
}

/* Émettre un message */
void envoyer_message(int socktraitement, char* message) {
    int verif = send(socktraitement, message, strlen(message), 0);
    if (verif == -1) {
        traiter_erreur(__FUNCTION__);
    }
}

/* Fermer la connexion */
void fermer_connexion(int socktraitement) {
    close(socktraitement);
    traiter_erreur(__FUNCTION__);
}
