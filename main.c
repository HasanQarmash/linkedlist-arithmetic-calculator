
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//x=120=>digit q=113=>operation
typedef struct node* pointerToNode;
typedef struct stack* pointerToTop;
pointerToNode EQUATION[100];//Array of DoublyLinkedList
pointerToNode validArray[10];//Array of valid equation
pointerToNode invalidArray[10];//Array of invalid equation
pointerToNode prefixEquation[10];//Array of prefix Equation
int EvalutionArry[10];
int numberOfEquation=0;
int numberOfValidEquation=0;
int numberOfEInvalidEquation=0;
int numberOfEquationForPrint=0;
int numberOfPrefixEquation=0;
int  numberOfEvalution=0;
//node in doubly linked list
struct node
    {
   int  digit;
   char operation;
   pointerToNode Next;
   pointerToNode prev;
    };

struct stack
    {
   int  Element;
   char operation;
   pointerToTop Next;
    };

//Method from doubly linked list
pointerToNode MakeEmptyLinkedList(struct node* L);
void Insert(int digit,char operand,struct node* L);
void InsertFromFront (int digit,char operand ,struct node* L);
void PrintList(struct node* L);
pointerToNode FindLast(pointerToNode L);
void DeleteList(pointerToNode L);
int IsEmptyLinkedList(struct node* L);
pointerToNode copyLinkedList(pointerToNode L);
pointerToNode FindLast(pointerToNode L);


//Method stack to implementation
int IsEmpty( pointerToTop S );
pointerToTop CreateStack(pointerToTop s );
pointerToTop MakeEmpty( pointerToTop S );
void PushElement( int X,char operand,pointerToTop S );
char Popchar( pointerToTop S );
int PopInt( pointerToTop S );
char Top( pointerToTop S );

//method private
void improveLinkedList(pointerToNode L);
void readFromFile(int num1);
void display_Menu();
void inToPre(pointerToNode L);
void EvaluatePreFix(pointerToNode L);
int isOperationAndPrecedence(char x);
int checkIsOPerationIfknown(pointerToNode L);
int checkBalancingParentheses(pointerToNode L);
int checkIfOperationIsValidity(pointerToNode L);
void writeFile(pointerToNode list,int c);




int main()
{

      int checkIfUserReadFromFile=0;
      int checkIfUserCheckValidity=0;
      int checkIfUserConvertToPrefix=0;
      int choice=0;
       display_Menu();
     printf("\n Enter your choice:");
     scanf("%d",&choice);
     int i=0;
     while(choice != 7)
     {
        switch(choice)
         {


        case 1://readFromFile(4,A);
            //Enter
            checkIfUserReadFromFile=1;
            for(i=1;i<=3;i++)
            {
                readFromFile(i);
              improveLinkedList(EQUATION[i]);
            }
            break;
        case 2://Check	the	validity of	equations(either valid or not)
            if(checkIfUserReadFromFile)
            {
                checkIfUserCheckValidity=1;
                for(i=1;i<=numberOfEquation;i++)
                {
                    numberOfEquationForPrint=i;
                    checkValidity(EQUATION[i]);

                }

            }
            else
            {
                printf("\nError:you should Enter choice one before this choice\n");
            }
           break;

      case 3://Convert	valid	equations	from	infix	to	prefix and	print	the	prefix
             //expressions.
          if(checkIfUserReadFromFile && checkIfUserCheckValidity)
            {
                checkIfUserConvertToPrefix=1;
                 for(i=0;i<numberOfValidEquation;i++)
                 {
                     printf("valid Equation No.%d:",i+1);
                     inToPre(validArray[i]);
                 }
            }
            else
            {
                printf("\nError:you should Enter choice one before this choice\n");
            }
        break;

    case 4://. Evaluate	the	prefix expressions and	print	the	results	of	each
           //equation on a separate line
            if(checkIfUserReadFromFile && checkIfUserCheckValidity && checkIfUserConvertToPrefix)
            {
                numberOfEquationForPrint=i;
                 for(i=0;i<numberOfPrefixEquation;i++)
                 {
                     PrintList(prefixEquation[i]);
                     EvaluatePreFix(prefixEquation[i]);
                 }
            }
            else
            {
                printf("\nError:you should Enter choice one before this choice\n");
            }

        break;

    case 5://Print	invalid equations. This	option	should	print	all	invalid
           //equations from the input file.
        if(checkIfUserReadFromFile && checkIfUserCheckValidity)
            {
               for(i=0;i<numberOfEInvalidEquation;i++)
               {
                   PrintList(invalidArray[i]);
               }
            }
            else
            {
                printf("\nError:you should Enter choice one before this choice\n");
            }
        break;
    case 6://Print	all	equations	to	a	file	(output.txt)	indicating	for	each	input
           //equation	if	it	is	valid	or	not	and	if	valid,	print	out	the	prefix
           //expression and	its result
         /*    for(i=0;i<numberOfEInvalidEquation;i++)
               {
                   writeFile(invalidArray[i],1);
               }
               printf("hasa");
             for(i=0;i<numberOfValidEquation;i++)
             {
                 writeFile(validArray[i],0);
             }*/
            writeFile(prefixEquation[i],0);
         // writeFile(copyResult,sign);
        break;

    case 7://Exit from program
        break;
    default:printf("\n\nInvalid Value\n");
        break;

         }

     display_Menu();
     printf("\nEnter your choice :");
     scanf("%d",&choice);
     }

        printf("\n\n\n.........................................   GOOD BAY    ......................................................  \n\n");


    printf("\nHello world!");
    return 0;
}
//Method Make Empty to linked list methods
struct node* MakeEmptyLinkedList(struct node* L)
{
    if(L != NULL)
    {

        //DeleteList( L );
    }

    L = (struct node*)malloc(sizeof(struct node));
    if(L == NULL)
    {
        printf("Out of memory!\n");

    }

    L->Next = NULL;
    L->prev=NULL;
    return L;
}
//Method to Insert digit from end doubly linked list
void Insert(int digit,char operand,struct node* L)
{

    struct node* new_Node;
    new_Node = (struct node*)malloc(sizeof(struct node));
    pointerToNode P=L;
    while(P->Next != NULL)
    {
        P=P->Next;

    }
    new_Node->operation=operand;
    new_Node->digit = digit;
    new_Node->Next = NULL;
    P->Next = new_Node;
    new_Node->prev= P;
}
//Method to insert digit From Front to doubly linked list
void InsertFromFront(int digit,char operand ,struct node* L)
{
    pointerToNode new_Node;
if(L!=NULL)
 {

    pointerToNode Pos=L->Next;
    new_Node=(pointerToNode)malloc(sizeof(struct node));
    if(new_Node==NULL)
    {
        printf("memory is Full");
    }
    new_Node->operation=operand;
    new_Node->digit=digit;
    new_Node->Next=Pos;
    new_Node->prev=L;
    L->Next=new_Node;
    if(L->Next->Next!=NULL)
    {

       L->Next->Next->prev=new_Node;
    }
 }
 else
 {
     printf("\n NULL POINTER EXCEPTION\n");
 }
}

//Method to print doubly linked list
void PrintList(struct node* L)
{
    if( IsEmptyLinkedList(L))
    {

        printf("\nEmpty list\n");
    }
    else
    {
       struct node* P = L->Next;

        while(P!=NULL)
        {
            if(P->digit!=120)
            {

              printf("%d", P->digit);
            }
            else if(P->operation!='q')
            {
                printf("%c", P->operation);

            }
            P=P->Next;
        }
    }
    printf("\n");
}

//This  Function to delete list if the list have any node that deletion and return list pointer to Null
void DeleteList(pointerToNode L)
{
    struct node* P, *temp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL)
    {
        temp = P->Next;
        free(P);
        P=temp;
    }
}
//This method to check linked list is empty
   int IsEmptyLinkedList(struct node* L)
{
   if(L!=NULL)
   {
    return L->Next == NULL;
   }
    else
    {
       printf("error list is NULL");
       return 1;
    }
}
//////////////////////////////////////////
//////////////////////////////////////////
//method stack implementation
int IsEmpty( pointerToTop S )
{

  if(S!=NULL)
  {
    return S->Next == NULL;
  }
  else
  {
      printf("\n The list is undefined\n");
      return 0;
  }
}

pointerToTop CreateStack(pointerToTop s ){

   s = (struct stack*)malloc( sizeof( struct stack ) );
   if( s == NULL )
   {
      //if memory do not allocation
    printf( "Out of space!" );
   }
   s->Next = NULL;
    return s;
}
//to delete top element and return value for this
int PopInt( pointerToTop S ){
    pointerToTop firstCell;
    //we put -1 to check when we return value -1 that mean the list is empty
    int x = -1;
    if( IsEmpty( S ) )
    {

    // printf( "\nEmpty stack\n" );
    }
    else
    {
       firstCell = S->Next;
       x = S->Next->Element;
       S->Next = S->Next->Next;
       free( firstCell );
    }
     return x;
}

char Popchar( pointerToTop S ){
    pointerToTop firstCell;
    //we put -1 to check when we return value -1 that mean the list is empty
    int x = -1;
    if( IsEmpty( S ) )
    {

    // printf( "\nEmpty stack\n" );
    }
    else
    {
       firstCell = S->Next;
       x = S->Next->operation;
       S->Next = S->Next->Next;
       free( firstCell );
    }
     return x;
}

//this make stack is pointer to null and delete all elements
pointerToTop MakeEmpty( pointerToTop S )
{

   if( S == NULL )
   {

     printf( "Out of space!" );
   }
   else
   {
     while( !IsEmpty( S ))
     {

       Popchar( S );
     }
   }

}
//return value of the top stack , if stack is empty then return -1
char Top( pointerToTop S )
{
//check if stack is not empty
   if( !IsEmpty( S ) )
   {

      return S->Next->operation;
   }
 // printf( "\nEmpty stack \n" );

  return '0';
}

void PushElement( int X,char operand,pointerToTop S )
{
    pointerToTop temp;
    temp = ( pointerToTop )malloc( sizeof( struct node ) );
    if( temp == NULL)
    {

      printf( "Out of space!" );
    }
     else
    {
      temp->operation=operand;
      temp->Element = X;
      temp->Next = S->Next;
      S->Next = temp;
    }
}

//any number you read in file depend on num1
//Very important :q=>char  x=>digit
void readFromFile(int num1)
{
    char nameFile[20];
 /*   if(num1==1)
    {
     printf("Enter your name file with .txt pless: ");
     scanf("%s",nameFile);

    }*/
    pointerToNode position;
    pointerToNode list1=NULL;
    char Rnum;
    int count=1;
   FILE *File=NULL;
      File=fopen("C:\\Users\\qarma\\Desktop\\testProj\\StackImplemintation\\reader.txt","r");
     // File=fopen(nameFile,"r");
   while((Rnum=fgetc(File))!=EOF)
   {
       if(count==num1 && Rnum !='\n')
       {
           //if(Rnum=='-')
           //if char is digit
           if(isdigit(Rnum))
           {
               if(list1==NULL)
               {
                list1=MakeEmptyLinkedList(list1);
                Insert(Rnum-'0','q',list1);

               }
               //else that mean list is not  null =>insert to the list
               else
               {

                   Insert(Rnum-'0','q',list1);

               }
           }
           // if char => operation
           else if(list1 == NULL)
           {

               list1=MakeEmptyLinkedList(list1);
               //ASSCI  code a 'x' =>120
               Insert(120,Rnum,list1);

           }
           else
           {
                Insert(120,Rnum,list1);

           }
       }
       else
        if(Rnum=='\n')
        {

          count++;
        }
   }
   fclose(File);
   EQUATION[num1]=list1;
   numberOfEquation++;

}
//function to delete space and make to number sequences one node
void improveLinkedList(pointerToNode L)
{
    if(L!=NULL)
    {
      pointerToNode curser=L->Next;
      pointerToNode temp;
      pointerToNode position=L->Next;
    int check=0;
      while(position!=NULL)
      {
           check=0;
            //printf("%d\n",position->digit);
        if(position->prev!=L && position->prev->digit!=120)
        {

          if(position->digit != 120)
          {
             // printf("q%d\n",position->prev->digit);
              position->prev->digit=(position->prev->digit*10)+position->digit;

             temp=position;

            if(position->Next!=NULL)
            {
                check=1;
               position->prev->Next=position->Next;
               position->Next->prev=position->prev;
             //position=temp->Next;
            }
            else
            {
                position->prev->Next = NULL;
            }
          }

        }
          position=position->Next;
          if(check)
             free(temp);

      }
    }
}

//In this Function we revers List and store them in new list name copyList
pointerToNode copyLinkedList(pointerToNode L)
{
    pointerToNode pos=FindLast(L);
    pointerToNode copyList=MakeEmptyLinkedList(copyList);
    while(pos!=L)
    {
        Insert(pos->digit,pos->operation,copyList);
        pos=pos->prev;
    }
    return copyList;
}

//this function to find last node in linked list
pointerToNode FindLast(pointerToNode L)
 {
     pointerToNode LAST=L;
    while(LAST->Next != NULL)
    {
        LAST=LAST->Next;

    }
    return LAST;
 }
 //check if char is operation +-*/^[]()
int isOperationAndPrecedence(char x)
{
    switch(x)
    {
    case '-':return 1;
        break;
    case'+': return 1;
        break;
    case '*': return 2;
        break;
    case '/': return 2;
        break;
    case '^': return 3;
        break;
    default :return 0;
        break;

    }
}

void inToPre(pointerToNode L)
{
    pointerToNode copyReversList=copyLinkedList(L);
    pointerToNode output_result=MakeEmptyLinkedList(output_result);
    pointerToTop stackOperation=CreateStack(stackOperation);
    pointerToNode position=copyReversList->Next;
    int precedence=0;
    int TopPrecedence=0;

    while(position!=NULL)
    {
        if(position->digit!=120)
        {
            Insert(position->digit,'q',output_result);
           // printf("y%d",position->digit);
        }
        if(position->operation!='q')
        {
           // printf("qE:%c",position->operation);
             TopPrecedence=isOperationAndPrecedence(Top(stackOperation));
             precedence=isOperationAndPrecedence(position->operation);
            // printf("F%d",precedence);
            if(position->operation==')' || position->operation==']')
            {
                PushElement(120,position->operation,stackOperation);
            }
            else if(position->operation=='(')
            {
                while(Top(stackOperation)!=')' && !(IsEmpty(stackOperation)))
                {
                    Insert(120,Popchar(stackOperation),output_result);
                }
                Popchar(stackOperation);
            }
            else if(position->operation=='[')
            {
                while(Top(stackOperation)!=']' && !(IsEmpty(stackOperation)))
                {
                     Insert(120,Popchar(stackOperation),output_result);
                }
                Popchar(stackOperation);
            }



            else if (precedence >= TopPrecedence)
            {
                PushElement(120,position->operation,stackOperation);
                // printf("\nq:%c\n",position->operation);
            }
            else if(precedence <TopPrecedence)
            {

                while(precedence<isOperationAndPrecedence(Top(stackOperation))&& !(IsEmpty(stackOperation)) )
                {
                    //printf("hass");
                    Insert(120,Popchar(stackOperation),output_result);
                }
                PushElement(120,position->operation,stackOperation);
            }

        }
        position=position->Next;
    }
    while(!IsEmpty(stackOperation))
    {
        Insert(120,Popchar(stackOperation),output_result);
    }
    pointerToNode reverseResult=copyLinkedList(output_result);
    printf("\n");
    prefixEquation[numberOfPrefixEquation]=reverseResult;
    numberOfPrefixEquation++;
    PrintList(reverseResult);
    // return reverseResult;

}
//display menu for choise
void display_Menu()
{
    printf("\n\n////////////////////////                          WELCOM BACK IN CALCULATER               //////////////////////////////\n\n\n");
    printf("                                      Enter your choice:\t\n\n");
    printf("                                       1-Read From File\n");
    printf("                                       2-Check the validity of equation\n");
    printf("                                       3-convert valid equation from infix to prefis\n");
    printf("                                       4-Evaluate  the	prefix \n");
    printf("                                       5-Print	invalid\n");
    printf("                                       6-Print all equations to a file \n");
    printf("                                       7-Exit\t\t\n\n");

}
//evaluate prefix by revers doubly LinkedList and evaluation postfix
void EvaluatePreFix(pointerToNode L)
{
    int result=0;
    //we here revers linked list after make prefix
     pointerToNode copyReverse=copyLinkedList(L);
     pointerToNode position =copyReverse->Next;
     pointerToTop stackOperation=CreateStack(stackOperation);
     int Top=0;
     int Top_1=0;
     while(position!=NULL)
     {
         if(position->digit!=120)
         {
             PushElement(position->digit,'q',stackOperation);
         }
         else if(position->operation!='q')
         {
           Top=PopInt(stackOperation);
           Top_1=PopInt(stackOperation);
           switch(position->operation)
           {
               case '+':PushElement(Top+Top_1,'q',stackOperation);
                 break;
               case '-':PushElement(Top-Top_1,'q',stackOperation);
                 break;
               case '*':PushElement(Top*Top_1,'q',stackOperation);
                 break;
               case '/':PushElement(Top/Top_1,'q',stackOperation);
                 break;
               case '^':PushElement(pow(Top,Top_1),'q',stackOperation);
                 break;
           }
         }
        position=position->Next;
     }
     result=PopInt(stackOperation);
     EvalutionArry[numberOfEvalution]=result;
     numberOfEvalution++;
     printf("Equation No.%d = %d\n",numberOfEquationForPrint,result);

}

/*Important Function check equation if valid or not and return two array
*First array consist valid equation second array consist invalid equation
*and print message explain
*/
int  checkValidity(pointerToNode L)
{
  if(!checkIsOPerationIfknown(L))
  {
    invalidArray[numberOfEInvalidEquation]=L;
    numberOfEInvalidEquation++;
    return 0;
  }
   else if(!checkBalancingParentheses(L))
  {
     invalidArray[numberOfEInvalidEquation]=L;
     numberOfEInvalidEquation++;
    return 0;
  }
   else if(!checkIfOperationIsValidity(L))
  {
      invalidArray[numberOfEInvalidEquation]=L;
      numberOfEInvalidEquation++;
        return 0;
  }
     validArray[numberOfValidEquation]=L;
     numberOfValidEquation++;
     printf("\nEquation No.%d ->Valid\n",numberOfEquationForPrint);
  return 1;
}
/*Function to check validity parentheses if not validity return zero and rejected if valid return 1
* Important note:this function Receive only infix linked list is done without any revers
*/
int checkBalancingParentheses(pointerToNode L)
{
    if(L!=NULL)
    {
        pointerToTop stackParentheses=CreateStack(stackParentheses);
        pointerToNode position=L->Next;
        char checks=NULL;
        while(position!=NULL)
        {
            char precedenc=position->operation;
            char TopPrecedence=Top(stackParentheses);
            //check if node consist of operation
            if(position->operation!='q')
            {
               if (position->operation=='(' || position->operation=='[')
               {
                   PushElement(120,position->operation,stackParentheses);
               }
               else if(position->operation==')')
               {
                    if(IsEmpty(stackParentheses))
                    {
                           printf("\nEquation No.%d -> invalid:This is closing Parentheses ')' without opening '('\n",numberOfEquationForPrint);
                           return 0;
                    }
                    if(Popchar(stackParentheses)!='(')
                    {
                        printf("\nEquation No.%d->invalid:this is not closing true Parentheses for '('\n",numberOfEquationForPrint);
                        return 0;
                    }
               }
               else if(position->operation==']')
               {
                       if(IsEmpty(stackParentheses))
                       {
                           printf("\nEquation No.%d->invalid:This is closing Parentheses ']' without opening '['\n",numberOfEquationForPrint);
                           return 0;
                       }
                       if(Popchar(stackParentheses)!='[')
                       {
                           printf("\nEquation No.%d->invalid:this is not closing true Parentheses for '['\n",numberOfEquationForPrint);
                           return 0;
                       }
               }

            }
            position=position->Next;
        }
        if(!IsEmpty(stackParentheses))
        {
            checks=Popchar(stackParentheses);
            printf("\nEquation No.%d->invalid: %c is not closed\n",numberOfEquationForPrint,checks);
            return 0;
        }
        return 1;
    }
}
//check if all operation is define like +-*/^[]() Any process other than these is rejected and return 0
int checkIsOPerationIfknown(pointerToNode L)
{
    if(L!=NULL)
    {
        pointerToNode position =L->Next;
        while(position!=NULL)
        {
            if(position->operation!='q')
            {
                switch(position->operation)
                {
                case '+':
                case '-':
                case '/':
                case '*':
                case ']':
                case '[':
                case '(':
                case ')':
                case '^':
                    break;
                    //if compiler It arrived here that mean the char is Undefined like !&%$@~?><|\,.: ":;'
                default :printf("\nEquation No.%d->invalid:This %c is not operation\n",numberOfEquationForPrint,position->operation);
                    return 0;
                break;
                }
            }
            position=position->Next;
        }
        //if while is end without return zero that mean all operation is known
        return 1;
    }
    //That mean is  LinkedList is NULL
    printf("\nEquation No.%d->invalid stack is NULL\n",numberOfEquationForPrint);
    return 0;
}
//This Function check a lot of cases make equation invalid
int checkIfOperationIsValidity(pointerToNode L)
{
    if(L!=NULL)
    {
        pointerToNode position =L->Next;
        while(position!=NULL)
        {
            if(position->digit!='q')
            {
               /* if(isOperationAndPrecedence(position->operation))
                {
                    if(position->Next==NULL)
                    {
                        printf("\ninvalid:there	is no digit next operator %c and Next this is NULL\n",position->operation);
                        return 0;
                    }
                    //if before operation is char and after operation  is char that mean is invalid like )+]
                    if(position->prev->digit==120 &&position->Next->digit==120 && position->Next->operation !='(' )
                    {
                        printf("\ninvalid:there is no operand between %c%c%c\n",position->prev->operation,position->operation,position->Next->operation);
                        return 0;
                    }
                }*/
                 if(position->operation=='('  || position->operation=='['  )
                {

                    if(position->prev!=L &&(position->prev->digit!=120 && (position->prev->operation!='(' || position->prev->operation!='[')))
                    {
                        if(position->Next!=NULL && position->Next->digit==120 )
                        {

                           printf("\nEquation No.%d->invalid:there is no operator between %d%c%c\n",numberOfEquationForPrint,position->prev->digit,position->operation,position->Next->operation);
                                return 0;

                        }
                        else //(position->Next!=NULL && position->Next->digit!=120)
                        {
                           printf("\nEquation No.%d->invalid:there is no operator between %d%c%d\n",numberOfEquationForPrint,position->prev->digit,position->operation,position->Next->digit);
                            return 0;
                        }
                        return 0;
                    }


                }
                else if(position->operation==')'  || position->operation==']')
                {
                    //check if befor ) or ] there is operation like +) this is invalid
                  /*  if(position->prev->digit==120 && position->prev->operation!=')' && position->prev->operation!=']')
                    {

                      printf("invalid:there is operator before as %d%c\n",position->prev->digit,position->operation);
                      return 0;
                    }*/
                    //check if after ] or ) there is operation like )6 this is invalid but if next==null do not care
                    if(position->Next!=NULL && ((position->Next->operation=='q') && (position->Next->operation!=')' || position->Next->operation!=']')) )
                    {
                        if(position->prev->digit!=120)
                        {
                          printf("\nEquation No.%d->invalid:there is no operator after  as  %d%c%d\n",numberOfEquationForPrint,position->prev->digit,position->operation,position->Next->digit);
                            return 0;
                        }
                        else
                        {
                          printf("\nEquation No.%d->invalid:there is no operator after  as  %c%c%d\n",numberOfEquationForPrint,position->prev->operation,position->operation,position->Next->digit);
                           return 0;
                        }
                        return 0;
                    }
                }

            }
            position=position->Next;

        }
        return 1;
    }
}

void writeFile(pointerToNode list ,int c)
{
    int resultEvalution=0;
    int i=0;
       FILE* file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("\nFailed to open the file.\n");
        return;
    }
    // Traverse the linked list forward and write each element to the file

    fprintf(file,"\nInValid Equation\n");
    for(i=0;i<numberOfEInvalidEquation;i++)
    {
       list=invalidArray[i];
    pointerToNode current_Node = list->Next;
    while (current_Node != NULL)
    {
        if(current_Node->digit!=120)
        {
          fprintf(file, "%d", current_Node->digit);
        current_Node = current_Node->Next;
        }
        else
        {
            fprintf(file, "%c", current_Node->operation);
            current_Node = current_Node->Next;

        }
    }
    }


        for(i=0;i<numberOfValidEquation;i++)
        {

        fprintf(file,"\nvalid Equation\n");
          list=validArray[i];
        pointerToNode current_Node = list->Next;

         while (current_Node != NULL)
         {
        if(current_Node->digit!=120)
        {
          fprintf(file, "%d", current_Node->digit);
        current_Node = current_Node->Next;
        }
        else
        {
            fprintf(file, "%c", current_Node->operation);
            current_Node = current_Node->Next;

        }
        }
        list=prefixEquation[i];
         current_Node = list->Next;
         fprintf(file,"\npreFix:");
        while(current_Node != NULL)
        {
        if(current_Node->digit!=120)
        {
          fprintf(file, "%d", current_Node->digit);
        current_Node = current_Node->Next;
        }
        else
        {
            fprintf(file, "%c", current_Node->operation);
            current_Node = current_Node->Next;

        }
        }
        fprintf(file, "\nResult Evalution:%d", EvalutionArry[i]);
        }

   fprintf(file,"\n");
    printf("\n check file \n ");
    fclose(file);  // Close the file
}
