#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct stud 
 {
     int rno;
     char name[50];
     struct stud *lp,*rp;
 };
 FILE *fp;

 struct stud *cr_node(int val,char n[])
 {
      struct stud *new1=(struct stud*)malloc(sizeof(struct stud));
      new1->rno=val;
      strcpy(new1->name,n);
      new1->lp=NULL;
      new1->rp=NULL;
      
      return new1;   
 }
 struct stud *ins(int val,char n[],struct stud *root)
 {
     if(root==NULL)
     {
         root=cr_node(val,n);
     }
     else if(val<root->rno)
     {
         root->lp=ins(val,n,root->lp);
     }
     else if(val>root->rno)
     {
         root->rp=ins(val,n,root->rp);
     }
     else
     {
         printf("Dulicate value note allow");
     }
     return root;
 }
 void in(struct stud *root)
 {
     if(root!=NULL)
     {
         in(root->lp);
         printf("\n%d ",root->rno);
         fprintf(fp,"%d ",root->rno);
         in(root->rp);
     }
 }
 void pre(struct stud *root)
 {
     if(root!=NULL)
     {
         printf("\n%d ",root->rno);
         pre(root->lp);
         pre(root->rp);
         
     }
 }
void post(struct stud *root)
 {
     if(root!=NULL)
     {
         post(root->lp);
         post(root->rp);
         printf("\n%d ",root->rno);
     }
 }
 
 void update(int val,struct stud *root)
 {
     if(root!=NULL)
     {
     if(root->rno==val)
     {
         printf("\nEnetr the new rno:");
         scanf("%d",&root->rno);
         printf("\nEnetr the new name:");
         scanf("%s",root->name);
         
     
     }
     else if(val<root->rno)
     {
         update(val,root->lp);
     }
     else if(val>root->rno)
     {
         update(val,root->rp);
     }
    }     
 }
 void search(int val,struct stud *root)
 {
     if(root!=NULL)
     {
     if(root->rno==val)
     {
         
        printf("data is found"); 
     }
     else if(val<root->rno)
     {
         search(val,root->lp);
     }
     else if(val>root->rno)
     {
         search(val,root->rp);
     }
     }
     else
     {
         printf("NOT");
     }
    
 }   
 struct stud*del(int val,struct stud *root)
 {
    if(root==NULL)
    {
            printf("tree is empty");
            return NULL;
    } 
    else if(val<root->rno)
    {
        root->lp=del(val,root->lp);
    }
    else if(val>root->rno)
    {
        root->rp=del(val,root->rp);
    }
    else
    {
        if(root->lp==NULL && root->rp==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->lp!=NULL && root->rp==NULL)
        {
            struct stud *temp=root->lp;
            free(root);
            return temp;
        }
        else if(root->rp!=NULL && root->lp==NULL)
        {
            struct stud *temp=root->rp;
            
            free(root);
            return temp;
        }
        else
        {
            struct stud *temp=root->rp;
            while(temp->lp!=NULL)
            {
                temp=temp->lp;
            }
            root->rno=temp->rno;
            root->rp=del(temp->rno,root->rp);
        }
        return root;
    }
}

 void main()
 {
     int i,ch,un;
     int a,sn,dn;
     char n[50];
     struct stud *root=NULL;
     
     while(1)
     {
         printf("\n1.INS \n2.IN \n3.PRE \n4.POST \n5.UP \n6.SREARCH \n7.DELETE \n0.EXIT");
         printf("\nEnetr the user choice");
         scanf("%d",&ch);
         
         switch(ch)
         {
              case 1:
                      printf("\nEnetr the rno:");
                      scanf("%d",&a);
                     // printf("\nEnter the name:");
                     // scanf("%s",n);
                      
                      root=ins(a,n,root);
                      break;
                      
              case 2:
                    fp=fopen("inredert.txt","w+");
                      in(root);
                      printf("\nfile data -->");
                      rewind(fp);
                      while (fscanf(fp,"%d",&a))
                      {
                        /* code */
                        printf("%d ",a);
                      }
                      
                      break;
                      
              case 3:
                      pre(root);
                      break;        
             case 4:
                      post(root);
                      break;        
             case 5:
                     printf("\nEnetr the what a number are you update");         
                      scanf("%d",&un);
                      update(un,root);
                      break;
             case 6:
                     printf("\nEnetr the search nu:");
                     scanf("%d",&sn);
                         search(sn,root);
                         break;         
             case 7:
                     printf("\nEnetr the delete no:");
                     scanf("%d",&dn);
                     
                     root=del(dn,root);            
                     break;
                     
             case 0:exit(0);
                     break;         
         }
     }    
 }//. Delete opration jo to