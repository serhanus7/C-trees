#include<stdio.h>
#include<stdlib.h>
#include "serhan.h"

void inserer (pnd* tree, int val){
        
        
        if((*tree)==NULL) {
                       nd* nv;
                       nv=(nd*)malloc(sizeof(nd));
                       nv->info=val;
                       nv->g=nv->d=NULL;
                       *tree=nv;
                       }
        else{
             if(val>(*tree)->info) 
             inserer(&((*tree)->d),val);
             else
             inserer(&((*tree)->g),val);
             }
}
/*****************afficher*****************/
void afficher(pnd root,int niv){
     if(root!=NULL){
                    int i;
                    for(i=1;i<=niv;i++) printf("%5s"," ");
                    printf("%i\n",root->info);
                    afficher(root->d,niv+1);
                    afficher(root->g,niv+1);
                    }
     }
/******************RECHERCHE***************/
pnd rechercher(pnd p,int val){
    if(p!=NULL)
    {
        if(val==p->info) return p; 
        else {
             if(val>p->info)return rechercher(p->d,val);
             if(val<p->info)return rechercher(p->g,val);     
             }
    }
    return NULL;
} 
/******************taille*********************/
int taille(pnd p){
    if(p!=NULL) return 1+taille(p->g)+taille(p->d);
    else return 0; 
    }
/********************repetition*********************/
int repetition(pnd p,int x){
    if(rechercher(p,x)!=NULL){
                          if(p->info==x) return 1+repetition(p->g,x)+repetition(p->d,x);
                          else return repetition(p->g,x)+repetition(p->d,x);
                          }
    else return 0;
    }
/*********************feuille**********************/
int feuille(pnd p)
{if(p!=NULL)
            {if(p->g=NULL
    
    }
/******************************************/
int main(){
int i;
pnd arbre=NULL;

inserer(&arbre,10);
inserer(&arbre,8);
inserer(&arbre,15);
inserer(&arbre,6);
inserer(&arbre,9);
inserer(&arbre,11);
inserer(&arbre,16);
inserer(&arbre,5);
inserer(&arbre,7);
inserer(&arbre,6);
inserer(&arbre,4);
inserer(&arbre,10);

afficher(arbre,0);
//rechercher(arbre,15);
i=taille(arbre);
printf("la taille de l'arbre est %i\n",i);
printf("10 est repete %i fois\n",repetition(arbre,10));
afficher(rechercher(arbre,15),0);

system("pause");
return 0;       
}
