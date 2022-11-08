
#include "graphe.h"
#include "fifo.h"



/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num)
{

    printf(" sommet %d :\n",num);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }

}

// Ajouter l'arete entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2)
{
    if(sommet[s1]->arc==NULL)
    {
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else
    {
        pArc temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// creer le graphe
Graphe* CreerGraphe(int ordre)
{
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));


    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->arc=NULL;
        Newgraphe->pSommet[i]->couleur = 0;
    }
    return Newgraphe;
}



Graphe * lire_graphe(char * nomFichier)
{
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    graphe=CreerGraphe(ordre); // creer le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);
    fscanf(ifs,"%d",&orientation);

    graphe->orientation=orientation;
    graphe->ordre=ordre;

    // creer les aretes du graphe
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);
    }

    return graphe;
}

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe)
{
    printf("graphe\n");

    if(graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n",graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

//fonction donnee a titre d'exemple d'utilisation de file
File exemple_remplir_file()
{
    //initialisation
    File file = fileVide();
    //on remplit avec les entiers de 1 à 10
    int i;
    printf("Etat de la file : ");
    afficherFile(file);
    for(i=1; i<10; i++)
    {
        enfiler(file, i);
        printf("Etat de la file : ");
        afficherFile(file);
    }
    return file;
}

//fonction donnee a titre d'exemple d'utilisation de file
void exemple_vider_file(File file)
{
    //tant que la file n'est pas vide, on défile
    while(!fileEstVide(file))
    {
        int element = defiler(file);
        printf("element defile : %d\n", element);
        printf("Etat de la file : ");
        afficherFile(file);
    }
}


void demanderSommet(typage* element){
    printf("A partir de quelle sommet souhaitez commencez?\n");
    scanf("%d", element);
}


void BFS(Graphe G)
{
    //initialisation
    File file = fileVide();
    Cellule cellule;
    typage element;
    //Au depart les sommet sont non marqué et n'ont pas de predecesseur

    for(int i=0;i<G.ordre;i++) {
        G.pSommet[i]->couleur=0;
    }

    //Tableau dynamique des predecesseur de chaque sommet
    int *preds=(int*)malloc(G.ordre*sizeof(int));
    for(int i=0;i<G.ordre;i++) {
        preds[i]=-1;
    }

    //On demande a partir de quelle sommet commencer la recherche
    demanderSommet(&element);

    //On enfile la premiere cellule et on la marque
    enfiler(file,element);
    G.pSommet[element]->couleur=1;


    while (!fileEstVide(file)){
        int num=defiler(file);
        struct Arc* temp=G.pSommet[num]->arc;
        while(temp!=NULL){
            //on récupère le numéro du sommet vers lequel conduit l'arc
            int num2=temp->sommet;
            //si ce sommet n'est pas marqué alors on le marque comme ca lorsqu'il sera decouvert a nouveau on aura pas besoin de le marque
            if(G.pSommet[num2]->couleur==0){
                //On l'enfile
                enfiler(file,num2);
                //Ensuite on marque
                G.pSommet[num2]->couleur=1;
                //Et enfin ici on nomme son predecesseur
                preds[num2]=num;
            }
            temp=temp->arc_suivant;
        }
    }
    printf("Parcours BFS a partir du sommet %d :\n",element);
    for (int i = 0; i < G.ordre; ++i) {
        if (preds[i] != -1){
            printf("%d <-- %d ",i, preds[i]);
            if (preds[preds[i]] != -1){
                printf(" <-- %d ", preds[preds[i]]);
                if (preds[preds[preds[i]]] != -1){
                    printf(" <-- %d ", preds[preds[preds[i]]]);

                }
            }
            printf("\n");
        }
    }
}


void DFS(Graphe G,const typage* sommet,int *preds) {


    File file = fileVide();
    Cellule cellule;
    typage element;
    int date = 0;

    enfiler(file,*sommet);
    G.pSommet[*sommet]->couleur=2;


    int num = defiler(file);
    struct Arc* temp=G.pSommet[num]->arc;
    while(temp!=NULL){
        //on récupère le numéro du sommet vers lequel conduit l'arc
        int num2=temp->sommet;
        //si ce sommet n'est pas marqué alors on le marque comme ca lorsqu'il sera decouvert a nouveau on aura pas besoin de le marque
        if(G.pSommet[num2]->couleur==0){
            //Ensuite on marque le sommet
            G.pSommet[num2]->couleur=1;
            //Et enfin ici on nomme son predecesseur
            preds[num2]=num;
            //appel recursif de la fct DFS
            DFS(G,&num2,preds);
        }
        temp=temp->arc_suivant;
    }
}


void init(Graphe G,int *preds,const typage* sommet){

    //Initialisation

    for(int i=0;i<G.ordre;i++) {
        G.pSommet[i]->couleur=0;
    }

    preds=(int*)malloc(G.ordre*sizeof(int));
    for(int i=0;i<G.ordre;i++) {
        preds[i]=-1;
    }

    //appel de la fct DFS
    DFS(G,sommet,preds);

    //affichage des predecesseurs de chaque sommet
    printf("Parcours DFS a partir du sommet %d :\n", *sommet);
    for (int i = 0; i < G.ordre; ++i) {
        if (preds[i] != -1) {
            printf("%d <-- %d ", i, preds[i]);
            if (preds[preds[i]] != -1) {
                printf(" <-- %d ", preds[preds[i]]);
                if (preds[preds[preds[i]]] != -1) {
                    printf(" <-- %d ", preds[preds[preds[i]]]);

                }
            }
            printf("\n");
        }
    }

}
