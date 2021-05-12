#include<stdio.h>
#include<string.h>
#include<sp_common.h>
#include<sp_sll.h>
#include<sp_priority_queue.h>
#include<avl_tree.h>
#include<sp_stack.h>
#include<stdlib.h>
void populateGraph();
void addCity();
void getRoute(const char*,const char*);
SinglyLinkedList *singlyLinkedList;
typedef struct __$_city_details
{
char cityName[21];
int totalDistanceFromSource;
}CityDetails;

typedef struct __$_adjacent_cities_with_edge
{
int edgeWeight;
char adjacentCityName[21];
}AdjacentCity;
typedef struct __$_city
{
char cityName[21];
SinglyLinkedList *listOfAdjacentCities;
int totalDistanceFromSource;
}City;
typedef struct __$_path
{
char srcCity[21];
char cityName[21];
int totalDistance;
}Path;
typedef struct __$_city_name
{
char cn[21];
}CityName;
int main()
{
int ch;
char src[22],dst[22];
populateGraph();
while(1)
{
printf("1.Add City\n");
printf("2.Get Route\n");
printf("3.Exit\n");
printf("Choose Option:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addCity();
if(ch==2)
{
printf("Enter Source City:");
fgets(src,22,stdin);
fflush(stdin);
src[strlen(src)-1]='\0';
printf("Enter Distnation City:");
fgets(dst,22,stdin);
fflush(stdin);
dst[strlen(dst)-1]='\0';
getRoute(src,dst);
}
if(ch==3) break;
}
return 0;
}

void populateGraph()
{
CityDetails *cd;
AdjacentCity *adc;
SinglyLinkedListIterator iterator1,iterator2;
int succ;
FILE *f;
City *city;
SinglyLinkedList *cityList;
singlyLinkedList=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("It is not working\n");
return;
}
f=fopen("map.p","rb");
if(f==NULL)
{
printf("graph is not exist.\n");
return ;
}
while(1)
{
city=(City*)malloc(sizeof(City));
if(city==NULL) 
{
free(city);
printf("something went wrong. try later\n");
return;
}
cd=(CityDetails*)malloc(sizeof(CityDetails));
if(cd==NULL) 
{
free(cd);
printf("something went wrong. try later\n");
return;
}
if(feof(f)) break;
fread(cd,sizeof(CityDetails),1,f);
printf("%s\n",cd->cityName);
strcpy(city->cityName,cd->cityName);
city->totalDistanceFromSource=cd->totalDistanceFromSource;
cityList=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("something went wrong. try later\n");
return;
}
while(1)
{
adc=(AdjacentCity*)malloc(sizeof(AdjacentCity));
if(adc==NULL)
{
free(adc);
printf("something went wrong. try later\n");
return;
}
fread(adc,sizeof(AdjacentCity),1,f);
if(adc->adjacentCityName=="breakCondition") break;
printf("%s\n",adc->adjacentCityName);
addInSinglyLinkedList(cityList,(void*)adc,&succ);

if(succ==false)
{
destroySinglyLinkedList(cityList);
printf("something went wrong.try later\n");
return;
}
} // innner loop end
city->listOfAdjacentCities=cityList;
addInSinglyLinkedList(singlyLinkedList,(void*)city,&succ);
if(succ==false)
{
destroySinglyLinkedList(singlyLinkedList);
printf("something went wrong.try later\n");
return;
}
} //end outer infinite loop
} //funtion end 

void addCity()
{
CityDetails *cd;
SinglyLinkedList *cityList;
SinglyLinkedListIterator iterator1,iterator2;
CityName *graphCityName,*name;
char cn[22];
FILE *f;
City *city;
AdjacentCity *adc;
char cityName[22];
char adjacentCityName[22];
Queue *queue;
int edgeWeight;
int i,j,found,y,succ; 	
printf("Enter number of cities to add in graph:");
scanf("%d",&i);
fflush(stdin);
if(i<=0) 
{
printf("Invalid Number\n");
return;
}
j=i;
y=0;
while(y<i)
{
printf("Enter city name:");
fgets(cn,22,stdin);
fflush(stdin);
cn[strlen(cn)-1]='\0';
graphCityName=(CityName*)malloc(sizeof(CityName));
strcpy(graphCityName->cn,cn);
f=fopen("city_name.p","a");
fwrite(graphCityName,sizeof(CityName),1,f);
fclose(f);
free(graphCityName);
y++;
}
cityList=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("something went wrong. try later\n");
return;
}
f=fopen("city_name.p","r");
if(f==NULL) 
{
printf("unable to add\n");
return;
}
while(1)
{
graphCityName=(CityName*)malloc(sizeof(CityName));
fread(graphCityName,sizeof(CityName),1,f);
if(feof(f)) break;
addInSinglyLinkedList(cityList,(void*)graphCityName,&succ);
}
fclose(f);
graphCityName=NULL;
iterator1=getSinglyLinkedListIterator(cityList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator1))
{
graphCityName=(CityName*)getNextElementFromSinglyLinkedList(&iterator1,&succ);
strcpy(cn,graphCityName->cn);
city=(City*)malloc(sizeof(City));
if(city==NULL)
{
printf("unable to add city\n");
return ;
}
strcpy(city->cityName,cn);
city->listOfAdjacentCities=NULL;
city->totalDistanceFromSource=0;
printf("How many adjacent cities of %s (0-%d):",cn,j-1);
scanf("%d",&i);
fflush(stdin);
if(i<0 || i>=j)
{
printf("Invalid Number\n");
continue;
}
if(i==0)
{
addInSinglyLinkedList(singlyLinkedList,(void*)city,&succ);
if(succ==false)
{
printf("unable to add\n");
free(city);
return;
}
printf("%s is added\n",cn);
continue;
}
city->listOfAdjacentCities=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("unable to create\n");
free(city);
destroySinglyLinkedList(cityList);
return;
}
y=0;
while(y<i)
{
printf("Enter adjacent city name of %s:",cn);
fgets(adjacentCityName,22,stdin);
adjacentCityName[strlen(adjacentCityName)-1]='\0';
fflush(stdin);
found=0;
iterator2=getSinglyLinkedListIterator(cityList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator2))
{
name=(CityName*)getNextElementFromSinglyLinkedList(&iterator2,&succ);
if(strcmp(name->cn,adjacentCityName)==0)
{
found=1;
break;
}
}
}  //iterator2
if(found==0)
{
printf("%s city is not exit\n",adjacentCityName);
printf("Give correct information.add again\n");
return;
}
printf("Enter distance from %s to %s:",cn,adjacentCityName);
scanf("%d",&edgeWeight);
fflush(stdin);
adc=(AdjacentCity*)malloc(sizeof(AdjacentCity));
if(adc==NULL)
{
printf("Unable to add.try later\n");
free(city);
destroySinglyLinkedList(city->listOfAdjacentCities);
destroySinglyLinkedList(cityList);
return;
}
strcpy(adc->adjacentCityName,adjacentCityName);
adc->edgeWeight=edgeWeight;
addInSinglyLinkedList(city->listOfAdjacentCities,(void*)adc,&succ);
if(succ==false)
{
destroySinglyLinkedList(city->listOfAdjacentCities);
destroySinglyLinkedList(cityList);
free(city);
free(adc);
printf("unable to add. try later\n");
return;
}
y++;
}
addInSinglyLinkedList(singlyLinkedList,(void*)city,&succ);
if(succ==false)
{
printf("unable to add.try later\n");
free(city);
return;
}
printf("%s is added\n",cn);
} 
}  //iterator1
f=fopen("map.p","ab");
cd=(CityDetails*)malloc(sizeof(CityDetails));
iterator1=getSinglyLinkedListIterator(singlyLinkedList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator1))
{
city=(City*)getNextElementFromSinglyLinkedList(&iterator1,&succ);
if(succ)
{
strcpy(cd->cityName,city->cityName);
cd->totalDistanceFromSource=city->totalDistanceFromSource;
fwrite(cd,sizeof(CityDetails),1,f);
iterator2=getSinglyLinkedListIterator(city->listOfAdjacentCities,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator2))
{
adc=(AdjacentCity*)getNextElementFromSinglyLinkedList(&iterator2,&succ);
if(succ)
fwrite(adc,sizeof(AdjacentCity),1,f);
}
}
adc=(AdjacentCity*)malloc(sizeof(AdjacentCity));
strcpy(adc->adjacentCityName,"breakCondition");
adc->edgeWeight=0;
fwrite(adc,sizeof(AdjacentCity),1,f);
free(adc);
}
}
}
fclose(f);
destroySinglyLinkedList(city->listOfAdjacentCities);
destroySinglyLinkedList(cityList);
printf("graph is added successfully\n");
} //end  addCity() function here



void getRoute(const char *source ,const char *destination)
{
int x;
Path *path,*tmpPath;
AvlTree *avlTree;
SinglyLinkedListIterator iterator,cityIterator,queueIterator;
Stack *stack;
PriorityQueue *priorityQueue;
City *srcCity,*dstCity,*tmpCity,*samCity,*queueCity;
AdjacentCity *adc;
int i,found,succ,routeExist,td,edgeWeight;
int distanceCalculator(void *left,void *right)
{
City *leftCity,*rightCity;
leftCity=(City*)left;
rightCity=(City*)right;
return leftCity->totalDistanceFromSource-rightCity->totalDistanceFromSource;
}
int avlTreeComparator(void *left,void *right)
{
Path *leftPath,*rightPath;
leftPath=(Path*)left;
rightPath=(Path*)right;
return leftPath->cityName-rightPath->cityName;
}
if(singlyLinkedList==NULL)
{
printf("something wrong\n");
return;
}
printf("%d\n",getSizeOfSinglyLinkedList(singlyLinkedList));
for(x=0;x<getSizeOfSinglyLinkedList(singlyLinkedList);x++);
{
printf("****************\n");

tmpCity=(City*)getFromSinglyLinkedList(singlyLinkedList,x,&succ);
printf("%s\n",tmpCity->cityName);
}

printf("****************\n");

srcCity=(City*)malloc(sizeof(City));
found=0;
iterator=getSinglyLinkedListIterator(singlyLinkedList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator))
{
srcCity=(City*)getNextElementFromSinglyLinkedList(&iterator,&succ);
printf("****************\n");
printf("%s        %s\n",srcCity->cityName,source);
if(srcCity->cityName==source)
{
found=1;
break;
}
}
}
if(found==0)
{
printf("Invalid source %s\n",source);
return;
}
found=0;
dstCity=(City*)malloc(sizeof(City));
iterator=getSinglyLinkedListIterator(singlyLinkedList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator))
{
dstCity=(City*)getNextElementFromSinglyLinkedList(&iterator,&succ);
if(dstCity->cityName==destination)
{
found=1;
break;
}
}
}
if(found==0)
{
printf("Invalid destination %s\n",*destination);
return;
}
priorityQueue=createPriorityQueue(distanceCalculator,&succ);
if(succ==false)
{
printf("sorry something went wrong\n");
return;
}
addInPriorityQueue(priorityQueue,(void*)srcCity,&succ);
if(succ==false)
{
printf("try later\n");
destroyPriorityQueue(priorityQueue);
return;
}
avlTree=createAvlTree(avlTreeComparator,&succ);
if(succ==false)
{
printf("something went wrong\n");
return;
}
routeExist=0;
while(!isPriorityQueueEmpty(priorityQueue))
{
tmpCity=(City*)removeFromPriorityQueue(priorityQueue,&succ);
if(tmpCity->cityName==destination) 
{
routeExist=1;
break;
}
iterator=getSinglyLinkedListIterator(tmpCity->listOfAdjacentCities,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iterator))
{
adc=(AdjacentCity*)getNextElementFromSinglyLinkedList(&iterator,&succ);
edgeWeight=adc->edgeWeight;
td=tmpCity->totalDistanceFromSource+edgeWeight;
cityIterator=getSinglyLinkedListIterator(singlyLinkedList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&cityIterator))
{
samCity=(City*)getNextElementFromSinglyLinkedList(&cityIterator,&succ);
if(samCity->cityName==adc->adjacentCityName) break;
}
}
path=(Path*)malloc(sizeof(Path));
if(path==NULL)
{
printf("try again\n");
destroyAvlTree(avlTree);
return;
}
strcpy(path->cityName,samCity->cityName);
strcpy(path->srcCity,tmpCity->cityName);
path->totalDistance=td;
tmpPath=(Path*)getFromAvlTree(avlTree,(void*)path,&succ);
if(tmpPath!=NULL && td>tmpPath->totalDistance) 
{
free(path);
continue;
}
tmpPath=(Path*)malloc(sizeof(Path));
if(tmpPath==NULL)
{
printf("try again\n");
destroyAvlTree(avlTree);
return;
}
strcpy(tmpPath->cityName,samCity->cityName);
strcpy(tmpPath->srcCity,tmpCity->cityName);
tmpPath->totalDistance=td;
insertInAvlTree(avlTree,(void*)tmpPath,&succ);
if(succ==false)
{
printf("try later\n");
return;
}
found=0;
queueIterator=getSinglyLinkedListIterator(priorityQueue->singlyLinkedList,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&queueIterator))
{
queueCity=(City*)getNextElementFromSinglyLinkedList(&queueIterator,&succ);
if(queueCity->cityName==samCity->cityName)
{
found=1;
break;
}
}
}
if(found==1)
{
samCity->totalDistanceFromSource=td;
}
else
{
addInPriorityQueue(priorityQueue,(void*)samCity,&succ);
if(succ==false)
{
printf("something wrong\n");
return;
}
}
}
}
if(routeExist==0)
{
printf("No Route Exist From %c to %c\n",*source,*destination);
return;
}
stack=createStack(&succ);
if(succ==false)
{
printf("Not responding\n");
return;
}
strcpy(path->cityName,destination);
tmpPath=(Path*)getFromAvlTree(avlTree,(void*)path,&succ);
pushInStack(stack,(void*)tmpPath,&succ);
while(1)
{
strcpy(path->cityName,tmpPath->srcCity);
tmpPath=(Path*)getFromAvlTree(avlTree,(void*)path,&succ);
pushInStack(stack,(void*)tmpPath,&succ);
if(tmpPath->cityName==source) break;
}
while(!isStackEmpty(stack))
{
path=(Path*)popFromStack(stack,&succ);
printf("%s   %d\n",path->cityName,path->totalDistance);
}
}
}