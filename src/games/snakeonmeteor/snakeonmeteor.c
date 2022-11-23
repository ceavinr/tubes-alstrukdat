#include "snakeonmeteor.h"

void Move (List *L, char input){
    address P=Last(*L);
    POINT temp;
            if (input=='w'){
                temp=(*Prev(P)).Pos;
                while (Prev(P)!=Nil){
                    (*P).Pos=temp;
                    P=Prev(P);
                    if (Prev(P)!=Nil){
                        temp=(*Prev(P)).Pos;
                    }
                }
            }else if(input=='s'){
                temp=(*Prev(P)).Pos;
                while (Prev(P)!=Nil){
                    (*P).Pos=temp;
                    P=Prev(P);
                    if (Prev(P)!=Nil){
                        temp=(*Prev(P)).Pos;
                    }
                }
            }else if(input=='d'){
                temp=(*Prev(P)).Pos;
                while (Prev(P)!=Nil){
                    (*P).Pos=temp;
                    P=Prev(P);
                    if (Prev(P)!=Nil){
                        temp=(*Prev(P)).Pos;
                    }
                }
            }else if(input=='a'){
                temp=(*Prev(P)).Pos;
                while (Prev(P)!=Nil){
                    (*P).Pos=temp;
                    P=Prev(P);
                    if (Prev(P)!=Nil){
                        temp=(*Prev(P)).Pos;
                    }
                }
            }
            moveHead(L,input); 
}  


void createSnake(List *L){
    CreateEmpty(L);
    address P1=Alokasi(72);
    address P2=Alokasi(1);
    address P3=Alokasi(2);
    srand(time(NULL));
    (*P1).Pos.X=rand()%5;
    (*P1).Pos.Y=rand()%5;
    if (P1->Pos.X==0){
        if (P1->Pos.Y==0){
            P2->Pos.X=P1->Pos.X;
            P3->Pos.X=P1->Pos.X;
            P2->Pos.Y=P1->Pos.Y+1;
            P3->Pos.Y=P1->Pos.Y+2;
        }else{
            P2->Pos.X=P1->Pos.X;
            P3->Pos.X=P1->Pos.X;
            if (P1->Pos.Y==1){
                P2->Pos.Y=P1->Pos.Y+1;
                P3->Pos.Y=P1->Pos.Y+2;
            }else{
                P2->Pos.Y=P1->Pos.Y-1;
                P3->Pos.Y=P1->Pos.Y-2;
            }
        }
    }else{
        if(P1->Pos.Y==0){
            if(P1->Pos.X==1){
                P2->Pos.X=P1->Pos.X-1;
                P3->Pos.X=P1->Pos.X-1;
                P2->Pos.Y=P1->Pos.Y;
                P3->Pos.Y=P1->Pos.Y+1;
            }else{
                P2->Pos.X=P1->Pos.X-1;
                P3->Pos.X=P1->Pos.X-2;
                P2->Pos.Y=P1->Pos.Y;
                P3->Pos.Y=P1->Pos.Y;
            }
        }else{
            P2->Pos.X=P1->Pos.X-1;
            P2->Pos.Y=P1->Pos.Y;
            if (P2->Pos.X==0){
                P3->Pos.X=P2->Pos.X;
                P3->Pos.Y=P2->Pos.Y-1;
            }else{
                P3->Pos.X=P2->Pos.X-1;
                P3->Pos.Y=P2->Pos.Y;
            }
        }
    }
    InsertLast(L,P1);
    InsertLast(L,P2);
    InsertLast(L,P3);
}

void printPoint(POINT P){

    printf("<%d,%d>\n",P.X,P.Y);
}

void printMap(List L,POINT food, POINT meteor,POINT obstacle){
    
    int i ;
    int j;
    for (i=0;i<11;i++){
        for ( j=0;j<11;j++){
            
            if (i%2==0 && j%2==0){
                printf("+");
            }else if (i%2==0){
                printf("---");
            }else if(j%2==0){
                printf("|");
            }else if(meteor.X==((j+1)/2)-1 && meteor.Y==((i+1)/2)-1){
                printf(" M ");
            }else if(obstacle.X==((j+1)/2)-1 && obstacle.Y==((i+1)/2)-1){
                printf(" # ");
            }else if(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1)){
                if (Info(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1))==72){
                    printf(" %c ",(char)Info(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1)));
                }else{
                    if (Info(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1))<9){
                        printf(" %d ",Info(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }else{
                        printf("%d ",Info(isPoinMember(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }
                }
            }else if(food.X==((j+1)/2)-1 && food.Y==((i+1)/2)-1){
                printf(" O ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

address isPoinMember(List L,int i,int j){
    address P=First(L);
    boolean found=false;
    while(!found && (P)!=Nil){
        if ((*P).Pos.X==i && (*P).Pos.Y==j){
            found=true;
        }else{
            P=Next(P);
        }
    }
    if (found){
        return P; 
    }else{
        return Nil;
    }
}

boolean isNotWall(List L,char input){
    address P=First(L);
    if ((*P).Pos.X==0 && input=='a'){
        return false;
    }else if((*P).Pos.X==5 && input=='d'){
        return false;
    }else if((*P).Pos.Y==0 && input=='w'){
        return false;
    }else if((*P).Pos.Y==5 && input=='s'){
        return false;
    }else{
        return true;
    }
}

void moveHead(List *L,char input){
    address P=First(*L);
    if (input=='a' ){
        if ((*P).Pos.X==0){   
            (*P).Pos.X=4;
        }else{
            (*P).Pos.X-=1;
        }   
    }else if(input=='d'){
        if ((*P).Pos.X==4){   
            (*P).Pos.X=0;
        }else{
            (*P).Pos.X+=1;
        }
    }else if(input=='w'){
        if ((*P).Pos.Y==0){   
            (*P).Pos.Y=4;
        }else{
            (*P).Pos.Y-=1;
        } 
    }else if(input=='s'){
        if ((*P).Pos.Y==4){   
            (*P).Pos.Y=0;
        }else{
            (*P).Pos.Y+=1;
        }
    }
}

void addMeteor(POINT *meteor,POINT food){
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found=false;
    int i=0;
    while (!found){
        if (X!=food.X && Y!=food.Y){
            found=true;
            meteor->X=X;
            meteor->Y=Y;
        }else{
        if (i%3==0){
            X=(X+1)%5;
            Y=(Y-1)%5;
        }else if(i%3==1){
            Y=(Y+1)%5;
            X=(X-1)%5;
        }else{
            X=(X+1)%5;
            Y=(Y+1)%5;
        }
        }
        if (X<0 || Y<0){
            X = rand() % 5;
            Y = rand() % 5;
        }
        i++;
    }
 
}

boolean isEat(List *L, POINT P){
    boolean found=((*First(*L)).Pos.X==P.X && (*First(*L)).Pos.Y==P.Y );
    //if (found){
        
    //}
    return found;
}

boolean isAvail(List L,int X,int Y){
    address Q=First(L);
    boolean found=true;
    while (found && Q!=Nil){
        if ((*Q).Pos.X==X && (*Q).Pos.Y==Y){
            found=false;
        }
        Q=Next(Q);
    }
    return found;
}

void addTail(List *L,ElmtList newtail){
    address P=Alokasi(((int)Info(Last(*L)))+1);
    P->Pos.X=newtail.Pos.X;
    P->Pos.Y=newtail.Pos.Y;
    InsertLast(L,P);
}

void addFood(POINT *food,List L, POINT obstacle){
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found=false;
    int i=0;
    while (!found){
        if (isAvail(L,X,Y) && X!=obstacle.X && Y!=obstacle.Y){
            found=true;
            food->X=X;
            food->Y=Y;
        }else{
        if (i%3==0){
            X=(X+1)%5;
            Y=(Y-1)%5;
        }else if(i%3==1){
            Y=(Y+1)%5;
            X=(X-1)%5;
        }else{
            X=(X+1)%5;
            Y=(Y+1)%5;
        }
        }
        if (X<0 || Y<0){
            X = rand() % 5;
            Y = rand() % 5;
        }
        i++;
    }
}

void MeteorHitBody(List *L,POINT food,POINT meteor){
    
    address P=First(*L);
    address Q=Last(*L);
    boolean found=false;
    while(!found && P!=Nil){
        if (P->Pos.X==meteor.X && P->Pos.Y==meteor.Y){
            found=true;    
        }
        P=Next(P);
    }
    if (found){
         if (P==Next(First(*L))){
            DelFirst(L,&Q);
            printf("Meteor mengenai bagian Head snake. Permainan berakhir\n");
         }else if(P==Nil){
            DelLast(L,&Q);
        }else{
            while (Q!=Prev(P)){
                Q->info=Prev(Q)->info;
        //     Q->Pos.X=Prev(Q)->Pos.X;
        //     Q->Pos.Y=Prev(Q)->Pos.Y;
        //     printf("%d %d\n",Q->Pos.X,Q->Pos.Y);    
        //     Q=Prev(Q);
                Q=Prev(Q);
            }
            DelBefore(L,&Q,P);
        }
    }

}

boolean isMeteorHitHead(List L){
    address P=First(L);
    return (P->info!='H');
}

void snakeOnMeteor(int * skor){
    srand(time(NULL));
    List L;
    ElmtList newtail;
    createSnake(&L);
    char input;
    POINT obstacle;
    POINT food;
    food.X=-999;
    food.Y=-999;
    POINT meteor;
    meteor.X=-999;
    meteor.Y=-999;
    printf("Selamat datang di snake on meteor!\n");
    printf("Mengenerate peta, snake dan makanan . . . \n");
    printf("Berhasil digenerate\n");
    printf("------------------------------\n");
    printf("Berikut merupakan peta permainan\n");
    addObstacle(L,&obstacle);
    addFood(&food,L,obstacle);
    printMap(L,food,meteor,obstacle);
    int i=1;
    boolean hit = false;
    while(!hit){
        printf("TURN %d:\n",i);
        printf("Silahkan masukkan command anda:");

        startInputWord();
        input = currentWord.TabWord[0];
        if (currentWord.Length == 1 && (input == 'w' || input == 'a' || input == 's' || input == 'd') && isInputValid(L,input)){
            newtail=*(Last(L));
            Move(&L,input);
            if (isEat(&L,food)){
                addTail(&L,newtail);
                addFood(&food,L,obstacle);     
            }
            addMeteor(&meteor,food);
            //printPoint(meteor);
            printMap(L,food,meteor,obstacle);
            MeteorHitBody(&L,food,meteor);
            if(isLose(L,meteor,obstacle)){
                *skor=lengthSnake(L)*2;
                printf("skor anda %d\n",*skor);
                hit = true;
            }else{
                i++;
            }
        } else
        {
            printf("Perintah tidak valid.\n");
        }
        
        
    }
}

boolean isHeadHitObstacle(List L,POINT obstacle){
    return (First(L)->Pos.X==obstacle.X && First(L)->Pos.Y==obstacle.Y);
}

boolean isLose(List L,POINT meteor, POINT obstacle){
    address P=First(L);
    P=Next(P);
    boolean found=false;
    while (P!=Nil && !found){
        if (P->Pos.X==First(L)->Pos.X && P->Pos.Y==First(L)->Pos.Y){
            found=true;
        }
        P=Next(P);
    }
    if (found){
        printf("Anda Kalah.Head menabrak body Snake\n");
        return found;
    }else{
        if(isMeteorHitHead(L)){
            return true;
        }else if(isHeadHitObstacle(L,obstacle)){
            printf("Anda Kalah.Head menabrak obstacle\n");
            return true;
        }else{
            return false;
        }
    }
}

void addObstacle(List L, POINT* obstacle){
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found=false;
    int i=0;
    while (!found){
        if (isAvail(L,X,Y)){ //&& X!=meteor.X && Y!=meteor.Y && X!=obstacle.X && Y!=obstacle.Y){
            found=true;
            obstacle->X=X;
            obstacle->Y=Y;
        }else{
        if (i%3==0){
            X=(X+1)%4;
            Y=(Y-1)%4;
        }else if(i%3==1){
            Y=(Y+1)%4;
            X=(X-1)%4;
        }else{
            X=(X+1)%4;
            Y=(Y+1)%4;
        }
        }
        if (X<0 || Y<0){
            X = rand() % 4;
            Y = rand() % 4;
        }
        i++;
    }
}

int lengthSnake(List L){
    return (Info(Last(L)));
}

boolean isInputValid(List L,char input){
    address P=First(L);
    if (input=='w' && Next(P)->Pos.Y==(P->Pos.Y-1)%5){
        return false;
    }else if(input=='s' && Next(P)->Pos.Y==(P->Pos.Y+1)%5){
        return false;
    }else if(input=='a' && Next(P)->Pos.X==(P->Pos.X-1)%5){
        return false;
    }else if(input=='d' && Next(P)->Pos.Y==(P->Pos.Y-1)%5){
        return false;
    }else{
        return true;
    }
}
