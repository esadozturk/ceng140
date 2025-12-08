#include "stock_market.h"

/*
allocate memory and initialize the Person struct
return value is a pointer to the new person

typedef struct
{
  char name[MAX_NAME_LEN];
  int id;
} Person;

declare variable
    Person *newPerson;
allocate memory
    newPerson = (Person *) malloc(sizeof(Person));
if successful
    if (newPerson)
    initialize values
        strcpy(newPerson->name, name);
        newPerson->id = id;
        return newPerson
else
    return NULL;
*/

Person* create_person(char *name, int id) {
    /* WRITE YOUR CODE HERE AND REMOVE RETURN NULL */
    
    Person *newPerson;
    
    newPerson = (Person *) malloc(sizeof(Person));
    
    if (newPerson)
    {
        strcpy(newPerson->name, name);
        newPerson->id = id;
        return newPerson;
    }
    else
    {
        return NULL;
    }
}

/*

typedef struct
{
    char name[MAX_NAME_LEN];
    char stock_abbreviation[10];
    int market_order;
} Company;

declare variable
allocate memory
if successful
    initialize values
    return
else
    return NULL;
    
    
Company *newCompany;
newCompany = (Company *) malloc(sizeof(Company));
if (newCompany)
    strcpy(newCompany->name, name);
    strcpy(newCompany->stock_abbreviaton, abbr);
    newCompany->market_order = order;
    return newCompany;
else
    return NULL;
*/

Company* create_company(char *name, char *abbr, int order) {
    /* WRITE YOUR CODE HERE AND REMOVE RETURN NULL */
    
    Company *newCompany;
    
    newCompany = (Company *) malloc(sizeof(Company));
    
    if (newCompany)
    {
        strcpy(newCompany->name, name);
        strcpy(newCompany->stock_abbreviation, abbr);
        newCompany->market_order = order;
        return newCompany;
    }
    else
    {
        return NULL;
    }
}

/*
typedef struct
{
    Company *company;
    RequestNode *buy_requests;
    RequestNode *sell_requests;
} StockMarketEntry;

typedef struct
{
    StockMarketEntry entries[MAX_COMPANIES];
    int company_count;
} StockMarket;


what to initialize here?

initialize StockMarketEntry for the given company
    StockMarketEntry *entryToAdd;
    entryToAdd = (StockMarketEntry *) malloc(sizeof(StockMarketEntry));
    if (entryToAdd)
        entryToAdd->company = company;
        entryToAdd->buy_requests = NULL;
        entryToAdd->sell_requests = NULL;
add this StockMarketEntry to given market
    market->entries[(company->market_order) - 1] = (*entryToAdd);
    (market->company_count)++;

*/

void add_company_to_market(StockMarket *market, Company *company) {
    /* WRITE YOUR CODE HERE */
    
    StockMarketEntry *entryToAdd;
    entryToAdd = (StockMarketEntry *) malloc(sizeof(StockMarketEntry));
    
    if (entryToAdd)
    {
        entryToAdd->company = company;
        entryToAdd->buy_requests = NULL;
        entryToAdd->sell_requests = NULL;
    }
    
    market->entries[(company->market_order) - 1] = (*entryToAdd);
    (market->company_count)++;
}

/*

typedef struct
{
    Person *person;
    int amount;
    float price_per_share;
} Request;

typedef struct RequestNode
{
    Request data;
    struct RequestNode *next;
} RequestNode;

RequestNode *newRequestNode;
newRequestNode = (RequestNode *) malloc(sizeof(RequestNode));
if (newRequestNode)
    newRequestNode->data.person = p;
    newRequestNode->data.amount = amount;
    newRequestNode->data.price_per_share = price;
    newRequestNode->next = NULL;
    return newRequestNode;
else
    return NULL;

*/

RequestNode* create_request_node(Person *p, int amount, float price) {
    /* WRITE YOUR CODE HERE AND REMOVE RETURN NULL */
    RequestNode *newRequestNode;
    newRequestNode = (RequestNode *) malloc(sizeof(RequestNode));
    
    if (newRequestNode)
    {
        newRequestNode->data.person = p;
        newRequestNode->data.amount = amount;
        newRequestNode->data.price_per_share = price;
        newRequestNode->next = NULL;
        return newRequestNode;
    }
    else
    {
        return NULL;
    }
}

/*

adding a new node to a linked list in ascending or descending order
edge cases
    if empty set
    else if (*head) need to be changed
    else if we need to add to the end
    else
    
if (*head) == NULL
    (*head) = node, node->next = NULL;
else if (ascending)
    RequestNode *prev = NULL, *current = (*head);
    while (current && current->data.price_per_share <= node->data.price_per_share)
        prev = current, current = current->next;
    if (prev != NULL)
        prev->next = node, node->next = current;
    else
        node->next = (*head), (*head) = node;
        
else if (!ascending)
    RequestNode *prev = NULL, *current = (*head);
    while (current && current->data.price_per_share >= node->data.price_per_share)
        prev = current, current = current->next;
    if (prev != NULL)
        prev->next = node, node->next = current;
    else
        node->next = (*head), (*head) = node;

*/

void insert_sorted(RequestNode **head, RequestNode *node, int ascending)
{
    /* WRITE YOUR CODE HERE */
    if ((*head) == NULL)
    {
        (*head) = node;
        node->next = NULL;   
    }
    else if (ascending)
    {
        RequestNode *prev = NULL, *current = (*head);
        while (current && current->data.price_per_share <= node->data.price_per_share)
        {
            prev = current, current = current->next;
        }
        if (prev != NULL)
        {
            prev->next = node, node->next = current;
        }
        else
        {
            node->next = (*head), (*head) = node;
        }
    }
    else if (!ascending)
    {
        RequestNode *prev = NULL, *current = (*head);
        while (current && current->data.price_per_share >= node->data.price_per_share)
        {
            prev = current, current = current->next;
        }
        if (prev != NULL)
        {
            prev->next = node, node->next = current;
        }
        else
        {
            node->next = (*head), (*head) = node;
        }
    }
}

/*
    
find sellRequestsHead
find buyRequestsHead
find the person
make newBuyRequest and initialize
while
    if head node is NULL
        add newBuyRequest
        break
    if head node is not available
        insert newBuyRequest node
        break
    else if head node is available
        if buy amount == sell amount
            print
            keep nodeToFree, change sellRequestsHead
            free sell node
            free newBuyRequest
            break
        else if buy amount < sell amount
            print
            decrease amount in sell node
            free newBuyRequest
            break
        else if buy amount > sell amount
            print
            decrease amount in newBuyRequest
            keep nodeToFree, change sellRequestsHead
            free sell node
            (go to the loop with new head)
    
            
initialize
RequestNode *sellRequestsHead, *buyRequestsHead, *newBuyRequest;
Person *currentPerson;
StockMarketEntry *currentEntry;
RequestNode *nodeToFree;
float currentDifference;
int currentBuyAmount, currentSellAmount, i;

find sellRequestsHead and buyRequestsHead
for ( ; i < market->company_count; )
    if (strcmp(company_abbr, market->entries[i].company->stock_abbreviation) == 0)
        currentEntry = &(market->entries[i]);
        break;
sellRequestsHead = currentEntry->sell_requests;
buyRequestsHead = currentEntry->buy_requests;

find the person
for
    if (strcmp(people[i]->name, buyer_name) == 0)
        currentPerson = people[i];
        break;
            
make newBuyRequest and initialize with given data
newBuyRequest = (RequestNode *) malloc(sizeof(RequestNode));
newBuyRequest->data.person = currentPerson;
newBuyRequest->data.amount = amount;
newBuyRequest->data.price_per_share = price;

    
while (1)
    if (sellRequestsHead == NULL)
        insert_sorted(&buyRequestsHead, newBuyRequest, 0);
        break;
    currentDifference = newBuyRequest->data.price_per_share - sellRequestsHead->data.price_per_share;
    currentBuyAmount = newBuyRequest->data.amount;
    currentSellAmount sellRequestsHead->data.amount;
    if (currentDifference < 0)
        insert_sorted(&buyRequestsHead, newBuyRequest, 0);
        break;
    else if (currentDifference > 0)
        if (currentBuyAmount == currentSellAmount)
            printf();
            nodeToFree = sellRequestsHead, sellRequestsHead = sellRequestsHead->next;
            free(nodeToFree);
            free(newBuyRequest);
            break;
        else if (currentBuyAmount < currentSellAmount)
            printf();
            sellRequestsHead->data.amount -= currentBuyAmount;
            free(newBuyRequest);
            break;
        else if (currentBuyAmount > currentSellAmount)
            printf();
            newBuyRequest->data.amount -= currentSellAmount;
            nodeToFree = sellRequestsHead, sellRequestsHead = sellRequestsHead->next;
            free(nodeToFree);

currentEntry->buy_requests = buyRequestsHead;
    


*/



void insert_buy_request(StockMarket *market, Person **people, int people_count, char *buyer_name, char *company_abbr, int amount, float price)
{
    /* WRITE YOUR CODE HERE */
    RequestNode *sellRequestsHead, *buyRequestsHead, *newBuyRequest;
    Person *currentPerson;
    StockMarketEntry *currentEntry;
    RequestNode *nodeToFree;
    float currentDifference;
    int currentBuyAmount, currentSellAmount, i;
    
    for (i = 0; i < market->company_count; i++)
    {
        if (strcmp(company_abbr, market->entries[i].company->stock_abbreviation) == 0)
        {
            currentEntry = &(market->entries[i]);
            break;
        }
    }
    sellRequestsHead = currentEntry->sell_requests;
    buyRequestsHead = currentEntry->buy_requests;
    
    for (i = 0; i < people_count; i++)
    {
        if (strcmp(people[i]->name, buyer_name) == 0)
        {
            currentPerson = people[i];
            break;
        }
    }
    
    newBuyRequest = (RequestNode *) malloc(sizeof(RequestNode));
    newBuyRequest->data.person = currentPerson;
    newBuyRequest->data.amount = amount;
    newBuyRequest->data.price_per_share = price;
    
    while (1)
    {
       if (sellRequestsHead == NULL)
       {
           insert_sorted(&buyRequestsHead, newBuyRequest, 0);
           break;
       }
       
       currentDifference = newBuyRequest->data.price_per_share - sellRequestsHead->data.price_per_share;
       currentBuyAmount = newBuyRequest->data.amount;
       currentSellAmount = sellRequestsHead->data.amount;
       
       if (currentDifference < 0)
       {
           insert_sorted(&buyRequestsHead, newBuyRequest, 0);
           break;
       }
       else if (currentDifference > 0)
       {
           if (currentBuyAmount == currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentBuyAmount, company_abbr, sellRequestsHead->data.price_per_share, sellRequestsHead->data.person->name, currentPerson->name);
               nodeToFree = sellRequestsHead, sellRequestsHead = sellRequestsHead->next;
               free(nodeToFree);
               free(newBuyRequest);
               break;
           }
           else if (currentBuyAmount < currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentBuyAmount, company_abbr, sellRequestsHead->data.price_per_share, sellRequestsHead->data.person->name, currentPerson->name);
               sellRequestsHead->data.amount -= currentBuyAmount;
               free(newBuyRequest);
               break;
               
           }
           else if (currentBuyAmount > currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentSellAmount, company_abbr, sellRequestsHead->data.price_per_share, sellRequestsHead->data.person->name, currentPerson->name);
               newBuyRequest->data.amount -= currentSellAmount;
               nodeToFree = sellRequestsHead, sellRequestsHead = sellRequestsHead->next;
               free(nodeToFree);
           }
       }
        
    }
    
    currentEntry->buy_requests = buyRequestsHead;
    currentEntry->sell_requests = sellRequestsHead;
}

/*

initialize
RequestNode *sellRequestsHead, *buyRequestsHead, *newSellRequest;
Person *currentPerson;
StockMarketEntry *currentEntry;
RequestNode *nodeToFree;
float currentDifference;
int currentBuyAmount, currentSellAmount, i;

find sellRequestsHead and buyRequestsHead
for ( ; i < market->company_count; )
    if (strcmp(company_abbr, market->entries[i].company->stock_abbreviation) == 0)
        currentEntry = &(market->entries[i]);
        break;
sellRequestsHead = currentEntry->sell_requests;
buyRequestsHead = currentEntry->buy_requests;

find the person
for
    if (strcmp(people[i]->name, seller_name) == 0)
        currentPerson = people[i];
        break;
            
make newSellRequest and initialize with given data
newSellRequest = (RequestNode *) malloc(sizeof(RequestNode));
newSellRequest->data.person = currentPerson;
newSellRequest->data.amount = amount;
newSellRequest->data.price_per_share = price;

    
while (1)
    if (buyRequestsHead == NULL)
        insert_sorted(&sellRequestsHead, newSellRequest, 1);
        break;
    currentDifference = buyRequestsHead->data.price_per_share - newSellRequest->data.price_per_share;
    currentBuyAmount = buyRequestsHead->data.amount;
    currentSellAmount newSellRequest->data.amount;
    if (currentDifference < 0)
        insert_sorted(&sellRequestsHead, newSellRequest, 1);
        break;
    else if (currentDifference > 0)
        if (currentBuyAmount == currentSellAmount)
            printf();
            nodeToFree = buyRequestsHead, buyRequestsHead = buyRequestsHead->next;
            free(nodeToFree);
            free(newSellRequest);
            break;
        else if (currentBuyAmount > currentSellAmount)
            printf();
            buyRequestsHead->data.amount -= currentSellAmount;
            free(newSellRequest);
            break;
        else if (currentBuyAmount < currentSellAmount)
            printf();
            newSellRequest->data.amount -= currentBuyAmount;
            nodeToFree = buyRequestsHead, buyRequestsHead = buyRequestsHead->next;
            free(nodeToFree);
    
currentEntry->sell_requests = sellRequestsHead;

*/


void insert_sell_request(StockMarket *market, Person **people, int people_count, char *seller_name, char *company_abbr, int amount, float price) {
    /* WRITE YOUR CODE HERE */
    RequestNode *sellRequestsHead, *buyRequestsHead, *newSellRequest;
    Person *currentPerson;
    StockMarketEntry *currentEntry;
    RequestNode *nodeToFree;
    float currentDifference;
    int currentBuyAmount, currentSellAmount, i;
    
    for (i = 0; i < market->company_count; i++)
    {
        if (strcmp(company_abbr, market->entries[i].company->stock_abbreviation) == 0)
        {
            currentEntry = &(market->entries[i]);
            break;
        }
    }
    sellRequestsHead = currentEntry->sell_requests;
    buyRequestsHead = currentEntry->buy_requests;
    
    for (i = 0; i < people_count; i++)
    {
        if (strcmp(people[i]->name, seller_name) == 0)
        {
            currentPerson = people[i];
            break;
        }
    }
    
    newSellRequest = (RequestNode *) malloc(sizeof(RequestNode));
    newSellRequest->data.person = currentPerson;
    newSellRequest->data.amount = amount;
    newSellRequest->data.price_per_share = price;

    while (1)
    {
       if (buyRequestsHead == NULL)
       {
           insert_sorted(&sellRequestsHead, newSellRequest, 1);
           break;
       }
       
       currentDifference = buyRequestsHead->data.price_per_share - newSellRequest->data.price_per_share;
       currentBuyAmount = buyRequestsHead->data.amount;
       currentSellAmount = newSellRequest->data.amount;
       
       if (currentDifference < 0)
       {
           insert_sorted(&sellRequestsHead, newSellRequest, 1);
           break;
       }
       else if (currentDifference > 0)
       {
           if (currentBuyAmount == currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentSellAmount, company_abbr, newSellRequest->data.price_per_share, currentPerson->name, buyRequestsHead->data.person->name);
               nodeToFree = buyRequestsHead, buyRequestsHead = buyRequestsHead->next;
               free(nodeToFree);
               free(newSellRequest);
               break;
           }
           else if (currentBuyAmount > currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentSellAmount, company_abbr, newSellRequest->data.price_per_share, currentPerson->name, buyRequestsHead->data.person->name);
               buyRequestsHead->data.amount -= currentSellAmount;
               free(newSellRequest);
               break;
               
           }
           else if (currentBuyAmount < currentSellAmount)
           {
               printf("Trade executed: %d shares of %s at %.2f between %s, %s\n", currentBuyAmount, company_abbr, newSellRequest->data.price_per_share, currentPerson->name, buyRequestsHead->data.person->name);
               newSellRequest->data.amount -= currentBuyAmount;
               nodeToFree = buyRequestsHead, buyRequestsHead = buyRequestsHead->next;
               free(nodeToFree);
           }
       }
        
    }
    
    currentEntry->buy_requests = buyRequestsHead;
    currentEntry->sell_requests = sellRequestsHead;
}

/*

we need to reach: company, buy_reqeusts, sell_reqeusts

initializations
    int i;
    StockMarketEntry *currentEntry;
    RequestNode *currentRequest;
for (; i < market->company_count; )
    currentEntry = &(market->entries[i]);
    printf("Company: %s (%s)\n", currentEntry->company->name, currentEntry->company->stock_abbreviation);
    printf("    Buy Requests:\n");
    currentRequest = currentEntry->buy_requests;
    while(currentRequest != NULL)
        printf("        %s wants %d @ %.2f\n", currentRequest->data.person->name, currentRequest->data.amount, currentRequest->data.price_per_share);
        currentRequest = currentRequest->next;
    printf("    Sell Requests:\n");
    currentRequest = currentEntry->sell_requests;
    while(currentRequest != NULL)
        printf("        %s sells %d @ %.2f\n", currentRequest->data.person->name, currentRequest->data.amount, currentRequest->data.price_per_share);
        currentRequest = currentRequest->next;
        
*/

void print_market(StockMarket *market)
{
    /* WRITE YOUR CODE HERE */
    int i;
    StockMarketEntry *currentEntry;
    RequestNode *currentRequest;
    
    for (i = 0; i < market->company_count; i++)
    {
        currentEntry = &(market->entries[i]);
        printf("Company: %s (%s)\n", currentEntry->company->name, currentEntry->company->stock_abbreviation);
        
        printf("\tBuy Requests:\n");
        currentRequest = currentEntry->buy_requests;
        
        while(currentRequest != NULL)
        {
            printf("\t\t%s wants %d @ %.2f\n", currentRequest->data.person->name, currentRequest->data.amount, currentRequest->data.price_per_share);
            currentRequest = currentRequest->next;            
        }
        
        printf("\tSell Requests:\n");
        currentRequest = currentEntry->sell_requests;
        while(currentRequest != NULL)
        {
            printf("\t\t%s sells %d @ %.2f\n", currentRequest->data.person->name, currentRequest->data.amount, currentRequest->data.price_per_share);
            currentRequest = currentRequest->next;
        }
    }
}
































