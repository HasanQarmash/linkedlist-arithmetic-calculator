/*
*  Name:Hasan Qarmash
*  ID :1210611
* sec:2
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node* pointerToNode;
typedef pointerToNode list;
struct node
    {
   int digit;
   pointerToNode Next;
   pointerToNode prev;
    };

    pointerToNode MakeEmpty(struct node* L);
    int IsEmpty(struct node* L);
    int IsLast(struct node* P, struct node* L);
    struct node* Find(int cof, int pwr, struct node* L);
    struct node* FindPrevious(int cof, int pwr, struct node* L);
    void Insert(int digit,struct node* L);
    void InsertFromFront (int digit ,struct node* L);
    void PrintList(struct node* L);
    pointerToNode FindLast(pointerToNode L);
   // pointerToNode LargerNumber(pointerToNode L1,pointerToNode L2);
    pointerToNode add_Node(pointerToNode L1,pointerToNode L2 );
    pointerToNode reverseList(pointerToNode head);
    pointerToNode sub_Node(pointerToNode L1,pointerToNode L2);
    void Size_Standardization(pointerToNode L1,pointerToNode L2);
    pointerToNode tensComplement(pointerToNode L);
    int FindLargerList(pointerToNode L1,pointerToNode L2);
    pointerToNode mul_node(pointerToNode L1,pointerToNode L2);
    int size( struct node* L);
    void DeleteZeroList(struct node* L);
    void DeleteList(pointerToNode L);
    pointerToNode copyLinkedList(pointerToNode L);
    pointerToNode div_Node(pointerToNode L1,pointerToNode L2);
    void display_Menu();
    pointerToNode New_add(pointerToNode L1,pointerToNode L2);
    pointerToNode New_MUL(pointerToNode L1,pointerToNode L2);
    pointerToNode readFromFile(int num1,int *A[]);
    void writeFile(pointerToNode list,int sign);





int main()
{

    /*in this line we definition sign as array consist from 3 index
    * index 1 for sign List one
    * index 2 for sign List two
    * index 3 for sign result
    * Hint: 0 positive >> << 1:negative
    */
    int A[]={1,1,0,0};
     pointerToNode List_1=readFromFile(1,A);
     pointerToNode List_2=readFromFile(2,A);
     pointerToNode List_3=readFromFile(3,A);
     pointerToNode copyResult=MakeEmpty(copyResult);
     Insert(0,copyResult);



     printf("For this Number choice any two number you want:\n");
     if(A[0]==1){printf("1:-");}
     else{printf("1:");}
     PrintList(List_1);
     if(A[1]==1){printf("2:-"); }
     else{printf("2:");}
     PrintList(List_2);
     if(A[2]==1){printf("3:-");}
     else{printf("3:");}
     PrintList(List_3);
      int num1=0;
     printf("\nEnter First choice Number:");
      scanf("%d",&num1);
        int num2=0;
      printf("\n");
    printf("\nEnter Second choice Number :");
    pointerToNode general_List1;
    pointerToNode general_List2;
        scanf("%d",&num2);
        switch(num1)
        {
            case 1:general_List1=List_1;
            break;
            case 2:general_List1=List_2;
            break;
            case 3:general_List1=List_3;
            break;
            default :general_List1=List_1;
            break;
        }
         switch(num2)
        {
            case 1:general_List2=List_1;
            break;
            case 2:general_List2=List_2;
            break;
            case 3:general_List2=List_3;
            break;
            default :general_List2=List_1;
            break;
        }

    Size_Standardization(general_List1,general_List2);
    printf("List Number one: ");
    PrintList(general_List1);
    printf("List Number two: ");
    PrintList(general_List2);
    int sign=0;

    int choice=0;

     pointerToNode result=MakeEmpty(result);
     display_Menu();
     printf("\n Enter your choice:");
     scanf("%d",&choice);
     while(choice != 7)
     {
        switch(choice)
         {


         case 1://readFromFile(4,A);
         break;
         case 2://Addition operation
              result=New_add(general_List1,general_List2);
              //PrintList(result);
            //that mean number one is + and number two is +
           if(A[num1-1]==0 && A[num2-1]==0)
           {
              A[2]=0;
              result=New_add(general_List1,general_List2);
              PrintList(result);

           }
           else if (A[num1-1]==1 && A[num2-1]==1)
           {

              A[2]=1;
               result=New_add(general_List2,general_List1);
               printf("-");
               PrintList(result);

           }
         else if (A[num1-1]==1 && A[num2-1]==0)
           {
               if(FindLargerList(general_List1,general_List2))
               {
                 A[2]=1;
                 printf("-");

               }
               result=sub_Node(general_List2,general_List1);
               PrintList(result);

           }
           //that mean number one is + and number two is -
           else if( A[num1-1]==0 && A[num2-1]==1)
           {
             if(FindLargerList(general_List2,general_List1))
               {
                 A[2]=1;
                 printf("-");
               }
               result=sub_Node(general_List1,general_List2);
               PrintList(result);
           }
           else{printf("Erorr operation");}
           break;

    case 3://subtraction operation
         if(A[num1-1]==0 && A[num2-1]==0)
           {
               A[2]==0;
              result=sub_Node(general_List1,general_List2);
              PrintList(result);

           }
           //that mean number one is - and number two is -
           else if(A[num1-1]==1 && A[num2-1]==1)
           {
              A[2]==1;
              result=sub_Node(general_List2,general_List1);
              printf("-");
              PrintList(result);
           }
           //that mean number one is - and number two is +
           else if (A[num1-1]==1 && A[num2-1]==0)
           {

               A[2]=1;
               result=New_add(general_List1,general_List2);
               printf("-");
               PrintList(result);
           }
           //that mean number one is + and number two is -
           else if( A[num1-1]==0 && A[num2-1]==1)
           {
               A[2]=0;
               result=New_add(general_List1,general_List2);
           }
           else{printf("\nErorr operation\n");}
           break;

    case 4://mull operation
        if((A[num1-1]==1 && A[num2-1]==1) || (A[num1-1]==0 && A[num2-1]==0) )
        {
            A[2]=0;

              if(FindLargerList(general_List1,general_List2))
             {
               result=New_MUL(general_List2,general_List1);
               PrintList(result);
             }
             else{result=New_MUL(general_List1,general_List2);PrintList(result);}
        }
        else
        {

            A[2]=1;
           result=New_MUL(general_List1,general_List2);
           printf("-");
           PrintList(result);
        }

        break;

    case 5://div
        break;
    case 6://print file
          writeFile(copyResult,sign);
        break;

    case 7://Exit
        break;
    default:printf("\n\n Envalid Value\n");
        break;

         }
          copyResult=copyLinkedList(result);
          copyResult=copyLinkedList(copyResult);
        // PrintList(copyResult);
         DeleteList(result);
     //store sign result if you want to print on file in next step
     sign=A[2];
     //defult positive
     A[2]=0;
     display_Menu();
     printf("\nEnter your choice :");
     scanf("%d",&choice);
     }

        printf("\n\n\n...............................               GOOD BAY    ...........................................  \n\n");



    printf("Hello world!\n");
    return 0;
}

struct node* MakeEmpty(struct node* L)
{
    if(L != NULL)
    {

        DeleteList( L );
    }

    L = (struct node*)malloc(sizeof(struct node));
    //struct node* tail= (struct node*)malloc(sizeof(struct node));
    if(L == NULL)
    {
        printf("Out of memory!\n");

    }

    L->Next = NULL;
    L->prev=NULL;
    return L;
}
   int IsEmpty(struct node* L)
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


int IsLast(struct node* P, struct node* L)
{
    return P->Next==NULL;
}



void DeleteZeroList(struct node* L)
{
    pointerToNode temp;
    //pointerToNode POS=L->Next->Next;
    while((L->Next!=NULL) && (L->Next->digit)==0 &&(L->Next->Next!=NULL))
    {
        temp =L->Next;
        L->Next->Next->prev = L;
        L->Next = L->Next->Next;
        free(temp);
    }
}
//DONE
void Insert(int digit,struct node* L)
{

    struct node* new_Node;
    new_Node = (struct node*)malloc(sizeof(struct node));
    pointerToNode P=L;
    while(P->Next != NULL)
    {
        P=P->Next;

    }

    new_Node->digit = digit;
    new_Node->Next = NULL;
    P->Next = new_Node;
    new_Node->prev= P;
}

void InsertFromFront(int digit ,struct node* L)
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

//DONE
void PrintList(struct node* L)
{
    if( IsEmpty(L))
    {

        printf("\nEmpty list\n");
    }
    else
    {
       struct node* P = L->Next;

        while(P!=NULL)
        {
            printf("%d", P->digit);
            P=P->Next;
        }
    }
    printf("\n");
}




pointerToNode add_Node(pointerToNode L1,pointerToNode L2)
{
   // DeleteList(result_Sum);
   printf("\n Here is first line in addition \n");
    pointerToNode result_Sum = MakeEmpty(result_Sum);
    PrintList(L1);
    PrintList(L2);
   // printf(L1);
    int count=0;
    int carry=0;
    int size1=size(L1);
    int size2=size(L2);
    pointerToNode position_2=FindLast(L2);
    pointerToNode position_1=FindLast(L1);
   // printf("\n digit number %d\n",position_1->prev->digit);
  //  if(position_1->prev==NULL)
  //  {
    //    printf("null pointer");
   // }
  //printf("here next call size stander\n");
   //PrintList(L1);
   // PrintList(L2);
    PrintList(L1);
    PrintList(L2);


        //Since the two numbers are equal, whichever number we ended up with means that we finished with the two lists
        while(!(position_1 == L1)&& (position_1!=NULL) && position_2!=NULL)
        {
            count =(position_1->digit)+(position_2->digit)+carry;
            //printf("count is %d\n",count);
           // printf("carry is %d \n",carry);
           // printf("%d + %d +%d\n",(position_1->digit),(position_2->digit),carry);
            if(count>9 && (position_1->prev != L1) && position_1!=NULL && position_2!=NULL)
            {
              //  printf("this befor print digti");
                carry=count/10;
                count=count%10;
                InsertFromFront(count ,result_Sum);
               // printf("carry is %d \n",carry);
                position_2=position_2->prev;
                position_1=position_1->prev;
            }

            else
            {
                carry=0;
              //printf("\njjjjjjj");
               InsertFromFront(count ,result_Sum);
               position_2=position_2->prev;
               position_1=position_1->prev;

            }

        }


        printf("\n\n");
    PrintList(result_Sum);
    return result_Sum;

}





void Size_Standardization(pointerToNode L1,pointerToNode L2)
{

    int lengthList1=size(L1);
    int lengthList2=size(L2);
    if(lengthList1==lengthList2 || L1==NULL || L2==NULL || L1->Next==NULL || L2->Next==NULL)
    {
    //printf("\n ERRORRRRRRR \n");

    }
    else
    {


   // printf("\nHERE SIZE STAND FIRST LINE IN FUNC\n");

    while(lengthList1>lengthList2)
    {
      /* pointerToNode temp=(pointerToNode)malloc(sizeof(struct node));
        temp->digit=0;
        temp->Next=L2->Next;
        temp->prev=L2;
        L2->Next->prev=temp;
        L2->Next=temp;*/
        InsertFromFront(0,L2);
        lengthList2++;

    }
    while(lengthList1<lengthList2)
    {
      /*  pointerToNode temp=(pointerToNode)malloc(sizeof(struct node));
        temp->digit=0;
        temp->Next=L1->Next;
        temp->prev=L1;
        L1->Next->prev=temp;
        L1->Next=temp;*/
        InsertFromFront(0,L1);
        lengthList1++;
    }
    }
}
pointerToNode tensComplement(pointerToNode L)
{
    printf("\nYOU CALL COMPLEMENT AND THIS FIRST LINE\n");
    pointerToNode result_complement=MakeEmpty(result_complement);
    pointerToNode position=L->Next;

    while(position != NULL)
    {
        //printf("here then call tens complement");
           Insert(9-position->digit,result_complement);
            position=position->Next;

    }
   // result_complement=add_Node(result_complement,add_1);
   // printf("RESULT COMPlement");
   // PrintList(result_complement);
    // printf("hhhhhhhqqqqq");
     //DeleteZeroList(result_complement);
     return result_complement;

}







int FindLargerList(pointerToNode L1,pointerToNode L2)
{
        pointerToNode Position1=L1->Next;
        pointerToNode Position2=L2->Next;
        while(Position1 !=NULL && Position2 != NULL)
        {
              if(Position1->digit > Position2->digit )
              {

                 return 1;
              }
              else if(Position1->digit < Position2->digit)
              {


                  return 0;
              }
              Position1=Position1->Next;
              Position2=Position2->Next;
        }

        //printf("\nHint :The two list is Equal \n");
        return 2;

}
//In this Function we revers List and store them in new list name copyList
pointerToNode copyLinkedList(pointerToNode L)
{
    pointerToNode pos=FindLast(L);
    pointerToNode copyList=MakeEmpty(copyList);
    while(pos!=L)
    {
        Insert(pos->digit,copyList);
        pos=pos->prev;
    }
    return copyList;
}

pointerToNode New_add(pointerToNode L1,pointerToNode L2)
{
    pointerToNode position_1=FindLast(L1);
    pointerToNode position_2=FindLast(L2);
    pointerToNode result_Sum=MakeEmpty(result_Sum);
    int count=0;
    int carry=0;
    int size1=size(L1);
    int size2=size(L2);

    //Check if size of number one is larger than number two >> that mean size one  is augend and size two is addend
    if(size1>size2)
    {
        //Check if the largest list ends
        while(position_1!=L1)
        {
            //printf("hello world");
            count=0;
            //Check if the smaller list ends
            if(position_2==L2 || position_2==NULL)
            {
                count=(position_1->digit)+carry;
               // carry=count/10;
               // count=count%10;
                InsertFromFront(count,result_Sum);
                position_1=position_1->prev;
            }
            else
            {
                //check if result of sum two node large than 10 then computes carry and
                count=(position_1->digit)+(position_2->digit)+carry;
                if(count>9 && position_1->prev != L1)
                {
                    //if sum two digit is lager than 10 >> the carry is 1 addend tp previous digit
                    carry=count/10;
                    count=count%10;
                  //  position_1->prev->digit=position_1->prev->digit+1;
                    InsertFromFront(count,result_Sum);
                    //make the pointer position
                    position_2=position_2->prev;
                    position_1=position_1->prev;

                }
                //else that mean two cases :case one count is smaller than 10 or case two the digit is most significant bit
                else
                {
                  count=(position_1->digit)+(position_2->digit)+carry;
                  carry=0;
                  InsertFromFront(count,result_Sum);
                  position_2=position_2->prev;
                  position_1=position_1->prev;
                }

            }
        }
        return result_Sum;
    }
//Check if size of number two is larger than number one >> that mean size two  is augend and size one is addend
       else if(size1<size2)
    {

    //Check if the largest list ends
        while(position_2!=L2)
        {
           // count=0;
            //Check if the smaller list ends
            if(position_1==L1)
            {
                printf("pos %d",position_2->digit);
                count=(position_2->digit)+carry;
                //printf("\n are %d :",count);
                //carry=count/10;
               // count=count%10;
               // printf("\n caryy is %d",carry);
                InsertFromFront(count,result_Sum);
                position_2=position_2->prev;
            }
           else
            {
                //check if result of sum two node large than 10 then computes carry and
                count=(position_1->digit)+(position_2->digit)+carry;
                if(count>9 && position_2->prev != L2)
                {

                    //if sum two digit is lager than 10 >> the carry is 1 addend tp previous digit
                    carry=count/10;
                    count=count%10;
                    InsertFromFront(count,result_Sum);
                    //make the pointer position
                    position_2=position_2->prev;
                    position_1=position_1->prev;

                }
                //else that mean two cases :case one count is smaller than 10 or case two the digit is most significant bit
                else
                {
                   // printf("\n caryy is %d",carry);
                    carry=0;
                    InsertFromFront(count,result_Sum);
                    //printf("\n konan %d :",count);
                    position_2=position_2->prev;
                    position_1=position_1->prev;
                }

            }
        }
        return result_Sum;

        }


    //else the two number is the same number of digit
    else
    {
        while(!(position_1 == L1)&& (position_1!=NULL) && position_2!=NULL && position_2 !=L2)
        {
           // printf("hello world");
            count=0;
            count=(position_1->digit)+(position_2->digit)+carry;
            if(count>9 && position_1->prev!=L1 && position_2->prev!=L2 )
            {
                carry=count/10;
                count=count%10;
                InsertFromFront(count,result_Sum);
                position_1=position_1->prev;
                position_2=position_2->prev;
            }
            else
            {
                InsertFromFront(count,result_Sum);
                carry=0;
                position_1=position_1->prev;
                position_2=position_2->prev;
            }
        }
        return result_Sum;
    }
}




/*
pointerToNode sub_Node(pointerToNode L1,pointerToNode L2)
{


       pointerToNode copyL1=copyLinkedList(L1);
       pointerToNode copyL2=copyLinkedList(L2);
      //printf("%d",FindLargerList(copyL1,copyL2));
      if(FindLargerList(copyL1,copyL2))
        printf("[[[[[[[[[]]]]]]]");
       pointerToNode result_Sub=NULL;
       pointerToNode complement=NULL;
       complement=tensComplement(L1);
       result_Sub = add_Node(complement,copyL2);

   // pointerToNode position_1=FindLast(L1);
    //pointerToNode position_2=FindLast(L2);
   //  char flag='+';
   // pointerToNode complementNode;
   // complementNode=MakeEmpty(complementNode);
  // Size_Standardization(L1,L2);
  // pointerToNode complementNode = NULL;
    // complementNode=tensComplement(smallNumber);
   /* if(LargerNumber==L2)
    {
        flag='-';
    }*/
   // int count=0;
  //  int size1=size(L1);
   // int size2=size(L2);
   /*  printf("this comp:");
     // PrintList(complementNode);
    printf("\n this larg:");
      PrintList(LargerNumber);
     printf("\n this small:");
      PrintList(smallNumber);
    printf("\n this line befor print\n");

    result_Sub=add_Node(smallNumber,LargerNumber);

      //result_Sub=add_Node(L1,L2);
      printf("\n this line after print\n");
    // pointerToNode add_1=MakeEmpty(add_1);
     //Insert(1,add_1);
     //Size_Standardization(add_1,L2);
     //result_Sub=add_Node(add_1,L2);
   // printf("\n%d\n",complementNode->Next->digit);
   /* pointerToNode position =result_Sub->Next;
     result_Sub->Next=result_Sub->Next->Next;
     result_Sub->Next->prev=result_Sub;
     free(position);


    return result_Sub;

}*/






pointerToNode sub_Node(pointerToNode L1,pointerToNode L2)
{

     //Size_Standardization(L1,L2);
     pointerToNode position_1=FindLast(L1);
     pointerToNode position_2=FindLast(L2);

     pointerToNode result_sub=MakeEmpty(result_sub);
     int borrow=0;
     if(FindLargerList(L1,L2))
     {

     while(position_1 !=L1 && position_2 !=L2)
     {
         if((position_1->digit +borrow) >= position_2->digit)
         {
             InsertFromFront(position_1->digit-position_2->digit+borrow,result_sub);
             borrow=0;
         }
         else
         {
             InsertFromFront((position_1->digit)+10-(position_2->digit)+borrow,result_sub);
             borrow =-1;
         }
         position_1=position_1->prev;
         position_2=position_2->prev;
     }
     return result_sub;
     }
     else
     {
         result_sub=sub_Node(L2,L1);
         // A[2]==0;
        return result_sub;
     }
}

pointerToNode mul_node(pointerToNode L1,pointerToNode L2)
{
    //Size_Standardization(L1,L2);
    pointerToNode position_1=FindLast(L1);
    pointerToNode position_2=FindLast(L2);
    pointerToNode result_MUL =MakeEmpty(result_MUL);
    Insert(0,result_MUL);//nice
    pointerToNode temp =MakeEmpty(temp);
    pointerToNode LastElement=position_2;
    int size_number1=size(L1);
    int size_number2=size(L2);
    PrintList(L1);
    PrintList(L2);
    //int insertZero=(FindLargerList(L1,L2)>0)?size_number2:size_number1;
    int carry=0;
    int count=0;
    int i=0;
    int resultOfMulNode =0;
    while(position_1 != L1)
    {
       // DeleteList(temp);
        position_2=LastElement;
        resultOfMulNode=0;
        while(position_2 !=L2)
        {
           // printf("\n wahdadawijdiajwdi \n");
            resultOfMulNode=(position_1->digit)*(position_2->digit)+carry;
            carry=resultOfMulNode/10;
            resultOfMulNode=resultOfMulNode%10;
           // printf("res %d",resultOfMulNode);
           // printf("carry %d",carry);
           // printf("%d\n",resultOfMulNode);
            InsertFromFront(resultOfMulNode,temp);
           // PrintList(temp);
            position_2=position_2->prev;

        }
         i=count;
        while(i>0)
        {
           // printf("\n \n");
            i--;
            Insert(0,temp);
            PrintList(temp);
            printf("\n");

        }
        //printf("\n rrrrrrrrrrrrrrrrrrrrrrrr \n");
        position_1=position_1->prev;
        //Size_Standardization(temp,result_MUL);
        count++;
        result_MUL = New_add(result_MUL,temp);
        PrintList(result_MUL);
        //DeleteList(temp);
    }
        //PrintList(result_MUL);
        printf("\n");
        //PrintList(result_MUL);
        return result_MUL;

}

//This  Function to delet list if the list have any node that deletion and return list pointer to Null
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
//this function to find size list
int size( struct node* L)
{
    struct node* p = L->Next;
    int count = 0;
    while(p != NULL )
    {
        count++;
        p = p->Next;
    }
    return count;
}
//Function mull
pointerToNode New_MUL(pointerToNode L1,pointerToNode L2)
{
     //In this line we revers two linked list to apply operation on them
     Size_Standardization(L1,L2);
     pointerToNode copyList_1=copyLinkedList(L1);
     pointerToNode copyList_2=copyLinkedList(L2);
    pointerToNode lastPosition_1=FindLast(L1);

  //  pointerToNode lastPosition_2=FindLast(L2);
  //printf("asd");
    // PrintList(copyList_2);
    // PrintList(copyList_1);
     pointerToNode position_1=copyList_1->Next;
    pointerToNode temp=position_1;
    pointerToNode position_2=copyList_2->Next;
    int size1=size(copyList_1);
    int size2=size(copyList_2);
    pointerToNode result_mul=MakeEmpty(result_mul);
     int  i=size1+size2+1;
    //insert to array result zero
    while(i>0)
    {
        InsertFromFront(0,result_mul);
        i--;
    }
    pointerToNode position_result=result_mul->Next;
    pointerToNode Save_position_result=position_result;
    int carry=0;
    while (position_2!=NULL)
    {

        carry=0;
        position_1=temp;
        position_result=Save_position_result;
        while(position_1->Next!=NULL )
        {
           int  resultOfMulNode =(position_1->digit) * (position_2->digit) +carry;
           (position_result->digit) =(position_result->digit)+resultOfMulNode%10;
           carry =(resultOfMulNode/10) + (position_result->digit)/10;
           position_result->digit=(position_result->digit)%10;
           position_result=position_result->Next;
            if(position_1!=NULL)
            position_1=position_1->Next;
            else
                break;
            //printf("position one after is %d\n",position_1->digit);
           // if(position_1->Next!=NULL)

        }
      //  printf("DONT CARE");
       // printf("DONT CARE");

        if(carry>0)
        {
            position_result->Next->digit= position_result->Next->digit +carry;

        }
        Save_position_result=Save_position_result->Next;
        //if(position_2==NULL)
        position_2=position_2->Next;


    }
    pointerToNode ReversResult=copyLinkedList(result_mul);
    return ReversResult;
}






//function division :)
pointerToNode div_Node(pointerToNode L1,pointerToNode L2)
{
    DeleteZeroList(L1);
    DeleteZeroList(L2);
    PrintList(L2);
    PrintList(L1);
    pointerToNode result_sub;
    pointerToNode result_mull;
    pointerToNode ListZero=MakeEmpty(ListZero);
    Insert(0,ListZero);
    pointerToNode result_div=MakeEmpty(result_div);
    pointerToNode temp=MakeEmpty(temp);
    int size_1=size(L1);
    int size_2=size(L2);
    //we apply do while loop and while loop
    //if L2 larger tan L1 that mean result is zero or if you want L1
    if(FindLargerList(L2,L1))
    {
        Insert(0,result_div);
        return result_div;
    }
    else
    {
        pointerToNode position=L1->Next;
        while(position !=NULL)
        {


           int i=0;
        /*   for(i=size_2;i>0;i--)
           {
            Insert(position->digit,temp);
            position=position->Next;
           }*/
        //if L2 large than temp we will get to another node then must temp larger than L2
        //WE try to find temp
        while(FindLargerList(L2,temp))
        {

            Insert(position->digit,temp);

            PrintList(temp);
           // if(position!=NULL){
            position=position->Next;
            //else{break;}

        }
           result_sub=sub_Node(temp,L2);
        /*temp is done and larger than L2
         * we must to sub temp-L2 to find how much L2 in temp
         *and we will store the result in sub_node
         *Then we compare sub_node>0 if yes sub aroud two
         *finally mul count in L2 and compare L2 in temp if larger add next digit
        */
           int count=0;
           do
            {
                count++;
             result_sub=sub_Node(result_sub,L2);

            }
            while(FindLargerList(result_sub,ListZero));

            InsertFromFront(count,result_div);
            DeleteList(temp);
            temp = mul_node(result_div,L2);

        }
        //temp is reminder



    }
}
//display menu for choise
void display_Menu()
{
    printf("\n\n////////////////////////                          WELCOM BACK IN CALCULATER               //////////////////////////////\n\n\n");
    printf("                                      Enter your choice:\t\n\n");
    printf("                                       1-Read From File\n");
    printf("                                       2-Addition\n");
    printf("                                       3-Subtraction\n");
    printf("                                       4-Multiplication\n");
    printf("                                       5-Division\n");
    printf("                                       6-print to file \n");
    printf("                                       7-Exit\t\t\n\n");

}


pointerToNode readFromFile(int num1,int *A[])
{
    pointerToNode list1=NULL;
    char Rnum;
    int count=1;
   FILE *File=NULL;
   File=fopen("C:\\Users\\qarma\\Desktop\\testProj\\NextPorg\\read.txt","r");
   while((Rnum=fgetc(File))!=EOF)
   {
       if(count==num1 && Rnum !='\n')
       {
           if(Rnum=='-')
           {
               if(list1==NULL)
               {
                  // A[num1-1]=1;
                  // printf("%d",A[0]);
                  // printf("%d",A[1]);
                   //printf("are you good %d \n",num1);
                list1=MakeEmpty(list1);
               }
               else
               {
                   printf("Invalid number");
               }
           }
           else if(list1 == NULL)
           {
             //printf("are you Sade % \n");
             //  A[num1-1]=0;
               list1=MakeEmpty(list1);
               Insert(Rnum-'0',list1);
           }
           else
           {
               Insert(Rnum-'0',list1);
           }
       }
       else
        if(Rnum=='\n')
        count++;
   }
   fclose(File);
   return list1;

}
void writeFile(pointerToNode list,int sign)
{


       FILE* file = fopen("write.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    if(sign==1)
    {
        char a='-';
      fprintf(file,"-",a);
    }
    // Traverse the linked list forward and write each element to the file
    pointerToNode current_Node = list->Next;
    while (current_Node != NULL) {
        fprintf(file, "%d", current_Node->digit);
        current_Node = current_Node->Next;
    }

    printf("\n check file \n ");
    fclose(file);  // Close the file
}


